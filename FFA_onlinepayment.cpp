#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class payment
{
public:
    payment(string payer, string payee, double amount);
    
   
    string getPayer( );
    void   setPayer( string pr );
    
    string getPayee( );
    void   setPayee(string pe);
    
    double getAmount( );
    void   setAmount( double am );
    
private:
    string mPayer, mPayee;
    double mAmount;
};


int main()
{
    payment p1("Bruce", "John", 79.00);
    payment p2( "Mary", "Kay", 699.00);
    payment p3( "George", "George", 1000.00);
    
    assert(p1.getPayer() == "Bruce" );
    assert(p2.getPayee() == "Kay" );
    assert(std::to_string(p1.getAmount() ) == "79.000000" );
    assert(p3.getPayee() == "" );
       
    
    return( 0 );
}


payment::payment(string payer, string payee, double amount)
{
    setPayer(payer);
    setPayee(payee);
    setAmount(amount);
}

double payment::getAmount( )
{
    return( mAmount );
}

void payment::setAmount(double amount)
{
    if (amount >= 0)
        mAmount = amount;
    else
        mAmount = -1;
}

string payment::getPayer( )
{
    return(mPayer);
}

void payment::setPayer(string payer)
{
     if (payer != "" && payer != mPayee)
        mPayer = payer;
}

string payment::getPayee( )
{
    return(mPayee);
}

void payment::setPayee(string payee)
{
    if (payee != "" && payee != mPayer)
        mPayee = payee;
}

