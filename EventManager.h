// Flie: EventManager.h
// Author: Miguel Llapa
// Date: 4/29/2026
// Course: CSCI 272 - Object Oriented Programming

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
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
    // Destructor to prevent memory leaks
    ~EventManager() {
        for (Event* e : events) {
            delete e;
        }
        events.clear();
    }
    
    // ---- ADD EVENT FUNCTION -------
    void addEvent(Event* newEvent) {
        events.push_back(newEvent);
    }

    // ---- SEARCH FUNCTION --------
    // Ask Google to help understand the member functions step by step and structure
    // Use void to display events and delete object pointers
    // Search by IP Address
    void searchByIp(const string targetIpAddress) const {
        for (Event* e : events) {
            if (e->getIpAddress() == targetIpAddress) {
                e->display();
            }
        }
    }
    
    // ----- SEARCH BY SERVERITY LEVELS & CVEID ------
    void searchBySeverity(const string& level) const {
        for (Event* e : events) {
            if (e->getSeverity() == level) {
                e->display(); // Shows the matching events
            }
        }
    }
    
    void searchByCveID(const string& targetCveID) const {
        for (Event* e : events) {
            if (e->getCveID() == targetCveID) {
                e->display();
            }
        }
    }

    // ---- REMOVES EVENTS -------
    // deletes events from the input by index or ID
    // index used to access events elements of the total event
    void deleteEvent(int index){
        if (index >= 0 && index < events.size()) {
            delete events[index]; // Frees the memory if dynamically allocated
            events.erase(events.begin() + index); // removes from vector
        }
    }

    // ------ HELPER FOR THE REPORT ------
    void displayAllEvents() const {
        for (const Event* e : events) {
            e->display();
        }
    }

    // ---- GENERATE REPORTS --------
    // Generates and displays reports for every pointer
    void generateReport() const {
        cout << "--- System Event Report ---" << endl;
        cout << "Events: " << events.size() << endl;
        displayAllEvents();
        cout << "--------------------" << endl;
    }
};

#endif
