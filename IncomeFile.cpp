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

    if(fileExists)
    {
        file.FindElem(); //go to INCOMES
        file.IntoElem(); //go to INCOMES
        while(file.FindElem("INCOME"))
        {
            file.IntoElem();
            file.FindElem("USER_ID");
            //if(AuxiliaryMethods::convertStringToInt(file.GetData()) == loggedInUserId)
            //{
                income = getIncomeDetails(file);
                incomes.push_back(income);
            //}
        }
    }
    else
    {
        system("clr");
        cout<<"XML file error!";
        system("pause");
    }

    return incomes;
}
