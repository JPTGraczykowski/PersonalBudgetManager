#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "DataFile.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Income.h"


#include <iostream>
#include <vector>


using namespace std;

class IncomeFile : public DataFile
{
    Income getIncomeDetails;
public:
    IncomeFile(string incomeFileName) : DataFile(incomeFileName);
    vector<Income> getIncomesOfLoggedInUserFromFile;
    void addIncomeToFile(Income income);

};
#endif // INCOMEFILE_H
