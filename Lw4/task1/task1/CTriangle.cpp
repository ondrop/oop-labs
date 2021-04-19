#include "CTriangle.h"

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, uint32_t fillColor, uint32_t outlineColor)
	:m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3),
	ISolidShape(outlineColor, fillColor)
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetArea() const
{	double halfOfPerimeter = GetPerimeter() / 2;

	CLineSegment AB(GetVertex1(), GetVertex2());
	CLineSegment AC(GetVertex1(), GetVertex3());
	CLineSegment BC(GetVertex2(), GetVertex3());

	double ABLength = AB.GetPerimeter();
	double ACLength = AC.GetPerimeter();
	double BCLength = BC.GetPerimeter();

	return sqrt(halfOfPerimeter * (halfOfPerimeter - ABLength) * (halfOfPerimeter - ACLength) * (halfOfPerimeter - BCLength));
}

double CTriangle::GetPerimeter() const
{
	CLineSegment AB(GetVertex1(), GetVertex2());
	CLineSegment AC(GetVertex1(), GetVertex3());
	CLineSegment BC(GetVertex2(), GetVertex3());

	double ABLength = AB.GetPerimeter();
	double ACLength = AC.GetPerimeter();
	double BCLength = BC.GetPerimeter();

	return ABLength + ACLength + BCLength;
}

string CTriangle::ToString() const
{
	stringstream streamStr;
	streamStr << U_TRIANGLE << endl;
	streamStr << AREA << GetArea() << setprecision(THREE) << fixed << endl;
	streamStr << PERIMETER << GetPerimeter() << setprecision(THREE) << fixed << endl;
	streamStr << OUTLINE_COLOR << ConvertColorToHex(GetOutlineColor()) << endl;
	streamStr << FILL_COLOR << ConvertColorToHex(GetFillColor()) << endl;
	streamStr << VERTEX_1 << GetVertex1().GetCoordinateX() << ' ' << GetVertex1().GetCoordinateY() << endl;
	streamStr << VERTEX_2 << GetVertex2().GetCoordinateX() << ' ' << GetVertex2().GetCoordinateY() << endl;
	streamStr << VERTEX_3 << GetVertex3().GetCoordinateX() << ' ' << GetVertex3().GetCoordinateY() << endl;

	return streamStr.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

string CTriangle::ConvertColorToHex(uint32_t color) const
{
	stringstream hexColor;
	hexColor << setfill('0') << setw(HEX_DIMENSION) << hex << color;

	return hexColor.str();
}
