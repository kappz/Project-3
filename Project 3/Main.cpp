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
	void move(int vel);
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

void Ship::move(int vel)
{
	if (vel < 0)  // if speed is set below min
	{
		vel = 0;
	}
	if (vel > speed)  // if speed is set above max
	{
		vel = speed;
	}
	// compute new start square if movement is within board bounds
	if (orient == north && ( ((startRow - vel) - (length - 1)) >= 1) )
	{
		startRow -= vel;
	}
	else if (orient == south && ( ((startRow + vel) + (length - 1)) <= 10) )
	{
		startRow += vel;
	}
	else if (orient == east && ( ((startCol + vel) + (length - 1)) <= 10) )
	{
		startCol += vel;
	}
	else if (orient == west && ( ((startCol - vel) - (length - 1)) >= 1) )
	{
		startCol -= vel;
	}
	// compute new start square if movement exceeds board bounds
	else if (orient == north && ( ((startRow - vel) - (length - 1)) < 1) )
	{
		startRow = 1;
		orient = south;
	}
	else if (orient == south && ( ((startRow + vel) + (length - 1)) > 10) )
	{
		startRow = 10;
		orient = north;
	}
	else if (orient == east && ( ((startCol + vel) + (length - 1)) > 10) )
	{
		startCol = 10;
		orient = west;
	}
	else if (orient == west && ( ((startCol - vel) - (length - 1)) < 1) )
	{
		startCol = 1;
		orient = east;
	}
}

void Ship::getHit(Ship shipType)
{

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
	speed = 3;
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

class Sub : public Ship
{
public:
	Sub(OrientType, int, int);
	void setUwater(bool);
	bool getUwater();

private:
	bool uWater;
};

// sub function definitions
Sub::Sub(OrientType orientation, int begRow, int begCol)
	: Ship(orientation, begRow, begCol)
{
	type = "sub";
	length = 2;
	speed = 2;
	damage = 2;
	uWater = false;
}

void Sub::setUwater(bool tempUWater)
{
	uWater = tempUWater;
}

bool Sub::getUwater()
{
	return uWater;
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

	char choice;
	int numShips, shipId, vel, attackedId;
	string direction, shipType;
	int startRow, startCol;
	vector<Ship *> fleet;

	cin >> choice;
	while (choice != 'q') {
		if (choice == 'i') {// initialize
			cin >> numShips;
			fleet.resize(numShips);
			for (int i = 0; i < numShips; i++) {
				cin >> shipType >> direction >> startRow >> startCol;
				if (shipType == "destroy")
					fleet[i] = new Destroyer(str2Orient(direction), startRow, startCol);
				else if (shipType == "carry") {
					fleet[i] = new Carrier(str2Orient(direction), startRow, startCol);
				}
				else if (shipType == "sub") {
					fleet[i] = new Sub(str2Orient(direction), startRow, startCol);
				}
			}
		}
		else if (choice == 's') {// status of fleet
			for (int i = 0; i < fleet.size(); i++)
				cout << (fleet[i]) << endl;
		}
		else if (choice == 'm') { // move
			cin >> shipId >> vel;
			fleet[shipId]->move(vel);
		}
		cin >> choice;
	}
	return 0;
}