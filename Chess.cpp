#include "Chess.h"
#include <iostream>
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
	/*currentPosition = root;
	 * for(int i = 0; i<root->next.size(); i++)
	 * {
	 * 		deleteVariation(root->next[i]->move);
	 * }
	 * */
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
		cout<<"Input move is not in the correct format."<<endl;
		return;
	}
	position *newPosition = new position;
	//title of move
	newPosition->move = move;
	//move number of new move
	if(!whiteMove)
	{
		newPosition->moveNum = currentPosition->moveNum++;
	}
	else
	{
		newPosition->moveNum = currentPosition->moveNum;
	}
	//FEN for new position
	
	//next and previous assignment
	newPosition->previous = currentPosition;
	currentPosition->next.push_back(newPosition);
	//moving into the newly created position
	currentPosition = newPosition;
}

void ChessBoard::deleteVariation(string move)
{
	
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
	if(currentPosition->next[0] != NULL)
	{
		currentPosition = currentPosition->next[0];
		cout<<"Main line followed:"<<endl;
		cout<<currentPosition->posFEN<<endl;
	}
	else
	{
		cout<<"End of line reached"<<endl;
	}
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
		currentPosition = currentPosition->previous;
		cout<<currentPosition->posFEN<<endl;
	}
	else
	{
		cout<<"Initial position reached"<<endl;
	}
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
	char firstletter = move[0];
	if(!(firstletter==66 || firstletter== 75 || firstletter==78 
	|| firstletter==80 || firstletter==81 || firstletter == 82 
	|| firstletter==98 || firstletter == 107 || firstletter == 110
	|| firstletter == 112 || firstletter == 113 || firstletter == 114)) //if the first character is not an accepted letter
	{
		return false;
	}
	if(!(49<=move[3] && move[3]<=56 && 49<=move[5] && move[5]<=56)) //if the numbers specify positions not on the board
	{
		return false;
	}
	if(!(97<=move[2] && move[2]<=104 && 97<=move[4] && move[4]<=104)) //if the letters specify positions not on the board
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
	if(currentPosition->next[0] == NULL)
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
	if(currentPosition->next[0] != NULL)
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
}
