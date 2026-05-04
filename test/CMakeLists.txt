add_executable(writer writer.cpp)
add_executable(reader reader.cpp)
add_executable(unit_test gtest.cpp)

target_link_libraries( unit_test PRIVATE
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_test)
