#ifndef ROUND_H
#define ROUND_H
#include "Ship.h"
#include <conio.h>
#include "UIKit.h"
#include "ETManager.h"
#include <string>
#include "BulletManager.h"
//#include "Bullet.h"
#include "ETManager.h"
#include <thread>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Ship;

class Round {
	int difficulty;
public:
	int pause = 0;
	static int score;
	static Ship* ship;
	Round(int difficulty);
	~Round();
	void startRound();
	static void setAddScore(int scoretoadd);
};
#endif // !1