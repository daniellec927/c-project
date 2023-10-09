/*
 Com Sci 31 Project 5
 FrequentFlyerAccount.h
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/05.
 */

#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

#include <iostream>
#include <string>
#include "PlaneFlight.h"

using namespace std;

class FrequentFlyerAccount {
private:
    string mName;
    double mBalance;
    
public:
    FrequentFlyerAccount(string name);
    
    double getBalance();
    string getName();
    
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);
};

#endif /* FrequentFlyerAccount_h */
