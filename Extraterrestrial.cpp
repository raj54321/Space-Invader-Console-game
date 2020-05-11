#include "Extraterrestrial.h"
#include <stdlib.h>
#include<iostream>
using namespace std;


Extraterrestrial::Extraterrestrial(int type,int value,int coolDown)
{
	extraterrestrialType=type;
	extraterrestrialValue=value;
	timeTillFire = coolDown;
	coord.setPositionX((rand() % (79-31)) + 31);
	coord.setPositionY((rand() % 29) + 1);
	isAlive = true;
	lifeEt = 5;
	UIKit::color((type) ? 2 : 4);
	drawExtraterrestrial();//Just spawned, so should draw it
	UIKit::color(8);
}

void Extraterrestrial::move()
{
	//#add	
	int position = 2; // no change needed
	int newposY = 1; // extreme top of the frame
	int newposX = 31; // extreme left of the frame
	Extraterrestrial* pp;

	switch (extraterrestrialType) {
	case 0:

		// 25 is the bottom of the frame  
		if (coord.getPositionY() < 29) {
			eraseExtraterrestrial();
			pp = ETManager::etManager->getET(coord.getPositionX(), coord.getPositionY() + position);
			while (pp != nullptr)
			{
				pp = ETManager::etManager->getET(coord.getPositionX(), coord.getPositionY() + position + 1);
				position++;


			}

			coord.setPositionY(coord.getPositionY() + position);
			drawExtraterrestrial();
		}

		else {
			eraseExtraterrestrial();
			pp = ETManager::etManager->getET(coord.getPositionX(), 30 + newposY);
			while (pp != nullptr)
			{
				pp = ETManager::etManager->getET(coord.getPositionX(), 30 + newposY + 1);
				newposY++;


			}

			coord.setPositionY(newposY);
			drawExtraterrestrial();
		}


		break;
	case 1:

		//18 is the extreme right of the frame
		if (coord.getPositionX() < 78 ){//|| coord.getPositionX() > 78) {
			eraseExtraterrestrial();

			pp = ETManager::etManager->getET(coord.getPositionX() + position, coord.getPositionY());
			while (pp != nullptr)
			{
				pp = ETManager::etManager->getET(coord.getPositionX() + position + 1, coord.getPositionY());
				position++;
			}

			coord.setPositionX(coord.getPositionX() + position);
			drawExtraterrestrial();
		}
		else {
			eraseExtraterrestrial();
			pp = ETManager::etManager->getET(31 + newposX, coord.getPositionY());
			while (pp != nullptr)
			{
				pp = ETManager::etManager->getET(31 + newposX + 1, coord.getPositionY());
				newposX++;


			}

			coord.setPositionX(newposX);
			drawExtraterrestrial();
		}

		break;

	default:
		cout << "unhandled switch at ET move";
	}
}

void Extraterrestrial::fire()
{
	timeTillFire = cooldown;
	//#add
	BulletManager::bulletManager->bulletManager->createBullet((rand()%2), coord.getPositionX(), coord.getPositionY() + 1, false);


}

void Extraterrestrial::update()
{
	//Any logic in here needed, timers, etc
	timeTillFire--;
	if (timeTillFire < 0)
		fire();
	//remove the move();


}
//


void Extraterrestrial::eraseExtraterrestrial() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";	
}

void Extraterrestrial::drawExtraterrestrial() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << "E"; //char(98);//extraterrestrialType);
}



void Extraterrestrial::checkDeath()
{
	//if(???)   the tile we are going on has a laser (Check the board, or check bullet manager) 
	//Round::etManager->destroy(this);
	//if () { }
}

int Extraterrestrial::addPoints() const
{
	return extraterrestrialValue;
}


void Extraterrestrial::die() //This is called by the manager
{
	//erase extraterrestial because it has died
	
		isAlive = false;
		eraseExtraterrestrial();
	
}

