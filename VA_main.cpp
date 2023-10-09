/*
 Com Sci 31 Project 6
 main.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/03/10.
 */

#include <iostream>
#include <string>
#include <cassert>

#include "VA_BloodDonation.h"
#include "VA_VacationAccount.h"

using namespace std;

int main() {
    // sample test code
    BloodDonation doner1( 752401, 45, 99.56);
    BloodDonation doner2( 889543, 55, 109.50);
    BloodDonation doner3( 89643244, 65, 187.55);
    BloodDonation doner4( 855565, 17, 127.00);
    VacationAccount account(889543);
    assert( doner1.getID( ) == 752401);
    assert(doner2.getAge( ) ==55);
    assert(doner3.getWeight( ) == 187.550000 );
    // account balance starts at zero...
    assert( account.getBalance( ) == 0.000000 );
    assert( account.getID( ) ==  889543);
    // Vacation adds to vacation balance
    assert( account.addVacationToAccount( doner2 ) == true );
    assert( account.addVacationToAccount( doner1 ) == false );
    assert( account.getBalance( ) == 4.000000 );
    //my test case
    VacationAccount account1(10);
    assert(account1.getID()==-1);
    assert(account1.getBalance()==0);
    BloodDonation doner5(10000,45,99);
    assert(doner5.getID()==-1);
    VacationAccount account2(100000);
    BloodDonation doner6(100000,40,110);
    assert(account2.getBalance()==0);
    assert(account2.addVacationToAccount(doner6)==true);
    assert(account2.getBalance()==4);
    assert(account2.addVacationToAccount(doner6)==true);
    assert(account2.getBalance()==8);
    doner6.setID(1000);
    assert(doner6.getID()==-1);
    assert(account2.addVacationToAccount(doner6)==false);
    assert(account2.getBalance()==8);
    VacationAccount account3(10000);
    assert(account3.getBalance()==0);
    
    cout<<"All test cases passed!"<<endl;
    return 0;
}
