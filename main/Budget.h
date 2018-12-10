#ifndef CPP_OTP_BUDGET_H
#define CPP_OTP_BUDGET_H

#include "date.h"
#include "Period.h"

using namespace date;

class Budget {

public:
    Budget(unsigned int aYear, unsigned int aMonth, unsigned int amount);
    year_month yearMonth;
    unsigned int amount;
    year_month_day getFirstDay() const;
    year_month_day_last getLastDay() const;
    const Period period;
};


#endif //CPP_OTP_BUDGET_H
