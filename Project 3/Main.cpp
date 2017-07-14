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

// Ship function definitions
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
	if (begRow < 1 || begRow > 10) // verify legal bounds
	{
		cout << "Invalid start row" << endl;
	}
	else if (begCol < 1 || begCol > 10)
	{
		cout << "Invalid start column." << endl;
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

// Destroyer function definitions
Destroyer::Destroyer(OrientType orientation, int begRow, int begCol)
	: Ship(orientation, begRow, begCol)
{
	type = "Destroyer";
	speed = 0;
	length = 3;
	damage = 4;

	// verify ship doesn't exceed the board's boundaries when placed at starting square
	if (orientation == south && (begRow + (length - 1) > 10))
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == north && (begRow - (length - 1)) < 1)
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == east && (begRow + (length - 1) > 10))
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == west && (begCol - (length - 1)) < 1)
	{
		cout << "Invalid ship placement, ship extends the board's bounds." << endl;
	}
}

class Carrier : public Ship
{
public:
	Carrier(OrientType, int, int);
};

// Carrier function definitions
Carrier::Carrier(OrientType orientation, int begRow, int begCol)
	: Ship(orientation, begRow, begCol)
{
	type = "Carrier";
	speed = 1;
	length = 4;
	damage = 3;

	// verify ship doesn't exceed the board's boundaries when placed at starting square
	if (orientation == south && (begRow + (length - 1) > 10))
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == north && (begRow - (length - 1)) < 1)
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == east && (begRow + (length - 1) > 10))
	{
		cout << "Invalid ship placement, ship extends beyond the board's bounds." << endl;
	}
	if (orientation == west && (begCol - (length - 1)) < 1)
	{
		cout << "Invalid ship placement, ship extends the board's bounds." << endl;
	}
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
	Ship* a = new Destroyer(str2Orient("south"), 8, 9);
	Ship* b = new Carrier(str2Orient("south"), 7, 4);
	cout << a << endl << b << endl;
	system("pause");
	return 0;
}