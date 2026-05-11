add_executable(writer writer.cpp)
add_executable(reader reader.cpp)
add_executable(unit_test gtest.cpp)
add_executable(random_writer random_writer.cpp)
add_executable(random_reader random_reader.cpp)

target_link_libraries( unit_test PRIVATE
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_test)
