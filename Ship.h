#ifndef SHIP_H
#define SHIP_H

#include "Coord.h"
#include "BulletManager.h"
class Ship
{
protected:
	void eraseShip() const;
	void drawShip() const;
public:
	Coord coord;
	int life=5;
	bool isDead = false;
	Ship();		
	void updateShip();
	void changePosition(char);
	void updateLife();
	bool getShip(int x,int y);
};

#endif