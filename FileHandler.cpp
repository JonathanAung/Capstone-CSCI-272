// Author     : Ibrahim Jahangir
// Date       : 5/5/2026
// Course     : CSCI 272 - Object Oriented Programming
// Role       : Member 5 - File handling, CSV parsing, sorting, searching, and exception handling

#include "FileHandler.h"

//this function loads all events from the csv file.
//i added try/catch here so the program does not crash if the file is missing.
vector<Event*> FileHandler::loadEventsFromFile(string filename) {
    vector<Event*> events;

    try {
        ifstream file(filename);

        //if the file cannot open, i throw an error and handle it in catch.
        if (!file.is_open()) {
            throw runtime_error("File could not be opened: " + filename);
        }

        string line;

        while (getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            Event* event = parseCSVLine(line);

            if (event != nullptr) {
                events.push_back(event);
            }
        }

        //badbit means something serious happened while reading the file.
        if (file.bad()) {
            throw runtime_error("Badbit error: serious file reading problem.");
        }

        //failbit can happen at the end of the file, so i check eof too.
        if (file.fail() && !file.eof()) {
            throw runtime_error("Failbit error: file reading failed before the end.");
        }

        file.close();
    }

    catch (const exception& e) {
        cout << "FileHandler Error: " << e.what() << endl;
        cout << "Starting with an empty event list instead." << endl;
    }

    return events;
}

//this function saves all events back into the csv file.
//i added exception handling here so save errors are caught.
void FileHandler::saveEventsToFile(string filename, const vector<Event*>& events) {
    try {
        ofstream file(filename);

        if (!file.is_open()) {
            throw runtime_error("File could not be saved: " + filename);
        }

        for (Event* event : events) {
            if (event != nullptr) {
                file << event->toCSV() << endl;

                //checks for a serious writing error.
                if (file.bad()) {
                    throw runtime_error("Badbit error: serious file writing problem.");
                }

                //checks if writing failed.
                if (file.fail()) {
                    throw runtime_error("Failbit error: file writing failed.");
                }
            }
        }

        file.close();
        cout << "Events saved to " << filename << endl;
    }

    catch (const exception& e) {
        cout << "Save Error: " << e.what() << endl;
        cout << "The events were not saved correctly." << endl;
    }
}

//this is the main parsing function for my role.
//the first 6 fields are shared, but the last 2 change depending on event type.
Event* FileHandler::parseCSVLine(string line) {
    try {
        vector<string> fields = splitCSVLine(line);

        if (fields.size() != 8) {
            throw runtime_error("Invalid CSV line because it does not have 8 fields: " + line);
        }

        string eventType = fields[0];

        string eventID = fields[1];
        string timestamp = fields[2];
        string ipAddress = fields[3];
        string severity = fields[4];
        string cveID = fields[5];

        if (eventType == "INTRUSION") {
            string attackType = fields[6];

            //attemptCount is supposed to be a number, so stoi can throw an error here.
            int attemptCount = stoi(fields[7]);

            return new IntrusionEvent(eventID, timestamp, ipAddress, severity, cveID, attackType, attemptCount);
        }

        else if (eventType == "MALWARE") {
            string malwareType = fields[6];
            string affectedFile = fields[7];

            return new MalwareEvent(eventID, timestamp, ipAddress, severity, cveID, malwareType, affectedFile);
        }

        else {
            throw runtime_error("Unknown event type: " + eventType);
        }
    }

    catch (const invalid_argument& e) {
        cout << "Parse Error: attemptCount was not a valid number." << endl;
        return nullptr;
    }

    catch (const out_of_range& e) {
        cout << "Parse Error: attemptCount number was too large." << endl;
        return nullptr;
    }

    catch (const exception& e) {
        cout << "Parse Error: " << e.what() << endl;
        return nullptr;
    }
}

//this helper function splits the csv row by commas.
//i used stringstream because it makes the line easier to break apart.
vector<string> FileHandler::splitCSVLine(string line) {
    vector<string> fields;
    stringstream ss(line);
    string field;

    while (getline(ss, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}

//this sorts the events by event ID.
//binary search needs the list to be sorted first.
void FileHandler::bubbleSortByEventID(vector<Event*>& events) {
    int n = events.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (events[j]->getEventID() > events[j + 1]->getEventID()) {
                Event* temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
            }
        }
    }
}

//this searches by cutting the sorted list in half each time.
//if the middle ID is not the one we need, the code moves left or right.
Event* FileHandler::binarySearchByEventID(vector<Event*>& events, string targetID) {
    bubbleSortByEventID(events);

    int left = 0;
    int right = events.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        string middleID = events[middle]->getEventID();

        if (middleID == targetID) {
            return events[middle];
        }

        else if (middleID < targetID) {
            left = middle + 1;
        }

        else {
            right = middle - 1;
        }
    }

    return nullptr;
}
