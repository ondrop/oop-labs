#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../task1/CShapeControl.h"

const string TEST_PASSED = "Test passed successfully";

SCENARIO("Test CPoint class")
{
	cout << "Test CPoint class" << endl;
	CPoint point(1, 2);
	GIVEN("Test GetCoordinateX method")
	{
		cout << "Test GetCoordinateX method" << endl;
		REQUIRE(point.GetCoordinateX() == 1);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Test GetCoordinateY method")
	{
		cout << "Test GetCoordinateY method" << endl;
		REQUIRE(point.GetCoordinateY() == 2);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Test SetCoordinateX method")
	{
		cout << "Test SetCoordinateX method" << endl;
		REQUIRE(point.SetCoordinateX(4.2) == true);
		REQUIRE(point.GetCoordinateX() == 4.2);
		cout << TEST_PASSED << endl;
	}

	GIVEN("Test SetCoordinateY method")
	{
		cout << "Test SetCoordinateY method" << endl;
		REQUIRE(point.SetCoordinateY(3.5) == true);
		REQUIRE(point.GetCoordinateY() == 3.5);
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CCircle class")
{
	cout << "Test CCircle class" << endl;
	GIVEN("CCircle with outline and fill color")
	{
		cout << "CCircle with outline and fill color" << endl;
		CCircle circle(CPoint(1, 1), 5, 16711680, 65280);
		double expectedArea = 78.5398;
		double expectedPerimeter = 31.416;
		uint32_t expectedOutlineColor = 65280;
		uint32_t expectedFillColor = 16711680;

		REQUIRE(to_string(circle.GetArea()) == "78.539816");
		REQUIRE(to_string(circle.GetPerimeter()) == "31.415927");
		REQUIRE(circle.GetCenter().GetCoordinateX() == 1);
		REQUIRE(circle.GetCenter().GetCoordinateY() == 1);
		REQUIRE(circle.GetRadius() == 5);
		REQUIRE(circle.GetOutlineColor() == expectedOutlineColor);
		REQUIRE(circle.GetFillColor() == expectedFillColor);
		REQUIRE(circle.ConvertColorToHex(circle.GetOutlineColor()) == "00ff00");
		REQUIRE(circle.ConvertColorToHex(circle.GetFillColor()) == "ff0000");

		stringstream expectedStreamStr;
		expectedStreamStr << U_CIRCLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << expectedPerimeter << endl;
		expectedStreamStr << OUTLINE_COLOR << "00ff00" << endl;
		expectedStreamStr << FILL_COLOR << "ff0000" << endl;
		expectedStreamStr << CENTER << "1.000 1.000" << endl;
		expectedStreamStr << RADIUS << "5.000" << endl;

		REQUIRE(circle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}
	
	GIVEN("CCircle without outline and fill color")
	{
		cout << "CCircle without outline and fill color" << endl;
		CCircle circle(CPoint(1, 1), 5);
		double expectedArea = 78.5398;
		double expectedPerimeter = 31.416;

		REQUIRE(circle.GetOutlineColor() == BLACK_COLOR);
		REQUIRE(circle.GetFillColor() == WHITE_COLOR);
		REQUIRE(circle.ConvertColorToHex(circle.GetOutlineColor()) == "000000");
		REQUIRE(circle.ConvertColorToHex(circle.GetFillColor()) == "ffffff");

		stringstream expectedStreamStr;
		expectedStreamStr << U_CIRCLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << expectedPerimeter << endl;
		expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
		expectedStreamStr << FILL_COLOR << "ffffff" << endl;
		expectedStreamStr << CENTER << "1.000 1.000" << endl;
		expectedStreamStr << RADIUS << "5.000" << endl;

		REQUIRE(circle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CRectangle class")
{
	cout << "Test CRectangle class" << endl;
	GIVEN("CRectangle with outline and fill color")
	{
		cout << "CRectangle with outline and fill color" << endl;
		CRectangle rectangle(CPoint(1, 1), CPoint(-9, 16), 10, 15, 16711680, 65280);
		double expectedArea = 150;
		double expectedPerimeter = 50.000;
		uint32_t expectedOutlineColor = 65280;
		uint32_t expectedFillColor = 16711680;

		REQUIRE(rectangle.GetArea() == expectedArea);
		REQUIRE(rectangle.GetPerimeter() == expectedPerimeter);
		REQUIRE(rectangle.GetLeftTop().GetCoordinateX() == 1);
		REQUIRE(rectangle.GetLeftTop().GetCoordinateY() == 1);
		REQUIRE(rectangle.GetRightBottom().GetCoordinateX() == -9);
		REQUIRE(rectangle.GetRightBottom().GetCoordinateY() == 16);
		REQUIRE(rectangle.GetOutlineColor() == expectedOutlineColor);
		REQUIRE(rectangle.GetFillColor() == expectedFillColor);
		REQUIRE(rectangle.ConvertColorToHex(rectangle.GetOutlineColor()) == "00ff00");
		REQUIRE(rectangle.ConvertColorToHex(rectangle.GetFillColor()) == "ff0000");

		stringstream expectedStreamStr;
		expectedStreamStr << U_RECTANGLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << "50.000" << endl;
		expectedStreamStr << OUTLINE_COLOR << "00ff00" << endl;
		expectedStreamStr << FILL_COLOR << "ff0000" << endl;
		expectedStreamStr << LEFT_TOP_POINT << "1.000 1.000" << endl;
		expectedStreamStr << RIGHT_BOTTOM_POINT << "-9.000 16.000" << endl;
		expectedStreamStr << WIDTH << "10.000" << endl;
		expectedStreamStr << HEIGHT << "15.000" << endl;

		REQUIRE(rectangle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}

	GIVEN("CRectangle without outline and fill color")
	{
		cout << "CRectangle without outline and fill color" << endl;
		CRectangle rectangle(CPoint(1, 1), CPoint(-9, 16), 10, 15);
		string expectedArea = "150";
		string expectedPerimeter = "50.000";

		REQUIRE(rectangle.GetOutlineColor() == BLACK_COLOR);
		REQUIRE(rectangle.GetFillColor() == WHITE_COLOR);
		REQUIRE(rectangle.ConvertColorToHex(rectangle.GetOutlineColor()) == "000000");
		REQUIRE(rectangle.ConvertColorToHex(rectangle.GetFillColor()) == "ffffff");

		stringstream expectedStreamStr;
		expectedStreamStr << U_RECTANGLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << expectedPerimeter << endl;
		expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
		expectedStreamStr << FILL_COLOR << "ffffff" << endl;
		expectedStreamStr << LEFT_TOP_POINT << "1.000 1.000" << endl;
		expectedStreamStr << RIGHT_BOTTOM_POINT << "-9.000 16.000" << endl;
		expectedStreamStr << WIDTH << "10.000" << endl;
		expectedStreamStr << HEIGHT << "15.000" << endl;

		REQUIRE(rectangle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CTriangle class")
{
	cout << "Test CTriangle class" << endl;
	GIVEN("CTriangle with outline and fill color")
	{
		cout << "CTriangle with outline and fill color" << endl;
		CTriangle triangle(CPoint(1, 1), CPoint(2, 3), CPoint(3, 4), 16711680, 65280);
		double expectedArea = 0.500;
		double expectedPerimeter = 7.255833;
		uint32_t expectedOutlineColor = 65280;
		uint32_t expectedFillColor = 16711680;

		REQUIRE(to_string(triangle.GetArea()) == to_string(expectedArea));
		REQUIRE(to_string(triangle.GetPerimeter()) == to_string(expectedPerimeter));
		REQUIRE(triangle.GetVertex1().GetCoordinateX() == 1);
		REQUIRE(triangle.GetVertex1().GetCoordinateY() == 1);
		REQUIRE(triangle.GetVertex2().GetCoordinateX() == 2);
		REQUIRE(triangle.GetVertex2().GetCoordinateY() == 3);
		REQUIRE(triangle.GetVertex3().GetCoordinateX() == 3);
		REQUIRE(triangle.GetVertex3().GetCoordinateY() == 4);
		REQUIRE(triangle.GetOutlineColor() == expectedOutlineColor);
		REQUIRE(triangle.GetFillColor() == expectedFillColor);
		REQUIRE(triangle.ConvertColorToHex(triangle.GetOutlineColor()) == "00ff00");
		REQUIRE(triangle.ConvertColorToHex(triangle.GetFillColor()) == "ff0000");

		stringstream expectedStreamStr;
		expectedStreamStr << U_TRIANGLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << "7.256" << endl;
		expectedStreamStr << OUTLINE_COLOR << "00ff00" << endl;
		expectedStreamStr << FILL_COLOR << "ff0000" << endl;
		expectedStreamStr << VERTEX_1 << "1.000 1.000" << endl;
		expectedStreamStr << VERTEX_2 << "2.000 3.000" << endl;
		expectedStreamStr << VERTEX_3 << "3.000 4.000" << endl;
		REQUIRE(triangle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}

	GIVEN("CTriangle without outline and fill color")
	{
		cout << "CTriangle without outline and fill color" << endl;
		CTriangle triangle(CPoint(1, 1), CPoint(2, 3), CPoint(3, 4));
		double expectedArea = 0.5;
		double expectedPerimeter = 7.256;

		REQUIRE(triangle.GetOutlineColor() == BLACK_COLOR);
		REQUIRE(triangle.GetFillColor() == WHITE_COLOR);
		REQUIRE(triangle.ConvertColorToHex(triangle.GetOutlineColor()) == "000000");
		REQUIRE(triangle.ConvertColorToHex(triangle.GetFillColor()) == "ffffff");

		stringstream expectedStreamStr;
		expectedStreamStr << U_TRIANGLE << endl;
		expectedStreamStr << AREA << expectedArea << endl;
		expectedStreamStr << PERIMETER << expectedPerimeter << endl;
		expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
		expectedStreamStr << FILL_COLOR << "ffffff" << endl;
		expectedStreamStr << VERTEX_1 << "1.000 1.000" << endl;
		expectedStreamStr << VERTEX_2 << "2.000 3.000" << endl;
		expectedStreamStr << VERTEX_3 << "3.000 4.000" << endl;
		REQUIRE(triangle.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CLineSegment class")
{
	cout << "Test CLineSegment class" << endl;
	GIVEN("CLineSegment with outline color")
	{
		cout << "CTriangle with outline color" << endl;
		CLineSegment line(CPoint(1, 1), CPoint(2, 3), 16711680);
		string expectedPerimeter = "2.236068";
		uint32_t expectedOutlineColor = 16711680;

		REQUIRE(line.GetArea() == 0.0);
		REQUIRE(to_string(line.GetPerimeter()) == expectedPerimeter);
		REQUIRE(line.GetStartPoint().GetCoordinateX() == 1);
		REQUIRE(line.GetStartPoint().GetCoordinateY() == 1);
		REQUIRE(line.GetEndPoint().GetCoordinateX() == 2);
		REQUIRE(line.GetEndPoint().GetCoordinateY() == 3);
		REQUIRE(line.GetOutlineColor() == expectedOutlineColor);
		REQUIRE(line.ConvertColorToHex(line.GetOutlineColor()) == "ff0000");

		stringstream expectedStreamStr;
		expectedStreamStr << U_LINE << endl;
		expectedStreamStr << AREA << "0" << endl;
		expectedStreamStr << PERIMETER << "2.236" << endl;
		expectedStreamStr << OUTLINE_COLOR << "ff0000" << endl;
		expectedStreamStr << START_POINT << "1.000 1.000" << endl;
		expectedStreamStr << END_POINT << "2.000 3.000" << endl;
		REQUIRE(line.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}

	GIVEN("CLineSegment without outline color")
	{
		cout << "CLineSegment without outline color" << endl;
		CLineSegment line(CPoint(1, 1), CPoint(2, 3));

		REQUIRE(line.GetOutlineColor() == BLACK_COLOR);
		REQUIRE(line.ConvertColorToHex(line.GetOutlineColor()) == "000000");

		stringstream expectedStreamStr;
		expectedStreamStr << U_LINE << endl;
		expectedStreamStr << AREA << "0" << endl;
		expectedStreamStr << PERIMETER << "2.236" << endl;
		expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
		expectedStreamStr << START_POINT << "1.000 1.000" << endl;
		expectedStreamStr << END_POINT << "2.000 3.000" << endl;
		REQUIRE(line.ToString() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
	}
}

SCENARIO("Test CShapeControl class")
{
	cout << "Test CShapeControl class" << endl;
	GIVEN("Shapes were not given")
	{
		cout << "Shapes were not given" << endl;
		stringstream output, streamStr, expectedStreamStr;
		CShapeControl shapeControl(output);
		streamStr << "test" << endl;
		shapeControl.AddShape(streamStr);
		shapeControl.PrintInfo();

		expectedStreamStr << SHAPE + "test" + NOT_EXIST << endl;
		expectedStreamStr << SHAPES_ARRAY_EMPTY << endl;

		REQUIRE(output.str() == expectedStreamStr.str());
		cout << TEST_PASSED << endl;
		
	}

	GIVEN("Shapes were given")
	{
		WHEN("Given only one shape")
		{
			cout << "Given only one shape" << endl;
			stringstream output, streamStr, expectedStreamStr;
			CShapeControl shapeControl(output);
			streamStr << "circle 1 1 5" << endl;
			shapeControl.AddShape(streamStr);
			shapeControl.PrintInfo();

			double expectedArea = 78.5398;
			double expectedPerimeter = 31.416;

			expectedStreamStr << SHAPE_RECEIVED << endl;
			expectedStreamStr << MAX_AREA_SHAPE_INFO << endl;
			expectedStreamStr << U_CIRCLE << endl;
			expectedStreamStr << AREA << expectedArea << endl;
			expectedStreamStr << PERIMETER << expectedPerimeter << endl;
			expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
			expectedStreamStr << FILL_COLOR << "ffffff" << endl;
			expectedStreamStr << CENTER << "1.000 1.000" << endl;
			expectedStreamStr << RADIUS << "5.000" << endl << endl;

			expectedStreamStr << MIN_PERIMETER_SHAPE_INFO << endl;
			expectedStreamStr << U_CIRCLE << endl;
			expectedStreamStr << AREA << expectedArea << endl;
			expectedStreamStr << PERIMETER << expectedPerimeter << endl;
			expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
			expectedStreamStr << FILL_COLOR << "ffffff" << endl;
			expectedStreamStr << CENTER << "1.000 1.000" << endl;
			expectedStreamStr << RADIUS << "5.000" << endl << endl;

			REQUIRE(output.str() == expectedStreamStr.str());
			cout << TEST_PASSED << endl;
		}

		WHEN("Given few shapes")
		{
			cout << "Given few shapes" << endl;
			stringstream output, streamStr, expectedStreamStr;
			CShapeControl shapeControl(output);
			streamStr << "circle 1 1 5" << endl;
			double expectedArea = 78.5398;
			double expectedPerimeter = 31.416;

			shapeControl.AddShape(streamStr);
			expectedStreamStr << SHAPE_RECEIVED << endl;
			stringstream().swap(streamStr);
			streamStr << "rectangle 1 1 10 15 ff0000 00ff00" << endl;
			shapeControl.AddShape(streamStr);
			expectedStreamStr << SHAPE_RECEIVED << endl;
			shapeControl.PrintInfo();

			expectedStreamStr << MAX_AREA_SHAPE_INFO << endl;
			expectedStreamStr << U_RECTANGLE << endl;
			expectedStreamStr << AREA << "150" << endl;
			expectedStreamStr << PERIMETER << "50.000" << endl;
			expectedStreamStr << OUTLINE_COLOR << "ff0000" << endl;
			expectedStreamStr << FILL_COLOR << "00ff00" << endl;
			expectedStreamStr << LEFT_TOP_POINT << "1.000 1.000" << endl;
			expectedStreamStr << RIGHT_BOTTOM_POINT << "11.000 -14.000" << endl;
			expectedStreamStr << WIDTH << "10.000" << endl;
			expectedStreamStr << HEIGHT << "15.000" << endl << endl;

			expectedStreamStr << MIN_PERIMETER_SHAPE_INFO << endl;
			expectedStreamStr << U_CIRCLE << endl;
			expectedStreamStr << AREA << expectedArea << endl;
			expectedStreamStr << PERIMETER << expectedPerimeter << endl;
			expectedStreamStr << OUTLINE_COLOR << "000000" << endl;
			expectedStreamStr << FILL_COLOR << "ffffff" << endl;
			expectedStreamStr << CENTER << "1.000 1.000" << endl;
			expectedStreamStr << RADIUS << "5.000" << endl << endl;

			REQUIRE(output.str() == expectedStreamStr.str());
			cout << TEST_PASSED << endl;
		}

		WHEN("Given shape but not received")
		{
			cout << "Given shape but not received" << endl;
			stringstream output, streamStr, expectedStreamStr;
			CShapeControl shapeControl(output);
			streamStr << "circle 1 1 -5" << endl;
			shapeControl.AddShape(streamStr);
			shapeControl.PrintInfo();

			expectedStreamStr << SHAPE_NOT_RECEIVED << endl;
			expectedStreamStr << SHAPES_ARRAY_EMPTY << endl;

			REQUIRE(output.str() == expectedStreamStr.str());
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Test GetRectangle method")
	{
		cout << "Test GetRectangle method" << endl;
		WHEN("Top left point was not given")
		{
			cout << "Top left point was not given" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);
			REQUIRE(shapeControl.GetRectangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Top left point contains non number symbols")
		{
			cout << "Top left point contains non number symbols" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "asd abs" << endl;
			REQUIRE(shapeControl.GetRectangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Rectangle not contain width and height")
		{
			cout << "Rectangle does not contain width and height" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1" << endl;
			REQUIRE(shapeControl.GetRectangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Rectangle's width and height contain non number symbol")
		{
			cout << "Rectangle's width and height contain non number symbol" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 as as" << endl;
			REQUIRE(shapeControl.GetRectangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Rectangle is correct")
		{
			cout << "Rectangle is correct" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 10 15" << endl;
			auto rectangle = shapeControl.GetRectangle(streamStr);
			REQUIRE(rectangle != nullopt);
			CRectangle* rectangleElem = rectangle.value();
			REQUIRE(rectangleElem->ConvertColorToHex(rectangleElem->GetOutlineColor()) == "000000");
			cout << TEST_PASSED << endl;
		}

		WHEN("Rectangle with outline color")
		{
			cout << "Rectangle with outline color" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 10 15 ff0000" << endl;
			auto rectangle = shapeControl.GetRectangle(streamStr);
			REQUIRE(rectangle != nullopt);
			CRectangle* rectangleElem = rectangle.value();
			REQUIRE(rectangleElem->ConvertColorToHex(rectangleElem->GetOutlineColor()) == "ff0000");
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Test GetTriangle method")
	{
		cout << "Test GetTriangle method" << endl;
		WHEN("Points were not received")
		{
			cout << "Points were not received" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);
			REQUIRE(shapeControl.GetTriangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Not all points received")
		{
			cout << "Not all points received" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1" << endl;
			REQUIRE(shapeControl.GetTriangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("All points received but they contain non number symbols")
		{
			cout << "All points received but they contain non number symbols" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 2 3 3 asas" << endl;
			REQUIRE(shapeControl.GetTriangle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Triangle is correct")
		{
			cout << "Triangle is correct" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 2 3 3 4" << endl;
			auto triangle = shapeControl.GetTriangle(streamStr);
			REQUIRE(triangle != nullopt);
			CTriangle* triangleElem = triangle.value();
			REQUIRE(triangleElem->ConvertColorToHex(triangleElem->GetOutlineColor()) == "000000");
			cout << TEST_PASSED << endl;
		}

		WHEN("Triangle with outline color")
		{
			cout << "Triangle with outline color" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 2 3 3 4 ff0000" << endl;
			auto triangle = shapeControl.GetTriangle(streamStr);
			REQUIRE(triangle != nullopt);
			CTriangle* triangleElem = triangle.value();
			REQUIRE(triangleElem->ConvertColorToHex(triangleElem->GetOutlineColor()) == "ff0000");
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Test GetCircle method")
	{
		cout << "Test GetCircle method" << endl;
		WHEN("Center was not given")
		{
			cout << "Center was not given" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);
			REQUIRE(shapeControl.GetCircle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Center point contains non number symbols")
		{
			cout << "Center point contains non number symbols" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "asd abs" << endl;
			REQUIRE(shapeControl.GetCircle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Center does not contain radius")
		{
			cout << "Center does not contain radius" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1" << endl;
			REQUIRE(shapeControl.GetCircle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Center's radius contains non number symbol")
		{
			cout << "Center's radius contains non number symbol" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 as" << endl;
			REQUIRE(shapeControl.GetCircle(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Circle is correct")
		{
			cout << "Circle is correct" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 5" << endl;
			auto circle = shapeControl.GetCircle(streamStr);
			REQUIRE(circle != nullopt);
			CCircle* circleElem = circle.value();
			REQUIRE(circleElem->ConvertColorToHex(circleElem->GetOutlineColor()) == "000000");
			cout << TEST_PASSED << endl;
		}

		WHEN("Circle with outline color")
		{
			cout << "Circle with outline color" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 5 ff0000" << endl;
			auto circle = shapeControl.GetCircle(streamStr);
			REQUIRE(circle != nullopt);
			CCircle* circleElem = circle.value();
			REQUIRE(circleElem->ConvertColorToHex(circleElem->GetOutlineColor()) == "ff0000");
			cout << TEST_PASSED << endl;
		}
	}

	GIVEN("Test GetLine method")
	{
		cout << "Test GetLine method" << endl;
		WHEN("Line was not given")
		{
			cout << "Line was not given" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);
			REQUIRE(shapeControl.GetLine(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Start point non number symbols")
		{
			cout << "Start point contains non number symbols" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "asd abs" << endl;
			REQUIRE(shapeControl.GetLine(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("End point non number symbols")
		{
			cout << "End point contains non number symbols" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 asd abs" << endl;
			REQUIRE(shapeControl.GetLine(streamStr) == nullopt);
			cout << TEST_PASSED << endl;
		}

		WHEN("Line is correct")
		{
			cout << "Line is correct" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 5 5" << endl;
			auto line = shapeControl.GetLine(streamStr);
			REQUIRE(line != nullopt);
			CLineSegment* lineSegment = line.value();
			REQUIRE(lineSegment->ConvertColorToHex(lineSegment->GetOutlineColor()) == "000000");
			cout << TEST_PASSED << endl;
		}

		WHEN("Line with outline color")
		{
			cout << "Line with outline color" << endl;
			stringstream output, streamStr;
			CShapeControl shapeControl(output);

			streamStr << "1 1 5 5 ff0000" << endl;
			auto line = shapeControl.GetLine(streamStr);
			REQUIRE(line != nullopt);
			CLineSegment* lineSegment = line.value();
			REQUIRE(lineSegment->ConvertColorToHex(lineSegment->GetOutlineColor()) == "ff0000");
			cout << TEST_PASSED << endl;
		}
	}
}
