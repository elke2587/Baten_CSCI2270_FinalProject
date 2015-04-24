OBJS = Chess.o Chessboard.o
CPPFLAGS = -std=c++11
PROG = chessboard
CC = g++
all : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(CPPFLAGS)
Chess.o : Chess.h Chess.cpp
	$(CC) -c Chess.cpp $(CPPFLAGS)
Chessboard.o : Chessboard.cpp
	$(CC) -c Chessboard.cpp $(CPPFLAGS)
