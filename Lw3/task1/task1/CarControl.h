#pragma once
#include "stdafx.h"
#include "Car.h"

using namespace std;

const string INFO = "Info";
const string ENGINE_ON = "EngineOn";
const string ENGINE_OFF = "EngineOff";
const string SET_GEAR = "SetGear";
const string SET_SPEED = "SetSpeed";
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

struct Command
{
	string command;
	int param;
};

class CarControl
{
public:
	CarControl(Car& car, ostream& output);
	~CarControl();

	void PrintInfo() const;
	void EngineOn() const;
	void EngineOff() const;
	void SetGear(int gear) const;
	void SetSpeed(int speed) const;
	void CallCommand(string command, int param) const;

private:
	Car& m_car;
	ostream& m_output;
};