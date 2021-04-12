#pragma once
#include "stdafx.h"

using namespace std;

enum class Direction
{
	FORWARD,
	STAY,
	BACK
};

struct CarInfo
{
	bool isEngineOn;
	string direction;
	int speed;
	int gear;
};

class Car
{
public:

	Car();
	~Car();

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	CarInfo GetCarInfo() const;
	
private:
	int m_gear;
	Direction m_direction;
	int m_speed;
	bool m_isEngineOn;

	bool CanSetSpeed(int speed) const;
	bool CanSetGear(int gear) const;
	bool CanTurnOffEngine() const;
	void SetDirection();
};