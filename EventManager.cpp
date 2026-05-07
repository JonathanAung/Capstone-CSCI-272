// Flie: EventManager.cpp
// Author: Miguel Llapa
// Date: 4/29/2026
// Course: CSCI 272 - Object Oriented Programming

// Moved the code from EventManager.h to EventManager.cpp
// Asked Google AI to help me understand step by step for EventManager.cpp
// and what's needed for cpp so I can understand what I'm doing for clarity on the structure
#include "EventManager.h"
#include <string>
#include <iostream>

// Destructor to clean up and prevent memory leaks
    EventManager::~EventManager() {
        for (Event* e : events) {
            delete e;
        }
        events.clear();
    }
    
    // ---- ADD EVENT FUNCTION -------
    // Adds event in this function
    void EventManager::addEvent(Event* newEvent) {
        if (newEvent != nullptr) { //added a nullptr for event so it can provide the pointer safely
            events.push_back(newEvent);
        }
    }

    // ---- SEARCH FUNCTION --------
    // Ask Google to help understand the member functions step by step and structure
    // Use void to display events and delete object pointers
    // Search by IP Address
    void EventManager::searchByIp(const string& targetIpAddress) const {
        bool found = false; // enables when searching Ip Address is false
        for (Event* e : events) {
            if (e->getIpAddress() == targetIpAddress) {
                e->display();
                found = true; // enables when searching Ip Address is true and displays it
            }
        }
        if (!found) cout << "No events found for the address: " << targetIpAddress << endl;
    }
    
    // ----- SEARCH BY SERVERITY LEVELS & CVEID ------
    void EventManager::searchBySeverity(const string& level) const {
        for (Event* e : events) {
            if (e->getSeverity() == level) {
                e->display(); // Shows the matching events
            }
        }
    }
    
    void EventManager::searchByCveID(const string& targetCveID) const {
        for (Event* e : events) {
            if (e->getCveID() == targetCveID) {
                e->display();
            }
        }
    }

    // ---- REMOVES EVENTS -------
    // deletes events from the input by index or ID
    // index used to access events elements of the total event
    void EventManager::deleteEvent(int index){
        if (index >= 0 && index < (int)events.size()) {
            delete events[index]; // Frees the memory if dynamically allocated
            events.erase(events.begin() + index); // removes from vector
        }
    }

    // ------ HELPER FOR THE REPORT ------
    void EventManager::displayAllEvents() const {
        for (const Event* e : events) {
            e->display();
        }
    }

    // ---- GENERATE REPORTS --------
    // Generates and displays reports for every pointer
    void EventManager::generateReport() const {
        cout << "--- System Event Report ---" << endl;
        cout << "Events: " << events.size() << endl;
        displayAllEvents();
        cout << "--------------------" << endl;
    }
