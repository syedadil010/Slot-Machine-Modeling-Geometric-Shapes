
#include<iostream>
#include "AcuteTriangle.h"

using Grid = vector<vector<char>>;

/*
class represents AcuteTriangle

*/



/*
constructor intializes side and intializes base class name and description
*/
AcuteTriangle::AcuteTriangle(double base, string name, string description)
{
	int si = base;
	if (si % 2 == 0)
	{
		si = si + 1;
	}
	b = si;
	h = (si+1)/2;
	Shape::set_Desc(description);
	Shape::set_Name(name);
}


/*
returns Geometric Area  
*/
double AcuteTriangle::area()
{
	return (b*h)/2;
}
/*
returns Geometric Perimeter
*/
double AcuteTriangle::perimeter()
{
	return b+(2*(sqrt((0.25*b*b)+(h*h))));
}

/*
returns Screen Area
*/
double AcuteTriangle::screenArea()
{
	return h*h;
}

/*
returns screen perimeter
*/
double AcuteTriangle::screenPerimeter()
{
	return 4*(h-1);
}

/*
draws the Acute Triangle shape
*/
Grid AcuteTriangle::draw(char fChar, char bChar)
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
		int j = 0;
		while(j < b_Height()-i-1)
		{
			g[i][j] = bChar;
			j++;
		}
		int k = 0;
		while(k!=(2*(i+1))-1)
		{
			g[i][j] = fChar;
			j++;
			k++;
		}
	}

	return g;
}

/*
returns height of bounding box
 */
double AcuteTriangle::b_Height()
{
	return h;
}
/*
returns width of bounding box
*/
double AcuteTriangle::b_Width()
{
	return b;
}
/*
operator << overload calls toString()
*/
ostream & operator<<(ostream & out, AcuteTriangle& AcuteTriangle)
{
	cout<<AcuteTriangle.toString();
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