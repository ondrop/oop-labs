#include "ISolidShape.h"

ISolidShape::ISolidShape(uint32_t outlineColor, uint32_t fillColor)
	:m_fillColor(fillColor),
	IShape(outlineColor)
{
}

ISolidShape::~ISolidShape()
{
}

uint32_t ISolidShape::GetFillColor() const
{
	return uint32_t();
}
