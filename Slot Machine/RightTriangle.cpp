
#include<iostream>
#include "RightTriangle.h"

using Grid = vector<vector<char>>;

/*
class represents Rectangle

*/
/*
constructor intializes sides and intializes base class name and description
*/

RightTriangle::RightTriangle(double base, string name, string description)
{
	b = base;
	h = b;
	Shape::set_Desc(description);
	Shape::set_Name(name);
}

/*
returns Geometric Area
*/

double RightTriangle::area()
{
	return (b*h) / 2;
}

/*
returns Geometric Perimeter
*/
double RightTriangle::perimeter()
{
	return (2+sqrt(2))*h;
}

/*
returns Screen Area
*/

double RightTriangle::screenArea()
{
	return (h * (h+1))/2;
}


/*
returns screen perimeter
*/
double RightTriangle::screenPerimeter()
{
	return 3 * (h - 1);
}

/*
draws the Rectangle shape
*/
Grid RightTriangle::draw(char fChar, char bChar)
{
	Grid g;
	for (int i = 0; i < b_Height(); i++)
	{
		vector<char> t1;
		for (int j = 0; j < b_Width(); j++)
		{
			t1.push_back(bChar);
		}
		g.push_back(t1);
	}
	for (int i = 0; i < b_Height(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			g[i][j]=fChar;
		}
	}
	return g;
}
/*
returns height of bounding box
 */
double RightTriangle::b_Height()
{
	return h;
}
/*
returns width of bounding box
*/
double RightTriangle::b_Width()
{
	return b;
}
/*
operator << overload calls toString()
*/
ostream & operator<<(ostream & out, RightTriangle& RightTriangle)
{
	cout<<RightTriangle.toString();
	return out;
}


/*
ostream & operator<<(ostream & out, Grid g)
{
	for (const auto& row : g)
	{
		for (const auto& ch : row)
		{
			out << ch;
		}
		out << endl;
	}
	return out;
}*/