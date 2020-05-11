#include "ETManager.h"

ETManager* ETManager::etManager = nullptr;

void ETManager::CreateEtManager()
{
	etManager = new ETManager();
}

void ETManager::DestroyEtManager()
{
	delete etManager;
}

bool ETManager::isDead(Extraterrestrial* tochk)
{
	for (int i = 0; i < MAX_ET; i++)
	{
		if(etArr[i]!=nullptr && etArr[i] ==tochk)
			etArr[i]->checkDeath();
	}
	return false;
}

ETManager::ETManager()
{
//	etManager = this;
	ticks = 0;
	nextSpawnTick = ticksPerSpawn;  //ticks + ticksPerSpawn, but ticks is 0 atm
	for (int i = 0; i < MAX_ET; i++)
		etArr[i] = nullptr;
}


void ETManager::update()
{
	timer++;
	//We should check if enough ticks has passed to summon a new ET
	ticks++;//In here, we should loop through each ET we have and update them (move, destroy, etc)
	for (int i = 0; i < MAX_ET; i++)
	{
		if (etArr[i] != nullptr) {
			etArr[i]->update();
			etArr[i]->drawExtraterrestrial();
		}
	}
	if (nextSpawnTick <= ticks)
	{
		
		int type = (rand() % 2);
		int value = (rand() % 40 + 10);
		int cd = 30;// (rand() % 50 + 1);//generate random number and assign to timetill fire using Extraterrestrial constructor
		spawnET(type,value,cd);

	}
	if (timer >= 40) {
		for (int i = 0; i < MAX_ET; i++)
		{
			if (etArr[i] != nullptr) {

				etArr[i]->move();

			}
		}
		timer = 0;
	}
}



void ETManager::spawnET(int type,int value,int cooldown)
{
	//Create a new ET
	 //Add it to the array
	nextSpawnTick = ticks + ticksPerSpawn;   //Next spawn is current time + time between spawns
	for (int i = 0; i < MAX_ET; i++)
	{
		if (etArr[i] == nullptr)//Free spot to create a new alien
		{
			
			etArr[i] = new Extraterrestrial(type, value,cooldown);  //Here you need to decide which kind is created. ATM its the basic Extratestrial, but maybe some random function
			break;//or something could determine which kind to create
		}
	}







}

void ETManager::destroy(Extraterrestrial* toDestroy)
{
	for (int i = 0; i < MAX_ET; i++)
	{
		if (etArr[i] == toDestroy) //if they are both pointing to the same object
		{
			if (etArr[i]->lifeEt > 0) {
				etArr[i]->lifeEt--;
				break;
			}

			Round::setAddScore(etArr[i]->addPoints());
			etArr[i]->die();
			delete etArr[i];			// deleted ate set to null pointer
			etArr[i] = nullptr;
			if (getNumOfEt() <= 0) {
				Round::ship->isDead = true;
			}
			break;
		}
	}
}

Extraterrestrial* ETManager::getET(int x, int y)
{
	for (int i = 0; i < MAX_ET; i++)
	{
		if (etArr[i] != nullptr) {
			if (etArr[i]->coord.getPositionX() == x && etArr[i]->coord.getPositionY() == y)
			{
				return etArr[i];
			}
		}
	}
	return nullptr; //no alien found
}

int ETManager::getNumOfEt()
{
	int cnt = 0;
	for(int i = 0; i < MAX_ET; i++) {
		if (etArr[i] != nullptr)
			cnt++;
	}
	return cnt;
}



