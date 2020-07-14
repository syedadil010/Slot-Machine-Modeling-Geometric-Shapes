
#include"Shape.h"
#include<typeinfo>
/*
Class  inherits shape class
*/

class Rectangle :public Shape
{
	private:
		double h;
		double w;
	public:
		Rectangle(double,double,string description = "Four-sided", string name = "Four right angles");
		Rectangle(const Rectangle& r) : Shape(r) {};
		double area() override;
		double perimeter() override;
		double screenArea() override;
		double screenPerimeter() override;
		Grid draw(char fChar = '*', char bChar = ' ') override;
		double b_Height() override;
		double b_Width() override;
		friend ostream& operator<<(ostream& out, Rectangle&);
		
};