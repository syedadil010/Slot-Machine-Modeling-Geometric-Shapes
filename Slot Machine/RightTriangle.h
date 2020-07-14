#pragma once

#include"Triangle.h"
#include<typeinfo>
#include<vector>

/*
Class  inherits shape class
*/
class RightTriangle :public Triangle
{

private:
	double b, h;
public:
	using Grid = vector<vector<char>>;
	RightTriangle(double base, string name = "Right Triangle", string description = "One right and two acute angles");
	RightTriangle(const RightTriangle& r) : Triangle(r) {};
	double area() override;
	double perimeter() override;
	double screenArea() override;
	double screenPerimeter() override;
	Grid draw(char fChar = '*', char bChar = ' ') override;
	double b_Height() override;
	double b_Width() override;
	friend ostream& operator<<(ostream& out, RightTriangle& Acute);
};