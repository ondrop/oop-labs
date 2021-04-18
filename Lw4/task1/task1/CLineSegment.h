#pragma once
#include "stdafx.h"
#include "CPoint.h"
#include "IShape.h"

const string U_LINE = "Line";
const string START_POINT = "Start point: ";
const string END_POINT = "End point: ";

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor = BLACK_COLOR);
	~CLineSegment();

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	string ConvertColorToHex(uint32_t color) const;

private:
	CPoint m_startPoint, m_endPoint;
};
