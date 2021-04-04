#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task3/DictionaryProcessing.h"

SCENARIO("Test ParseArgs function")
{
	string workStr;
	string expectedStr;
	cout << "Test: ";
	GIVEN("Invalid arguments count")
	{
		int argc = 1;
		char* argv[] = { {} };
		cout << "Given invalid arguments count" << endl;
		REQUIRE(ParseArgs(argc, argv) == nullopt);
	}
}

SCENARIO("Tets DeserializeDictionary function")
{
	cout << "Test: ";
	string dictionaryFileName;
	GIVEN("Given file doesn't exist")
	{
		cout << "Given file doesn't exist" << endl;
		dictionaryFileName = "missingDictionary.txt";
		map<string, string> dictionary = DeserializeDictionary(dictionaryFileName);
		REQUIRE(dictionary.empty() == true);		
	}

	GIVEN("Given file exist")
	{
		cout << "Given file exist" << endl;
		dictionaryFileName = "dictionary.txt";
		map<string, string> dictionary = DeserializeDictionary(dictionaryFileName);
		REQUIRE(dictionary.empty() == false);

	}

	GIVEN("Given empty dictionary")
	{
		cout << "Given empty dictionary" << endl;
		dictionaryFileName = "dictionary2.txt";
		map<string, string> dictionary = DeserializeDictionary(dictionaryFileName);
		REQUIRE(dictionary.empty() == true);
	}
}

SCENARIO("Tets UseDictionary function")
{
	cout << "Test: ";
	string dictionaryFileName = "dictionary.txt";
	GIVEN("Give the translation")
	{
		WHEN("Entered word is same as dictionary key")
		{
			cout << "Entered word is same as dictionary key" << endl;
			map<string, string> dictionary = {
				{"mom", "мама"}
			};
			map<string, string> expectedDictionary = dictionary;

			ifstream testDialogIn;
			dictionaryFileName = "./TestDialogs/dialog1out.txt";
			testDialogIn.open("./TestDialogs/dialog1.txt");
			ofstream testDialogOut;
			testDialogOut.open(dictionaryFileName);

			auto outDictionary = UseDictionary(testDialogIn, testDialogOut, dictionary, dictionaryFileName);
			REQUIRE(outDictionary == expectedDictionary);
		}

		WHEN("Entered word is same as dictionary key but uppercase")
		{
			cout << "Entered word is same as dictionary key but uppercase" << endl;
			map<string, string> dictionary = {
				{"mom", "мама"}
			};
			map<string, string> expectedDictionary = dictionary;

			ifstream testDialogIn;
			dictionaryFileName = "./TestDialogs/dialog5out.txt";
			testDialogIn.open("./TestDialogs/dialog5.txt");
			ofstream testDialogOut;
			testDialogOut.open(dictionaryFileName);

			auto outDictionary = UseDictionary(testDialogIn, testDialogOut, dictionary, dictionaryFileName);
			REQUIRE(outDictionary == expectedDictionary);

		}
	}

	GIVEN("Add value to dictionary")
	{
		cout << "Add value to dictionary" << endl;
		map<string, string> dictionary = {
			{"mom", "мама"}
		};
		map<string, string> expectedDictionary = {
			{"mom", "мама"},
			{"test", "test1"}
		};

		ifstream testDialogIn;
		dictionaryFileName = "./TestDialogs/dialog2out.txt";
		testDialogIn.open("./TestDialogs/dialog2.txt");
		ofstream testDialogOut;
		testDialogOut.open(dictionaryFileName);

		auto outDictionary = UseDictionary(testDialogIn, testDialogOut, dictionary, dictionaryFileName);
		REQUIRE(outDictionary == expectedDictionary);
	}

	GIVEN("Add value to dictionary but don't save")
	{
		cout << "Add value to dictionary but don't save" << endl;
		map<string, string> dictionary = {
			{"mom", "мама"}
		};
		map<string, string> expectedDictionary = dictionary;

		ifstream testDialogIn;
		dictionaryFileName = "./TestDialogs/dialog3out.txt";
		testDialogIn.open("./TestDialogs/dialog3.txt");
		ofstream testDialogOut;
		testDialogOut.open(dictionaryFileName);

		auto outDictionary = UseDictionary(testDialogIn, testDialogOut, dictionary, dictionaryFileName);
		REQUIRE(outDictionary == expectedDictionary);
	}

	GIVEN("Enter new word but translation didn't enter")
	{
		cout << "Enter new word but translation didn't enter" << endl;
		map<string, string> dictionary = {
			{"mom", "мама"}
		};
		map<string, string> expectedDictionary = dictionary;

		ifstream testDialogIn;
		dictionaryFileName = "./TestDialogs/dialog4out.txt";
		testDialogIn.open("./TestDialogs/dialog4.txt");
		ofstream testDialogOut;
		testDialogOut.open(dictionaryFileName);

		auto outDictionary = UseDictionary(testDialogIn, testDialogOut, dictionary, dictionaryFileName);
		REQUIRE(outDictionary == expectedDictionary);
	}
}