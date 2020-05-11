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


void IncomeManager::showIncomesFromTheMonth(int month)
{
    tm dateOfIncome;
    vector<Income> incomesFromTheMonth;
    sumOfTheTransactions = 0;

    for(unsigned int i = 0; i<incomes.size(); i++)
    {
        dateOfIncome = incomes[i].getDate();
        if(dateOfIncome.tm_mon == month)
        {
            incomesFromTheMonth.push_back(incomes[i]);
            sumOfTheTransactions += incomes[i].getAmount();
        }
    }

    sort(incomesFromTheMonth.begin(), incomesFromTheMonth.end());

    for(unsigned int i = 0; i < incomesFromTheMonth.size(); i++)
    {
        incomesFromTheMonth[i].showIncomeDetails();
    }
}


void IncomeManager::showIncomesFromOtherPeriodOfTime(tm startDate, tm stopDate)
{
    tm dateOfIncome;
    vector<Income> incomesFromTheOtherPeriodOfTime;
    sumOfTheTransactions = 0;

    for (unsigned int i = 0; i<incomes.size(); i++)
    {
        dateOfIncome = incomes[i].getDate();
        if(!(DateOperations::isDateAEarlierThanDateB(dateOfIncome, startDate))
           && !(DateOperations::isDateAEarlierThanDateB(stopDate, dateOfIncome)))
           {
               incomesFromTheOtherPeriodOfTime.push_back(incomes[i]);
               sumOfTheTransactions += incomes[i].getAmount();
           }
    }

    sort(incomesFromTheOtherPeriodOfTime.begin(), incomesFromTheOtherPeriodOfTime.end());

    for(unsigned int i = 0; i<incomesFromTheOtherPeriodOfTime.size(); i++)
    {
        incomesFromTheOtherPeriodOfTime[i].showIncomeDetails();
    }
}


