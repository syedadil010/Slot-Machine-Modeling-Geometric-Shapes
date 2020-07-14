#include "pch.h"
#include<iostream>
#include "Rectangle.h"

using Grid = vector<vector<char>>;

/*
class represents Rectangle

*/

/*
constructor intializes sides and intializes base class name and description
*/

Rectangle::Rectangle(double width, double height, string name, string description)
{
	w = width;
	h = height;
	this->set_Desc(description);
	this->set_Name(name);
}


/*
returns Geometric Area
*/
double Rectangle::area()
{
	return h * w;
}
/*
returns Geometric Perimeter
*/
double Rectangle::perimeter()
{
	return 2 * (h + w);
}

/*
returns Screen Area
*/
double Rectangle::screenArea()
{
	return h * w;
}

/*
returns screen perimeter
*/
double Rectangle::screenPerimeter()
{
	return 2 * (h + w) - 4;
}

/*
draws the Rectangle shape
*/

Grid Rectangle::draw(char fChar, char bChar)
{
	Grid g;
	for (int i = 0; i <b_Height(); i++)
	{
		vector<char> t1;
		for (int j = 0; j < b_Width(); j++)
		{
			t1.push_back(fChar);
		}
		g.push_back(t1);
	}


	return g;
}

/*
returns height of bounding box
 */
double Rectangle::b_Height()
{
	return h;
}
/*
returns width of bounding box
*/
double Rectangle::b_Width()
{
	return w;
}
/*
operator << overload calls toString()
*/
ostream & operator<<(ostream & out,Rectangle& Rectangle)
{
	cout<<Rectangle.toString();
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