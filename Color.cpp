/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Caitlin Berry and Liad Gross
 * cnberry and liadgr
 *
 * Contains implementations of functions in the color class which represent a color in RGB mode.
 */

#include "Color.h"

// create the default constructor
Color::Color(){
    red = 0;
    green = 0;
    blue = 0;
}

// create the non-default constructor which sets RGB values inside the range
Color::Color(int redVal, int greenVal, int blueVal){
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

void Color::setRed(int redVal){
    red = checkRange(redVal);
}

int Color::getRed(){
    return red;
}

void Color::setGreen(int greenVal){
    green = checkRange(greenVal);
}

int Color::getGreen(){
    return green;
}

void Color::setBlue(int blueVal){
    blue = checkRange(blueVal);
}

int Color::getBlue(){
    return blue;
}

void Color::read(istream& ins){
    // read in all RGB values from a file and asign the cooresponding colors
    ins >> red;
    ins >> green;
    ins >> blue;
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

void Color::write(ostream& outs){
    outs << red << " ";
    outs << green << " ";
    outs << blue;
}

int Color::checkRange(int val){
    int maxRGBValue = 255;
    if (val >= 0 && val <= maxRGBValue){
        return val;
    // return the closest of 0 and DIMENSION - 1 if val is out of range
    } else if (val < 0){
        return 0;
    } else {
        return maxRGBValue;
    }
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
