#ifndef CHESS_H
#define CHESS_H
#include <string>
#include <vector>
struct position
{
	std::string posFEN;
	std::string move;
	int moveNum;
	position *previous;
	std::vector<position*> next;
};

class ChessBoard
{
	public:
		ChessBoard();
		~ChessBoard();
		std::string getFEN();
		int getMoveNum();
		void addMove(std::string move);
		std::string lineToString(std::string line);
		std::string stringToLine(std::string str1);
		void deleteVariation(std::string move);
		void moveForward();
		void moveBackward();
		bool isValidInputMove(std::string move);
		void showVariations();
		void enterVariation(std::string move);
		//void startOver(std::vector<position*> next);
		std::string getPrevious();
	private:
		position *root;
		position *currentPosition;
		bool whiteMove;
};
#endif
