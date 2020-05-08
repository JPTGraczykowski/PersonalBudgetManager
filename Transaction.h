#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <ctime>

using namespace std;

class Transaction
{
protected:
    int userId;
    tm date;
    string item;
    float amount;

public:
    Transaction();
    int getUserId();
    tm getDate();
    string getItem();
    float getAmount();
    void setUserId(int newUserId);
    void setDate(tm newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    bool operator < (const Transaction &x) const //definition of operator < which indicates which transaction is older
    {
        if(date.tm_year < x.date.tm_year)
            return true;
        else if(date.tm_mon < x.date.tm_mon)
            return true;
        else if(date.tm_mday < x.date.tm_mday)
            return true;
        else
            return false;
    };
};

#endif // TRANSACTION_H
