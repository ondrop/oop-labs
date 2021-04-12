#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task1/CommandProcessing.h"

const string TEST_PASSED = "Test passed successfully";

SCENARIO("TurnOnEngine and public const functions")
{
	cout << "Test TurnOnEngine and public const functions" << endl;
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetSpeed() == 0);
	REQUIRE(car.GetDirection() == Direction::STAY);
	cout << TEST_PASSED << endl;
}

SCENARIO("TurnOffEngine")
{
	cout << "Test TurnOffEngine" << endl;
	Car car;
	WHEN("Engine is off")
	{
		cout << "Engine is off" << endl;
		REQUIRE(car.TurnOffEngine() == true);
		cout << TEST_PASSED << endl;
	}

	car.TurnOnEngine();
	WHEN("Gear = 0 and Speed = 0")
	{
		cout << "Gear = 0 and Speed = 0" << endl;
		REQUIRE(car.TurnOffEngine() == true);
		cout << TEST_PASSED << endl;
	}

	WHEN("Gear != 0 and Speed = 0")
	{
		cout << "Gear != 0 and Speed = 0" << endl;
		car.SetGear(1);
		REQUIRE(car.TurnOffEngine() == false);
		cout << TEST_PASSED << endl;
	}

	WHEN("Gear != 0 and Speed != 0")
	{
		cout << "Gear != 0 and Speed != 0" << endl;
		car.SetGear(1);
		car.SetSpeed(20);
		REQUIRE(car.TurnOffEngine() == false);
		cout << TEST_PASSED << endl;
	}

	WHEN("Gear == 0 and Speed != 0")
	{
		cout << "Gear != 0 and Speed != 0" << endl;
		car.SetGear(1);
		car.SetSpeed(20);
		car.SetGear(0);
		REQUIRE(car.TurnOffEngine() == false);
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("SetGear and SetSpeed")
{
	cout << "Test SetGear and SetSpeed" << endl;
	Car car;
	GIVEN("Engine is off")
	{
		cout << "Engine is off" << endl;
		WHEN("Gear set 1")
		{
			cout << "Gear set 1" << endl;
			REQUIRE(car.SetGear(1) == false);
			cout << TEST_PASSED << endl;
		}

		WHEN("Gear set 0")
		{
			cout << "Gear set 0" << endl;
			REQUIRE(car.SetGear(0) == true);
			cout << TEST_PASSED << endl;
		}
	}

	car.TurnOnEngine();

	GIVEN("Engine is on")
	{
		cout << "Engine is on" << endl;
		cout << "Set gear -2" << endl;
		REQUIRE(car.SetGear(-2) == false);
		cout << "Set gear -1" << endl;
		REQUIRE(car.SetGear(-1) == true);
		cout << TEST_PASSED << endl;

		cout << "Set gear 0 when speed == 0 and prev gear -1" << endl;
		REQUIRE(car.SetGear(0) == true);
		cout << TEST_PASSED << endl;

		car.SetGear(-1);

		cout << "Set gear 0 when speed != 0 and prev gear -1" << endl;
		REQUIRE(car.SetSpeed(10) == true);
		REQUIRE(car.SetGear(0) == true);
		REQUIRE(car.GetDirection() == Direction::BACK);
		cout << "Try set gear 1 when speed != 0 and gear = 0" << endl;
		REQUIRE(car.SetGear(1) == false);
		cout << "Try set gear -1 when speed != 0 and gear = 0" << endl;
		REQUIRE(car.SetGear(-1) == false);
		cout << TEST_PASSED << endl;

		car.SetSpeed(0);
		car.SetGear(0);

		cout << "Set speed 200" << endl;
		REQUIRE(car.SetSpeed(200) == false);
		cout << "Set speed -10" << endl;
		REQUIRE(car.SetSpeed(-10) == false);

		cout << "Speed equal 0" << endl;
		REQUIRE(car.SetSpeed(0) == true);
		cout << "Set Gear 1" << endl;
		REQUIRE(car.SetGear(1) == true);
		cout << "Test direction" << endl;
		REQUIRE(car.GetDirection() == Direction::STAY);
		cout << TEST_PASSED << endl;

		cout << "Set speed 30" << endl;
		REQUIRE(car.SetSpeed(30) == true);
		cout << "Set speed 40" << endl;
		REQUIRE(car.SetSpeed(40) == false);
		cout << "Set Gear 2" << endl;
		REQUIRE(car.SetGear(2) == true);
		cout << "Test direction" << endl;
		REQUIRE(car.GetDirection() == Direction::FORWARD);
		cout << TEST_PASSED << endl;

		cout << "Set speed 10" << endl;
		REQUIRE(car.SetSpeed(10) == false);
		cout << "Set speed 20" << endl;
		REQUIRE(car.SetSpeed(20) == true);
		cout << "Set speed 50" << endl;
		REQUIRE(car.SetSpeed(50) == true);
		cout << "Set speed 60" << endl;
		REQUIRE(car.SetSpeed(60) == false);
		cout << "Set Gear 3" << endl;
		REQUIRE(car.SetGear(3) == true);
		cout << TEST_PASSED << endl;

		cout << "Set speed 20" << endl;
		REQUIRE(car.SetSpeed(20) == false);
		cout << "Set speed 30" << endl;
		REQUIRE(car.SetSpeed(30) == true);
		cout << "Set speed 60" << endl;
		REQUIRE(car.SetSpeed(60) == true);
		cout << "Set speed 70" << endl;
		REQUIRE(car.SetSpeed(70) == false);
		cout << "Set Gear 4" << endl;
		REQUIRE(car.SetGear(4) == true);
		cout << TEST_PASSED << endl;

		cout << "Set speed 30" << endl;
		REQUIRE(car.SetSpeed(30) == false);
		cout << "Set speed 40" << endl;
		REQUIRE(car.SetSpeed(40) == true);
		cout << "Set speed 90" << endl;
		REQUIRE(car.SetSpeed(90) == true);
		cout << "Set speed 100" << endl;
		REQUIRE(car.SetSpeed(100) == false);
		cout << "Set Gear 5" << endl;
		REQUIRE(car.SetGear(5) == true);
		cout << TEST_PASSED << endl;

		cout << "Set speed 40" << endl;
		REQUIRE(car.SetSpeed(40) == false);
		cout << "Set speed 50" << endl;
		REQUIRE(car.SetSpeed(50) == true);
		cout << "Set speed 150" << endl;
		REQUIRE(car.SetSpeed(150) == true);
		cout << "Set speed 200" << endl;
		REQUIRE(car.SetSpeed(200) == false);
		cout << "Set Gear 6" << endl;
		REQUIRE(car.SetGear(6) == false);
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test GetCarInfo method")
{
	Car car;
	WHEN("Car's engine off")
	{
		cout << "Car's engine off" << endl;
		CarInfo expectedCarInfo = { false, "Stay", 0, 0 };
		CarInfo carInfo = car.GetCarInfo();
		REQUIRE(expectedCarInfo.isEngineOn == carInfo.isEngineOn);
		REQUIRE(expectedCarInfo.direction == carInfo.direction);
		REQUIRE(expectedCarInfo.gear == carInfo.gear);
		REQUIRE(expectedCarInfo.speed == carInfo.speed);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Car's engine on")
	{
		WHEN("Gear more than 0")
		{
			CarInfo expectedCarInfo = { true, "Forward", 10, 1 };
			car.TurnOnEngine();
			car.SetGear(1);
			car.SetSpeed(10);
			CarInfo carInfo = car.GetCarInfo();
			REQUIRE(expectedCarInfo.isEngineOn == carInfo.isEngineOn);
			REQUIRE(expectedCarInfo.direction == carInfo.direction);
			REQUIRE(expectedCarInfo.gear == carInfo.gear);
			REQUIRE(expectedCarInfo.speed == carInfo.speed);
			cout << TEST_PASSED << endl;
		}

		WHEN("Gear equal -1")
		{
			CarInfo expectedCarInfo = { true, "Back", 10, -1 };
			car.TurnOnEngine();
			car.SetGear(-1);
			car.SetSpeed(10);
			CarInfo carInfo = car.GetCarInfo();
			REQUIRE(expectedCarInfo.isEngineOn == carInfo.isEngineOn);
			REQUIRE(expectedCarInfo.direction == carInfo.direction);
			REQUIRE(expectedCarInfo.gear == carInfo.gear);
			REQUIRE(expectedCarInfo.speed == carInfo.speed);
			cout << TEST_PASSED << endl;
		}
	}
}

SCENARIO("Test CommandProcessing")
{
	cout << "Test CommandProcessing" << endl;
	GIVEN("Test GetCommand")
	{
		cout << "Test GetCommand" << endl;
		CommandData expectedCommandData;
		WHEN("Command is \"Info\"")
		{
			cout << "Command is \"Info\"" << endl;
			expectedCommandData = { "Info", 0 };
			auto commandData = GetCommandData("Info", cout);
			REQUIRE(expectedCommandData.command == commandData->command);
			REQUIRE(expectedCommandData.param == commandData->param);
			cout << TEST_PASSED << endl;
		}

		WHEN("Command is \"SetGear\"")
		{
			cout << "Command with param" << endl;
			cout << "Command is \"SetGear\"" << endl;
			expectedCommandData = { "SetGear", 1 };
			auto commandData = GetCommandData("SetGear 1", cout);
			REQUIRE(expectedCommandData.command == commandData->command);
			REQUIRE(expectedCommandData.param == commandData->param);
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Test GetParam")
	{
		cout << "Test GetParam" << endl;
		stringstream streamStr;
		int param;
		WHEN("Param is too large")
		{
			param = 0;
			streamStr << " 88888888888888888888888";
			bool paramValid = GetCommandParam(streamStr, param, cout);
			REQUIRE(paramValid == false);
			REQUIRE(param == 0);
			cout << TEST_PASSED << endl;
		}

		WHEN("Param is 1")
		{
			param = 1;
			streamStr << " 1";
			bool paramValid = GetCommandParam(streamStr, param, cout);
			REQUIRE(paramValid == true);
			REQUIRE(param == 1);
			cout << TEST_PASSED << endl;
		}

		WHEN("Param is too large negative number")
		{
			param = 0;
			streamStr << " -88888888888888888888888888";
			bool paramValid = GetCommandParam(streamStr, param, cout);
			REQUIRE(paramValid == false);
			REQUIRE(param == 0);
			cout << TEST_PASSED << endl;
		}

		WHEN("Param is non number symbol")
		{
			param = 0;
			streamStr << " abs";
			bool paramValid = GetCommandParam(streamStr, param, cout);
			REQUIRE(paramValid == false);
			REQUIRE(param == 0);
			cout << TEST_PASSED << endl;
		}
	}
}