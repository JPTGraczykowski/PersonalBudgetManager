#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <ctime>

using namespace std;

class Transaction
{
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
    void setDate();
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif // TRANSACTION_H
