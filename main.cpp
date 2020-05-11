#include <iostream>
#include "Round.h"
#include "UIKit.h"
using namespace std;
void setWindow();
int main() {

	int dif;
	system("cls");
	UIKit::gotoXY(0, 0);
	cout << "Welcome to Space Invadors II " << endl << "Choose difficulty:" << endl << "1. Easy " << endl << "2. Difficult" << endl << "3. Expert" << endl;
	do { cin >> dif; } while (dif < 0 && dif>3);

	//hidecursor();
	UIKit::visibleCursor(false);
	UIKit::color(1);
	system("cls");
	Round round(dif);
	round.startRound();
	system("cls");
	UIKit::gotoXY(40,20);
	UIKit::color(4);
	cout << "Game Over.." << endl;
	UIKit::gotoXY(40,22);
	UIKit::color(2);
	cout<< "Your score:" << round.score<<endl;
	system("pause");
	return 0;
}

void setWindow()
{
	HWND consoleHandle = GetConsoleWindow();
	RECT r;
	GetWindowRect(consoleHandle, &r);
	MoveWindow(consoleHandle, r.left, r.top, 90, 105, TRUE);

}