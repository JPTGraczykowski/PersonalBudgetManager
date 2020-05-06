#include "IncomeFile.h"


Income IncomeFile::getIncomeDetails(CMarkup &file)
{
    Income income;

    file.IntoElem();
    file.FindElem("INCOME_ID");
    income.setIncomeId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("USER_ID");
    income.setUserId(AuxiliaryMethods::convertStringToInt(file.GetData()));
    file.FindElem("DATE");
    income.setDate(AuxiliaryMethods::getDateFromString(file.GetData() + "-"));
    file.FindElem("ITEM");
    income.setItem(file.GetData());
    file.FindElem("AMOUNT");
    income.setAmount(AuxiliaryMethods::convertStringToFloat(file.GetData()));
    file.OutOfElem();


    return income;
}


vector<Income> IncomeFile::getIncomesOfLoggedInUserFromFile(int loggedInUserId)
{
    Income income;
    vector<Income> incomes;
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());
    bool isFileEmpty = true;

    if(fileExists)
    {
        file.FindElem(); //go to INCOMES
        file.IntoElem(); //go to INCOMES
        while(file.FindElem("INCOME"))
        {
            isFileEmpty = false;
            income = getIncomeDetails(file);
            if(income.getUserId() == loggedInUserId)
                incomes.push_back(income);
        }
        if (!isFileEmpty)
            lastIncomeId = income.getIncomeId();
        else
            lastIncomeId = 0;
    }
    else
    {
        system("cls");
        cout<<"XML file error!";
        system("pause");
    }

    return incomes;
}


int IncomeFile::getLastIncomeId()
{
    return lastIncomeId;
}


void IncomeFile::addIncomeToFile(Income income)
{
    CMarkup file;

    bool fileExists = file.Load(getFileName().c_str());

    if(fileExists)
    {
        file.FindElem(); //go to INCOMES
        file.IntoElem(); //go to INCOMES

        file.AddElem("INCOME");
        file.IntoElem();

        file.AddElem("INCOME_ID", income.getIncomeId());
        file.AddElem("USER_ID", income.getUserId());
        file.AddElem("DATE", AuxiliaryMethods::convertDateToString(income.getDate()));
        file.AddElem("ITEM", income.getItem());
        file.AddElem("AMOUNT", income.getAmount());

        file.Save(getFileName().c_str());
    }
    else
    {
        system("cls");
        cout<<"XML file error!";
        system("pause");
    }

}
