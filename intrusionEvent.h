//added these 2 lines to stop file from showing up more then twice accidentally.
#ifndef INTRUSIONEVENT_H
#define INTRUSIONEVENT_H

#include "Event.h" //created by member 1 not avaliable yet.
#include <string>
using namespace std;
class IntrusionEvent : public Event {
  
  private: 
  // these 2 vars will only belong to intrusion event.
    string attackType; //the attack type like brute force
    int attemptCount; // how many times attacks were tried.
    
    
    
  public:
  // this constructor builds intrusionEvents from given data provided in Events.
  //const & are used for strings to avoid copying them.
  //used claude for help on weather i should add const & to the code and it said yes to avoid this file from modifying the original data. 
    IntrusionEvent(const string& id, const string& timestamp,
                    const string& ip, const string& severity,
                    const string& cve, const string& attackType,
                    int attemptCount);
                    
                    
    //display will print events on the screen.
    //asked claude about how to override a virtual function and it told me to use override.
    void display() const override;
    
    
    //get functions creates a copy of the private data.
    //and are given const to avoid making changes.
    string getAttackType() const;
    int getAttemptCount() const;
};

#endif

//made a typo where i wrote intrustionEvent throughout the .h file giving me errors.