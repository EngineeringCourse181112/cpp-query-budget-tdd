#ifndef CPP_OTP_STUB_BUDGET_DAO_H
#define CPP_OTP_STUB_BUDGET_DAO_H

#include "gmock/gmock.h"


#include "../main/BudgetDao.h"

class stub_budget_dao : public BudgetDao {
public :
   MOCK_METHOD0 (findAll, vector<Budget> ());

};


#endif //CPP_OTP_STUB_BUDGET_DAO_H
