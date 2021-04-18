#include "CPoint.h"

CPoint::CPoint(double x, double y)
	:m_x(x),
	m_y(y)
{

}

CPoint::~CPoint()
{
}

double CPoint::GetCoordinateX() const
{
	return m_x;
}

double CPoint::GetCoordinateY() const
{
	return m_y;
}

bool CPoint::SetCoordinateX(double x)
{
	m_x = x;

	return true;
}

bool CPoint::SetCoordinateY(double y)
{
	m_y = y;

	return true;
}
