// Compile And Run Time
#define CART_CHECK(boost_check, expr, ...)      \
  {                                             \
    constexpr auto compile_time_val = expr;     \
    boost_check(compile_time_val, __VA_ARGS__); \
    volatile auto run_time_val = expr;          \
    boost_check(run_time_val, __VA_ARGS__);     \
  }

#define CART_CHECK_EQUAL(...) CART_CHECK(BOOST_CHECK_EQUAL, __VA_ARGS__)
#define CART_CHECK_CLOSE(...) CART_CHECK(BOOST_CHECK_CLOSE, __VA_ARGS__)
#define EPS 1e-5  // percent

constexpr int sgn(int n) {
  return (n == 0) ? 0 : ((n > 0) ? 1 : -1);
}

#define CHAR_TEST(func1, func2)                         \
  {                                                     \
    CART_CHECK_EQUAL(sgn(func1(0)), sgn(func2(0)));     \
    CART_CHECK_EQUAL(sgn(func1(1)), sgn(func2(1)));     \
    CART_CHECK_EQUAL(sgn(func1(2)), sgn(func2(2)));     \
    CART_CHECK_EQUAL(sgn(func1(3)), sgn(func2(3)));     \
    CART_CHECK_EQUAL(sgn(func1(4)), sgn(func2(4)));     \
    CART_CHECK_EQUAL(sgn(func1(5)), sgn(func2(5)));     \
    CART_CHECK_EQUAL(sgn(func1(6)), sgn(func2(6)));     \
    CART_CHECK_EQUAL(sgn(func1(7)), sgn(func2(7)));     \
    CART_CHECK_EQUAL(sgn(func1(8)), sgn(func2(8)));     \
    CART_CHECK_EQUAL(sgn(func1(9)), sgn(func2(9)));     \
    CART_CHECK_EQUAL(sgn(func1(10)), sgn(func2(10)));   \
    CART_CHECK_EQUAL(sgn(func1(11)), sgn(func2(11)));   \
    CART_CHECK_EQUAL(sgn(func1(12)), sgn(func2(12)));   \
    CART_CHECK_EQUAL(sgn(func1(13)), sgn(func2(13)));   \
    CART_CHECK_EQUAL(sgn(func1(14)), sgn(func2(14)));   \
    CART_CHECK_EQUAL(sgn(func1(15)), sgn(func2(15)));   \
    CART_CHECK_EQUAL(sgn(func1(16)), sgn(func2(16)));   \
    CART_CHECK_EQUAL(sgn(func1(17)), sgn(func2(17)));   \
    CART_CHECK_EQUAL(sgn(func1(18)), sgn(func2(18)));   \
    CART_CHECK_EQUAL(sgn(func1(19)), sgn(func2(19)));   \
    CART_CHECK_EQUAL(sgn(func1(20)), sgn(func2(20)));   \
    CART_CHECK_EQUAL(sgn(func1(21)), sgn(func2(21)));   \
    CART_CHECK_EQUAL(sgn(func1(22)), sgn(func2(22)));   \
    CART_CHECK_EQUAL(sgn(func1(23)), sgn(func2(23)));   \
    CART_CHECK_EQUAL(sgn(func1(24)), sgn(func2(24)));   \
    CART_CHECK_EQUAL(sgn(func1(25)), sgn(func2(25)));   \
    CART_CHECK_EQUAL(sgn(func1(26)), sgn(func2(26)));   \
    CART_CHECK_EQUAL(sgn(func1(27)), sgn(func2(27)));   \
    CART_CHECK_EQUAL(sgn(func1(28)), sgn(func2(28)));   \
    CART_CHECK_EQUAL(sgn(func1(29)), sgn(func2(29)));   \
    CART_CHECK_EQUAL(sgn(func1(30)), sgn(func2(30)));   \
    CART_CHECK_EQUAL(sgn(func1(31)), sgn(func2(31)));   \
    CART_CHECK_EQUAL(sgn(func1(32)), sgn(func2(32)));   \
    CART_CHECK_EQUAL(sgn(func1(33)), sgn(func2(33)));   \
    CART_CHECK_EQUAL(sgn(func1(34)), sgn(func2(34)));   \
    CART_CHECK_EQUAL(sgn(func1(35)), sgn(func2(35)));   \
    CART_CHECK_EQUAL(sgn(func1(36)), sgn(func2(36)));   \
    CART_CHECK_EQUAL(sgn(func1(37)), sgn(func2(37)));   \
    CART_CHECK_EQUAL(sgn(func1(38)), sgn(func2(38)));   \
    CART_CHECK_EQUAL(sgn(func1(39)), sgn(func2(39)));   \
    CART_CHECK_EQUAL(sgn(func1(40)), sgn(func2(40)));   \
    CART_CHECK_EQUAL(sgn(func1(41)), sgn(func2(41)));   \
    CART_CHECK_EQUAL(sgn(func1(42)), sgn(func2(42)));   \
    CART_CHECK_EQUAL(sgn(func1(43)), sgn(func2(43)));   \
    CART_CHECK_EQUAL(sgn(func1(44)), sgn(func2(44)));   \
    CART_CHECK_EQUAL(sgn(func1(45)), sgn(func2(45)));   \
    CART_CHECK_EQUAL(sgn(func1(46)), sgn(func2(46)));   \
    CART_CHECK_EQUAL(sgn(func1(47)), sgn(func2(47)));   \
    CART_CHECK_EQUAL(sgn(func1(48)), sgn(func2(48)));   \
    CART_CHECK_EQUAL(sgn(func1(49)), sgn(func2(49)));   \
    CART_CHECK_EQUAL(sgn(func1(50)), sgn(func2(50)));   \
    CART_CHECK_EQUAL(sgn(func1(51)), sgn(func2(51)));   \
    CART_CHECK_EQUAL(sgn(func1(52)), sgn(func2(52)));   \
    CART_CHECK_EQUAL(sgn(func1(53)), sgn(func2(53)));   \
    CART_CHECK_EQUAL(sgn(func1(54)), sgn(func2(54)));   \
    CART_CHECK_EQUAL(sgn(func1(55)), sgn(func2(55)));   \
    CART_CHECK_EQUAL(sgn(func1(56)), sgn(func2(56)));   \
    CART_CHECK_EQUAL(sgn(func1(57)), sgn(func2(57)));   \
    CART_CHECK_EQUAL(sgn(func1(58)), sgn(func2(58)));   \
    CART_CHECK_EQUAL(sgn(func1(59)), sgn(func2(59)));   \
    CART_CHECK_EQUAL(sgn(func1(60)), sgn(func2(60)));   \
    CART_CHECK_EQUAL(sgn(func1(61)), sgn(func2(61)));   \
    CART_CHECK_EQUAL(sgn(func1(62)), sgn(func2(62)));   \
    CART_CHECK_EQUAL(sgn(func1(63)), sgn(func2(63)));   \
    CART_CHECK_EQUAL(sgn(func1(64)), sgn(func2(64)));   \
    CART_CHECK_EQUAL(sgn(func1(65)), sgn(func2(65)));   \
    CART_CHECK_EQUAL(sgn(func1(66)), sgn(func2(66)));   \
    CART_CHECK_EQUAL(sgn(func1(67)), sgn(func2(67)));   \
    CART_CHECK_EQUAL(sgn(func1(68)), sgn(func2(68)));   \
    CART_CHECK_EQUAL(sgn(func1(69)), sgn(func2(69)));   \
    CART_CHECK_EQUAL(sgn(func1(70)), sgn(func2(70)));   \
    CART_CHECK_EQUAL(sgn(func1(71)), sgn(func2(71)));   \
    CART_CHECK_EQUAL(sgn(func1(72)), sgn(func2(72)));   \
    CART_CHECK_EQUAL(sgn(func1(73)), sgn(func2(73)));   \
    CART_CHECK_EQUAL(sgn(func1(74)), sgn(func2(74)));   \
    CART_CHECK_EQUAL(sgn(func1(75)), sgn(func2(75)));   \
    CART_CHECK_EQUAL(sgn(func1(76)), sgn(func2(76)));   \
    CART_CHECK_EQUAL(sgn(func1(77)), sgn(func2(77)));   \
    CART_CHECK_EQUAL(sgn(func1(78)), sgn(func2(78)));   \
    CART_CHECK_EQUAL(sgn(func1(79)), sgn(func2(79)));   \
    CART_CHECK_EQUAL(sgn(func1(80)), sgn(func2(80)));   \
    CART_CHECK_EQUAL(sgn(func1(81)), sgn(func2(81)));   \
    CART_CHECK_EQUAL(sgn(func1(82)), sgn(func2(82)));   \
    CART_CHECK_EQUAL(sgn(func1(83)), sgn(func2(83)));   \
    CART_CHECK_EQUAL(sgn(func1(84)), sgn(func2(84)));   \
    CART_CHECK_EQUAL(sgn(func1(85)), sgn(func2(85)));   \
    CART_CHECK_EQUAL(sgn(func1(86)), sgn(func2(86)));   \
    CART_CHECK_EQUAL(sgn(func1(87)), sgn(func2(87)));   \
    CART_CHECK_EQUAL(sgn(func1(88)), sgn(func2(88)));   \
    CART_CHECK_EQUAL(sgn(func1(89)), sgn(func2(89)));   \
    CART_CHECK_EQUAL(sgn(func1(90)), sgn(func2(90)));   \
    CART_CHECK_EQUAL(sgn(func1(91)), sgn(func2(91)));   \
    CART_CHECK_EQUAL(sgn(func1(92)), sgn(func2(92)));   \
    CART_CHECK_EQUAL(sgn(func1(93)), sgn(func2(93)));   \
    CART_CHECK_EQUAL(sgn(func1(94)), sgn(func2(94)));   \
    CART_CHECK_EQUAL(sgn(func1(95)), sgn(func2(95)));   \
    CART_CHECK_EQUAL(sgn(func1(96)), sgn(func2(96)));   \
    CART_CHECK_EQUAL(sgn(func1(97)), sgn(func2(97)));   \
    CART_CHECK_EQUAL(sgn(func1(98)), sgn(func2(98)));   \
    CART_CHECK_EQUAL(sgn(func1(99)), sgn(func2(99)));   \
    CART_CHECK_EQUAL(sgn(func1(100)), sgn(func2(100))); \
    CART_CHECK_EQUAL(sgn(func1(101)), sgn(func2(101))); \
    CART_CHECK_EQUAL(sgn(func1(102)), sgn(func2(102))); \
    CART_CHECK_EQUAL(sgn(func1(103)), sgn(func2(103))); \
    CART_CHECK_EQUAL(sgn(func1(104)), sgn(func2(104))); \
    CART_CHECK_EQUAL(sgn(func1(105)), sgn(func2(105))); \
    CART_CHECK_EQUAL(sgn(func1(106)), sgn(func2(106))); \
    CART_CHECK_EQUAL(sgn(func1(107)), sgn(func2(107))); \
    CART_CHECK_EQUAL(sgn(func1(108)), sgn(func2(108))); \
    CART_CHECK_EQUAL(sgn(func1(109)), sgn(func2(109))); \
    CART_CHECK_EQUAL(sgn(func1(110)), sgn(func2(110))); \
    CART_CHECK_EQUAL(sgn(func1(111)), sgn(func2(111))); \
    CART_CHECK_EQUAL(sgn(func1(112)), sgn(func2(112))); \
    CART_CHECK_EQUAL(sgn(func1(113)), sgn(func2(113))); \
    CART_CHECK_EQUAL(sgn(func1(114)), sgn(func2(114))); \
    CART_CHECK_EQUAL(sgn(func1(115)), sgn(func2(115))); \
    CART_CHECK_EQUAL(sgn(func1(116)), sgn(func2(116))); \
    CART_CHECK_EQUAL(sgn(func1(117)), sgn(func2(117))); \
    CART_CHECK_EQUAL(sgn(func1(118)), sgn(func2(118))); \
    CART_CHECK_EQUAL(sgn(func1(119)), sgn(func2(119))); \
    CART_CHECK_EQUAL(sgn(func1(120)), sgn(func2(120))); \
    CART_CHECK_EQUAL(sgn(func1(121)), sgn(func2(121))); \
    CART_CHECK_EQUAL(sgn(func1(122)), sgn(func2(122))); \
    CART_CHECK_EQUAL(sgn(func1(123)), sgn(func2(123))); \
    CART_CHECK_EQUAL(sgn(func1(124)), sgn(func2(124))); \
    CART_CHECK_EQUAL(sgn(func1(125)), sgn(func2(125))); \
    CART_CHECK_EQUAL(sgn(func1(126)), sgn(func2(126))); \
    CART_CHECK_EQUAL(sgn(func1(127)), sgn(func2(127))); \
  }
