/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Caitlin Berry and Liad Gross
 * cnberry and liadgr
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

void test_Point();
void test_Color();
void test_Line();
void test_Triangle();
void test_Circle();
void test_Rectangle();


void startTests() {
    cout << "---------------------------------------------" << endl;
    test_Point();
    test_Color();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();
}

void test_Point() {
    cout << "Testing Point Class:" << endl << endl;
    
    // TEST DEFAULT CONSTRUCTOR
    Point p1;
    cout << "Expected: (0,0), Actual: " << p1 << endl;
    
    // TEST NON DEFAULT CONSTRUCTOR
    Point p2(3, 9);
    cout << "Expected: (3,9), Actual: " << p2 << endl;
    
    // TEST SETTERS
    p1.setX(5);
    p1.setY(3);
    
    // TEST GETTERS
    cout << "Expected: (5,3), Actual: ";
    cout << "(" << p1.getX() << "," << p1.getY() << ")" << endl;
    
    cout << "---------------------------------------------" << endl;
}

void test_Color(){
    cout << "Testing Color Class pt1:" << endl << endl;;
    
    Color color;
    Color color1(49, 20, 1);
    
    // TEST CONSTRUCTORS
    Color color2(14, 93, 1);
    cout << "Expected: '14 93 1', Actual: '" << color2 << "'" << endl;
    cout << "Expected: '14 93 1', Actual: '" << color2.getRed() << " "
         << color2.getGreen() << " " << color2.getBlue() << "'" << endl;
    
    // TEST SETTERS
    int blueColor = 10;
    color.setRed(20);
    color.setGreen(300);
    color.setBlue(-100); // TEST SET BLUE *****
    color.setBlue(blueColor);
    color2.setBlue(50);
    
    //TEST GETTERS
    cout << "Expected: '20 255 0', Actual: '" << color.getRed() << " "
         << color.getGreen() << " " << color.getBlue() << "'" << endl;
        
    cout << endl;
    
    cout << "Testing Color Class pt2:" << endl << endl;
    
    //test of default constructor and get colors
    Color COLOR;
    Color COLOR1(49, 20, 1);
    
    cout << "Expected: 49 20 1, Actual: " << COLOR1 << endl;
    
    cout << "Expected: 0,0,0, Actual: " << COLOR.getRed() << " "
         << COLOR.getGreen() << " " << COLOR.getBlue() << endl;
    
    //test of set colors and checkRange
    Color COLOR2(10, 15, 20);
    
    cout << "Expected: 10 15 20, Actual: " << COLOR2 << endl;
    
    Color COLOR3;
    COLOR3.setRed(20);
    COLOR3.setGreen(260);
    COLOR3.setBlue(-15);
        
    cout << "Expected: 20, 255, 0, Actual: " << COLOR3.getRed() << " "
         << COLOR3.getGreen() << " " << COLOR3.getBlue() << endl;
    
    cout << "---------------------------------------------" << endl;
}

void test_Line(){
    cout << "Testing Line Class pt1:" << endl << endl;
    
    Line line;
    Point pt1;
    Point pt2(40, 50);
    Color color;
    
    // TEST CONSTRUCTOR
    Line ln(pt1, pt2, color);
    cout << "Expected: (0,0) (40,50) 0 0 0, Actual: " << ln;
    
    // TEST SETTERS
    line.setStart(pt1);
    line.setEnd(pt2);
    line.setColor(color);
    cout << "Expected: '(0,0) (40,50) 0 0 0', Actual: '" << line.getStart()
         << " " << line.getEnd() << " " << line.getColor() << "'" << endl;
    
    // TEST WRITE *****
    cout << "Testing write: " << endl;
    line.write(cout);
    ln.write(cout);
    
    
    
    cout << endl << "Testing Line pt2:" << endl << endl;
    
    Line LINE;
    
    Point PT1;
    Point PT2(40, 50);
    Color COLOR;
    Line LN(PT1, PT2, COLOR);
        
    cout << "Expected: (0,0), (40,50), 0 0 0 Actual: " << LN.getStart() << " "
         << LN.getEnd() << " " << LN.getColor() << endl;
        
    LINE.setStart(PT1);
    LINE.setEnd(PT2);
    LINE.setColor(COLOR);
        
    cout << "Expected: (0,0), (40,50), 0 0 0 Actual: " << LINE.getStart()
         << " " << LINE.getEnd() << " " << LINE.getColor() << endl;
        
    cout << "Testing Write:" << endl;
    LN.write(cout);
    LINE.write(cout);
    
    cout << "---------------------------------------------" << endl;
}

void test_Triangle(){
    cout << "Testing Triangle Class pt1:" << endl << endl;
    
    Point pt1;
    Point pt2(10,5);
    Point pt3(15,10);
    Color color;
    
    // TEST CONSTRUCTORS *****
    Triangle triangle(pt1, pt2, pt3, color);
    Triangle triangle1(pt1, pt2, pt3, color);
    triangle1.setVertexOne(pt3);
    triangle1.setVertexTwo(pt3);
    cout << "Testing Constructor1: " << triangle << endl;
    
    // TEST SET VERTEX
    triangle.setVertexOne(pt1);
    triangle.setVertexTwo(pt2);
    triangle.setVertexThree(pt3);
    
    Color colorOne(35, 2, 255);
    Color colorTwo(53, 24, 5);
    Color colorThree(100, 100, 100);
    triangle.setVertexOneColor(colorOne);
    triangle.setVertexTwoColor(colorTwo);
    triangle.setVertexThreeColor(colorThree);
    
    // TEST GET VERTEX 
    // TEST GET VERTEX COLOR *****
    cout << "Expected: '(10,5) 35 2 255', Actual: '"
         << triangle.getVertexOne() << " " << triangle.getVertexOneColor()
         << "'" << endl;
    cout << "Expected: '(10,5) 53 24 5', Actual: '"
         << triangle.getVertexTwo() << " " << triangle.getVertexTwoColor()
         << "'" << endl;
    cout << "Expected: '(10,5) 100 100 100', Actual: '"
         << triangle.getVertexThree() << " " << triangle.getVertexThreeColor()
         << "'" << endl;
    
    // TEST WRITE
    cout << "Testing Write: " << endl;
    triangle.write(cout);
    
    cout << endl << endl;
    
    cout << "Testing Triangle Class pt2:" << endl << endl;
    
    Color COLOR1;
    Color COLOR2;
    Color COLOR3;
    Point PT1;
    Point PT2;
    Point PT3;
    Point PT4(5,5);
    Point PT5(10,4);
    Point PT6(11,3);
        
    Triangle TRIANGLE1;
    Triangle TRIANGLE2(PT1, PT2, PT3, COLOR1);
    Triangle TRIANGLE3(PT1, COLOR1, PT2, COLOR2, PT3, COLOR3);
        
    cout << "Expected: (0,0),0 0 0 (0,0),0 0 0(0,0),0 0 0 Actual: "
         << TRIANGLE2 << endl;
    cout << "Expected: (0,0),0 0 0 (0,0),0 0 0(0,0),0 0 0 Actual: "
         << TRIANGLE3 << endl;
    cout << "Expected: 0 0 0, Actual: " << TRIANGLE2.getVertexOneColor()
         << endl;
    cout << "Expected: 0 0 0, Actual: " << TRIANGLE2.getVertexTwoColor()
         << endl;
    cout << "Expected: 0 0 0, Actual: " << TRIANGLE2.getVertexThreeColor()
         << endl;
        
    //setVertex tests
    TRIANGLE1.setVertexOne(PT4);
    TRIANGLE1.setVertexTwo(PT4);
    TRIANGLE1.setVertexThree(PT4);
    TRIANGLE1.setColor(COLOR2);
    cout << "Expected: (5,5) 0 0 0 (5,5) 0 0 0 (5,5) 0 0 0, Actual: "
         << TRIANGLE1 << endl;;
        
    //getVertex tests
    cout << "Expected: (5,5)(5,5)(5,5), Actual: "
         << TRIANGLE1.getVertexOne() << TRIANGLE1.getVertexTwo()
         << TRIANGLE1.getVertexThree() << endl;
    
    cout << "Expected: (0,0)(0,0)(0,0)0 0 0, Actual: "
         << TRIANGLE2.getVertexOne() << TRIANGLE2.getVertexTwo()
         << TRIANGLE2.getVertexThree() << TRIANGLE2.getVertexOneColor()
         << endl;
        
    cout << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0, Actual: ";
    TRIANGLE3.write(cout);
    cout << endl;
    
    cout << "---------------------------------------------" << endl;
}

void test_Circle(){
    cout << "Testing Circle Class pt1:" << endl << endl;
    
    Point pt(3, 9);
    Point pt2(12,12);
    int r = 4;
    int r2 = 6;
    Color c;
    
    // TEST CONSTRUCTORS *****
    Circle circle1(pt, r, c);
    Circle circle2;
    Circle circle3;
    cout << "Testing Constructor1: " << circle1;
    cout << "Testing Constructor2: " << circle2;
    circle3.setCenter(pt2);
    circle3.setRadius(r);
    circle3.setColor(c);
    cout << "Testing Constructor3: " << circle3;
    
    // TEST SET CENTER 
    circle1.setCenter(pt);
    
    // TEST SET RADIUS *****
    circle1.setRadius(r);
    circle2.setRadius(6);
    int radius = 2;
    circle3.setRadius(radius);
    cout << "Expected: (3,9), 4, 0 0 0, Actual: " << circle1.getCenter() << ","
         << circle1.getRadius() << ", " << circle1.getColor() << endl;
    
    cout << "Expected: (0,0), 2, 0 0 0, Actual: " << circle3.getCenter() << ","
         << circle3.getRadius() << ", " << circle3.getColor() << endl;
    
    // TEST
    circle2.setCenter(pt2);
    circle2.setRadius(r2);
    cout << "Expected: (12,12), 6, 0 0 0, Actual: " << circle2.getCenter()
         << ", " << circle2.getRadius() << ", " << circle2.getColor() << endl;
    
    cout << endl;
    
    
    cout << "Testing Circle pt2:" << endl << endl;

    Color COLOR;
    Point PT;
    Point PT2(10,5);
    int X = 10;
    Circle CIRCLE1;
    Circle CIRCLE2(PT, 5, COLOR);
    cout << "Expected:(10, 5), 5 0 0 0, Actual: " << CIRCLE2;
        
    CIRCLE2.setCenter(PT2);
    CIRCLE2.setRadius(X);
    cout << "Expected: (10,5), 10, 0 0 0, Actual: " << CIRCLE2.getCenter()
         << " " << CIRCLE2.getRadius() << " " << CIRCLE2.getColor() << endl;
        
    CIRCLE1.setCenter(PT2);
    CIRCLE1.setRadius(10);
    CIRCLE1.setColor(COLOR);
        
    cout << "Expected: (10,5), 10, 0 0 0, Actual: " << CIRCLE1.getCenter()
         << " " << CIRCLE1.getRadius() << " " << CIRCLE1.getColor() << endl;
    
    cout << "Expected: (10,5), 10, 0 0 0, Actual: " << CIRCLE1;
    
    cout << "---------------------------------------------" << endl;
}

void test_Rectangle(){
    cout << "Testing Rectangle Class pt1:" << endl << endl;
    
    Point pt1(5,10);
    Point pt2(12,12);
    Color color;
    Color cTopLeft(0, 4, 255);
    Color cTopRight(250, 250, 94);
    Color cBottomRight(35, 32, 59);
    Color cBottomLeft;
    
    // TEST CONSTRUCTORS 1
    Rectangle rectangle1(pt1, pt2, color);
    cout << "Testing Constructor1: " << rectangle1 << endl;
    
    // TEST CONSTRUCTORS 2
    Rectangle rectangle2(pt1, pt2, cTopLeft, cTopRight, cBottomRight,
                         cBottomLeft);
    cout << "Testing Constructor2: " << rectangle2 << endl;
    
    // TEST GET END
    rectangle1.setEnd(pt2);
    cout << "Expected: (12,12), Actual: " << rectangle1.getEnd() << endl;
    
    // TEST SET COLOR
    rectangle1.setColor(cTopLeft);
    cout << "Expected: 0 4 255, 0 4 255, 0 4 255, 0 4 255, Actual: "
         << rectangle1.getColorTopLeft() << " "
         << rectangle1.getColorTopRight() << " "
         << rectangle1.getColorBottomLeft() << " "
         << rectangle1.getColorBottomRight() << endl;
    
    // TEST SET START
    rectangle2.setStart(pt1);
    cout << "Expected: (5,10), Actual: " << rectangle2.getStart() << endl;
    
    cout << endl;
    
    
    cout << "Testing Rectangle pt2:" << endl << endl;
    
    Point PT1;
    Point PT2(10,10);
    Color COLOR1;
    Color COLOR2;
    Color COLOR3;
    Color COLOR4;
    Color COLOR5(10, 5, 4);
    
    Rectangle RECTANGLE1;
    Rectangle RECTANGLE2(PT1, PT2, COLOR1);
    Rectangle RECTANGLE3(PT1, PT2,COLOR1, COLOR2, COLOR3, COLOR4);
        
    cout << "Testing rectangle2:" << RECTANGLE2 << endl;
    
    cout << "Testing rectangle3:" << RECTANGLE2 << endl;
        
    RECTANGLE2.setEnd(pt2);
    cout << "Expected: (12,12), Actual: " << RECTANGLE2.getEnd() << endl;
    RECTANGLE2.setColorTopLeft(COLOR1);
    RECTANGLE2.setColorTopRight(COLOR5);
    RECTANGLE2.setColorBottomRight(COLOR1);
    RECTANGLE2.setColorBottomLeft(COLOR5);
    cout << "Testing rectangle2:" << RECTANGLE2 << endl;
        
        
    RECTANGLE2.setStart(pt2);
    cout << "Expected: (12,12), Actual: " << RECTANGLE2.getStart() << endl;
    
    cout << "---------------------------------------------" << endl << endl;
}
