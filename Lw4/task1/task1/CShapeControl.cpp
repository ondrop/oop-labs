#include "CShapeControl.h"

CShapeControl::CShapeControl(ostream& output)
	:m_output(output)
{
}

CShapeControl::~CShapeControl()
{
}

bool CShapeControl::ConvertStringToDouble(double& number, const string& strNumber) const
{
	try
	{
		number = stod(strNumber);
	}
	catch (const exception& error)
	{
		m_output << error.what() << endl;
		return false;
	}

	return true;
}

optional<CPoint> CShapeControl::MakePoint(const string& xStr, const string& yStr) const
{
	double x = 0.0;
	double y = 0.0;
	if (!ConvertStringToDouble(x, xStr))
	{
		return nullopt;
	}

	if (!ConvertStringToDouble(y, yStr))
	{
		return nullopt;
	}

	CPoint leftTopPoint(x, y);

	return leftTopPoint;
}

optional<uint32_t> CShapeControl::GetColor(stringstream& streamStr) const
{
	string colorStr;
	streamStr >> colorStr;
	if (streamStr.fail())
	{
		return nullopt;
	}

	uint32_t color = 0;
	try
	{
		color = stoul(colorStr, nullptr, 16);
		if (color > WHITE_COLOR)
		{
			m_output << COLOR_OUT_OF_RANGE << endl;
		}
	}
	catch (const exception& error)
	{
		m_output << error.what() << endl;
		return nullopt;
	}

	return color;
}

vector<IShape*> CShapeControl::GetShapes() const
{
	return m_shapes;
}

optional<CRectangle*> CShapeControl::GetRectangle(stringstream& streamStr) const
{
	string topLeftXStr, topLeftYStr;
	streamStr >> topLeftXStr >> topLeftYStr;
	if (streamStr.fail())
	{
		m_output << POINT_NOT_RECEIVED << endl;
		return nullopt;
	}

	auto leftTopPoint = MakePoint(topLeftXStr, topLeftYStr);
	if (!leftTopPoint)
	{
		m_output << POINT_CONTAINS_NON_NUMBER_SYMBOLS << endl;
		return nullopt;
	}

	string widthStr, heightStr;
	streamStr >> widthStr >> heightStr;
	if (streamStr.fail())
	{
		m_output << WIDTH_AND_HEIGHT_NOT_RECEIVED << endl;
		return nullopt;
	}

	double width = 0.0;
	double height = 0.0;
	if (!GetDimensionValue(width, widthStr))
	{
		return nullopt;
	}

	if (!GetDimensionValue(height, heightStr))
	{
		return nullopt;
	}

	CPoint rightBottomPoint(leftTopPoint->GetCoordinateX() + width, leftTopPoint->GetCoordinateY() - height);

	auto outlineColor = GetColor(streamStr);
	auto fillColor = GetColor(streamStr);

	if (outlineColor == nullopt)
	{
		outlineColor = BLACK_COLOR;
	}

	if (fillColor == nullopt)
	{
		fillColor = WHITE_COLOR;
	}

	return new CRectangle(leftTopPoint.value(), rightBottomPoint, width, height, fillColor.value(), outlineColor.value());
}

optional<CTriangle*> CShapeControl::GetTriangle(stringstream& streamStr) const
{
	vector<CPoint> trianglePoints;
	for (int i = 0; i < THREE; i++)
	{
		string xStr, yStr;
		streamStr >> xStr >> yStr;
		if (streamStr.fail())
		{
			m_output << POINT_NOT_RECEIVED << endl;
			return nullopt;
		}

		auto trianglePoint = MakePoint(xStr, yStr);
		if (!trianglePoint)
		{
			return nullopt;
		}

		trianglePoints.push_back(trianglePoint.value());
	}

	auto outlineColor = GetColor(streamStr);
	auto fillColor = GetColor(streamStr);

	if (outlineColor == nullopt)
	{
		outlineColor = BLACK_COLOR;
	}

	if (fillColor == nullopt)
	{
		fillColor = WHITE_COLOR;
	}

	return new CTriangle(trianglePoints[0], trianglePoints[1], trianglePoints[2], fillColor.value(), outlineColor.value());
}

optional<CCircle*> CShapeControl::GetCircle(stringstream& streamStr) const
{
	string xStr, yStr;
	streamStr >> xStr >> yStr;
	if (streamStr.fail())
	{
		m_output << POINT_NOT_RECEIVED << endl;
		return nullopt;
	}

	auto centerPoint = MakePoint(xStr, yStr);
	if (!centerPoint)
	{
		return nullopt;
	}

	string radiusStr;
	streamStr >> radiusStr;
	if (streamStr.fail())
	{
		m_output << RADIUS_NOT_RECEIVED << endl;
		return nullopt;
	}

	double radius = 0.0;
	if (!GetDimensionValue(radius, radiusStr))
	{
		return nullopt;
	}

	auto outlineColor = GetColor(streamStr);
	auto fillColor = GetColor(streamStr);

	if (outlineColor == nullopt)
	{
		outlineColor = BLACK_COLOR;
	}

	if (fillColor == nullopt)
	{
		fillColor = WHITE_COLOR;
	}

	return new CCircle(centerPoint.value(), radius, fillColor.value(), outlineColor.value());
}

optional<CLineSegment*> CShapeControl::GetLine(stringstream& streamStr) const
{
	vector<CPoint> linePoints;
	for (int i = 0; i < TWO; i++)
	{
		string xStr, yStr;
		streamStr >> xStr >> yStr;
		if (streamStr.fail())
		{
			m_output << POINT_NOT_RECEIVED << endl;
			return nullopt;
		}

		auto linePoint = MakePoint(xStr, yStr);
		if (!linePoint)
		{
			return nullopt;
		}

		linePoints.push_back(linePoint.value());
	}

	auto outlineColor = GetColor(streamStr);
	if (outlineColor == nullopt)
	{
		outlineColor = BLACK_COLOR;
	}

	return new CLineSegment(linePoints[0], linePoints[1], outlineColor.value());
}

void CShapeControl::AddShape(stringstream& streamStr)
{
	string shapeName;
	streamStr >> shapeName;
	if (streamStr.fail())
	{
		m_output << SHAPE_NOT_RECEIVED << endl;
	}

	if (shapeName == RECTANGLE)
	{
		auto rectangle = GetRectangle(streamStr);
		if (rectangle)
		{
			m_shapes.push_back(rectangle.value());
			m_output << SHAPE_RECEIVED << endl;
		}
		else
		{
			m_output << SHAPE_NOT_RECEIVED << endl;
		}
	}
	else if (shapeName == TRIANGLE)
	{
		auto triangle = GetTriangle(streamStr);
		if (triangle)
		{
			m_shapes.push_back(triangle.value());
			m_output << SHAPE_RECEIVED << endl;
		}
		else
		{
			m_output << SHAPE_NOT_RECEIVED << endl;
		}
	}
	else if (shapeName == CIRCLE)
	{
		auto circle = GetCircle(streamStr);
		if (circle)
		{
			m_shapes.push_back(circle.value());
			m_output << SHAPE_RECEIVED << endl;
		}
		else
		{
			m_output << SHAPE_NOT_RECEIVED << endl;
		}
	}
	else if (shapeName == LINE)
	{
		auto line = GetLine(streamStr);
		if (line)
		{
			m_shapes.push_back(line.value());
			m_output << SHAPE_RECEIVED << endl;
		}
		else
		{
			m_output << SHAPE_NOT_RECEIVED << endl;
		}
	}
	else
	{
		m_output << SHAPE + shapeName + NOT_EXIST << endl;
	}
}

void CShapeControl::PrintInfo()
{
	vector<IShape*> shapes = GetShapes();
	if (!shapes.empty())
	{
		auto maxAreaShape = min_element(shapes.begin(), shapes.end(),
			[](IShape* shape1, IShape* shape2)
			{
				return shape1->GetArea() > shape2->GetArea();
			});

		auto minPerimeterShape = min_element(shapes.begin(), shapes.end(),
			[](IShape* shape1, IShape* shape2)
			{
				return shape1->GetPerimeter() < shape2->GetPerimeter();
			});

		m_output << MAX_AREA_SHAPE_INFO << endl;
		m_output << (*maxAreaShape)->ToString() << endl;
		m_output << MIN_PERIMETER_SHAPE_INFO << endl;
		m_output << (*minPerimeterShape)->ToString() << endl;
	}
	else
	{
		m_output << SHAPES_ARRAY_EMPTY << endl;
	}
}

bool CShapeControl::GetDimensionValue(double& dimension, const string& dimensionStr) const
{
	return ConvertStringToDouble(dimension, dimensionStr) && dimension >= 0;
}
