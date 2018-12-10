#include "Period.h"

Period::Period(const year_month_day start, const year_month_day end) : start(start), end(end) {

}

int Period::getDayCount() const {
   return ((sys_days{end} - sys_days{start}).count() + 1);
}
