#pragma once
#include "stdafx.h"
#include "IShape.h"

const string FILL_COLOR = "Fill color: ";

class ISolidShape : public IShape
{
public:
	ISolidShape(uint32_t outlineColor = BLACK_COLOR, uint32_t fillColor = WHITE_COLOR);
	~ISolidShape();

	virtual uint32_t GetFillColor() const;

protected:
	uint32_t m_fillColor;
};
