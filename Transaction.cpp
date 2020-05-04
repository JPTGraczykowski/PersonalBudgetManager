#include "Transaction.h"

Transaction::Transaction()
{

}


int Transaction::getUserId()
{
    return userId;
}


tm Transaction::getDate()
{
    return date;
}


string Transaction::getItem()
{
    return item;
}


float Transaction::getAmount()
{
    return amount;
}


void Transaction::setUserId(int newUserId)
{
    userId = newUserId;
}


void Transaction::setDate(tm newDate)
{
    date = newDate;
}


void Transaction::setItem(string newItem)
{
    item = newItem;
}


void Transaction::setAmount(float newAmount)
{
    amount = newAmount;
}
