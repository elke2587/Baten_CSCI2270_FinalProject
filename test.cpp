#include <iostream>
#include "Chess.h"
using namespace std;

int main()
{
	string line = "1P2KR2";
	ChessBoard board = ChessBoard();
	
	//line to string
	string str1 = board.lineToString(line);
	cout<<str1<<endl;
	
	//string to line
	cout<<board.stringToLine(str1)<<endl;
	
	//isValidInputMove
	//-correct input-
	cout<<"Qd4c5"<<" "<<board.isValidInputMove("Qd4c5")<<endl;
	//-incorrect inputs-
	cout<<"Qd4i5"<<" "<<board.isValidInputMove("Qd4i5")<<endl;
	//
	board.addMove("Pe2e4");
	cout<<board.getFEN()<<endl;
	board.addMove("pe7e5");
	cout<<board.getFEN()<<endl;
	board.addMove("Nb1c3");
	cout<<board.getFEN()<<endl;
	board.addMove("pd7d6");
	cout<<board.getFEN()<<endl;
}
