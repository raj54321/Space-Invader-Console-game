#include "Ship.h"

#include <iostream>
using namespace std;

void Ship::eraseShip() const
{	
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";
}

void Ship::drawShip() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << "^";
}

Ship::Ship()
{
	coord.setPositionX(55);
	coord.setPositionY(39);
	drawShip();
}

void Ship::updateShip()
{
	drawShip();
}

void Ship::changePosition(char key)
{	
	eraseShip();
	switch(key)
	{
		case 'l' :	
			if(coord.getPositionX()>31 )
				coord.setPositionX(coord.getPositionX()-1);	
			break;
		case 'r' :	
			if (coord.getPositionX() <79)
				coord.setPositionX(coord.getPositionX()+1);
			break;
		case 's':
			BulletManager::bulletManager->createBullet(1, coord.getPositionX(),coord.getPositionY() - 1, true);
			break;
	}
	drawShip();
}

void Ship::updateLife()
{
		life--;
		drawShip();
		if (life <= 0)
			isDead = true;
}

bool Ship::getShip(int x, int y)
{
	if (x == coord.getPositionX() && y == coord.getPositionY()) {
		return true;
	}
	return false;
}







