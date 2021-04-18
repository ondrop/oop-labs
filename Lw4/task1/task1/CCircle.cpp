#include "CCircle.h"

CCircle::CCircle(const CPoint& center, double radius, uint32_t fillColor, uint32_t outlineColor)
	:m_center(center),
	m_radius(radius),
	ISolidShape(outlineColor, fillColor)
{
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(GetRadius(), 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * CCircle::GetRadius();
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

string CCircle::ToString() const
{
	stringstream streamStr;
	streamStr << U_CIRCLE << endl;
	streamStr << AREA << GetArea() << setprecision(THREE) << fixed << endl;
	streamStr << PERIMETER << GetPerimeter() << setprecision(THREE) << fixed << endl;
	streamStr << OUTLINE_COLOR << ConvertColorToHex(GetOutlineColor()) << endl;
	streamStr << FILL_COLOR << ConvertColorToHex(GetFillColor()) << endl;
	streamStr << CENTER << GetCenter().GetCoordinateX() << ' ' << GetCenter().GetCoordinateY() << endl;
	streamStr << RADIUS << GetRadius() << endl;

	return streamStr.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

string CCircle::ConvertColorToHex(uint32_t color) const
{
	stringstream hexColor;
	hexColor << setfill('0') << setw(6) << hex << color;

	return hexColor.str();
}
