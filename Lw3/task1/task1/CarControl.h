#pragma once
#include "stdafx.h"
#include "Car.h"

using namespace std;

const string INFO = "Info";
const string ENGINE_ON = "EngineOn";
const string ENGINE_OFF = "EngineOff";
const string SET_GEAR = "SetGear";
const string SET_SPEED = "SetSpeed";

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