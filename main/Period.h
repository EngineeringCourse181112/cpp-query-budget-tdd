#ifndef CPP_OTP_PERIOD_H
#define CPP_OTP_PERIOD_H

#include "date.h"

using namespace date;

class Period {

public:
    Period(year_month_day start, year_month_day end);
    int getDayCount() const;
    int getOverlappingDayCount(const Period &another) const;

private:
    year_month_day start;
    year_month_day end;

};


#endif //CPP_OTP_PERIOD_H
