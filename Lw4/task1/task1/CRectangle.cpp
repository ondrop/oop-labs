#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, double width, double height, uint32_t fillColor, uint32_t outlineColor)
	:m_leftTop(leftTop),
	m_rightBottom(rightBottom),
	m_width(width),
	m_height(height),
	ISolidShape(outlineColor, fillColor)
{
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}

string CRectangle::ToString() const
{
	stringstream streamStr;
	streamStr << U_RECTANGLE << endl;
	streamStr << AREA << GetArea() << setprecision(THREE) << fixed << endl;
	streamStr << PERIMETER << GetPerimeter() << setprecision(THREE) << fixed << endl;
	streamStr << OUTLINE_COLOR << ConvertColorToHex(GetOutlineColor()) << endl;
	streamStr << FILL_COLOR << ConvertColorToHex(GetFillColor()) << endl;
	streamStr << LEFT_TOP_POINT << GetLeftTop().GetCoordinateX() << ' ' << GetLeftTop().GetCoordinateY() << endl;
	streamStr << RIGHT_BOTTOM_POINT << GetRightBottom().GetCoordinateX() << ' ' << GetRightBottom().GetCoordinateY() << endl;
	streamStr << WIDTH << GetWidth() << endl;
	streamStr << HEIGHT << GetHeight() << endl;

	return streamStr.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

string CRectangle::ConvertColorToHex(uint32_t color) const
{
	stringstream hexColor;
	hexColor << setfill('0') << setw(6) << hex << color;

	return hexColor.str();
}
