/*
 Com Sci 31 Project 5
 FrequentFlyerAccount.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/05.
 */

#include <iostream>
#include <string>
#include "FFA_PlaneFlight.h"
#include "FFA_FrequentFlyerAccount.h"

using namespace std;

//constructor
FrequentFlyerAccount::FrequentFlyerAccount(string name){
    mName=name;
    mBalance=0.0;
}

//accessor
double FrequentFlyerAccount::getBalance(){
    return mBalance;
}
string FrequentFlyerAccount::getName(){
    return mName;
}

//mutator
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight){
    if(mName==flight.getName()&&flight.getCost()>0&&flight.getFromCity()!=flight.getToCity()&&flight.getFromCity()!=""&&flight.getToCity()!=""){
        mBalance+=flight.getMileage();
        return true;
    }else
        return false;
}
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage){
    if(mBalance>=mileage&&mileage>0)
        return true;
    else
        return false;
}
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight){
    if(from==to||from==""||to==""||(!canEarnFreeFlight(mileage)))
        return false;
    if(mileage>=flight.getCost()){
        mBalance-=mileage;
        flight.setCost(0);
        flight.setName(mName);
        flight.setFromCity(from);
        flight.setToCity(to);
        flight.setMileage(mileage);
        return true;
    }else
        return false;
}
