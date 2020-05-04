#include "IncomeManager.h"


void IncomeManager::addIncome()
{
    Income income;

    system("cls");
    cout<<" $$$ ADD NEW INCOME $$$ "<<endl<<endl;

    income = provideIncomeDetails();
    incomes.push_back(income);

    system("pause");
}


Income IncomeManager::provideIncomeDetails()
{
    Income income;

    income.setIncomeId(1);
    income.setUserId(getLoggedInUserId());

    income.setDate(setDateOfTransaction());

    cout<<endl<<"Set an item of the income: ";
    income.setItem(AuxiliaryMethods::getLine());

    cout<<endl<<"Set amount of the income: ";
    income.setAmount(AuxiliaryMethods::getCurrnecyFloat());
    cout<<endl<<income.getAmount();


    return income;
}




