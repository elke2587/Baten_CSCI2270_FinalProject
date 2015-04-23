#include <iostream>
#include "Chess.h"
using namespace std;

void printMenu();

int main()
{
	bool quit = false;
	int command;
	string input;
	ChessBoard board = ChessBoard();
	while(!quit)
	{
		printMenu();
		cin>>command;
		cin.clear();
		switch(command)
		{
			case 1:
			//Print Current Position
			cout<<board.getFEN<<endl;
			break;
			case 2:
			//Add Move
			cout<<"Enter Move:"<<endl;
			getline(cin, input);
			board.addMove(input);
			break;
			case 3:
			//Move Forward
			board.moveForward();
			break;
			case 4:
			//Move Backward
			board.moveBackward();
			break;
			case 5:
			//Display Variations
			board.showVariations();
			break;
			case 6:
			//Enter Variation
			cout<<"Enter Move:"<<endl;
			getline(cin, input);
			board.enterVariation(input);
			break;
			case 7:
			//Delete Variation
			
			break;
	}
}

void printMenu()
{
	cout<<"=======CHESS BOARD======="
	    <<"1. Print Current Position"
	    <<"2. Add Move"
	    <<"3. Move Forward"
	    <<"4. Move Backward"
	    <<"5. Display Variations"
	    <<"6. Enter Variation"
	    <<"7. Delete Variation"
	    <<endl;
}
