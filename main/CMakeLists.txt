set(Main_SRCS main.cpp date.h BudgetDao.h Budget.cpp Budget.h)

add_library(core ${Main_SRCS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} core)
