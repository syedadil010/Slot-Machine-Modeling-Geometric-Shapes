
#include"Triangle.h"
#include<typeinfo>
#include<vector>
/*
Class represents Acute Triangle, inherits shape class
*/

class AcuteTriangle :public Triangle
{
	
private:
	double b,h;
public:
	using Grid = vector<vector<char>>;
	AcuteTriangle(double base, string name = "Acute Triangle", string description = "All acute angels");
	AcuteTriangle(const AcuteTriangle& r) : Triangle(r) {};
	double area() override;
	double perimeter() override;
	double screenArea() override;
	double screenPerimeter() override;
	Grid draw(char fChar = '*', char bChar = ' ') override;
	double b_Height() override;
	double b_Width() override;
	friend ostream& operator<<(ostream& out,AcuteTriangle& Acute);
};