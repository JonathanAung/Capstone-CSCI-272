// ===========================================================================
// File       : Event.h
// Author     : Tun Tun (Jonathan) Aung
// Date       : 4/20/2026
// Course     : CSCI 272 - Object Oriented Programming
// ---------------------------------------------------------------------------
// MY ROLE ON THE TEAM: Event base class (Member 1).
// Per the Phase 1 proposal, this file must declare:
//     - 5 protected data members
//     - parameterized constructor
//     - virtual destructor
//     - virtual display()
//     - virtual toCSV()                 <-- serialization hook for FileHandler
//     - static validateSeverity(...)    <-- shared by everyone, no object needed
//     - 5 getters
//     - friend operator<<
// ===========================================================================
// Above description is generated using Ai for structure and clarity.
#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <iostream>
using namespace std;

class Event {
protected:
//We will work with protected for now as start of project phase, since we will not be pushing this for production.
//However it is worth to note that if we do decide to change this to private later, we will need to make adjustments such as providing gettings and setters.
    string eventID;
    string timestamp;
    string ipAddress;
    string severity;
    string cveID;

public:
    //Parameterized constructor in an agreed upon format.
    Event(const string& id, const string& ts,
          const string& ip, const string& sev,
          const string& cve);

    //Polymorphism, virtual. Essentially allowing each class to inherit its own version of display.
    // we will not be setting void display() = 0; because we want to be able to call display() on an Event*
    // and have it work, even if the Event is not actually an IntrusionEvent or MalwareEvent.
    // If we made it pure virtual, then Event would be an abstract class.
    virtual void display() const;
    virtual string toCSV() const;

    // ---- STATIC HELPER ------------------------------------------------------
    //static because we want to call it before any Event object exists.
    //It doesn't need to access any fields, just check the string.
    //This allows cleaner coding format. Without this, we would need to 
    //first create a dummy event just to check validateSeverity, then delete the dummmy
    //event and then create new event object. Its silly.
    static bool validateSeverity(const string& s);

    // ---- SETTER -------------------------------------------------------------
    void setEventID(const string& id) { eventID = id; }
    void setSeverity(const string& s) { severity = s; }
    void setCveID(const string& id) { cveID = id; }
    //The following setters are available but unncessary since real event would not and should not
    //alter timestamp or ipaddresses.

    //void setIPAddress(const string& ip) { ipAddress = ip; }
    //void setTimestamp(const string& t) { timestamp = t; }

    // ---- GETTERS ------------------------------------------------------------
    const string& getEventID()   const { return eventID; }
    const string& getTimestamp() const { return timestamp; }
    const string& getIpAddress() const { return ipAddress; }
    const string& getSeverity()  const { return severity; }
    const string& getCveID()     const { return cveID; }

    // ---- VIRTUAL DESTRUCTOR-----------------------
    //Rules of 3
    virtual ~Event() { }
};
// ---- OPERATOR OVERLOAD 
    //used Claude to identify the necessity for this operator overload to be a friend function,
    //since it needs access to the protected fields of Event.
    //friend ostream& operator<<(ostream& os, const Event& e); ////Commented this out since friend function is not part of the required rubric but tempate <typename T> is. 
template <typename T>
T& operator<<(T& os, const Event& e) {
    os << "[" << e.getEventID()
       << " | " << e.getSeverity()
       << " | " << e.getIpAddress()
       << " | " << e.getCveID() << "]"; 
    return os; 
}
#endif
