#include "Budget.h"

Budget::Budget(unsigned int aYear, unsigned int aMonth, unsigned int amount) : yearMonth(year_month(year(aYear), month(aMonth))), amount(amount) {}

year_month_day Budget::getFirstDay() const {
    return year_month_day(yearMonth.year(), yearMonth.month(), day(1));
}

year_month_day_last Budget::getLastDay() const {
    return year_month_day_last(yearMonth.year(), month_day_last(yearMonth.month()));
}

Period Budget::getPeriod() const {
    return Period(getFirstDay(), getLastDay());
}
