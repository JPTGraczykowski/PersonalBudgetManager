#include "IncomeManager.h"


void IncomeManager::addIncome()
{
    Income income;

    system("cls");
    cout<<" $$$ ADD NEW INCOME $$$ "<<endl<<endl;

    income = provideIncomeDetails();
    incomes.push_back(income);

    incomeFile.addIncomeToFile(income);
    incomeFile.setLastIncomeId(income.getIncomeId());

    system("pause");
}


Income IncomeManager::provideIncomeDetails()
{
    Income income;

    income.setIncomeId(incomeFile.getLastIncomeId() + 1);
    income.setUserId(getLoggedInUserId());

    income.setDate(setDateOfTransaction());

    cout<<endl<<"Set an item of the income: ";
    income.setItem(AuxiliaryMethods::getLine());

    cout<<endl<<"Set amount of the income: ";
    income.setAmount(AuxiliaryMethods::getCurrencyFloat());

    return income;
}


void IncomeManager::showAllIncomes()
{
    system("cls");
    for(int i=0; i<incomes.size(); i++)
    {
        cout<<"INCOME_ID: "<<incomes[i].getIncomeId()<<endl;
        cout<<"USER_ID: "<<incomes[i].getUserId()<<endl;
        tm date = incomes[i].getDate();
        cout<<"DATE: "<<date.tm_year<<"-"<<date.tm_mon<<"-"<<date.tm_mday<<endl;
        cout<<"ITEM: "<<incomes[i].getItem()<<endl;
        cout<<"AMOUNT: "<<incomes[i].getAmount()<<endl;
        cout<<"_______________"<<endl;
    }
    system("pause");
}




