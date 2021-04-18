#pragma once

class CPoint
{
public:
	CPoint(double x, double y);
	~CPoint();

	double GetCoordinateX() const;
	double GetCoordinateY() const;
	bool SetCoordinateX(double x);
	bool SetCoordinateY(double y);

private:
	double m_x;
	double m_y;
};
