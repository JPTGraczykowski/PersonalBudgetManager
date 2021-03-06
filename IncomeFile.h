#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "DataFile.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
#include "Markup.h"
#include "Income.h"


#include <iostream>
#include <vector>


using namespace std;

class IncomeFile : public DataFile
{
    int lastIncomeId;

    Income getIncomeDetails(CMarkup &file);
public:
    IncomeFile(string incomeFileName) : DataFile(incomeFileName) {};
    vector<Income> getIncomesOfLoggedInUserFromFile(int loggedInUserId);
    void addIncomeToFile(Income income);
    int getLastIncomeId();
    void setLastIncomeId(int newLastIncomeId);

};
#endif // INCOMEFILE_H
