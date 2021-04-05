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
		int port = 0;
		bool isPortVaild = GetPort(protocol, givenPort, port);
		REQUIRE(port == expectedPort);
		REQUIRE(isPortVaild == true);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Url contain port")
	{
		cout << "Url contain port" << endl;
		protocol = "http";
		givenPort = "8000";
		int expectedPort = 8000;
		int port = 0;
		bool isPortVaild = GetPort(protocol, givenPort, port);
		REQUIRE(port == expectedPort);
		REQUIRE(isPortVaild == true);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Port is equal 1")
	{
		cout << "Port is equal 1" << endl;
		protocol = "http";
		givenPort = "1";
		int expectedPort = 1;
		int port = 0;
		bool isPortVaild = GetPort(protocol, givenPort, port);
		REQUIRE(isPortVaild == true);
		REQUIRE(port == expectedPort);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Port is equal 65535")
	{
		cout << "Port is equal 65535" << endl;
		protocol = "http";
		givenPort = "65535";
		int expectedPort = 65535;
		int port = 0;
		bool isPortVaild = GetPort(protocol, givenPort, port);
		REQUIRE(isPortVaild == true);
		REQUIRE(port == expectedPort);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Port is out of range")
	{
		WHEN("Port is equal negative number")
		{
			cout << "Port is equal negative number" << endl;
			protocol = "http";
			givenPort = "-1";
			int port = 0;
			bool isPortVaild = GetPort(protocol, givenPort, port);
			REQUIRE(isPortVaild == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("Port is equal 0")
		{
			cout << "Port is equal 0" << endl;
			protocol = "http";
			givenPort = "0";
			int port = 0;
			bool isPortVaild = GetPort(protocol, givenPort, port);
			REQUIRE(isPortVaild == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("Port is equal 65536")
		{
			cout << "Port is equal 65536" << endl;
			protocol = "http";
			givenPort = "65536";
			int port = 0;
			bool isPortVaild = GetPort(protocol, givenPort, port);
			REQUIRE(isPortVaild == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("Port is equal 888888888888888888888888")
		{
			cout << "Port is equal 888888888888888888888888" << endl;
			protocol = "http";
			givenPort = "888888888888888888888888";
			int port = 0;
			bool isPortVaild = GetPort(protocol, givenPort, port);
			REQUIRE(isPortVaild == false);
			cout << TEST_PASSED << endl;
		}
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