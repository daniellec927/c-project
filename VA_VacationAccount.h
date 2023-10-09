/*
 Com Sci 31 Project 6
 VacationAccount.h
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/10.
 */

#ifndef VacationAccount_h
#define VacationAccount_h

#include <iostream>
#include "VA_BloodDonation.h"

using namespace std;

class VacationAccount{
private:
    int mID;
    double mBalance;
public:
    VacationAccount(int EmployeeID);
    double getBalance();
    int getID();
    bool addVacationToAccount(BloodDonation donation);
};

#endif /* VacationAccount_h */
