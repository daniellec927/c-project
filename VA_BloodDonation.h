/*
 Com Sci 31 Project 6
 BloodDonation.h
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/10.
 */

#ifndef BloodDonation_h
#define BloodDonation_h

#include <iostream>

using namespace std;

class BloodDonation{
private:
    int mID;
    int mAge;
    double mWeight;
public:
    BloodDonation(int EmployeeID,int EmployeeAge,double EmployeeWeight);
    int getID();
    void setID(int EmployeeID);
    int getAge();
    void setAge(int EmployeeAge);
    double getWeight();
    void setWeight(double EmployeeWeight);
};

#endif /* BloodDonation_h */
