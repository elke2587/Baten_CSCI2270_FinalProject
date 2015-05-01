#include "Chess.h"
#include <iostream>
#include <stack>
using namespace std;

/* 1. ChessBoard::ChessBoard()
 * 2. Constructs the chessboard, initializing the graph and initial position.
 * 3. ChessBoard board = new ChessBoard();
 * 4. Preconditions: none 
 * 	  Postconditions: creates a new instance of the ChessBoard class" */
ChessBoard::ChessBoard()
{
	root = new position;
	currentPosition = root;
	whiteMove = true;
	root->moveNum = 1;
	root->posFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	root->move = "";
}

//destructor
ChessBoard::~ChessBoard()
{
	currentPosition = root;
	if(root->next.size() != 0)
	{
		for(int i = 0; i<root->next.size(); i++)
		{
			deleteVariation(root->next[i]->move);
		}
	}
}

/* 1. string ChessBoard::getFEN()
 * 2. Returns the currentPosition's FEN string
 * 3. string str = board.getFEN();
 * 4. Preconditions: an existing board, use of the returned FEN string
 * 	  Postconditions: a returned string
 */
string ChessBoard::getFEN()
{
	return currentPosition->posFEN;
}

/* 1. int ChessBoard::getMoveNum()
 * 2. Returns the currentPosition's move number
 * 3. int num = board.getMoveNum();
 * 4. Preconditions: an existing board, use of the returned integer
 * 	  Postconditions: a returned integer
 */
int ChessBoard::getMoveNum()
{
	return currentPosition->moveNum;
}

/* 1. void ChessBoard::addMove(string move)
 * 2. Adds a move to the vector containing all moves in the currentPosition's
 *    subtree. The move number is increased appropriately for the new position
 *    and the resulting FEN position and move is added to the new move. The current
 *    position is set to the newly created position.
 * 3. board.addMove(Qd1f3);
 * 4. Preconditions: an existing board, move is in notation (piece)(start square)(end square)
 *    ex: Nb1c3
 * 	  Postconditions: addition of a variation to the position tree
 */
void ChessBoard::addMove(string move)
{
	//checks if the move is in the right format
	if(!(isValidInputMove(move)))
	{
		cout<<"The input move is not a valid move."<<endl;
		return;
	}
	position *newPosition = new position;
	
	//title of move
	newPosition->move = move;
	
	//move number of new move
	if(!whiteMove)
	{
		newPosition->moveNum = currentPosition->moveNum++;
		whiteMove = true;
	}
	else
	{
		newPosition->moveNum = currentPosition->moveNum;
		whiteMove = false;
	}
	
	//FEN for new position
	string newFEN = currentPosition->posFEN;
		//getting the row and column indexes from the input move
	int firstRowIndex = 0;
	for(int i = 0; i<8-(move[2]-48); i++)
	{
		firstRowIndex = newFEN.find("/",firstRowIndex+1);
	}
	int secondRowIndex = 0;
	for(int i = 0; i<8-(move[4]-48); i++)
	{
		secondRowIndex = newFEN.find("/",secondRowIndex+1);
	}
	int firstColumnIndex = move[1]-97;
	int secondColumnIndex = move[3]-97;
			//converting the row in which the change is made to the string
	string startLine = lineToString(newFEN.substr(firstRowIndex+1, newFEN.find("/",firstRowIndex+1)-firstRowIndex-1));
	string endLine = lineToString(newFEN.substr(secondRowIndex+1, newFEN.find("/",secondRowIndex+1)-secondRowIndex-1));
			//making the appropriate changes to the lines
	startLine = startLine.substr(0,firstColumnIndex)+" "+startLine.substr(firstColumnIndex+1, 7-firstColumnIndex);
	endLine = endLine.substr(0,secondColumnIndex)+move.substr(0,1)+endLine.substr(secondColumnIndex+1, 7-secondColumnIndex);
			//converting the line back to FEN notation
	startLine = stringToLine(startLine);
	endLine = stringToLine(endLine);
			//creating the whole FEN position
	if(newFEN.find("/",firstRowIndex+1)<=newFEN.length())
	{
		newFEN = newFEN.substr(0,firstRowIndex+1)+startLine+newFEN.substr(newFEN.find("/",firstRowIndex+1));
	}
	else
	{
		newFEN = newFEN.substr(0,firstRowIndex+1)+startLine;
	}
	secondRowIndex = 0;//the reassignment of secondRowIndex is required in case the length of a line has changed
	for(int i = 0; i<8-(move[4]-48); i++)
	{
		secondRowIndex = newFEN.find("/",secondRowIndex+1);
	}
	
	if(newFEN.find("/",secondRowIndex+1)<=newFEN.length())
	{
		newFEN = newFEN.substr(0,secondRowIndex+1)+endLine+newFEN.substr(newFEN.find("/",secondRowIndex+1));
	}
	else
	{
		newFEN = newFEN.substr(0,secondRowIndex+1)+endLine;
	}
			//storing the new FEN position to the new position
	newPosition->posFEN = newFEN;
	
	//next and previous assignment
	newPosition->previous = currentPosition;
	currentPosition->next.push_back(newPosition);
	//moving into the newly created position
	currentPosition = newPosition;
}

/* 1. string ChessBoard::lineToString(string line)
 * 2. Converts a line from a FEN position into a string of length 8 representing
 *    that line in the position.
 * 3. board.lineToString(Qd1f3);
 * 4. Preconditions: an existing board, input line in FEN notaiton
 * 	  Postconditions: none
 */
string ChessBoard::lineToString(string line)
{
	string str1 = "";
	for(int i = 0; i<line.length(); i++)
	{
		int num = line[i];
		if(num<=57 && num >= 49) //if the character is a number greater than 0
		{
			for(int i = 0; i<num-48; i++)
			{
				str1 += " ";
			}
		}
		else
		{
			str1 += line[i];
		}
	}
	return str1;
}

/* 1. string ChessBoard::stringToLine(string str1)
 * 2. Converts a string of length 8 representing a line in the FEN position
 * 	  to the FEN notation equivalent.
 * 3. board.stringToLine(Qd1f3);
 * 4. Preconditions: an existing board, move is in notation obtained from lineToString
 * 	  method.
 * 	  Postconditions: none
 */
string ChessBoard::stringToLine(string str1)
{
	string line = "";
	int space = 0;
	for(int i = 0; i<str1.length(); i++)
	{
		if((int)str1[i] == 32)
		{
			space++;
		}
		else
		{
			if(space != 0)
			{
				line += to_string(space);
				space = 0;
			}
			line += str1.substr(i,1);
		}
	}
	if(space != 0)
	{
		line += to_string(space);
	}
	return line;
}

/* 1. void ChessBoard::deleteVariation()
 * 2. Deletes a variation branchign from the currentPositon
 * 3. board.deleteVariation();
 * 4. Preconditions: an existing board, a variation in the line to delete
 * 	  Postconditions: a whole line will be deleted form the tree
 */
void ChessBoard::deleteVariation(string move)
{
	position *position2 = NULL;
	int foundPosition;
	for(int i = 0; i<currentPosition->next.size(); i++)
	{
		if(currentPosition->next[i]->move == move)
		{
			position2 = currentPosition->next[i];
			foundPosition = i;
		}
	}
	if(position2 == NULL)
	{
		cout<<"Variation not found"<<endl;
		return;
	}
	currentPosition->next.erase(currentPosition->next.begin()+foundPosition);
	stack<position*> P;
	P.push(position2);
	position* current;
	while(!P.empty())
	{
		current = P.top();
		P.pop();
		if(current->next.size() != 0)
		{
			for(int i = 0; i<current->next.size(); i++)
			{
				P.push(current->next[i]);
			}
		}
		delete current;
	}
}

/* 1. void ChessBoard::moveForward()
 * 2. Moves forward one move through the main variation (the first slot in the vector)
 *    and displays the position.
 * 3. board.moveForward();
 * 4. Preconditions: an existing board, preferrably a move to go forward to.
 * 	  Postconditions: if the currentPosition was not the end of the line, the
 * 	  currentPosition will have been updated to be the next move in the main line.
 */
void ChessBoard::moveForward()
{
	if(currentPosition->next.size() != 0)
	{
		currentPosition = currentPosition->next[0];
		cout<<"Main line followed:"<<endl;
		cout<<currentPosition->posFEN<<endl;
	}
	else
	{
		cout<<"End of line reached"<<endl;
	}
	whiteMove != whiteMove;
}

/* 1. void ChessBoard::moveBackward()
 * 2. Moves back one move through the main variation (the first slot in the vector)
 *    and displays the position.
 * 3. board.moveBackward();
 * 4. Preconditions: an existing board, preferrably a move to go backward to.
 * 	  Postconditions: if the currentPosition was not the root of the tree, the
 * 	  currentPosition will have been updated to be the previous move in the variation.
 */
void ChessBoard::moveBackward()
{
	if(currentPosition->previous != NULL)
	{
		cout<<"Current position is now:"<<endl;
		currentPosition = currentPosition->previous;
		cout<<currentPosition->posFEN<<endl;
	}
	else
	{
		cout<<"Initial position reached"<<endl;
	}
	whiteMove = !whiteMove;
}

/* 1. bool ChessBoard::isValidInputMove(string move)
 * 2. Checks to see if the input move is in the correct format
 * 3. board.isValidInputMove(Qd1f3);
 * 4. Preconditions: an existing board
 * 	  Postconditions: no change made
 */
bool ChessBoard::isValidInputMove(string move)
{
	if(move.length()!=5) // if the input move is not of the right length
	{
		return false;
	}
	int firstletter = move[0];
	if(!((whiteMove && (firstletter==66 || firstletter== 75 || firstletter==78 
	|| firstletter==80 || firstletter==81 || firstletter == 82)) || (!whiteMove && 
	(firstletter==98 || firstletter == 107 || firstletter == 110
	|| firstletter == 112 || firstletter == 113 || firstletter == 114)))) //if the first character is not an accepted letter
	{
		return false;
	}
	if(!(49<=move[2] && move[2]<=56 && 49<=move[4] && move[4]<=56)) //if the numbers specify positions not on the board
	{
		return false;
	}
	if(!(97<=move[1] && move[1]<=104 && 97<=move[3] && move[3]<=104)) //if the letters specify positions not on the board
	{
		return false;
	}
	return true;
}

/* 1. void ChessBoard::showVariations()
 * 2. Displays all variations branching from the currentPosition in the order of the
 *    vector next.
 * 3. board.showVariations();
 * 4. Preconditions: an existing board
 * 	  Postconditions: no change made
 */
void ChessBoard::showVariations()
{
	if(currentPosition->next.size() != 0)
	{
		cout<<"Variations:"<<endl;
		for(int i = 0; i<currentPosition->next.size(); i++)
		{
			cout<<i+1<<":"<<currentPosition->next[i]->move<<endl;
		}
	}
	else
	{
		cout<<"No variations branching from current move."<<endl;
	}
}

/* 1. void ChessBoard::enterVariation()
 * 2. Moves forward one move through the described variation
 *    and displays the position.
 * 3. board.enterVariation(Qd1f3);
 * 4. Preconditions: an existing board, preferrably a variation to go forward to, move is in notation (piece)(start square)(end square)
 *    ex: Nb1c3
 * 	  Postconditions: if the currentPosition was not the end of the line, the
 * 	  currentPosition will have been updated to be the position in the specified variation.
 */
void ChessBoard::enterVariation(string move)
{
	//checks if the move is in the right format
	if(!(isValidInputMove(move)))
	{
		cout<<"Input move is not in the correct format."<<endl;
		return;
	}
	//if the variation exists, it is found and entered
	if(currentPosition->next.size() != 0)
	{
		bool found = false;
		for(int i = 0; i<currentPosition->next.size(); i++)
		{
			if(currentPosition->next[i]->move == move)
			{
				found = true;
				currentPosition = currentPosition->next[i];
				cout<<"Variation: "<<currentPosition->moveNum<<"."
					<<currentPosition->move<<" entered"<<endl;
				cout<<"Current Position: "<<currentPosition->posFEN<<endl;
			}
		}
		if(!found)
		{
			cout<<"Variation Not Found"<<endl;
		}
	}
	else
	{
		cout<<"No variations branching from the current position"<<endl;
	}
	whiteMove = !whiteMove;
}
