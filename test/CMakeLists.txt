find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

macro(add_boost_test src_no_ext)
    add_executable(${src_no_ext} "${src_no_ext}.cpp")
    target_link_libraries(${src_no_ext} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test("${src_no_ext}" ${src_no_ext})
endmacro(add_boost_test)

add_boost_test(math)
add_boost_test(string)