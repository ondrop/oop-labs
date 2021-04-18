#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"

const string U_RECTANGLE = "RECTANGLE";
const string LEFT_TOP_POINT = "Left top point: ";
const string RIGHT_BOTTOM_POINT = "Right bottom point: ";
const string WIDTH = "Width: ";
const string HEIGHT = "Height: ";

class CRectangle : public ISolidShape
{
public:
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, double width, double height, uint32_t fillColor = WHITE_COLOR, uint32_t outlineColor = BLACK_COLOR);
	~CRectangle();

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	string ConvertColorToHex(uint32_t color) const;

private:
	CPoint m_leftTop, m_rightBottom;
	double m_width, m_height;
};
