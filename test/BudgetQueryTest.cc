#include <gtest/gtest.h>
#include "../main/date.h"
#include "../main/BudgetQuery.h"
#include "stub_budget_dao.h"

using namespace date;
using ::testing::Return;

class BudgetQueryTest : public ::testing::Test {
protected:
    stub_budget_dao stubBudgetDao;
    BudgetQuery budgetQuery = BudgetQuery(stubBudgetDao);

    void givenBudget(vector<Budget> budgets) {
        ON_CALL(stubBudgetDao, findAll()).WillByDefault(Return(budgets));
    }

};


TEST_F(BudgetQueryTest, CheckStartDateIsLaterThanEndDate) {
    ASSERT_EQ(0, budgetQuery.getTotal(year_month_day(year(2018), month(10), day(10)),
                                      year_month_day(year(2018), month(9), day(15))));
}

TEST_F(BudgetQueryTest, NoBudget) {

    ASSERT_EQ(0, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(10)),
                                      year_month_day(year(2018), month(9), day(10))));
}

TEST_F(BudgetQueryTest, OneBudget) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(10, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(10)),
                                       year_month_day(year(2018), month(9), day(10))));
}

TEST_F(BudgetQueryTest, StartAndEndBothInMonth) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(20, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(10)),
                                       year_month_day(year(2018), month(9), day(11))));
}

TEST_F(BudgetQueryTest, EndInCurrentMonth) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(110, budgetQuery.getTotal(year_month_day(year(2018), month(8), day(20)),
                                        year_month_day(year(2018), month(9), day(11))));
}

TEST_F(BudgetQueryTest, StartInCurrentMonth) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(120, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(19)),
                                        year_month_day(year(2018), month(10), day(11))));
}

TEST_F(BudgetQueryTest, EndBeforeFirstDayOfMonth) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(0, budgetQuery.getTotal(year_month_day(year(2018), month(8), day(19)),
                                      year_month_day(year(2018), month(8), day(25))));
}

TEST_F(BudgetQueryTest, StartAfterLastDayOfMonth) {
    givenBudget({Budget(2018, 9, 300)});

    ASSERT_EQ(0, budgetQuery.getTotal(year_month_day(year(2018), month(10), day(19)),
                                      year_month_day(year(2018), month(10), day(25))));
}

TEST_F(BudgetQueryTest, TwoBudgets) {
    givenBudget({Budget(2018, 9, 300), Budget(2018, 10, 310)});

    ASSERT_EQ(110 + 250, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(20)),
                                              year_month_day(year(2018), month(10), day(25))));
}

TEST_F(BudgetQueryTest, DailyAmount) {
    givenBudget({Budget(2018, 9, 600)});

    ASSERT_EQ(20 * 7, budgetQuery.getTotal(year_month_day(year(2018), month(9), day(19)),
                                      year_month_day(year(2018), month(9), day(25))));
}
