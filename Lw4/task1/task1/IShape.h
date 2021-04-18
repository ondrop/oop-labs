#pragma once
#include "stdafx.h"

using namespace std;

const uint32_t BLACK_COLOR = 0;
const uint32_t WHITE_COLOR = 16777215;

const string AREA = "Area: ";
const string PERIMETER = "Perimeter: ";
const string OUTLINE_COLOR = "Outline color: ";

class IShape
{
public:
	IShape(uint32_t outlineColor = BLACK_COLOR);
	~IShape();

	virtual double GetArea() const=0;
	virtual double GetPerimeter() const=0;
	virtual string ToString() const=0;
	virtual uint32_t GetOutlineColor() const=0;

protected:
	uint32_t m_outlineColor;
};
