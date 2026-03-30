/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Caitlin Berry and Liad Gross
 * cnberry and liadgr
 *
 * Contains implementations of functions in the point class which represent coordinate points of images.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// create the default constructor
Point::Point(){
    x = 0;
    y = 0;
}

// create the non-default constructor
Point::Point(int xVal, int yVal){
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// sets the x-coordinate of the point
void Point::setX(int xVal){
    x = checkRange(xVal);
}

int Point::getX(){
    return x;
}

// sets the y-coordinate of the point
void Point::setY(int yVal){
    y = checkRange(yVal);
}

int Point::getY(){
    return y;
}

void Point::read(istream& ins){
    char garbage;
    // read in garbage values for the '(' ',' and ')' part of the coordinate pt
    ins >> garbage;
    ins >> x;
    ins >> garbage;
    ins >> y;
    ins >> garbage;
    x = checkRange(x);
    y = checkRange(y);
}

void Point::write(ostream& outs){
    outs << '(' << x << ',' << y << ')';
}

int Point::checkRange(int val){
    if (val >= 0 && val < DIMENSION){
        return val;
    // return the closest of 0 and DIMENSION - 1 if val is out of range
    } else if (val < 0){
        return 0;
    } else {
        return (DIMENSION - 1);
    }
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
