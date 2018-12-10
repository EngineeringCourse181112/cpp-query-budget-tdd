#ifndef CPP_OTP_BUDGETQUERY_H
#define CPP_OTP_BUDGETQUERY_H

#include "date.h"
#include "BudgetDao.h"
#include "Period.h"

using namespace date;
class BudgetQuery {
public:
    BudgetQuery(BudgetDao&);
    int getTotal(year_month_day start, year_month_day end);

private:
    BudgetDao&   budgetDao;

    year_month_day_last getLastDay(const Budget &budget) const;

    int getTotal(const Period &period) const;

    int getDayCount(const Period &period) const;

    int getOverlappingDayCount(const Period &period, const Period &another) const;

    int getOverlappingAmount(const Period &period, const Budget &budget) const;
};


#endif //CPP_OTP_BUDGETQUERY_H
