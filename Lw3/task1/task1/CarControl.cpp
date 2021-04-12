#include "CarControl.h"

const string COMMAND = "Command \"";
const string NOT_FOUND = "\" not found";
const string UNABLE_TO_SET = "Unable to set ";
const string L_SPEED = "speed";
const string U_SPEED = "Speed";
const string SET = " has been set";
const string L_GEAR = "gear";
const string U_GEAR = "Gear";
const string ON = "On";
const string OFF = "Off";
const string CAR_INFO = "Car info";
const string ENGINE = "Engine: ";
const string DIRECTION = "Direction: ";
const string SPEED = "Speed: ";
const string GEAR = "Gear: ";
const string ENGINE_WORK = "The engine was on";
const string ENGINE_NOT_WORK = "The engine was off";
const string UNABLE_TO_TURN_ON_ENGINE = "Unable to turn on the engine";
const string UNABLE_TO_TURN_OFF_ENGINE = "Unable to turn off the engine";

CarControl::CarControl(Car& car, ostream& output)
	:m_car(car),
	m_output(output)
{
}

CarControl::~CarControl()
{
}

void CarControl::PrintInfo() const
{
	CarInfo carInfo = m_car.GetCarInfo();
	string engineState = carInfo.isEngineOn ? ON : OFF;
	m_output << CAR_INFO << endl;
	m_output << ENGINE << engineState << endl;
	m_output << DIRECTION << carInfo.direction << endl;
	m_output << SPEED << carInfo.speed << endl;
	m_output << GEAR << carInfo.gear << endl;
}

void CarControl::EngineOn() const
{
	bool canTurnEngine = m_car.TurnOnEngine();
	if (canTurnEngine)
	{
		m_output << ENGINE_WORK << endl;
	}
	else
	{
		m_output << UNABLE_TO_TURN_ON_ENGINE << endl;
	}
}

void CarControl::EngineOff() const
{
	bool canTurnEngine = m_car.TurnOffEngine();
	if (canTurnEngine)
	{
		m_output << ENGINE_NOT_WORK << endl;
	}
	else
	{
		m_output << UNABLE_TO_TURN_OFF_ENGINE << endl;
	}
}

void CarControl::SetGear(int gear) const
{
	bool canSetGear = m_car.SetGear(gear);
	if (canSetGear)
	{
		m_output << U_GEAR + SET << endl;
	}
	else
	{
		m_output << UNABLE_TO_SET + L_GEAR << endl;
	}
}

void CarControl::SetSpeed(int speed) const
{
	bool canSetSpeed = m_car.SetSpeed(speed);
	if (canSetSpeed)
	{
		m_output << U_SPEED + SET << endl;
	}
	else
	{
		m_output << UNABLE_TO_SET + L_SPEED << endl;
	}
}

void CarControl::CallCommand(string command, int param) const
{
	if (command == INFO)
	{
		CarControl::PrintInfo();
	}
	else if (command == ENGINE_ON)
	{
		CarControl::EngineOn();
	}
	else if (command == ENGINE_OFF)
	{
		CarControl::EngineOff();
	}
	else if (command == SET_GEAR)
	{
		CarControl::SetGear(param);
	}
	else if (command == SET_SPEED)
	{
		CarControl::SetSpeed(param);
	}
	else
	{
		m_output << COMMAND + command << NOT_FOUND << endl;
	}
}
