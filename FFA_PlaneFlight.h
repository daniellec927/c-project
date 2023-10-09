/*
 Com Sci 31 Project 5
 PlaneFlight.h
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/05.
 */

#ifndef PlaneFlight_h
#define PlaneFlight_h

#include <iostream>
#include <string>
using namespace std;

class PlaneFlight {
private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;
    
public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
    
    double getCost();
    void setCost(double cost);
    
    double getMileage();
    void setMileage(double mileage);
    
    string getName();
    void setName(string name);
    
    string getFromCity();
    void setFromCity(string from);
    
    string getToCity();
    void setToCity(string to);
};

#endif /* PlaneFlight_h */
