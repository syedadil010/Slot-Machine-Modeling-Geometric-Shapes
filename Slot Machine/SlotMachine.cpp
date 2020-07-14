
#pragma once
#include<iostream>
#include"SlotMachine.h"
#include"Rhombus.h"
#include"AcuteTriangle.h"
#include"RightTriangle.h"
#include"Rectangle.h"
using namespace std;
using Grid = vector<vector<char>>;


/*

run method runs the game.It takes input from user for bet and calls other methods to display shapes and prize
*/
void SlotMachine::run()
{
	cout << "Welcome to 3-Reel Lucky Slot Machine Game!\n";
	int slot_token = 10;
	while (slot_token != 0)
	{
		cout << "How much would you like to bet (enter 0 to quit)?\n";
		int bet = 0;
		int n, h, w;
		
		cin >> bet;
		if (bet < 0)
		{
			cout << "No negative bets , try again!\n";
		}
		else if (bet == 0)
		{
			cout << "Thank you for playing\nBe sure to cash your  remaining " << slot_token << "tokens at the bar\n Game over.\n";
			break;
		}
		else if (slot_token == 0)
		{
			cout << "you lose!\n You have " << slot_token << " tokens\n";
			break;
		}
		else
		{
			for (int k = 0; k < 3; k++)
			{
				n = (rand() % (3 + 1 - 0)) + 0;
				w = (rand() % (25 + 1 - 1)) + 1;
				if (n == 0)
				{
					this->reel[k].reset(new Rhombus(w));
				}
				else if (n == 1)
				{
					this->reel[k].reset(new AcuteTriangle(w));
				}
				else if (n == 2)
				{
					this->reel[k].reset(new AcuteTriangle(w));
				}
				else
				{
					h = (rand() % (25 + 1 - 1)) + 1;
					this->reel[k].reset(new Rectangle(w, h));
				}
			}
			reelsongrid();
			int payout = calculatepayline(bet);
			//cout << payout;
			slot_token = slot_token + payout;
			cout << "You now have " << slot_token << "tokens\n";
		}
	}
}

/*
computes and outputs the payout/prize 
*/
int SlotMachine::calculatepayline(int bet)
{
	string n1 = this->reel[0]->get_Name();
	string n2 = this->reel[1]->get_Name();
	string n3 = this->reel[2]->get_Name();
	double a1 = this->reel[0]->screenArea();
	double a2 = this->reel[1]->screenArea();
	double a3 = this->reel[2]->screenArea();
	cout << "\n(" << this->reel[0]->get_Name() << "," << this->reel[0]->b_Height() << ", " << this->reel[0]->b_Width() << ") ";
	cout << "\n(" << this->reel[1]->get_Name() << "," << this->reel[0]->b_Height() << ", " << this->reel[0]->b_Width() << ") ";
	cout << "\n(" << this->reel[2]->get_Name() << "," << this->reel[0]->b_Height() << ", " << this->reel[0]->b_Width() << ") ";
	if ((n1 == n2 || n2 == n3 || n3 == n1) && (a1 == a2 || a2 == a3 || a3 == a1))
	{
		cout << "Jackpot! 2 similar shapes AND 2 Equal Screen Areas\n Congrats! you win 3 times your bet: " << 3 * bet<<endl;
		return 3 * bet;
	}
	else if (n1 == n2 && n2 == n3)
	{
		cout << "3 similar shapes\n congrats! you win 2 times your bet: " << 2 + bet<<endl;
		return 2 * bet;
	}
	else if (a2 > a1 + a2)
	{
		cout << "Middle > Left+Right, in Screen Areas\n congrats, you win your bet : " << bet<<endl;
		return bet;
	}
	else if (n1 == n3)
	{
		cout << "Lucky this time!\n You dont win , you dont lose, you are safe!\n";
		return 0;
	}
	else
	{
		cout << "You lose your bet\n";
		return -1;
	}
}

/*
draws the 3 shapes from reel on the main grid and returns it
*/
Grid& SlotMachine::reelsongrid()
{
	Grid out;
	out=createnewgrid(out,getmaxheight() + 2, getwidth() + 10);
	Grid box_0 = this->reel[0]->draw();
	Grid box_1 = this->reel[1]->draw();
	Grid box_2 = this->reel[2]->draw();
	drawongrid(out, box_0, 1, 2);
	drawongrid(out, box_1, 1, 2 + this->reel[0]->b_Width() + 3);
	drawongrid(out, box_2, 1, 2 + this->reel[0]->b_Width() + 3+ this->reel[1]->b_Width()+3);
	printgrid(out);
	return out;

}

/*
draws a shape on main grid 
*/
Grid& SlotMachine::drawongrid(Grid &out,Grid b1, int h, int w)
{
	for (int i = 0 ; i < b1.size(); i++)
	{
		for (int j = 0; j < b1.at(0).size(); j++)
		{
			out[i+h][j+w] = b1.at(i).at(j);
		}
	}
	return out;
}


/*
returns the height for the main grid
*/

	int SlotMachine::getmaxheight()
	{

		double m1=std::max(this->reel[0]->b_Height(), this->reel[1]->b_Height());
		int m2= std::max(m1, this->reel[2]->b_Height());
			return m2;
	}
	double SlotMachine::getwidth()
	{
		int t=this->reel[0]->b_Width() + this->reel[1]->b_Width() + this->reel[2]->b_Width();
		return t;
	}


/*
creates a new grid with border according to the max and height and total width

*/

Grid& SlotMachine::createnewgrid(Grid& g,int h, int w)
{
		for (int i = 0; i < h; i++)
		{
			vector<char> t1;
			for (int j = 0; j < w; j++)
			{	
				t1.push_back(' ');
			}
			g.push_back(t1);
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || i == h - 1)
				{
					g[i][j] = '-';
				}
				if (j == 0|| j==w-1)
				{
					g[i][j] = '|';

				}
				if (i == 0 && j == 0 || i == 0 && j == w - 1 || i == h - 1 && j == 0 || i == h - 1 && j == w - 1)
				{
					g[i][j] = '+';
				}
			}
		}
		return g;
	}

/*
prints the grid to console
*/

	void SlotMachine::printgrid(Grid g)
	{
		
		for (int i = 0; i < g.size(); i++)
		{
			vector<char> t1;
			for (int j = 0; j < g.at(0).size(); j++)
			{
				cout << g[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}