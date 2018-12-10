#include "Period.h"

Period::Period(const year_month_day start, const year_month_day end) : start(start), end(end) {

}

int Period::getDayCount() const {
   return ((sys_days{end} - sys_days{start}).count() + 1);
}

int Period::getOverlappingDayCount(const Period &another) const {
   auto overlappingEnd = end < another.end ? end : another.end;
   auto overlappingStart = start > another.start ? start : another.start;
   if (overlappingStart > overlappingEnd)
      return 0;

   return Period(overlappingStart, overlappingEnd).getDayCount();
}

