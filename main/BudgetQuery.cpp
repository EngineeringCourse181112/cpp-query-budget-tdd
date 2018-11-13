#include "BudgetQuery.h"

int BudgetQuery::getTotal(year_month_day start, year_month_day end) {
    if (budgetDao.findAll().empty()) {
        return 0;
    }

    auto budget = budgetDao.findAll()[0];
    if (budget.getFirstDay() > start)
        return 10 * ((sys_days{end} - sys_days{budget.getFirstDay()}).count() + 1);

    return 10 * ((sys_days{end} - sys_days{start}).count() + 1);
}

BudgetQuery::BudgetQuery(BudgetDao &_budgetDao) : budgetDao(_budgetDao) {}
