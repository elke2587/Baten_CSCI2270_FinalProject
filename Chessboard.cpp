#include <iostream>
#include "Chess.h"
using namespace std;

void printMenu();

int main()
{
	bool quit = false;
	string command;
	int commandint;
	string input;
	ChessBoard board = ChessBoard();
	while(!quit)
	{
		printMenu();
		cin.clear();
		getline(cin,command);
		commandint = stoi(command);
		switch(commandint)
		{
			case 1:
			//Print Current Position
			cout<<board.getFEN()<<endl;
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
			cout<<"Enter Move:"<<endl;
			getline(cin, input);
			board.deleteVariation(input);
			break;
			case 8:
			cout<<"The current move number is: "<<board.getMoveNum()<<endl;
			break;
			case 9:
			//quit
			quit = true;
			cout<<"Goodbye!"<<endl;
			break;
			default:
			cout<<"Invalid command given"<<endl;
			break;
		}
	}
}

void printMenu()
{
	cout<<"=======CHESS BOARD=======\n"
	    <<"1. Print Current Position\n"
	    <<"2. Add Move\n"
	    <<"3. Move Forward\n"
	    <<"4. Move Backward\n"
	    <<"5. Display Variations\n"
	    <<"6. Enter Variation\n"
	    <<"7. Delete Variation\n"
	    <<"8. Get Move Number\n"
	    <<"9. Quit"
	    <<endl;
}
