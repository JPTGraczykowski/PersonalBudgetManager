#include "Income.h"

Income::Income()
{

}


int Income::getIncomeId()
{
    return incomeId;
}


void Income::setIncomeId(int newId)
{
    incomeId = newId;
}


void Income::showIncomeDetails()
{
    cout<<"INCOME_ID: "<<incomeId<<endl;
    cout<<"USER_ID: "<<userId<<endl;
    cout<<"DATE: "<<date.tm_year<<"-"<<date.tm_mon<<"-"<<date.tm_mday<<endl;
    cout<<"ITEM: "<<item<<endl;
    cout<<"AMOUNT: "<<amount<<endl;
    cout<<"_______________"<<endl;
}
