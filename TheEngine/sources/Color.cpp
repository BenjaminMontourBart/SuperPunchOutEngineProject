#include "Color.h"



void Color::Set(const Color& other)
{
	red = other.red;
	green = other.green;
	blue = other.blue;
	alpha = other.alpha;
}

Color::Color(uchar _red, uchar _green, uchar _blue, uchar _alpha)
{
	red = _red;
	green = _green;
	blue = _blue;
	alpha = _alpha;	
}

