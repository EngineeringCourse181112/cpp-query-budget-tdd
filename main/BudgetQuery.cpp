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
        return getOverlappingDayCount(period, budget.getPeriod());

    if (budget.getFirstDay() > period.start)
        return 10 * ((sys_days{period.end} - sys_days{budget.getFirstDay()}).count() + 1);

    return 10 * period.getDayCount();
}

int BudgetQuery::getOverlappingDayCount(const Period &period, const Period &another) const {
    return 10 * ((sys_days{another.end} - sys_days{period.start}).count() + 1);
}

BudgetQuery::BudgetQuery(BudgetDao &_budgetDao) : budgetDao(_budgetDao) {}
