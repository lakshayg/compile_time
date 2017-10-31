#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "String"
#include <string>
#include <boost/test/unit_test.hpp>
#include "compile_time/string.hpp"
#include "common.hpp"

namespace CT = compile_time;

BOOST_AUTO_TEST_CASE(strlen_test) {
  CART_CHECK_EQUAL(CT::strlen(""), ::strlen(""));
  CART_CHECK_EQUAL(CT::strlen("test string"), ::strlen("test string"));
  CART_CHECK_EQUAL(CT::strlen("this is a very very long string"),
                   ::strlen("this is a very very long string"));
}

BOOST_AUTO_TEST_CASE(strcmp_test) {
  constexpr char empty[] = "";
  constexpr char str[] = "small string";
  constexpr char str1[] = "small string";
  constexpr char str2[] = "a longer string";
  constexpr char caps[] = "SMALL STRING";

  CART_CHECK_EQUAL(sgn(CT::strcmp(str1, str1)), sgn(::strcmp(str1, str1)));
  CART_CHECK_EQUAL(sgn(CT::strcmp(str, str1)), sgn(::strcmp(str, str1)));
  CART_CHECK_EQUAL(sgn(CT::strcmp(str1, str2)), sgn(::strcmp(str1, str2)));
  CART_CHECK_EQUAL(sgn(CT::strcmp(caps, str1)), sgn(::strcmp(caps, str1)));
  CART_CHECK_EQUAL(sgn(CT::strcmp(empty, str1)), sgn(::strcmp(empty, str1)));
}

BOOST_AUTO_TEST_CASE(isalnum_test) CHAR_TEST(CT::isalnum, ::isalnum);
BOOST_AUTO_TEST_CASE(isalpha_test) CHAR_TEST(CT::isalpha, ::isalpha);
BOOST_AUTO_TEST_CASE(islower_test) CHAR_TEST(CT::islower, ::islower);
BOOST_AUTO_TEST_CASE(isupper_test) CHAR_TEST(CT::isupper, ::isupper);
BOOST_AUTO_TEST_CASE(isdigit_test) CHAR_TEST(CT::isdigit, ::isdigit);
BOOST_AUTO_TEST_CASE(iscntrl_test) CHAR_TEST(CT::iscntrl, ::iscntrl);
BOOST_AUTO_TEST_CASE(isgraph_test) CHAR_TEST(CT::isgraph, ::isgraph);
BOOST_AUTO_TEST_CASE(isspace_test) CHAR_TEST(CT::isspace, ::isspace);
BOOST_AUTO_TEST_CASE(isblank_test) CHAR_TEST(CT::isblank, ::isblank);
BOOST_AUTO_TEST_CASE(isprint_test) CHAR_TEST(CT::isprint, ::isprint);
BOOST_AUTO_TEST_CASE(ispunct_test) CHAR_TEST(CT::ispunct, ::ispunct);
BOOST_AUTO_TEST_CASE(tolower_test) CHAR_TEST(CT::tolower, ::tolower);
BOOST_AUTO_TEST_CASE(toupper_test) CHAR_TEST(CT::toupper, ::toupper);
BOOST_AUTO_TEST_CASE(isxdigit_test) CHAR_TEST(CT::isxdigit, ::isxdigit);