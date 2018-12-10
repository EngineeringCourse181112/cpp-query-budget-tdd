#include "BudgetQuery.h"
#include "Period.h"

int BudgetQuery::getTotal(year_month_day start, year_month_day end) {
    return getTotal(Period(start, end));
}

int BudgetQuery::getTotal(const Period &period) const {
    if (budgetDao.findAll().empty()) {
        return 0;
    }

    auto budget = budgetDao.findAll()[0];
    return 10 * period.getOverlappingDayCount(budget.period);
}

BudgetQuery::BudgetQuery(BudgetDao &_budgetDao) : budgetDao(_budgetDao) {}
