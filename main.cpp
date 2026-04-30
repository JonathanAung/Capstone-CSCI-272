//main.cpp (shared file)
//Course : CSCI 272
// Based on the capstone project rules the main file cant contain anything with business longic.
//its just creating objects, calling menus, controller functions and handling high lvl flow.

// any section marked with ============== will be where you put your code based on your designated task.


#include "Event.h" // Member 1 (Tun Tun (Jonathan) Aung)
#include "IntrusionEvent.h" // Member 2 (Tanzin Priyoh)
//#include "MalwareEvent.h" // Member 3 (Bilal Ahmed)
//#include "EventManager.h" // Member 4 (Miguel Llapa)
//#include "FileHandler.h" //Member 5 (Ibrahim Janangir)
#include <iostream>
#include <vector>
using namespace std;

int main() {

cout << "Cybersecurity Event Logger" << endl;

// ====================================================================
//member 4 - Event Manager 
//The EventManager that owns vector<Event*> goes here.
// ====================================================================



// ====================================================================
// Member 5 - File Handler 
// Load existing events from events.csv into the manager at startup.
// ====================================================================



// ====================================================================
// Member 2 - Intrusion Event code snippit test.
//after EventMAnager and Filehander exist you can either 
// move this code into the manager or remove it with your own format.
IntrusionEvent demo("E002", "2026-04-13T08:35:12", "192.168.1.1", "HIGH", "CVE-2023-36884", "brute_force", 15);
Event* ePtr = &demo; // base class pointer/ polymorphism check.
ePtr->display();
cout << "CSV row: " << ePtr->toCSV() << endl;




// ====================================================================
// Member 3 - Malware Event 
// Create a MalwareEvent and call display() / toCSV on it. same as member 2
//in demo above.
// ====================================================================



// ====================================================================
// Member 4 - Event Manager 
// Create a looping menu with something like 
// manager.Menu();
// The menu must let users add/search/display/save events.
// ====================================================================



// ====================================================================
// Member 5 File Handler.
// Save the manager's events into events.csv before the user exits.
// Example: FileHandler::saveEvents("events.csv", manager)
// ====================================================================

return 0;
}
