# Project 4 - CoolPics

A C++ graphics program that generates BMP images by reading and drawing geometric shapes from text-based input files. The project implements classes for points, colors, lines, circles, triangles, and rectangles, along with file parsing, image generation, and testing.

## Overview
This project builds a simple drawing system that creates 100 x 100 bitmap images from shape descriptions stored in text files. The program:
- Loads drawing instructions from a text file
- Parses and draws lines, circles, triangles, and rectangles
- Stores pixel data in a graphics canvas
- Writes the final image to a BMP file
- Includes test functions for the main classes

The project is structured using multiple classes to represent geometric objects and color data, with a driver program that handles loading and writing image files. :contentReference[oaicite:3]{index=3} :contentReference[oaicite:4]{index=4} :contentReference[oaicite:5]{index=5}

## How to Run
Compile the program:
```bash
g++ Point.cpp Color.cpp Line.cpp Circle.cpp Triangle.cpp Rectangle.cpp Graphics.cpp pics.cpp start.cpp test.cpp -o coolpics
```

Run the program:
```bash
./coolpics
```

Then choose whether to run the test suite or use the CoolPics program.

## Concepts Used
- Object-oriented programming with classes
- File input and output
- Geometric modeling with points, lines, circles, triangles, and rectangles
- Pixel-based image generation
- Input validation and parsing
- Testing class functionality
- Working across multiple C++ source files

## Program Structure
- `Point.cpp`: Represents 2D points and coordinate validation
- `Color.cpp`: Represents RGB colors and range checking
- `Line.cpp`: Represents and draws lines
- `Circle.cpp`: Represents and draws circles
- `Triangle.cpp`: Represents and draws triangles
- `Rectangle.cpp`: Represents and draws rectangles
- `Graphics.cpp`: Stores image pixel data and writes BMP files
- `pics.cpp`: Main CoolPics program logic for loading shape files and writing images
- `start.cpp`: Entry point and menu system
- `test.cpp`: Test suite for the project classes

## Contributions
This project was completed with one partner.

## Example Features
- Reads shape data from `.txt` files
- Draws multiple geometric shapes onto a canvas
- Supports RGB color values for shapes
- Exports finished drawings as `.bmp` image files
- Includes class-based testing for major components

## Example Usage
```text
1) Execute testing functions in test.cpp
2) Execute coolPics() function to make pics
Choice --> 2
```

```text
Command:            Description:
--------            ------------
load filename       Loads data from a txt file
write filename      Creates a bmp image from data
quit                Quits the program
```
