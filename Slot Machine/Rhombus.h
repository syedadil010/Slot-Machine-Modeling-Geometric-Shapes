
#include"Shape.h"
#include<typeinfo>
#include<vector>
/*
Class  inherits shape class
*/
class Rhombus :public Shape
{
	
private:
	double d;
public:
	Rhombus(double, string description = "Diamond", string name = "A parallelogram with equal sides");
	Rhombus(const Rhombus& r) : Shape(r) {};
	double area() override;
	double perimeter() override;
	double screenArea() override;
	double screenPerimeter() override;
	Grid draw(char fChar = '*', char bChar = ' ') override;
	double b_Height() override;
	double b_Width() override;
	friend ostream& operator<<(ostream& out, Rhombus& rhombus);
	//friend ostream& operator<<(ostream& out, const Grid& g);
};