#include <iostream>
#include <string>
#include <functional>
#include <catch2/catch_test_macros.hpp>

double _sin(double x)
{
	return std::sin(x);
}

double _cos(double x)
{
	return std::cos(x);
}

double _exp(double x)
{
	return std::exp(x);
}

double calculate(double epsilon, int f_num)
{
	double x = 1;
	double x0 = 0;

	std::function<double(double)> function;

	switch (f_num)
	{
	case(1):
		function = _sin;
		break;
	case(2):
		function = _cos;
		break;
	case(3):
		function = _exp;
		break;
	default:
		break;
	}

	while (std::abs(x - x0) > epsilon)
	{
		x0 = x;
		x = function(x);
	}

	return x0;

}

TEST_CASE("test1", "[t1]") {
	REQUIRE(abs(calculate(0.001, 2) - 0.739567) < 0.001);
	
}

TEST_CASE("test2", "[t2]") {
	REQUIRE(calculate(0.001, 2) == 0);
	
}

TEST_CASE("test3", "[t3]") {
	REQUIRE(calculate(0.001, 3) == 0);
	
}

TEST_CASE("test4", "[t4]") {
	REQUIRE(abs(calculate(0.001, 1) - 0) < 0.001);
}