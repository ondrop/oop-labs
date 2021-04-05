#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task5/UrlProcessing.h"

const string TEST_PASSED = "Test passed successfully";

SCENARIO("Test GetPort functions")
{
	cout << "Test: ";
	string protocol, givenPort;
	GIVEN("Url doesn't contain port")
	{
		cout << "Url doesn't contain port" << endl;
		protocol = "http";
		givenPort = "";
		int expectedPort = 80;
		int port = GetPort(protocol, givenPort);
		REQUIRE(port == expectedPort);	
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url contain port")
	{
		cout << "Url contain port" << endl;
		protocol = "http";
		givenPort = "8000";
		int expectedPort = 8000;
		int port = GetPort(protocol, givenPort);
		REQUIRE(port == expectedPort);
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test ParseUrl functions")
{
	cout << "Test: ";
	string url;
	UrlInfo urlinfo;
	UrlInfo expectedUrlinfo;
	GIVEN("Url with ftp protocol")
	{
		cout << "Url with ftp protocol" << endl;
		expectedUrlinfo = {
			"www.mysite.com",
			21,
			"docs/document1.html?page=30&lang=en#title"
		};

		url = "ftp://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		bool validUrl = ParseURL(url, urlinfo);
		REQUIRE(validUrl == true);
		REQUIRE(urlinfo.host == expectedUrlinfo.host);
		REQUIRE(urlinfo.port == expectedUrlinfo.port);
		REQUIRE(urlinfo.document == expectedUrlinfo.document);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url with http protocol")
	{
		cout << "Url with http protocol" << endl;
		expectedUrlinfo = {
			"www.mysite.com",
			80,
			"docs/document1.html?page=30&lang=en#title"
		};

		url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		bool validUrl = ParseURL(url, urlinfo);
		REQUIRE(validUrl == true);
		REQUIRE(urlinfo.host == expectedUrlinfo.host);
		REQUIRE(urlinfo.port == expectedUrlinfo.port);
		REQUIRE(urlinfo.document == expectedUrlinfo.document);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url with https protocol")
	{
		cout << "Url with https protocol" << endl;
		expectedUrlinfo = {
			"www.mysite.com",
			443,
			"docs/document1.html?page=30&lang=en#title"
		};

		url = "https://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		bool validUrl = ParseURL(url, urlinfo);
		REQUIRE(validUrl == true);
		REQUIRE(urlinfo.host == expectedUrlinfo.host);
		REQUIRE(urlinfo.port == expectedUrlinfo.port);
		REQUIRE(urlinfo.document == expectedUrlinfo.document);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url with port")
	{
		cout << "Url with port" << endl;
		expectedUrlinfo = {
			"www.mysite.com",
			8000,
			"docs/document1.html?page=30&lang=en#title"
		};

		url = "https://www.mysite.com:8000/docs/document1.html?page=30&lang=en#title";
		bool validUrl = ParseURL(url, urlinfo);
		REQUIRE(validUrl == true);
		REQUIRE(urlinfo.host == expectedUrlinfo.host);
		REQUIRE(urlinfo.port == expectedUrlinfo.port);
		REQUIRE(urlinfo.document == expectedUrlinfo.document);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url without doc")
	{
		cout << "Url without doc" << endl;
		expectedUrlinfo = {
			"www.mysite.com",
			8000,
			""
		};

		url = "https://www.mysite.com:8000";
		bool validUrl = ParseURL(url, urlinfo);
		REQUIRE(validUrl == true);
		REQUIRE(urlinfo.host == expectedUrlinfo.host);
		REQUIRE(urlinfo.port == expectedUrlinfo.port);
		REQUIRE(urlinfo.document == expectedUrlinfo.document);
		cout << TEST_PASSED << endl;
	}
}