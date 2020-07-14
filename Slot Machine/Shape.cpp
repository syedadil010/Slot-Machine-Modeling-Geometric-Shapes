
#include "Shape.h"
#include<iostream>
/*constructor initializes id*/
Shape::Shape()
{
	static int sid = 1;
	this->id = sid;
	sid++;
}

/*
returns id
*/
int Shape::get_id()
{
	return id;
}
/*
returns description
*/
string Shape::get_Desc()
{
	return description;
}

/*
returns Name
*/
string Shape::get_Name()
{
	return name;
}

/*
setter method for name variable
*/
void Shape::set_Name(string name)
{
	this->name = name;
}
/*
setter method for description variable
*/
void Shape::set_Desc(string desc)
{
	this->description = desc;
}
/*
Prints the information about shape this method works polymorphicly*/

string Shape::toString()
{
	string s{};

	s+="Shape Information \n";
	s += "------------------\n";
	s += "id:          ";
	s+= to_string(this->get_id());
	s += "\n";
	s += "Shape name:          " + this->get_Name();
	s += "\n";
	s += "Description:          " +this->get_Desc();
	s += "\n";
	s += "B. box width:          ";
	s+=to_string(b_Width());
	s += "\n";
	s += "B. box height:          ";
	s+= to_string(b_Height());
	s += "\n";
	s += "Scr area:          ";
	s+= to_string(screenArea());
	s += "\n";
	s += "Geo area:          ";
	s+= to_string(area());
	s += "\n";
	s += "Scr perimeter:          ";
	s+= to_string(screenPerimeter());
	s += "\n";
	s += "Geo perimeter:          ";
	s+= to_string(perimeter());
	s += "\n";
	s += "Static type:          ";
	s+=typeid(this).name();
	s += "\n";
	s += "Dynamic type:          ";
	s+=typeid(*this).name();
	s += "\n";
	return s;
}
double Shape::area()
{
	return 0.0;
}

double Shape::perimeter()
{
	return 0.0;
}

double Shape::screenArea()
{
	return 0.0;
}

double Shape::screenPerimeter()
{
	return 0.0;
}
double Shape::b_Height()
{
	return 0.0;
}

double Shape::b_Width()
{
	return 0.0;
}

/*
	operator << overload calls tostring()
*/
ostream & operator<<(ostream & out, Shape& sh)
{
	sh.toString();
	return out;
}
vector<vector<char>> Shape::draw(const char fChar,const char bChar)
{
	return vector<vector<char>>();
}