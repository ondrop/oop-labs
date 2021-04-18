#pragma once
#include "stdafx.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CLineSegment.h"

using namespace std;

const int TWO = 2;
const string MIN_PERIMETER_SHAPE_INFO = "Information about a shape with a minimum perimeter";
const string MAX_AREA_SHAPE_INFO = "Information about the figure with the maximum area";
const string POINT_CONTAINS_NON_NUMBER_SYMBOLS = "Point contains non number suymbols";
const string WIDTH_AND_HEIGHT_NOT_RECEIVED = "Width and height was not received";
const string SHAPES_ARRAY_EMPTY = "The array of shapes is empty";
const string RADIUS_NOT_RECEIVED = "Radius was not received";
const string POINT_NOT_RECEIVED = "Point was not received";
const string SHAPE_NOT_RECEIVED = "Shape was not recevied";
const string COLOR_OUT_OF_RANGE = "Color out of range";
const string SHAPE_RECEIVED = "Shape was received";
const string NOT_EXIST = "\" doesn't exist";
const string RECTANGLE = "rectangle";
const string TRIANGLE = "triangle";
const string SHAPE = "Shape \"";
const string CIRCLE = "circle";
const string LINE = "line";

class CShapeControl
{
public:
	CShapeControl(ostream& output);
	~CShapeControl();

	void AddShape(stringstream& streamStr);
	void PrintInfo();
	optional<CRectangle*> GetRectangle(stringstream& streamStr) const;
	optional<CTriangle*> GetTriangle(stringstream& streamStr) const;
	optional<CCircle*> GetCircle(stringstream& streamStr) const;
	optional<CLineSegment*> GetLine(stringstream& streamStr) const;

private:
	ostream& m_output;
	vector<IShape*> m_shapes;

	bool ConvertStringToDouble(double& number, const string& strNumber) const;
	optional<CPoint> MakePoint(const string& xStr, const string& yStr) const;
	bool GetDimensionValue(double& dimension, const string& dimensionStr) const;
	optional<uint32_t> GetColor(stringstream& streamStr) const;
	vector<IShape*> GetShapes() const;
};
