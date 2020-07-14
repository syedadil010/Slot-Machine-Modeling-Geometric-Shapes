#pragma once

#include<iomanip>
#include<string>
#include<vector>

/*
Shape class is the base class for all the  the classes in the project.
It has id, name and description of each shape
*/

using namespace std;
class Shape
{
	
	private:
		int id;
		string name;
		string description;
	public:
		using Grid = vector<vector<char>>;
		Shape();
		Shape(const Shape&);
		int get_id();
		string get_Desc();
		string get_Name();
		void set_Name(string);
		void set_Desc(string);
		virtual string toString() ;
		virtual double area() = 0;
		virtual double perimeter() =0;
		virtual double screenArea() = 0;
		virtual double screenPerimeter() = 0;
		virtual Grid draw(char f='*',char c=' ') = 0;
		virtual double b_Height() = 0;
		virtual double b_Width() = 0;
		friend ostream& operator<<(ostream& out, Shape&  sh);
		
};