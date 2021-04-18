#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

const string U_TRIANGLE = "Triangle";
const string VERTEX_1 = "Vertex 1: ";
const string VERTEX_2 = "Vertex 2: ";
const string VERTEX_3 = "Vertex 3: ";

class CTriangle : public ISolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, uint32_t fillColor = WHITE_COLOR, uint32_t outlineColor = BLACK_COLOR);
	~CTriangle();

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	string ConvertColorToHex(uint32_t color) const;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
