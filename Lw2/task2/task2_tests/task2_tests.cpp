#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task2/StringProcessor.h"

SCENARIO("Decode Html string")
{
	string workStr;
	string expectedStr;
	cout << "Test: ";
	GIVEN("Non empty string received")
	{
		WHEN("String contains one encode symbol")
		{
			cout << "String contains one encode symbol" << endl;
			workStr = "Cat &lt;says";
			expectedStr = "Cat <says";
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}

		WHEN("String contains few encode symbols")
		{
			cout << "String contains few encode symbols" << endl;
			workStr = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
			expectedStr = "Cat <says> \"Meow\". M&M's";
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}

		WHEN("String doesn't contain encode symbols")
		{
			cout << "String doesn't contain encode symbols" << endl;
			workStr = "Cat &;says test& &message;";
			expectedStr = workStr;
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}

		WHEN("String contains only one encode symbol")
		{
			cout << "String contains only one encode symbol" << endl;
			workStr = "&lt;";
			expectedStr = "<";
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}

		WHEN("String contains only encode symbols")
		{
			cout << "String contains only encode symbols" << endl;
			workStr = "&quot;&apos;&lt;&gt;&amp;";
			expectedStr = "\"'<>&";
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}

		WHEN("String contains where semicolon stay before ampersand")
		{
			cout << "String contains where semicolon stay before ampersand" << endl;
			workStr = ";sadsa&";
			expectedStr = workStr;
			REQUIRE(HtmlDecode(workStr) == expectedStr);
		}
	}

	GIVEN("Empty string received")
	{
		cout << "Empty string received" << endl;
		workStr = "";
		REQUIRE(CheckEmptyString(workStr) == false);
	}
}