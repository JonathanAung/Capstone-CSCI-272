// ===========================================================================
// File       : Event.cpp
// Author     : Tun Tun (Jonathan) Aung
// Description: Implementation of the Event base class.
// ---------------------------------------------------------------------------
//What this file contains:
//   1) Constructor               - sets the 5 shared fields
//   2) display()                 - prints the 5 shared fields with labels
//   3) toCSV()                   - returns the 5 shared fields joined by commas
//   4) validateSeverity()        - static helper used by main.cpp's prompts
//   5) operator<<                - lets `cout << someEvent;` just work
// ===========================================================================
//Above section is generated using AI for strucutre and guidance
#include "Event.h"
#include <iostream>
#include <sstream>     // ostringstream used inside toCSV()
#include <cctype>      // toupper used inside validateSeverity()
using namespace std;


//Initialize Constructor
Event::Event(const string& id, const string& ts, const string& ip,
             const string& sev, const string& cve) {
    eventID   = id;
    timestamp  = ts;
    ipAddress = ip;
    severity  = sev;
    cveID    = cve;
}

void Event::display() const {
    cout << " Event ID    : " << eventID   << "\n";
    cout << " Timestamp   : " << timestamp << "\n";
    cout << " IP Address  : " << ipAddress << "\n";
    cout << " Severity    : " << severity  << "\n";
    cout << " CVE ID      : " << cveID     << "\n";
}


//Included Ostringstream for formatized output, also covering class material. once again, const because we do not want
//data tampering
string Event::toCSV() const {
    ostringstream oss;
    oss << eventID   << ','
        << timestamp << ','
        << ipAddress << ','
        << severity  << ','
        << cveID;
    return oss.str();
}

//Because we made it static in our Event.h file, we can now validateSeverity before we even construct
//an event, otherwise, a dummy is required.
//Also to note, because s is const, immuatable, therefore we need to make a copy of s in order to switch to
//all uppercase for validation.
bool Event::validateSeverity(const string& s) {
    // Make a mutable copy so we can upper-case it.
    string up = s;
        for (size_t i = 0; i < up.length(); ++i) {
        up[i] = static_cast<char>(toupper(static_cast<unsigned char>(up[i])));
    }
    return up == "LOW"  || up == "MEDIUM"
        || up == "HIGH" || up == "CRITICAL";
}
//our friend function is used here, no need for Event::
//this allows overload the operator<<
// ostream& operator<<(ostream& os, const Event& e) {
//     // Left for test case. Short, single-line summary format for when we just want to print an Event without all the labels, might leave it for actual use.
//     os << "[" << e.eventID
//        << " | " << e.severity
//        << " | " << e.ipAddress
//        << " | " << e.cveID << "]";
//     return os;
// }
