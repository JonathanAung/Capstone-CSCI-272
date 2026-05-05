#include "FileHandler.h"

//this function loads all the events from the csv file.
//each line gets sent to parseCSVLine so it can become an actual event object.
vector<Event*> FileHandler::loadEventsFromFile(string filename) {
    vector<Event*> events;

    //i used ifstream because this part only needs to read from the file.
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return events;
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

    file.close();
    return events;
}

//this function saves all the events back into csv format.
//each child class already has its own toCSV(), so this keeps the save part simple.
void FileHandler::saveEventsToFile(string filename, const vector<Event*>& events) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not save file " << filename << endl;
        return;
    }

    for (Event* event : events) {
        if (event != nullptr) {
            file << event->toCSV() << endl;
        }
    }

    file.close();
    cout << "Events saved to " << filename << endl;
}

//this is the main parsing function for my part.
//the first 6 fields are shared, but the last 2 change based on the event type.
Event* FileHandler::parseCSVLine(string line) {
    vector<string> fields = splitCSVLine(line);

    if (fields.size() != 8) {
        cout << "Invalid CSV line: " << line << endl;
        return nullptr;
    }

    string eventType = fields[0];

    //these fields are shared by both IntrusionEvent and MalwareEvent.
    string eventID = fields[1];
    string timestamp = fields[2];
    string ipAddress = fields[3];
    string severity = fields[4];
    string cveID = fields[5];

    if (eventType == "INTRUSION") {
        string attackType = fields[6];

        //attemptCount comes from the csv as text, so I convert it into an int.
        int attemptCount = stoi(fields[7]);

        return new IntrusionEvent(eventID, timestamp, ipAddress, severity, cveID, attackType, attemptCount);
    }

    else if (eventType == "MALWARE") {
        string malwareType = fields[6];

        //affectedFile stays as a string because it is a file name.
        string affectedFile = fields[7];

        return new MalwareEvent(eventID, timestamp, ipAddress, severity, cveID, malwareType, affectedFile);
    }

    cout << "Unknown event type: " << eventType << endl;
    return nullptr;
}

//this helper function separates the csv row by commas.
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
//binary search needs the list sorted first, so this function helps prepare it.
void FileHandler::bubbleSortByEventID(vector<Event*>& events) {
    int n = events.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            //if the current event ID is bigger than the next one, I swap them.
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

            //target is bigger, so the left side can be ignored.
            left = middle + 1;
        }

        else {

            //target is smaller, so the right side can be ignored.
            right = middle - 1;
        }
    }

    return nullptr;
}
