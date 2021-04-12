#include "Car.h"

struct SpeedRange
{
	int minSpeed;
	int maxSpeed;
};

map<int, SpeedRange> gear_speeds = {
	{ -1, { 0, 20 } },
	{ -0, { 0, 150 } },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } }
};

map<Direction, string> direction_by_string = {
	{ Direction::BACK, "Back" },
	{ Direction::FORWARD, "Forward" },
	{ Direction::STAY, "Stay" }
};

const int MIN_GEAR = -1;
const int MAX_GEAR = 5;

Car::Car()
	:m_speed(0), 
	m_gear(0), 
	m_isEngineOn(false), 
	m_direction(Direction::STAY)
{
}

Car::~Car()
{
}

int Car::GetSpeed() const
{
	return m_speed;
}

int Car::GetGear() const
{
	return m_gear;
}

Direction Car::GetDirection() const
{
	return m_direction;
}

bool Car::IsTurnedOn() const
{
	return m_isEngineOn;
}

bool Car::TurnOnEngine()
{
	if (!Car::IsTurnedOn())
	{
		m_isEngineOn = true;
	}

	return m_isEngineOn;
}

bool Car::TurnOffEngine()
{
	bool canTurnOff = Car::CanTurnOffEngine();
	if (canTurnOff)
	{
		m_isEngineOn = false;
		return true;
	}

	return false;
}

bool Car::CanTurnOffEngine() const
{
	if (Car::IsTurnedOn())
	{
		return Car::GetGear() == 0 && Car::GetDirection() == Direction::STAY;
	}

	return true;
}

bool Car::SetGear(int gear)
{
	bool canSetCear = Car::CanSetGear(gear);
	if (canSetCear)
	{
		m_gear = gear;
		return true;
	}

	return false;
}

void Car::SetDirection()
{
	int speed = Car::GetSpeed();
	int gear = Car::GetGear();
	if (speed != 0)
	{
		if (gear == MIN_GEAR)
		{
			m_direction = Direction::BACK;
		}
		else
		{
			m_direction = Direction::FORWARD;
		}
	}
	else
	{
		m_direction = Direction::STAY;
	}
}

bool Car::SetSpeed(int speed)
{
	bool canSetSpeed = Car::CanSetSpeed(speed);
	if (canSetSpeed)
	{
		m_speed = speed;
		Car::SetDirection();
		return true;
	}

	return false;
}

bool Car::CanSetSpeed(int speed) const
{
	int gear = Car::GetGear();
	if (Car::IsTurnedOn())
	{
		SpeedRange speeds = gear_speeds[gear];
		if (gear == 0)
		{
			int prevSpeed = Car::GetSpeed();
			if (prevSpeed >= speed && speed >= speeds.minSpeed && speed <= speeds.maxSpeed)
			{
				return true;
			}
			
			return false;
		}

		return speed >= speeds.minSpeed && speed <= speeds.maxSpeed;
	}
	else
	{
		return speed == 0;
	}
}

bool Car::CanSetGear(int gear) const
{
	if (Car::IsTurnedOn())
	{
		int speed = Car::GetSpeed();
		if (gear == MIN_GEAR)
		{
			return speed == 0;
		}
		else if (gear > MIN_GEAR && gear <= MAX_GEAR)
		{
			Direction direction = Car::GetDirection();
			if (direction == Direction::BACK)
			{
				if (gear == 0)
				{
					return true;
				}
				else if (gear == 1)
				{
					return speed == 0;
				}
			}

			SpeedRange speeds = gear_speeds[gear];
			return speed >= speeds.minSpeed && speed <= speeds.maxSpeed;
		}
		else
		{
			return false;
		}
	}
	else if (gear == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CarInfo Car::GetCarInfo() const
{
	CarInfo carInfo = {
		Car::IsTurnedOn(),
		direction_by_string[Car::GetDirection()],
		Car::GetSpeed(),
		Car::GetGear()
	};

	return carInfo;
}