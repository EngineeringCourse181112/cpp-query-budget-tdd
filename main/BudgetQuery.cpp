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
    if (period.end < budget.getFirstDay() || period.start > budget.getLastDay())
        return 0;

    if (period.end > budget.getLastDay())
        return 10 * period.getOverlappingDayCount(budget.period);

    if (budget.getFirstDay() > period.start)
        return 10 * period.getOverlappingDayCount(budget.period);

    return 10 * period.getOverlappingDayCount(budget.period);
}

BudgetQuery::BudgetQuery(BudgetDao &_budgetDao) : budgetDao(_budgetDao) {}
