
#include<iostream>
#include "Rhombus.h"
using Grid = vector<vector<char>>;


/*
class represents Rhombus

*/

/*
constructor intializes sides and intializes base class name and description
*/


Rhombus::Rhombus(double side, string name, string description)
{
	int si = side;
	if( si % 2 == 0)
	{
		si = si + 1;
	}
	this->d= si;
	this->set_Desc(description);
	this->set_Name(name);
}

/*
returns Geometric Area
*/
double Rhombus::area()
{
	return (d*d)/2;
}
/*
returns Geometric Perimeter
*/
double Rhombus::perimeter()
{
	return 2 * 1.414 * d;
}

/*
returns Screen Area
*/

double Rhombus::screenArea()
{
	int n = d / 2;
	return (2*n*(n+1))+1;
}

/*
returns screen perimeter
*/
double Rhombus::screenPerimeter()
{
	return 2 * (d-1);
}


/*
draws the Rhombus shape
*/
Grid Rhombus::draw(char fChar, char bChar)
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
	int hh = (b_Height() / 2) +1;
	int i = 0;
	for (i = 0; i <hh; i++)
	{
		int j = 0;
		while (j < hh - i - 1)
		{
			g[i][j] = bChar;
			j++;
		}
		int k = 0;
		while (k != (2 * (i + 1)) - 1)
		{
			g[i][j] = fChar;
			j++;
			k++;
		}
	}
	Grid g1 = g;
	int f = 0;
	int s = hh;
	for (int i = hh-1; i>0; i--)
	{
		vector<char> n1;
		for (int j = 0; j < b_Width(); j++)
		{
			n1.push_back(g1.at(i-1).at(j));
		}
		g[s] = n1;
		s++;
		f++;
	}
	return g;
}
/*
returns height of bounding box
 */

double Rhombus::b_Height()
{
	return d;
}
/*
returns width of bounding box
*/
double Rhombus::b_Width()
{
	return d;
}
/*
operator << overload calls toString()
*/


ostream & operator<<(ostream & out,Rhombus& rom)
{
	cout<<rom.toString();
	return out;
}
/*ostream & operator<<(ostream & out, Grid g)
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