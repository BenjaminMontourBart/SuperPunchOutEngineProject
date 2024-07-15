#pragma once


typedef unsigned char uchar;
class Color
{
public:

	void Set(const Color& other);
	Color(uchar red, uchar green, uchar blue, uchar alpha = 255);
	uchar red = 255;
	uchar green = 255;
	uchar blue = 255;
	uchar alpha = 255;

};

static const Color& Red = Color(255, 0, 0);
static const Color& Green = Color(0, 255, 0);
static const Color& Blue = Color(0, 0, 255);

