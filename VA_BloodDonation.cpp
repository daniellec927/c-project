/*
 Com Sci 31 Project 6
 BloodDonation.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/10.
 */

#include <iostream>
#include "VA_BloodDonation.h"

using namespace std;

//constructor
BloodDonation::BloodDonation(int EmployeeID,int EmployeeAge,double EmployeeWeight){
    setID(EmployeeID);
    setAge(EmployeeAge);
    setWeight(EmployeeWeight);
}

//accessor
int BloodDonation::getID(){
    return mID;
}
int BloodDonation::getAge(){
    return mAge;
}
double BloodDonation::getWeight(){
    return mWeight;
}

//mutator
void BloodDonation::setID(int EmployeeID){
    if(EmployeeID>=100000&&EmployeeID<=999999)
        mID=EmployeeID;
    else
        mID=-1;
}
void BloodDonation::setAge(int EmployeeAge){
    if(EmployeeAge>=21&&EmployeeAge<=65)
        mAge=EmployeeAge;
    else
        mAge=-1;
}
void BloodDonation::setWeight(double EmployeeWeight){
    if(EmployeeWeight>=101.00&&EmployeeWeight<=280.00)
        mWeight=EmployeeWeight;
    else
        mWeight=-1;
}
