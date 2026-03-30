/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Caitlin Berry and Liad Gross
 * cnberry and liadgr
 *
 * Contains implementations of functions in the rectangle class which represent a rectangle.
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// create the default constructor
Rectangle::Rectangle(){
}

// create the non-default constructor
Rectangle::Rectangle(Point pt1, Point pt2, Color color){
    start = pt1;
    end = pt2;
    // assign all corners to the same color
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft){
    start = pt1;
    end = pt2;
    // assign each corner their own color
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

void Rectangle::setStart(Point pt){
    start = pt;
}

Point Rectangle::getStart(){
    return start;
}

void Rectangle::setEnd(Point pt){
    end = pt;
}

Point Rectangle::getEnd(){
    return end;
}

void Rectangle::setColor(Color color){
    // assign all corners to the same color
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

void Rectangle::setColorTopLeft(Color color){
    colorTopLeft = color;
}

Color Rectangle::getColorTopLeft(){
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color){
    colorTopRight = color;
}

Color Rectangle::getColorTopRight(){
    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color){
    colorBottomRight = color;
}

Color Rectangle::getColorBottomRight(){
    return colorBottomRight;
}

void Rectangle::setColorBottomLeft(Color c){
    colorBottomLeft = c;
}

Color Rectangle::getColorBottomLeft(){
    return colorBottomLeft;
}

void Rectangle::read(istream& ins) {
    // read in all values, assuming each corner has its own color
    ins >> start >> end >> colorTopLeft >> colorTopRight
        >> colorBottomRight >> colorBottomLeft;
    // if each corner has the same color, there will not be enough values to
    // read into the different variables ---> ins will be in a fail state.
    if (ins.fail()) {
        Color mainColor = colorTopLeft;
        // if ins is in fail, it must be cleared to be fixed
        ins.clear();
        // if this branch is executed, it means all corners must be assigned
        // the same color; assign the corners to the first color read
        colorTopRight = mainColor;
        colorBottomRight = mainColor;
        colorBottomLeft = mainColor;
    }
}

void Rectangle::write(ostream& outs) {
    // display the start and end points, along with all four colors
    outs << " " << start << " " << end << " " << colorTopLeft << " "
         << colorTopRight << " " << colorBottomRight << " " << colorBottomLeft;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
