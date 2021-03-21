#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task1/VectorProcessor.h"

SCENARIO("Processing and sorting the vector")
{
	GIVEN("Vector with numbers")
	{
		vector<float> numberVector;
		vector<float> expectedResult;

		WHEN("Vector contains only zero")
		{
			numberVector = { 0, 0, 0 };
			REQUIRE(VectorProcessing(numberVector) == false);
		}

		WHEN("Vector contains only one item")
		{
			numberVector = { 1 };
			expectedResult = { 2 };
			VectorProcessing(numberVector);
			REQUIRE(numberVector == expectedResult);
		}

		WHEN("Vector contains only negative numbers")
		{
			numberVector = { -1.5, -1, -50 };
			expectedResult = { 2, 3, 100 };
			VectorProcessing(numberVector);
			SortVector(numberVector);
			REQUIRE(numberVector == expectedResult);
		}

		WHEN("Vector contains only positive numbers")
		{
			numberVector = { 1.5, 1, 50 };
			expectedResult = { 0.04, 0.06, 2.0 };
			VectorProcessing(numberVector);
			SortVector(numberVector);
			REQUIRE(numberVector == expectedResult);
		}

		WHEN("Vector contains large number")
		{
			numberVector = { 1, 2.5, 8888888888888888888.0 };
			expectedResult = { 2.25e-19, 5.625e-19, 2 };
			VectorProcessing(numberVector);
			SortVector(numberVector);
			REQUIRE(numberVector == expectedResult);
		}

		WHEN("Vector contains few item")
		{
			numberVector = { 1, -1, 0, 0.5, 100 };
			expectedResult = { -0.02, 0, 0.01, 0.02, 2 };
			VectorProcessing(numberVector);
			SortVector(numberVector);
			REQUIRE(numberVector == expectedResult);
		}
	}

	GIVEN("Empty vector")
	{
		vector<float> emptyVector = {};
		REQUIRE(VectorProcessing(emptyVector) == false);
	}
}