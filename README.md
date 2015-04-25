# Baten_CSCI2270_FinalProject

#==========README============

#Summary:
This project contains a chess
class for creating and editing
chess positions. Each position
is represented in FEN notation.
Making a move with one of the
methods will result in the
move, the move number, and 
resulting position being stored 
in a tree. A move and the position 
after that move can be searched 
for, the class will store a 
"current board", to which the user
can add moves or variations
branching from the main variation.
The driver file makes use of this
class to allow the user to easily
keep track of positions, the move
number, variations, and easily
maneuver back and forth across the
variation trees.

#How to run:

-Clone the repository to your machine.

-In the terminal, navigate to the inside
of the folder.

-Compile the program with either

1) make all
(this makes use of the provided makefile)

			or

2) g++ -c Chess.cpp -std=c++11
followed by: 
g++ Chessboard.cpp Chess.o -std=c++11 -o chessboard

-Run the program with command: ./chessboard

#Using the Program:
1. Print Current Position
Prints the current position's FEN notation.
2. Add Move
Adds a position to the tree resulting
from the user specified move.
3. Move Forward
Moves the current position forward to
the next move in the main line.
4. Move Backward
Moves the current position backward to
the previous move in the main line.
5. Display Variations
Displays all variations stemming from the
current position.
6. Enter Variation
Enters the user specified variation.
7. Delete Variation
Deletes the subtree that has the user
specified variation of the current
position as the root.
8. Get Move Number
Returns the current position's move
number.
9. Quit
Quits the Program

#Notation:
Each position is expressed in Forsyth-
Edwards Notation, an actual notation
used to represent an entire chess board
in one simple, compact string.

Each input move should be in the format:
(piece)(column)(row)(column)(row)
For example, moving a white pawn from the
squares e2 to e4 is represented by: Pe2e4.
White pieces are represented by uppercase
letters and black by lowercase.

R-rook N-knight B-bishop Q-queen K-king P-Pawn

Extra example moves: 
Pe2e4, pe7e5, Ng1f3, Nb8c6, Bf1b5
(this exact order is an opening 
called the Ruy Lopez)

#Dependencies:
C++

#System Requirements:
Linux (the build commands and makefile are designed for linux)

#Contributors:
Ryan Baten

#Open issues/bugs:
