set(Test_SRCS BudgetQueryTest.cc stub_budget_dao.h)

add_executable(cpp_otp_test ${Test_SRCS})
target_link_libraries(cpp_otp_test gtest gmock gtest_main core)
