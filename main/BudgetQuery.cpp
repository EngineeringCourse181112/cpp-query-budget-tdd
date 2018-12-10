#include "BudgetQuery.h"
#include "Period.h"

int BudgetQuery::getTotal(year_month_day start, year_month_day end) {
    return getTotal(Period(start, end));
}

int BudgetQuery::getTotal(const Period &period) const {
    int total = 0;

    for (auto budget : budgetDao.findAll()) {
        total += 10 * period.getOverlappingDayCount(budget.period);
    }

    return total;
}

BudgetQuery::BudgetQuery(BudgetDao &_budgetDao) : budgetDao(_budgetDao) {}
