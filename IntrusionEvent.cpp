// File       : IntrusionEven.cpp
// Author     : Tanzin Priyoh
// Date       : 4/28/2026
// Course     : CSCI 272 - Object Oriented Programming



#include "IntrusionEvent.h"
#include <sstream>


//this constructor runs when a new IntEvent is created.
// doing intE::intE tells cpp that the function belongs to the intE class.
// the second intE is the name of the constructor apart of lesson 8.
IntrusionEvent::IntrusionEvent(const string& eventID,
    const string& timestamp, const string& ipAddress,
    const string& severity, const string& cveID, 
    const string& attackType, int attemptCount)


//after the paramaterized list is called the Initializer list is used next.

:Event(eventID,  timestamp, ipAddress, severity, cveID)
//the body of the constr starts after the initilization list.
//which is the 5 shared data points from Event Parent.
{
    //now i add this to store the two new fields to the Event list.
    this->attackType = attackType;
    this->attemptCount = attemptCount;
}



//display for printing out the entire event to the screen.
//using the getters from Event because the non 'get' ones are private inside event.
// adding const at the end to make it a read only function.
void IntrusionEvent::display() const {
    cout << "[INTRUSION] " 
    << "ID: " << getEventID() << " | " <<
    "Time: "<< getTimestamp() << " | " <<
    "IP: " << getIpAddress() << " | " <<
    "Severity: "<< getSeverity() << " | " << 
    "CVE: " << getCveID() << " | " <<
    "Attack: "<< attackType << " | " << 
    "Attempts: " << attemptCount << endl;
}


//CSV converter using toCSV().
//the user will use this when they want to save all events.
// and it will use "INTRUSION" so the user knows what type this belongs to.
string IntrusionEvent::toCSV() const {
    ostringstream oss; 
    //using ostringstream to build the string.
    
oss << "INTRUSION," << getEventID() << ","
    << getTimestamp() << "," << getIpAddress() << ","
    << getSeverity() << "," << getCveID() << "," 
    << attackType << "," << attemptCount;
    return oss.str(); // .str prints the built string.
    
}

//making getters to return values of private fields.
//set to const since its read only and other parts of the program will use it to ask
//about what attack type it was? or how many attempts occured?

string IntrusionEvent::getAttackType() const {
    return attackType;
}

int IntrusionEvent::getAttemptCount() const {
    return attemptCount;
}

//will add sources and comments after feedback.
