#pragma once

#include"array"
#include"Shape.h"
#include<vector>
using Grid = vector<vector<char>>;
/*
Class inherits shape class reprsents slot Machine
*/
class SlotMachine
{
	std::array<std::unique_ptr<Shape>, 3> reel{};
	void make_shapes();
	void make_shape(int k);
	void display();
public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine(const SlotMachine&&) = delete;
	SlotMachine& operator=(const SlotMachine&) = delete;
	SlotMachine& operator=(SlotMachine&&) = delete;
	virtual ~SlotMachine() = default;
	void run();
	int calculatepayline(int bet);
	Grid & reelsongrid();
	Grid & drawongrid(Grid& out, Grid b1, int i, int j);
	int getmaxheight();
	double getwidth();
	Grid & createnewgrid(Grid& g, int h, int w);
	void printgrid(Grid g);
};