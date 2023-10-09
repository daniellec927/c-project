/*
 Com Sci 31 Project 5
 PlaneFlight.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/05.
 */

#include <iostream>
#include <string>
#include "FFA_PlaneFlight.h"

using namespace std;

//constructor
 PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage){
     setName(passengerName);
     setFromCity(fromCity);
     setToCity(toCity);
     setCost(cost);
     setMileage(mileage);
 }

 //accessor
 double PlaneFlight::getCost(){
     return mCost;
 }
 double PlaneFlight::getMileage(){
     return mMileage;
 }
 string PlaneFlight::getName(){
     return mName;
 }
 string PlaneFlight::getFromCity(){
     return mFromCity;
 }
 string PlaneFlight::getToCity(){
     return mToCity;
 }

 //mutator
 void PlaneFlight::setCost(double cost){
     if (cost>=0)
         mCost=cost;
     else
         mCost=-1;
 }
 void PlaneFlight::setMileage(double mileage){
     if (mileage>0)
         mMileage=mileage;
     else
         mMileage=-1;
 }
 void PlaneFlight::setName(string name){
     if(name!="")
         mName=name;
 }
 void PlaneFlight::setFromCity(string from){
     if(from!=""&&from!=mToCity)
         mFromCity=from;
 }
 void PlaneFlight::setToCity(string to){
     if(to!=""&&to!=mFromCity)
         mToCity=to;
 }

