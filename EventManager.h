// Flie: EventManager.h
// Author: Miguel Llapa
// Date: 4/29/2026
// Course: CSCI 272 - Object Oriented Programming

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include "Event.h"
#include <vector>
#include <string>
using namespace std;


class EventManager {
    protected: 
    vector<Event*> events;

    public:
    // Destructor to prevent memory leaks
    ~EventManager();

    // ---- The core functions like add and remove event ---
    // These are specifically for EventManager.cpp
    void addEvent(Event* newEvent);
    void deleteEvent(int index);
    
    // ---- Search Function ----
    void searchByIp(const string& targetIpAddress) const;
    void searchBySeverity(const string& level) const;
    void searchByCveID(const string& targetCveID) const;
    
    // --- Reports ---
    void displayAllEvents() const;
    void generateReport() const;
};

#endif
