#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task4/PrimeNumberGenerator.h"

SCENARIO("Generate prime numbers set")
{
	cout << "Test: ";
	GIVEN("Invalid arguments count")
	{
		int argc = 1;
		char* argv[] = { {} };
		cout << "Invalid arguments count" << endl;
		REQUIRE(ParseArgs(argc, argv) == nullopt);
	}

	GIVEN("Given 2 arguments")
	{
		int upperBound;
		set<int> expectedSet;
		WHEN("UpperBound less than 1")
		{
			cout << "UpperBound less than 1" << endl;
			upperBound = -1;
			REQUIRE(IsCorrectUpperBound(upperBound) == false);
		}

		WHEN("UpperBound more than 0")
		{
			cout << "UpperBound more than 0" << endl;
			upperBound = 10;
			expectedSet = { 2, 3, 5, 7 };
			IsCorrectUpperBound(upperBound);
			REQUIRE(GeneratePrimeNumbersSet(upperBound) == expectedSet);
		}

		WHEN("Prime numbers don't exist")
		{
			cout << "Prime numbers don't exist" << endl;
			upperBound = 1;
			IsCorrectUpperBound(upperBound);
			set<int> primeNumberSet = GeneratePrimeNumbersSet(upperBound);
			REQUIRE(ArePrimeNumbersExist(primeNumberSet) == false);
		}

		WHEN("UpperBound equal 100000000")
		{
			cout << "UpperBound is equal 100000000" << endl;
			upperBound = 100000000;
			int expectedSetCount = 5761455;
			IsCorrectUpperBound(upperBound);
			set<int> primeNumberSet = GeneratePrimeNumbersSet(upperBound);
			REQUIRE(primeNumberSet.size() == expectedSetCount);
		}
	}
}