// Flie: EventManager.h
// Author: Miguel Llapa
// Date: 4/29/2026
// Course: CSCI 272 - Object Oriented Programming

#include "Event.h"
#include <vector>
using namespace std;


class EventManager {
    private: 
    vector<Event*> events; // The collection of event pointer inputs
    // Stores pointers to ensure that a destructor was there for EventManager
    // to delete pointers and memory leaks
    
    // ---- ADD EVENT FUNCTION -------
    public:
    void addEvent(Event* newEvent) {
        events.push_back(newEvent);
    }
    
    // ---- SEARCH FUNCTION --------
    // Ask Google to help understand the member functions step by step
    // Use void to display events and delete object pointers
    // Search by IP Address
    void searchByIp(string targetIP) {
        for (Event* e : events) {
            if (e -> getIP() == tragetIP) {
                e -> display();
            }
        }
    }
    
    // ----- SEARCH BY SERVERITY LEVELS & CVEID ------
    void searchBySeverity(int level) {
        for (Event* e : events) {
            if (e -> getSeverity() == level) {
                e -> display(); // Shows the matching events
            }
        }
    }
    
    void searchByCveID(string targetCveID) {
        for (Event* e : events) {
            if (e -> getCveID() == targetCveID) {
                e -> display(); // 
            }
        }
    }
    
    // ---- REMOVES EVENTS -------
    // deletes events from the input by index or ID
    // index used to access events elements of the total event
    void deleteEvent(int index){
        if (index >= 0 && index < events.size()) {
            delete event[index]; // Frees the memory if dynamically allocated
            events.erase(events.begin() + index);
        }
    }
    
    // ---- GENERATE REPORTS --------
    // Generates and displays reports for every pointer
    void generateReport() {
        cout << "--- System Event Report ---" << endl;
        cout << "Events: " << events.size() << endl;
        displayAllEvents();
        cout << "--------------------" << endl;
    }
}:
