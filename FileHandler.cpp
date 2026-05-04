// File       : FileHandler.cpp
// Author     : Ibrahim Jahangir
// Date       : 4/28/2026
// Course     : CSCI 272 - Object Oriented Programming
// Role       : Member 5 - File handling and CSV parsing

#include "FileHandler.h"


//this function loads all the events from the CSV file.
//it reads the file line by line and sends each line to parseCSVLine().
//this is the main function that other parts of the project can call when they need data from the file.
vector<Event*> FileHandler::loadEventsFromFile(string filename) {

    //this vector stores all the event pointers.
    //i used Event* because IntrusionEvent and MalwareEvent both come from Event.
    //this is important because it supports polymorphism in the project.
    vector<Event*> events;

    //this opens the file using the filename given by the user.
    //ifstream is used because this function only needs to read from the file.
    ifstream file(filename);

    //this checks if the file did not open correctly.
    //if the file cannot open then the program should not crash.
    if (!file.is_open()) {

        //this prints an error message so the user knows the file was not found or could not be opened.
        cout << "Error: Could not open file " << filename << endl;

        //returning the empty vector because no events were loaded.
        return events;
    }

    //this string holds one full line from the CSV file.
    //each line should represent one security event.
    string line;

    //this loop reads the file one line at a time.
    //getline stops when it reaches the end of the file.
    while (getline(file, line)) {

        //this checks for blank lines.
        //blank lines should be skipped because they do not have event data.
        if (line.empty()) {

            //continue moves to the next line in the file without running the rest of the loop.
            continue;
        }

        //this calls parseCSVLine to turn the CSV line into an event object.
        //the returned object can either be an IntrusionEvent or a MalwareEvent.
        Event* event = parseCSVLine(line);

        //this makes sure the event was created before adding it to the vector.
        //if parseCSVLine returns nullptr, that means something was wrong with the row.
        if (event != nullptr) {

            //this adds the new event pointer into the events vector.
            //now the event can be used later by the EventManager or display functions.
            events.push_back(event);
        }
    }

    //this closes the file when the program is done reading.
    //closing the file is good practice after using ifstream.
    file.close();

    //this returns all the events that were loaded from the file.
    return events;
}



//this function takes one line from the CSV file.
//then it splits the line and creates the right type of event.
//this function is private because it is only needed inside FileHandler.
Event* FileHandler::parseCSVLine(string line) {

    //this splits the line by commas.
    //each part goes into the fields vector.
    vector<string> fields = splitCSVLine(line);

    //each event row should have exactly 8 fields.
    //if it does not have 8 fields then the row is not valid.
    if (fields.size() != 8) {

        //this prints the line that caused the problem.
        //this helps with testing and debugging the CSV file.
        cout << "Invalid CSV line: " << line << endl;

        //nullptr means no event object was created.
        //the load function will skip this row.
        return nullptr;
    }

    //field 1 is the event type.
    //it tells the program if this is INTRUSION or MALWARE.
    string eventType = fields[0];

    //field 2 is the event id.
    //example: E001.
    string eventID = fields[1];

    //field 3 is the timestamp.
    //example format: 2026-04-13T08:35:12.
    string timestamp = fields[2];

    //field 4 is the ip address where the event came from.
    string ipAddress = fields[3];

    //field 5 is the severity.
    //examples can be LOW, MEDIUM, HIGH, or CRITICAL.
    string severity = fields[4];

    //field 6 is the CVE id.
    //this connects the event to a known vulnerability.
    string cveID = fields[5];



    //this part checks if the event type is INTRUSION.
    //intrusion events use attackType and attemptCount for the last two fields.
    if (eventType == "INTRUSION") {

        //field 7 is attack type for intrusion events.
        //examples could be brute_force, sql_injection, or buffer_overflow.
        string attackType = fields[6];

        //field 8 is attempt count for intrusion events.
        //stoi converts it from string to int because attemptCount is a number.
        int attemptCount = stoi(fields[7]);

        //this creates a new IntrusionEvent object.
        //new is used because the vector stores Event pointers.
        //the first six values go to the parent Event part, and the last two belong to IntrusionEvent.
        return new IntrusionEvent(eventID, timestamp, ipAddress, severity, cveID, attackType, attemptCount);
    }

    //this part checks if the event type is MALWARE.
    //malware events use malwareType and affectedFile for the last two fields.
    else if (eventType == "MALWARE") {

        //field 7 is malware type for malware events.
        //examples could be Ransomware, Trojan, or Spyware.
        string malwareType = fields[6];

        //field 8 is affected file for malware events.
        //this stays as a string because it is a file name.
        string affectedFile = fields[7];

        //this creates a new MalwareEvent object.
        //it still returns as Event* because MalwareEvent is a child of Event.
        //the program can store MalwareEvent and IntrusionEvent together this way.
        return new MalwareEvent(eventID, timestamp, ipAddress, severity, cveID, malwareType, affectedFile);
    }

    //this else runs if the type is not INTRUSION or MALWARE.
    else {

        //this prints the unknown event type so it is easier to debug.
        //this can happen if the CSV file has a typo in the first field.
        cout << "Unknown event type: " << eventType << endl;

        //no object is created because the type is invalid.
        return nullptr;
    }
}



//this function splits one CSV line into separate fields.
//the comma is used as the separator.
//this helper function keeps parseCSVLine cleaner and easier to read.
vector<string> FileHandler::splitCSVLine(string line) {

    //this vector will hold each field after it gets split.
    vector<string> fields;

    //stringstream lets me read from the string like it is a file.
    //this makes it easier to use getline with a comma separator.
    stringstream ss(line);

    //this string stores one field at a time.
    string field;

    //this loop keeps reading until it reaches a comma.
    //each value before the comma gets saved as one field.
    while (getline(ss, field, ',')) {

        //this adds the field into the vector.
        fields.push_back(field);
    }

    //this returns the list of fields back to parseCSVLine().
    return fields;
}
