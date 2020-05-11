#include "Round.h"

int Round::score = 0;
Ship* Round::ship = new Ship();

Round::Round(int difficulty) {

	ship->updateShip();
	UIKit::color(1);
	Round::difficulty = difficulty >= 1 && difficulty <= 3 ? difficulty : 1;

	BulletManager::CreateBulletManager();
	ETManager::CreateEtManager(); 
	
	switch (difficulty)
	{

	case 1:pause = 75;
		break;
	case 2:pause=45;
		break;
	case 3:pause=20;
		break;
	default:pause=75;
		break;
	}
	
}

Round::~Round()
{
	BulletManager::DestroyBulletManager();
	ETManager::DestroyEtManager();
	delete ship;
}

void Round::startRound() {
	
		int width = 50, height = 40, s;
	int hs = 7;
	bool gameOver = false;
	fstream inf("highscore.dat");
	inf.seekg(0, SEEK_END);
	s = (int)inf.tellg();
	inf.close();

	if (s <= 0)
	{
		ofstream outf("highscore.dat");
		if (outf.is_open())
		{
			outf.seekp(0);
			outf.write(reinterpret_cast<const char *>(&score), sizeof(score));
		}
		outf.close();
	}

	ifstream infs("highscore.dat");
	//string s;
	//getline(infs,s);
	infs.seekg(0);
	infs.read(reinterpret_cast<char *>(&hs), sizeof(hs));
	infs.close();
		UIKit::frame(30, 0, 80, 40, 5);
		UIKit::gotoXY(0,5);
		UIKit::color(2);
	
		cout << "highscore: " << hs;
		
		cout << endl << "      Space Invender" << endl;
		cout << "      How To Play " << endl;
		cout << "l:Move Left     r:Move Right" << endl;
		cout << "s:Fire Bullet   x:Quit" << endl;
		cout << "Life Line " << endl;
	srand(time(0));
	while (!ship->isDead) {
		
		

		UIKit::gotoXY(4,11);
		
		for (int i = 0; i < 5; i++) {
			if (i < ship->life) {
				UIKit::color(2);
				wcout << setw(5) << char('\5');
			}
			else
			{
				UIKit::color(4);
				wcout << setw(5) << char('\5');
			}
		}
			
		UIKit::color(2);
		cout << endl << "score: " << score << endl;
		
		BulletManager::bulletManager->updateBullets();
		ETManager::etManager->update();
		if (_kbhit()) {
			char c = _getch();
			switch (c) {
			case 'r':
			case 's':
			case 'l':
				ship->changePosition(c);
				break;
			
			case 'x':
				exit(0);
				break;

			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(pause));
	}
	if (hs < score) {
		ofstream outf("highscore.dat", ios::trunc);
		if (outf.is_open()) {

			outf.write(reinterpret_cast<const char *>(&score), sizeof(score));

		}
	outf.close();
	}


	//THIS REPLACES THE MAIN FUNCTION
	//Should loop
	//Should call bulletManager and ETManager::CreateManager
	//should update them
	//should update player
	//Should have a pause	
	
}

void Round::setAddScore(int scoretoadd)
{
	score += scoretoadd;

}




//Notes _getch() can let you read input