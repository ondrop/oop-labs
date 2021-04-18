#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
	:m_startPoint(startPoint),
	m_endPoint(endPoint),
	IShape(outlineColor)
{
}

CLineSegment::~CLineSegment()
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();

	return sqrt(pow(startPoint.GetCoordinateX() - endPoint.GetCoordinateX(), 2) + pow(startPoint.GetCoordinateY() - endPoint.GetCoordinateY(), 2));
}

string CLineSegment::ToString() const
{
	stringstream streamStr;
	streamStr << U_LINE << endl;
	streamStr << AREA << GetArea() << setprecision(THREE) << fixed << endl;
	streamStr << PERIMETER << GetPerimeter() << setprecision(THREE) << fixed << endl;
	streamStr << OUTLINE_COLOR << ConvertColorToHex(GetOutlineColor()) << endl;
	streamStr << START_POINT << GetStartPoint().GetCoordinateX() << ' ' << GetStartPoint().GetCoordinateY() << endl;
	streamStr << END_POINT << GetEndPoint().GetCoordinateX() << ' ' << GetEndPoint().GetCoordinateY() << endl;

	return streamStr.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

string CLineSegment::ConvertColorToHex(uint32_t color) const
{
	stringstream hexColor;
	hexColor << setfill('0') << setw(6) << hex << color;

	return hexColor.str();
}
