#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "Bullet.h"
#include <iostream>
using namespace std;

class Bullet; //foward declaration


class BulletManager
{
public:
	static BulletManager* bulletManager;
	static void CreateBulletManager();
	static void DestroyBulletManager();

	BulletManager();
	const int maxBullets = 50;
	int test = 0;
	void createBullet(int type,int x,int y,bool _tUpwards);
	Bullet *bulletArr[50];
	void updateBullets();
	void destroyBullet(Bullet*);

	//void getNumOfBullets();

private:
	void addBullet(Bullet*,int);
};
#endif