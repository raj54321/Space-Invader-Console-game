#ifndef BULLET_H
#define BULLET_H
#include "ETManager.h"
#include "Coord.h"
#include "UIKit.h"
#include "BulletManager.h"
#include"Ship.h"

#include "Round.h"

class Bullet
{
public:
	//constants
	const char laser = '|';
	const char bullet = ':';
	int bulletType;
	int travelUpwards;
	bool isAlive;
	Coord coord;
	bool isOnAlien();
	bool isOnShip();
	void startLaser(int,int,bool);
	void eraseLaser() const;
	void drawLaser() const;
	void updateBullet();
	virtual void moveLaser();
	virtual void killLaser();
};

#endif