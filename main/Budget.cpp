#include "Budget.h"

Budget::Budget(unsigned int aYear, unsigned int aMonth, unsigned int amount) : yearMonth(year_month(year(aYear), month(aMonth))), amount(amount) {}

year_month_day Budget::getFirstDay() const {
    return year_month_day(yearMonth.year(), yearMonth.month(), day(1));
}
