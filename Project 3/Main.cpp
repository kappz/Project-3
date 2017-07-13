#pragma once
/*
Author: Peter O'Donohue
Creatoin Date: 07/11/17
Modification Date: 07/11/17
Description: FILL IN LATER
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum OrientType { north, south, east, west };

class Ship
{
public:
	Ship(OrientType, int, int);
	int getSpeed();
	int getDamage();
	int getStartRow();
	int getStartCol();
	string getType();
	OrientType getOrient();
	void move(const int& speed);
	void getHit(Ship shipType);

protected:
	int speed;
	int length;
	int damage;
	int startRow;
	int startCol;
	string type;
	OrientType orient;
};

Ship::Ship(OrientType orientation, int begRow, int begCol)
{
	// verify legal orientation 
	if (orientation == north || orientation == south || orientation == east || orientation == west)
	{
		orient = orientation;
	}
	else
	{
		cout << "Invalid ship orientation" << endl;
	}
	if (begRow < 1 || begRow > 10 || begCol) // verify legal bounds
	{
		cout << "Invavlid start row and or start column" << endl;
	}
	else
	{
		startRow = begRow;
		startCol = begCol;
	}
}
int Ship::getSpeed()
{
	return speed;
}

int Ship::getDamage()
{
	return damage;
}

int Ship::getStartRow()
{
	return startRow;
}

int Ship::getStartCol()
{
	return startCol;
}

string Ship::getType()
{
	return type;
}

OrientType Ship::getOrient()
{
	return orient;
}

class Destroyer : public Ship
{
public:
	Destroyer(OrientType, int, int);

};

Destroyer::Destroyer(OrientType orientation, int begRow, int begCol)
	: Ship(orientation, begRow, begCol)
{
	type = "destroyer";
	speed = 0;
	length = 3;
	damage = 4;
	

}

OrientType str2Orient(string dir) {
	if (dir == "north") return north;
	else if (dir == "south") return south;
	else if (dir == "east") return east;
	else return west;
}

string orient2Str(OrientType orient)
{
	if (orient == north)
		return "north";
	else if (orient == south)
		return "south";
	else if (orient == east)
		return "east";
	else
		return "west";
}

ostream & operator<<(ostream &out, Ship* ship)
{
	out << ship->getType() << " "
		<< ship->getStartRow() << " "
		<< ship->getStartCol() << " "
		<< ship->getDamage() << " "
		<< ship->getSpeed() << " "
		<< orient2Str(ship->getOrient());

	return out;
}

int main()
{
	Ship* a = new Destroyer(str2Orient("south"), 1, 10);
	cout << a;
	system("pause");
	return 0;
}