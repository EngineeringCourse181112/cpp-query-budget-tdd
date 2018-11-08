#ifndef CPP_OTP_BUDGETDAO_H
#define CPP_OTP_BUDGETDAO_H

#include <vector>
#include "Budget.h"

using namespace std;

class BudgetDao {

public:
    virtual vector<Budget> findAll() {
        return vector<Budget>();
    }

};


#endif //CPP_OTP_BUDGETDAO_H
