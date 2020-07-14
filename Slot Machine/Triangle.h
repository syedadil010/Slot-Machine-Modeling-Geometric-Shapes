#pragma once
#include"pch.h"
#include"Shape.h"
#include<iomanip>
#include<string>
#include<vector>

using namespace std;
class Triangle: public Shape
{
	
public:
	using Grid = vector<vector<char>>;
	Triangle();
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual double screenArea() = 0;
	virtual double screenPerimeter() = 0;
	virtual Grid draw(char, char) = 0;
	virtual double b_Height() = 0;
	virtual double b_Width() = 0;
};