/*
 Com Sci 31 Project 6
 VacationAccount.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/10.
 */

#include <iostream>

#include "VA_BloodDonation.h"
#include "VA_VacationAccount.h"

using namespace std;

//constructor
VacationAccount::VacationAccount(int EmployeeID){
    if(EmployeeID>=100000&&EmployeeID<=999999)
        mID=EmployeeID;
    else
        mID=-1;
    mBalance=0.0;
}

//accessor
double VacationAccount::getBalance(){
    return mBalance;
}
int VacationAccount::getID(){
    return mID;
}

//mutator
bool VacationAccount::addVacationToAccount(BloodDonation donation){
    if((donation.getID()!=-1)&&(mID==donation.getID())&&(donation.getAge()!=-1)&&(donation.getWeight()!=-1)){
        mBalance+=4.0;
        return true;
    } else
        return false;
}
