#pragma once
#ifndef EXTRATERRESTRIAL_H
#define EXTRATERRESTRIAL_H

#include "Coord.h"
#include "Round.h"

class Round;

class Extraterrestrial
{
protected:
	int extraterrestrialType;	//identifier for type
	int extraterrestrialValue;  //how many points it is worth
	int timeTillFire;			//when they should fire
	int cooldown = 30;	       //Should be setup by the invidual child

public:
	Coord coord;
	bool isAlive;

	int lifeEt = 5;
	Extraterrestrial(int,int,int);
	virtual void update();
	void eraseExtraterrestrial() const;
	void drawExtraterrestrial() const;
	void checkDeath();
	int addPoints() const;
	void die();
	

	void move();
	void fire();

};

#endif




