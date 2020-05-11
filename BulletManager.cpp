#include "BulletManager.h"

BulletManager* BulletManager::bulletManager = nullptr;


void BulletManager::CreateBulletManager()
{
	bulletManager = new BulletManager();
}

void BulletManager::DestroyBulletManager()
{
	delete bulletManager;
}

BulletManager::BulletManager()
{
	for (int i = 0; i < maxBullets; i++)
		bulletArr[i] = nullptr;
}

void BulletManager::createBullet(int type,int x,int y,bool _tUpwards)
{
	Bullet* nBullet=new Bullet();

	if (nBullet != nullptr) {
		addBullet(nBullet,type);
		nBullet->startLaser(x, y, _tUpwards);
	}
}

void BulletManager::updateBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] != nullptr)
			bulletArr[i]->updateBullet();
	}
}

void BulletManager::destroyBullet(Bullet * toDestroy)
{
	//Do the excat same thing that ETManager does, go there and do the same here
	//The goal is to delete the memory from the array and free it from memory
	//and set the array index back to nullptr
	//should call the laser "KillLaser()"
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] == toDestroy) {
			bulletArr[i]->killLaser();
			delete bulletArr[i];
			bulletArr[i] = nullptr;
			break;

		}

	}
}



void BulletManager::addBullet( Bullet* b,int type )
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArr[i] == nullptr) {
			bulletArr[i] = b;
			bulletArr[i]->bulletType = type;
			break;
		}
	}
}

