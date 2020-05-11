#include "Bullet.h"



#include <iostream>
using namespace std;

void Bullet::startLaser(int x,int y,bool _travelUpwards)
{
	travelUpwards = (_travelUpwards) ? -1 : 1;
	coord.setPositionX(x);
	coord.setPositionY(y);
	
	drawLaser();
	isAlive = true;
}

void Bullet::eraseLaser() const
{	
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";
}

void Bullet::drawLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	if (bulletType == 0)
	{
		UIKit::color(1);
		cout << bullet;
		UIKit::color(4);
}
	else {
		UIKit::color(2);
		cout << laser;
		UIKit::color(4);
		
	}
	
	
	
}

void Bullet::updateBullet()
{
	//#add
	if (travelUpwards == 1)
	{
		if ( isOnShip()) {
			
			BulletManager::bulletManager->destroyBullet(this);
			Round::ship->updateLife();

		}
		else {
			moveLaser();
		}
	}
	else {

		if (isOnAlien())
		{
			isAlive = false;

			BulletManager::bulletManager->destroyBullet(this);

			//Check if there is an alien
				//use ETManager::etManager->getET(x,y)  and check if its null
				//if it is not null, then we need to tell the ETManager that it has died & pass the reference we got in step above
				//then destroy this laser by calling the BulletManager and pass "this" reference
		}

		else
		{

			moveLaser();
			//else
					//Move the laser foward
		}
	}
}










bool Bullet::isOnAlien()
{//#f
	Extraterrestrial* p = ETManager::etManager->getET(coord.getPositionX(), coord.getPositionY());
	if (p != nullptr) {
		ETManager::etManager->destroy(p);
		
		return true;
	}
	return false;
}
bool Bullet::isOnShip()
{//#f

	if(Round::ship->getShip(coord.getPositionX(),coord.getPositionY()))
			return true;
	
	return false;
}
void Bullet::moveLaser()
{
	eraseLaser();
	if (coord.getPositionY() > 1 && coord.getPositionY() < 39)  //If still in bounds
	{
		coord.setPositionY(coord.getPositionY() + travelUpwards);
		drawLaser();
	}
	else  //outta bounds
	{
		isAlive = false;
		BulletManager::bulletManager->destroyBullet(this);

	}
}

void Bullet::killLaser()
{
	eraseLaser();
	isAlive = false;
}

