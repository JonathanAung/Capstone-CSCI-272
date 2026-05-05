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

    public:
    // Destructor to prevent memory leaks
    ~EventManager();

    // ---- The core functions like add and remove event ---
    void addEvent(Event* newEvent);
    void deleteEvent(int index);
    
    // ---- Search Function ----
    void searchByIp(const string& targetIpAdress) const;
    void searchBySeverity(const string& level) const;
    void SearchByCveID(const string& targetCveID) const;
    
    // --- Reports ---
    void displayAllEvents() const;
    void generateReport() const;
};

#endif
