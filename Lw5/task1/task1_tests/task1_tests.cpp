#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task1/CComplex.h"

const string TEST_PASSED = "Test passed successfully";

SCENARIO("Test CComlpex methods")
{
	cout << "Test CComlpex methods" << endl;
	GIVEN("Get real")
	{
		cout << "Get real" << endl;
		CComplex complex(1, 2);
		REQUIRE(complex.Re() == 1);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Get image")
	{
		cout << "Get image" << endl;
		CComplex complex(1, 2);
		REQUIRE(complex.Im() == 2);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Get argument")
	{
		cout << "Get argument" << endl;
		WHEN("When real >= 0")
		{
			cout << "When real >= 0" << endl;
			CComplex complex(1, 2);
			REQUIRE(to_string(complex.GetArgument()) == "1.107149");
			cout << TEST_PASSED << endl;
		}

		WHEN("When real < 0")
		{
			cout << "When real < 0" << endl;
			CComplex complex(-1, 2);
			REQUIRE(to_string(complex.GetArgument()) == "0.851418");
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Get magnitude")
	{
		cout << "Get magnitude" << endl;
		CComplex complex(1, 2);
		REQUIRE(to_string(complex.GetMagnitude()) == "2.236068");
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CComlpex operators")
{
	cout << "Test CComlpex operators" << endl;
	GIVEN("Binary addition test")
	{
		cout << "Binary addition test" << endl;
		WHEN("complex + complex")
		{
			cout << "complex + complex" << endl;
			CComplex complexSum = CComplex(1, 2) + CComplex(1, 1);
			REQUIRE(complexSum.Re() == 2);
			REQUIRE(complexSum.Im() == 3);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex + real")
		{
			cout << "complex + real" << endl;
			CComplex complexSum = CComplex(1, 2) + 5;
			REQUIRE(complexSum.Re() == 6);
			REQUIRE(complexSum.Im() == 2);
			cout << TEST_PASSED << endl;
		}

		WHEN("real + complex")
		{
			cout << "real + complex" << endl;
			CComplex complexSum = 5 + CComplex(1, 2);
			REQUIRE(complexSum.Re() == 6);
			REQUIRE(complexSum.Im() == 2);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Binary subtraction test")
	{
		cout << "Binary subtraction test" << endl;
		WHEN("complex - complex")
		{
			cout << "complex - complex" << endl;
			CComplex complexSum = CComplex(1, 2) - CComplex(1, 1);
			REQUIRE(complexSum.Re() == 0);
			REQUIRE(complexSum.Im() == 1);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex - real")
		{
			cout << "complex - real" << endl;
			CComplex complexSum = CComplex(1, 2) - 5;
			REQUIRE(complexSum.Re() == -4);
			REQUIRE(complexSum.Im() == 2);
			cout << TEST_PASSED << endl;
		}

		WHEN("real - complex")
		{
			cout << "real - complex" << endl;
			CComplex complexSum = 5 - CComplex(1, 2);
			REQUIRE(complexSum.Re() == 4);
			REQUIRE(complexSum.Im() == -2);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Binary multiplication test")
	{
		cout << "Binary multiplication test" << endl;
		WHEN("complex * complex")
		{
			cout << "complex * complex" << endl;
			CComplex complexSum = CComplex(1, 2) * CComplex(1, 1);
			REQUIRE(complexSum.Re() == -1);
			REQUIRE(complexSum.Im() == 3);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex * real")
		{
			cout << "complex * real" << endl;
			CComplex complexSum = CComplex(1, 2) * 5;
			REQUIRE(complexSum.Re() == 5);
			REQUIRE(complexSum.Im() == 10);
			cout << TEST_PASSED << endl;
		}

		WHEN("real * complex")
		{
			cout << "real * complex" << endl;
			CComplex complexSum = 5 * CComplex(1, 2);
			REQUIRE(complexSum.Re() == 5);
			REQUIRE(complexSum.Im() == 10);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Binary divicion test")
	{
		cout << "Binary divicion test" << endl;
		WHEN("When the second complex or real is not equal zero")
		{
			WHEN("complex / complex")
			{
				cout << "complex / complex" << endl;
				CComplex complexSum = CComplex(1, 2) / CComplex(1, 1);
				REQUIRE(complexSum.Re() == 1.5);
				REQUIRE(complexSum.Im() == 0.5);
				cout << TEST_PASSED << endl;
			}

			WHEN("complex / real")
			{
				cout << "complex / real" << endl;
				CComplex complexSum = CComplex(1, 2) / 5;
				REQUIRE(complexSum.Re() == 1);
				REQUIRE(complexSum.Im() == 2);
				cout << TEST_PASSED << endl;
			}

			WHEN("real / complex")
			{
				cout << "real / complex" << endl;
				CComplex complexSum = 5 / CComplex(1, 2);
				REQUIRE(complexSum.Re() == 1);
				REQUIRE(complexSum.Im() == -2);
				cout << TEST_PASSED << endl;
			}
		}

		WHEN("When the second complex or real is equal zero")
		{
			CComplex complexSum = CComplex(1, 2) / 0;
			REQUIRE(complexSum.Re() == 1);
			REQUIRE(complexSum.Im() == 2);
			cout << TEST_PASSED << endl;
		}		
	}

	GIVEN("Unary operators test")
	{
		cout << "Unary operators test" << endl;
		WHEN("Unary +")
		{
			cout << "Unary +" << endl;
			CComplex complexSum = +CComplex(1, 2);
			REQUIRE(complexSum.Re() == 1);
			REQUIRE(complexSum.Im() == 2);
			cout << TEST_PASSED << endl;
		}

		WHEN("Unary -")
		{
			cout << "Unary -" << endl;
			CComplex complexSum = -CComplex(1, 2);
			REQUIRE(complexSum.Re() == -1);
			REQUIRE(complexSum.Im() == -2);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Operator += test")
	{
		cout << "Operator += test" << endl;
		CComplex complex1(1, 2);
		complex1 += CComplex(1, 1);
		REQUIRE(complex1.Re() == 2);
		REQUIRE(complex1.Im() == 3);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Operator -= test")
	{
		cout << "Operator -= test" << endl;
		CComplex complex1(1, 2);
		complex1 -= CComplex(1, 1);
		REQUIRE(complex1.Re() == 0);
		REQUIRE(complex1.Im() == 1);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Operator *= test")
	{
		cout << "Operator *= test" << endl;
		CComplex complex1(1, 2);
		complex1 *= CComplex(1, 1);
		REQUIRE(complex1.Re() == -1);
		REQUIRE(complex1.Im() == 1);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Operator /= test")
	{
		cout << "Operator /= test" << endl;
		WHEN("Second operand is equal 0")
		{
			cout << "Second operand is equal 0" << endl;
			CComplex complex1(1, 2);
			complex1 /= CComplex(0, 0);
			REQUIRE(complex1.Re() == 1);
			REQUIRE(complex1.Im() == 2);
			cout << TEST_PASSED << endl;
		}

		WHEN("Second operand is not equal 0")
		{
			cout << "Second operand is not equal 0" << endl;
			CComplex complex1(1, 2);
			complex1 /= CComplex(1, 1);
			REQUIRE(complex1.Re() == 1.5);
			REQUIRE(complex1.Im() == 0.25);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Comparison operator test")
	{
		cout << "Comparison operator test" << endl;
		WHEN("complex == complex")
		{
			cout << "complex == complex" << endl;
			bool isEqual = CComplex(1, 1) == CComplex(1, 1);
			REQUIRE(isEqual == true);
			isEqual = CComplex(1, 2) == CComplex(1, 1);
			REQUIRE(isEqual == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex == real")
		{
			cout << "complex == real" << endl;
			bool isEqual = CComplex(1, 0) == 1;
			REQUIRE(isEqual == true);
			isEqual = CComplex(1, 2) == 1;
			REQUIRE(isEqual == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("real == complex")
		{
			cout << "real == complex" << endl;
			bool isEqual = 1 == CComplex(1, 0);
			REQUIRE(isEqual == true);
			isEqual = 1 == CComplex(1, 2);
			REQUIRE(isEqual == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex != complex")
		{
			cout << "complex != complex" << endl;
			bool isNotEqual = CComplex(1, 1) != CComplex(1, 1);
			REQUIRE(isNotEqual == false);
			isNotEqual = CComplex(1, 2) != CComplex(1, 1);
			REQUIRE(isNotEqual == true);
			cout << TEST_PASSED << endl;
		}

		WHEN("complex != real")
		{
			cout << "complex != real" << endl;
			bool isNotEqual = CComplex(1, 0) != 1;
			REQUIRE(isNotEqual == false);
			isNotEqual = CComplex(1, 2) != 1;
			REQUIRE(isNotEqual == true);
			cout << TEST_PASSED << endl;
		}

		WHEN("real != complex")
		{
			cout << "real != complex" << endl;
			bool isNotEqual = 1 != CComplex(1, 0);
			REQUIRE(isNotEqual == false);
			isNotEqual = 1 != CComplex(1, 2);
			REQUIRE(isNotEqual == true);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Stream output operator")
	{
		cout << "Stream output operator" << endl;
		stringstream streamStr;
		CComplex complex1(1, 2);
		streamStr << complex1;
		REQUIRE(streamStr.str() == "1+2i");

		stringstream().swap(streamStr);
		CComplex complex2(-1, -2);
		streamStr << complex2;
		REQUIRE(streamStr.str() == "-1-2i");

		stringstream().swap(streamStr);
		CComplex complex3;
		streamStr << complex3;
		REQUIRE(streamStr.str() == "0+0i");
	}

	GIVEN("Stream input operator")
	{
		cout << "Stream input operator" << endl;
		stringstream streamStr;
		streamStr << "1+1i";
		CComplex complex1;
		streamStr >> complex1;
		REQUIRE(complex1 == CComplex(1, 1));

		stringstream().swap(streamStr);
		streamStr << "-1.555+888888888888888888888888888.555i";
		CComplex complex2;
		streamStr >> complex2;
		REQUIRE(complex2 == CComplex(-1.555, 888888888888888888888888888.555));

		stringstream().swap(streamStr);
		streamStr << "0-888888888888888888888888888i";
		CComplex complex3;
		streamStr >> complex3;
		REQUIRE(complex3 == CComplex(0, -888888888888888888888888888.0));

		stringstream().swap(streamStr);
		streamStr << "-10.25-12.5i";
		CComplex complex4;
		streamStr >> complex4;
		REQUIRE(complex4 == CComplex(-10.25, -12.5));

		stringstream().swap(streamStr);
		streamStr << "10i";
		CComplex complex5;
		streamStr >> complex5;
		REQUIRE(complex5 == CComplex(0, 0));

		stringstream().swap(streamStr);
		streamStr << "adasdasdasdas";
		streamStr >> complex5;
		REQUIRE(complex5 == CComplex(0, 0));
	}
}