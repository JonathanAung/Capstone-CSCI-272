// File       : FileHandler.h
// Author     : Ibrahim Jahangir
// Date       : 5/5/2026
// Course     : CSCI 272 - Object Oriented Programming
// Role       : Member 5 - File handling, CSV parsing, sorting, searching, and exception handling

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

#include "Event.h"
#include "IntrusionEvent.h"
#include "MalwareEvent.h"

//this class is for my Member 5 part.
//it handles loading events from the csv file, saving them,
//sorting them, and searching for them by event ID.
class FileHandler {

public:

    //loads events from a csv file and returns them as Event pointers.
    static vector<Event*> loadEventsFromFile(string filename);

    //saves the current events back into a csv file.
    static void saveEventsToFile(string filename, const vector<Event*>& events);

    //sorts the events by event ID before binary search.
    static void bubbleSortByEventID(vector<Event*>& events);

    //searches for an event ID using binary search.
    static Event* binarySearchByEventID(vector<Event*>& events, string targetID);

private:

    //turns one csv row into either an IntrusionEvent or MalwareEvent.
    static Event* parseCSVLine(string line);

    //splits one csv row into separate fields using commas.
    static vector<string> splitCSVLine(string line);
};

#endif
