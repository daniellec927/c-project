/*
 Com Sci 31 Project 2
 payment.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/01/24.
 */

#include <iostream>
#include <string>
using namespace std;
int main() {
    string state, month;
    double purchase_amount, total_amount;
    int day, year;
    bool invalid_state=0; //to find out if 'state' value is valid or not
    double stateTaxRate, avgLocalTaxRate, Levy;

    cout<<"State Name: ";
    getline(cin,state);
    cout<<"Purchase amount: ";
    cin>>purchase_amount;
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Provide the month: ";
    getline(cin, month);
    cout<<"Provide the day: ";
    cin>>day;
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Provide the year: ";
    cin>>year;
    cin.clear();
    cin.ignore(10000,'\n');
    
    stateTaxRate=0.00;
    avgLocalTaxRate=0.00;
    Levy=0.00;
    
    if (state=="Alabama"){
        if (!((month=="July")&&(day>=15&&day<=17))){ //Alabama Free Tax Dates
            stateTaxRate=4.00;
            avgLocalTaxRate=5.14;
            Levy=0.00;
        }
    } else if (state=="Alaska"){
        stateTaxRate=0.00;
        avgLocalTaxRate=1.43;
        Levy=0.00;
    } else if (state=="Arizona"){
        stateTaxRate=5.60;
        avgLocalTaxRate=2.77;
        Levy=0.00;
    } else if (state=="Arkansas"){
        if (!((month=="August")&&(day>=6&&day<=7))){  //Arkansas Free Tax Dates
            stateTaxRate=6.50;
            avgLocalTaxRate=2.93;
            Levy=0.00;
        }
    } else if (state=="California"){
        stateTaxRate=7.25;
        avgLocalTaxRate=1.31;
        Levy=1.00;
    } else if (state=="Colorado"){
        stateTaxRate=2.90;
        avgLocalTaxRate=4.73;
        Levy=0.00;
    } else if (state=="Connecticut"){
        if (!((month=="August")&&(day>=21&&day<=27))){ //Connecticut Free Tax Dates
            stateTaxRate=6.35;
            avgLocalTaxRate=0.00;
            Levy=0.00;
        }
    } else if (state=="Delaware") {
        stateTaxRate=0.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Florida"){
        stateTaxRate=6.00;
        avgLocalTaxRate=1.05;
        Levy=0.00;
    } else if (state=="Georgia"){
        stateTaxRate=4.00;
        avgLocalTaxRate=3.29;
        Levy=0.00;
    } else if (state=="Hawaii"){
        stateTaxRate=4.00;
        avgLocalTaxRate=0.41;
        Levy=0.00;
    } else if (state=="Idaho"){
        stateTaxRate=6.00;
        avgLocalTaxRate=0.03;
        Levy=0.00;
    } else if (state=="Illinois"){
        stateTaxRate=6.25;
        avgLocalTaxRate=2.49;
        Levy=0.00;
    } else if (state=="Indiana"){
        stateTaxRate=7.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Iowa"){
        if (!((month=="August")&&(day>=5&&day<=6))){ //Iowa Free Tax Dates
            stateTaxRate=6.00;
            avgLocalTaxRate=0.82;
            Levy=0.00;
        }
    } else if (state=="Kansas"){
        stateTaxRate=6.50;
        avgLocalTaxRate=2.17;
        Levy=0.00;
    } else if (state=="Kentucky"){
        stateTaxRate=6.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Louisiana"){
        stateTaxRate=4.45;
        avgLocalTaxRate=5.00;
        Levy=0.00;
    } else if (state=="Maine"){
        stateTaxRate=5.50;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Maryland"){
        if (!((month=="August")&&(day>=14&&day<=20))){ //Maryland Free Tax Dates
            stateTaxRate=6.00;
            avgLocalTaxRate=0.00;
            Levy=0.00;
        }
    } else if (state=="Massachusetts"){
        if (!((month=="August")&&(day>=14&&day<=15))){ //Massachusetts Free Tax Dates
            stateTaxRate=6.25;
            avgLocalTaxRate=0.00;
            Levy=0.00;
        }
    } else if (state=="Michigan"){
        stateTaxRate=6.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Minnesota"){
        stateTaxRate=6.88;
        avgLocalTaxRate=0.55;
        Levy=0.00;
    } else if (state=="Mississippi"){
        if (!((month=="July")&&(day>=29&&day<=30))){ //Mississippi Free Tax Dates
            stateTaxRate=7.00;
            avgLocalTaxRate=0.07;
            Levy=0.00;
        }
    } else if (state=="Missouri"){
        if (!((month=="April")&&(day>=19&&day<=25))){ //Missouri Free Tax Dates
            stateTaxRate=4.23;
            avgLocalTaxRate=3.90;
            Levy=0.00;
        }
    } else if (state=="Montana"){
        stateTaxRate=0.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Nebraska"){
        stateTaxRate=5.50;
        avgLocalTaxRate=1.35;
        Levy=0.00;
    } else if  (state=="Nevada"){
        if (!((month=="August")&&(day>=5&&day<=7))){ //Nevada Free Tax Dates
            stateTaxRate=6.85;
            avgLocalTaxRate=1.29;
            Levy=0.00;
        }
    } else if (state=="New Hampshire"){
        stateTaxRate=0.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="New Jersey"){
        stateTaxRate=6.63;
        avgLocalTaxRate=-0.03;
        Levy=0.00;
    } else if (state=="New Mexico"){
        stateTaxRate=5.13;
        avgLocalTaxRate=2.69;
        Levy=0.00;
    } else if (state=="New York"){
        stateTaxRate=4.00;
        avgLocalTaxRate=4.49;
        Levy=0.00;
    } else if (state=="North Carolina"){
        stateTaxRate=4.75;
        avgLocalTaxRate=2.22;
        Levy=0.00;
    } else if (state=="North Dakota"){
        stateTaxRate=5.00;
        avgLocalTaxRate=1.85;
        Levy=0.00;
    } else if (state=="Ohio"){
        if (!((month=="August")&&(day>=5&&day<=7))){ //Ohio Free Tax Dates
            stateTaxRate=5.75;
            avgLocalTaxRate=1.42;
            Levy=0.00;
        }
    } else if (state=="Oklahoma"){
        if (!((month=="August")&&(day>=5&&day<=7))){ //Oklahoma Free Tax Dates
            stateTaxRate=4.50;
            avgLocalTaxRate=4.42;
            Levy=0.00;
        }
    } else if (state=="Oregon"){
        stateTaxRate=0.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="Pennsylvania"){
        stateTaxRate=6.00;
        avgLocalTaxRate=0.34;
        Levy=0.00;
    } else if (state=="Rhode Island"){
        stateTaxRate=7.00;
        avgLocalTaxRate=0.00;
        Levy=0.00;
    } else if (state=="South Carolina"){
        if (!((month=="August")&&(day>=5&&day<=7))){ //South Carolina Free Tax Dates
            stateTaxRate=6.00;
            avgLocalTaxRate=1.43;
            Levy=0.00;
        }
    } else if (state=="South Dakota"){
        stateTaxRate=4.50;
        avgLocalTaxRate=1.90;
        Levy=0.00;
    } else if (state=="Tennessee"){
        if (!((month=="July")&&(day>=29&&day<=31))){ //Tennessee Free Tax Dates
            stateTaxRate=7.00;
            avgLocalTaxRate=2.47;
            Levy=0.00;
        }
    } else if (state=="Texas"){
        if (!((month=="August")&&(day>=5&&day<=7))){ //Texas Free Tax Dates
            stateTaxRate=6.25;
            avgLocalTaxRate=1.94;
            Levy=0.00;
        }
    } else if (state=="Utah"){
        stateTaxRate=5.95;
        avgLocalTaxRate=0.99;
        Levy=1.25;
    } else if (state=="Vermont"){
        stateTaxRate=6.00;
        avgLocalTaxRate=0.18;
        Levy=0.00;
    } else if (state=="Virginia"){
        stateTaxRate=5.30;
        avgLocalTaxRate=0.35;
        Levy=1.00;
    } else if (state=="Washington"){
        stateTaxRate=6.50;
        avgLocalTaxRate=2.67;
        Levy=0.00;
    } else if (state=="West Virginia"){
        if (!((month=="August")&&(day>=5&&day<=7))){ // West Virginia Free Tax Dates
            stateTaxRate=6.00;
            avgLocalTaxRate=0.39;
            Levy=0.00;
        }
    } else if (state=="Wisconsin"){
        stateTaxRate=5.00;
        avgLocalTaxRate=0.44;
        Levy=0.00;
    } else if (state=="Wyoming"){
        stateTaxRate=4.00;
        avgLocalTaxRate=1.36;
        Levy=0.00;
    } else{
        invalid_state=1; //if 'state' value doesn't match all 50 states, change the boolean value from false(0) to true(1)
    }
    
    total_amount=purchase_amount*(1+0.01*(stateTaxRate+avgLocalTaxRate+Levy));

    if (invalid_state){
        cout<<"Invalid state!"<<endl;
    } else if (purchase_amount<=0){
        cout<<"Invalid amount!"<<endl;
    } else if ((month!="January")&&(month!="February")&&(month!="March")&&(month!="April")&&(month!="May")&&(month!="June")&&(month!="July")&&(month!="August")&&(month!="September")&&(month!="October")&&(month!="November")&&(month!="December")){
        cout<<"Invalid month!"<<endl;
    } else if (day<1||day>31){
        cout<<"Invalid day!"<<endl;
    } else if (year<1||year>2025){
        cout<<"Invalid year!"<<endl;
    } else {
        cout<<"Please pay a total of $";
        cout.setf(ios::fixed);
        cout.precision(2); //up to two decimal poins
        cout<<total_amount<<endl;
    }
    return 0;
}
