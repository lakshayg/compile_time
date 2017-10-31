#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "Math"
#include <cmath>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "compile_time/math.hpp"
#include "compile_time/constants.hpp"
#include "common.hpp"

// Helper functions
template <typename Real>
struct more {
  constexpr bool operator()(Real a, Real b) { return a > b; }
};

namespace CT = compile_time;

// Tests begin here
BOOST_AUTO_TEST_CASE(factorial_test) {
  CART_CHECK_EQUAL(CT::factorial(0), 1);
  CART_CHECK_EQUAL(CT::factorial(1), 1);
  CART_CHECK_EQUAL(CT::factorial(2), 2);
  CART_CHECK_EQUAL(CT::factorial(4), 24);
  BOOST_CHECK_THROW(CT::factorial(-1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(abs_test) {
  CART_CHECK_EQUAL(CT::abs(1), 1)
  CART_CHECK_EQUAL(CT::abs(0), 0);
  CART_CHECK_EQUAL(CT::abs(-1), 1);
}

BOOST_AUTO_TEST_CASE(odd_even_test) {
  CART_CHECK_EQUAL(CT::is_even(0), true);
  CART_CHECK_EQUAL(CT::is_even(1), false);
  CART_CHECK_EQUAL(CT::is_even(-1), false);
  CART_CHECK_EQUAL(CT::is_even(0), true);
  CART_CHECK_EQUAL(CT::is_even(2), true);
  CART_CHECK_EQUAL(CT::is_odd(0), false);
  CART_CHECK_EQUAL(CT::is_odd(1), true);
  CART_CHECK_EQUAL(CT::is_odd(-1), true);
  CART_CHECK_EQUAL(CT::is_odd(0), false);
  CART_CHECK_EQUAL(CT::is_odd(2), false);
}

BOOST_AUTO_TEST_CASE(is_negative_test) {
  CART_CHECK_EQUAL(CT::is_negative(-1), true);
  CART_CHECK_EQUAL(CT::is_negative(0), false);
  CART_CHECK_EQUAL(CT::is_negative(1), false);
}

BOOST_AUTO_TEST_CASE(pow_test) {
  CART_CHECK_EQUAL(CT::pow(1, 0), 1);
  CART_CHECK_EQUAL(CT::pow(2, 0), 1);
  CART_CHECK_EQUAL(CT::pow(0, 1), 0);
  CART_CHECK_EQUAL(CT::pow(1, 1), 1);
  CART_CHECK_EQUAL(CT::pow(2, 1), 2);
  CART_CHECK_EQUAL(CT::pow(5, 3), 125);
  CART_CHECK_EQUAL(CT::pow(0.5, -1), 2);
  CART_CHECK_EQUAL(CT::pow(1.0, -2), 1);
  CART_CHECK_EQUAL(CT::pow(0.9, -0), 1);
  CART_CHECK_EQUAL(CT::pow(5.0, -2), 0.04);
}

BOOST_AUTO_TEST_CASE(min_max_test) {
  CART_CHECK_EQUAL(CT::max(1, 2), 2);
  CART_CHECK_EQUAL(CT::min(1, 2), 1);
  CART_CHECK_EQUAL(CT::min(1, 2, more<int>()), 2);
  CART_CHECK_EQUAL(CT::max(1, 2, more<int>()), 1);
}

BOOST_AUTO_TEST_CASE(sqrt_test) {
  CART_CHECK_CLOSE(CT::sqrt(25), ::sqrt(25), EPS);
  CART_CHECK_CLOSE(CT::sqrt(25.0), ::sqrt(25.0), EPS);
  CART_CHECK_CLOSE(CT::sqrt(23.0), ::sqrt(23.0), EPS);
  CART_CHECK_CLOSE(CT::sqrt(0.0), ::sqrt(0.), EPS);
  CART_CHECK_CLOSE(CT::sqrt(1.0), ::sqrt(1.), EPS);
  BOOST_CHECK_THROW(CT::sqrt(-1.), std::domain_error);
}

BOOST_AUTO_TEST_CASE(hypot_test) {
  CART_CHECK_CLOSE(CT::hypot(3., 4.), ::hypot(3., 4.), EPS);
  CART_CHECK_CLOSE(CT::hypot(-3., 4.), ::hypot(-3, 4), EPS);
  CART_CHECK_CLOSE(CT::hypot(-5., -12.), ::hypot(-5, -12), EPS);
}

BOOST_AUTO_TEST_CASE(sqr_test) {
  CART_CHECK_EQUAL(CT::sqr(-1), 1);
  CART_CHECK_EQUAL(CT::sqr(1), 1);
  CART_CHECK_EQUAL(CT::sqr(0), 0);
  CART_CHECK_EQUAL(CT::sqr(0.5), 0.25);
}

BOOST_AUTO_TEST_CASE(choose_test) {
  CART_CHECK_EQUAL(CT::choose(1, 0), 1);
  CART_CHECK_EQUAL(CT::choose(1, 1), 1);
  CART_CHECK_EQUAL(CT::choose(10, 1), 10);
  CART_CHECK_EQUAL(CT::choose(10, 0), 1);
  CART_CHECK_EQUAL(CT::choose(10, 2), 45);
  CART_CHECK_EQUAL(CT::choose(10, 10), 1);
  CART_CHECK_EQUAL(CT::choose(50L, 10L), 10272278170);
  BOOST_CHECK_THROW(CT::choose(0L, 1L), std::domain_error);
  BOOST_CHECK_THROW(CT::choose(-10L, 1L), std::domain_error);
  BOOST_CHECK_THROW(CT::choose(10L, -2L), std::domain_error);
}

BOOST_AUTO_TEST_CASE(fibonacci_test) {
  CART_CHECK_EQUAL(CT::fibonacci(1), 1);
  CART_CHECK_EQUAL(CT::fibonacci(2), 1);
  CART_CHECK_EQUAL(CT::fibonacci(3), 2);
  CART_CHECK_EQUAL(CT::fibonacci(4), 3);
  CART_CHECK_EQUAL(CT::fibonacci(5), 5);
  CART_CHECK_EQUAL(CT::fibonacci(6), 8);
  BOOST_CHECK_THROW(CT::fibonacci(0), std::domain_error);
  BOOST_CHECK_THROW(CT::fibonacci(-1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(deg_rad_test) {
  CART_CHECK_CLOSE(CT::deg2rad(CT::rad2deg(1.0)), 1.0, EPS);
}

BOOST_AUTO_TEST_CASE(wrap_test) {
  constexpr auto pi = CT::constants::pi;
  CART_CHECK_EQUAL(CT::detail::wrap(2. * pi), 0.);
  CART_CHECK_EQUAL(CT::detail::wrap(3. * pi), pi);
  CART_CHECK_EQUAL(CT::detail::wrap(4.), 4. - 2 * pi);
  CART_CHECK_EQUAL(CT::detail::wrap(-4.), 2 * pi - 4);
}

BOOST_AUTO_TEST_CASE(floor_ceil_test) {
  CART_CHECK_EQUAL(CT::floor(1.2), 1);
  CART_CHECK_EQUAL(CT::ceil(1.2), 2);
  CART_CHECK_EQUAL(CT::floor(1.), 1);
  CART_CHECK_EQUAL(CT::ceil(1.), 1);
  CART_CHECK_EQUAL(CT::floor(0.5), 0);
  CART_CHECK_EQUAL(CT::ceil(0.5), 1);
  CART_CHECK_EQUAL(CT::floor(0.), 0);
  CART_CHECK_EQUAL(CT::ceil(0.), 0);
  CART_CHECK_EQUAL(CT::floor(-0.5), -1);
  CART_CHECK_EQUAL(CT::ceil(-0.5), 0);
  CART_CHECK_EQUAL(CT::floor(-1.), -1);
  CART_CHECK_EQUAL(CT::ceil(-1.), -1);
  CART_CHECK_EQUAL(CT::floor(-1.2), -2);
  CART_CHECK_EQUAL(CT::ceil(-1.2), -1);
}

BOOST_AUTO_TEST_CASE(exp_test) {
  CART_CHECK_CLOSE(CT::exp(12.23), ::exp(12.23), EPS);
  CART_CHECK_CLOSE(CT::exp(1.2), ::exp(1.2), EPS);
  CART_CHECK_CLOSE(CT::exp(0.5), ::exp(0.5), EPS);
  CART_CHECK_CLOSE(CT::exp(0.0), ::exp(0.0), EPS);
  CART_CHECK_CLOSE(CT::exp(-0.7), ::exp(-0.7), EPS);
}

BOOST_AUTO_TEST_CASE(sin_test) {
  CART_CHECK_CLOSE(CT::sin(-10.), ::sin(-10.), EPS);
  CART_CHECK_CLOSE(CT::sin(10.), ::sin(10.), EPS);
  CART_CHECK_CLOSE(CT::sin(2.3), ::sin(2.3), EPS);
  CART_CHECK_CLOSE(CT::sin(-2.3), ::sin(-2.3), EPS);
}

BOOST_AUTO_TEST_CASE(cos_test) {
  CART_CHECK_CLOSE(CT::cos(-10.), ::cos(-10.), EPS);
  CART_CHECK_CLOSE(CT::cos(10.), ::cos(10.), EPS);
  CART_CHECK_CLOSE(CT::cos(20.), ::cos(20.), EPS);
  CART_CHECK_CLOSE(CT::cos(2.3), ::cos(2.3), EPS);
  CART_CHECK_CLOSE(CT::cos(-2.3), ::cos(-2.3), EPS);
}

BOOST_AUTO_TEST_CASE(tan_test) {
  CART_CHECK_CLOSE(CT::tan(-10.), ::tan(-10.), EPS);
  CART_CHECK_CLOSE(CT::tan(10.), ::tan(10.), EPS);
  CART_CHECK_CLOSE(CT::tan(2.3), ::tan(2.3), EPS);
  CART_CHECK_CLOSE(CT::tan(-2.3), ::tan(-2.3), EPS);
}

BOOST_AUTO_TEST_CASE(ilog_test) {
  CART_CHECK_CLOSE(CT::ilog(0.1), ::floor(::log(0.1)), EPS);
  CART_CHECK_CLOSE(CT::ilog(0.5), ::floor(::log(0.5)), EPS);
  CART_CHECK_CLOSE(CT::ilog(1.0), ::floor(::log(1.0)), EPS);
  CART_CHECK_CLOSE(CT::ilog(2.0), ::floor(::log(2.0)), EPS);
  CART_CHECK_CLOSE(CT::ilog(3.0), ::floor(::log(3.0)), EPS);
  CART_CHECK_CLOSE(CT::ilog(0.1, 2.), ::floor(::log2(0.1)), EPS);
  CART_CHECK_CLOSE(CT::ilog(0.5, 2.), ::floor(::log2(0.5)), EPS);
  CART_CHECK_CLOSE(CT::ilog(1.0, 2.), ::floor(::log2(1.0)), EPS);
  CART_CHECK_CLOSE(CT::ilog(2.0, 2.), ::floor(::log2(2.0)), EPS);
  CART_CHECK_CLOSE(CT::ilog(3.0, 2.), ::floor(::log2(3.0)), EPS);
  BOOST_CHECK_THROW(CT::ilog(0.1, -1.), std::domain_error);
  BOOST_CHECK_THROW(CT::ilog(0.1, 1.), std::domain_error);
  BOOST_CHECK_THROW(CT::ilog(-0.1, 2.), std::domain_error);
}

BOOST_AUTO_TEST_CASE(fast_atan_test) {
  auto const err = 1.5;  // percent
  CART_CHECK_CLOSE(CT::fast_atan(0.1), ::atan(0.1), err);
  CART_CHECK_CLOSE(CT::fast_atan(-0.1), ::atan(-0.1), err);
  CART_CHECK_CLOSE(CT::fast_atan(1.), ::atan(1.), err);
  CART_CHECK_CLOSE(CT::fast_atan(10.), ::atan(10.), err);
  CART_CHECK_CLOSE(CT::fast_atan(100.), ::atan(100.), err);
  CART_CHECK_CLOSE(CT::fast_atan(1000.), ::atan(1000.), err);
}
