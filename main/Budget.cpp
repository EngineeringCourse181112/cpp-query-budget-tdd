#include "Budget.h"

Budget::Budget(unsigned int aYear, unsigned int aMonth, unsigned int amount) : yearMonth(year_month(year(aYear), month(aMonth))), amount(amount) {}
