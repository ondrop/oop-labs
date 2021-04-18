#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"

const string U_CIRCLE = "Circle";
const string CENTER = "Center: ";
const string RADIUS = "Radius: ";

class CCircle : public ISolidShape
{
public:
	CCircle(const CPoint& center, double radius, uint32_t fillColor = WHITE_COLOR, uint32_t outlineColor = BLACK_COLOR);
	~CCircle();

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	string ConvertColorToHex(uint32_t color) const;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
};
