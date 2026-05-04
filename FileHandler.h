#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//including the event classes because this file will create event objects.
//event is the parent class, while intrusionevent and malwareevent are child classes.
#include "Event.h"
#include "IntrusionEvent.h"
#include "MalwareEvent.h"


//this class is used for reading the CSV file.
//my member 5 role is to take the raw data from the file and turn it into usable objects.
//this helps the rest of the program work with events instead of plain text.
class FileHandler {

public:

    //this function opens the CSV file and loads all events into a vector.
    //it returns Event pointers because both intrusion and malware are children of Event.
    //using Event* also lets the program store different event types in the same vector.
    static vector<Event*> loadEventsFromFile(string filename);

private:

    //this function reads one line from the CSV file.
    //then it checks the first field to decide what type of object should be created.
    //if the first field says INTRUSION, it creates an IntrusionEvent.
    //if the first field says MALWARE, it creates a MalwareEvent.
    static Event* parseCSVLine(string line);

    //this function splits one CSV line by commas.
    //it helps separate the 8 fields from the file so each value can be used correctly.
    static vector<string> splitCSVLine(string line);
};

#endif
