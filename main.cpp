//main.cpp (shared file)
//Course : CSCI 272
// Based on the capstone project rules the main file cant contain anything with business logic.
//its just creating objects, calling menus, controller functions and handling high lvl flow.

// any section marked with ============== will be where you put your code based on your designated task.


#include "Event.h" // Member 1 (Tun Tun (Jonathan) Aung)
#include "IntrusionEvent.h" // Member 2 (Tanzin Priyoh)
#include "MalwareEvent.h" // Member 3 (Bilal Ahmed)
#include "EventManager.h" // Member 4 (Miguel Llapa)
#include "FileHandler.h" //Member 5 (Ibrahim Janangir)
#include <iostream>
#include <vector>
#include <stdexcept> //for invalid arguement exception
using namespace std;

int main() {

cout << "Cybersecurity Event Log Analyzer" << endl;

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



//=======================Main Menu==========================
int option = 0;
while (option != 7) { //forgot to add while loop so the menu can LOOP
cout << "Main Menu:\n" << "1. Add Event\n" 
    << "2. View All Events\n" << "3. Search by IP Address\n"
    << "4. Search by Severity\n" << "5. Delete Event\n" 
    << "6. Generate Report\n" << "7. Save and Exit\n"
    << "Enter your option (1-7): ";
    
    
    
        //replacing cin.ignore() with a try/catch source: https://codepractice.in/programming-language/cpp-programming/cpp-input-validation
    try { //this runs the code and waits for errors to be created.
            cin >> option;
        if (cin.fail()) {
                cin.clear();  //resets error flag
                cin.ignore(1000, '\n'); //removes bad input
                throw invalid_argument("Must enter a number between 1-7."); //exception object/message holder
            }
            cin.ignore(1000, '\n'); //if input is good clears new line.
    }       
    
        catch (exception& e) { //if an error is made above it will be handled here instead of crashing the program.
                //this also grabs the exception object.
                cout << "Error: " << e.what() << "\n"; //.what() is a function of exception class(handles runtime errors) in <stdexcept>.
                // will return the error message passed to throw 
                option = 0; //resets the variable so its not holding whatever caused the error.
                continue; // skips the code in the current iteration and jumps
                //back to the top of the while loop.
                //source https://codepractice.in/programming-language/cpp-programming/cpp-break-continue
                //source https://faculty.cs.niu.edu/~mcmahon/CS241/Notes/exceptions.html    needed this to find out what .what() does.
            }

    //using a switch for choice selector. better then if else due to not having to write 
    //the condition for each number the user types.
    
    switch(option) {
        
        
        case 1: { 
            //===========================================
            //Members ... add event
            //Ask user if event type is intrusion or malware.
            // ask for all fields (ID,Time, IP, severity... follow the CVE order we agreed on.)
            // create the correct object like new intrusionEvent() or new malwareEvent()...
            // Last: pass it to the manager. ex: intrusionEvent* event = new intrusionEvent(...);
            // add it to event manager
            cout << "\n Option 1: Add Event \n";
            break; //tells the program to stop running the switch when the break is reached.
            }
            
            
        case 2: {
            //===========================================
            // EventManager::displayAllEvents()
            // Calls eventmanager method to print all stored events.
            // it must loop through vector<Event*> and calls display()
            // on each one and polymorphism will use the right one.
            //display funct for intrusionEvent and malwareEvent.
            cout << "\n Option 2: View All Events\n";
            break;
        }
        
        
        case 3: { 
            //===========================================
            //EventMAnager::searchByIP()
            //Ask user to enter IP address to search.
            // this calls eventMAnager.searchByIP(ip)
            // it must find and display all events with a matching IP address.
           cout << "\n Option 3: Search by IP\n";
           break; 
        }
        
        
        case 4: {
            //===========================================
            //EventManager::searchBySeverity()
            //Ask user to Enter Severity (LOW,MEDIUM,HIGH,CRITICAL)
            // calls eventManager.searchBySeverity(severity)
            // it must find and display all events that share that severity level.
            cout <<"\n Option 4: Search by Severity\n";
            break;
        }
        
        
        case 5: {
            //===========================================
            //EventManager::deleteEvent()
            //Ask user to enter event ID to delete like E002.
            // Calls eventManager.deleteEvennt(id)
            // this removes the matching event and frees memory.
            cout << "\n Option 5: Delete Event\n";
            break;
        }
        
        case 6: {
            //===========================================
            //EventMAnager::generateReport()
            //prints a summary through eventManager.generateReport()
            //it should show total events, counts by type, weather it was 
            //intrusion or malware. counts by severity, and list unique IPs.
            cout << "\nOption 6: Generate Report\n";
            break;
        }
        
        
        case 7: {
            //===========================================
            //FileHandler::saveEventsToFile()
            //Calls Filehandler method to write all events from eventManager
            //back to the CSV File ex : FileHandler::saveEventsToFile("events.csv", eventManager)
            //it must iterate over all events and write their toCSV output.
            cout << "\nOption 7: Saving and exiting\n";
            break;
        }
        
        default: cout <<"\nInvalid Option. Please enter a number between 1 and 7. \n";
        break;
    }
}
// ====================================================================
// Member 5 File Handler.
// Save the manager's events into events.csv before the user exits.
// Example: FileHandler::saveEvents("events.csv", manager)
// ====================================================================

cout <<"Thank you for using the Cybersecurity Event Log Analyzer!" << endl;

return 0;
}
