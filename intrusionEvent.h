// File       : IntrusionEven.h
// Author     : Tanzin Priyoh
// Date       : 4/23/2026
// Course     : CSCI 272 - Object Oriented Programming




//added these 2 lines to stop file from showing up more then twice accidentally.
#ifndef INTRUSIONEVENT_H
#define INTRUSIONEVENT_H

#include "Event.h" 
#include <string>
using namespace std;
class IntrusionEvent : public Event {
  
  private: 
  // these 2 vars will only belong to intrusion event.
    string attackType; //the attack type like brute force
    int attemptCount; // how many times attacks were tried.
    
    
    
  public:
  // Parameterized constructor, taking the 5 data points from Event and adding 2 more fields unique to this header.
  //const & are used for strings to avoid copying them.
  //used claude for help on weather i should add const & to the code and it said yes to avoid this file from modifying the original data. 
    IntrusionEvent(const string& eventid, const string& timestamp,
                    const string& ipAddress, const string& severity,
                    const string& cveID, const string& attackType,
                    int attemptCount);
                    
                    
    //display will print events on the screen.
    //asked claude about how to replace a virtual function and it told me to use const override.
    void display() const override;
    //this line converts an intrustion events data into a CSV format required by the file handler.
    string toCSV() const override;
    
    //getter functions creates a copy of the private data.
    //and are given const to avoid making changes.
    string getAttackType() const;
    int getAttemptCount() const;
};

#endif

//made a typo where i wrote intrustionEvent throughout the .h file giving me errors. 
//updated the param constructor after event.h was provided.
