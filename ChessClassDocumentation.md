/* 1. ChessBoard::ChessBoard()
 * 2. Constructs the chessboard, initializing the graph and initial position.
 * 3. ChessBoard board = new ChessBoard();
 * 4. Preconditions: none 
 * 	  Postconditions: creates a new instance of the ChessBoard class" */
 
 /* 1. string ChessBoard::getFEN()
 * 2. Returns the currentPosition's FEN string
 * 3. string str = board.getFEN();
 * 4. Preconditions: an existing board, use of the returned FEN string
 * 	  Postconditions: a returned string
 */
 
 /* 1. int ChessBoard::getMoveNum()
 * 2. Returns the currentPosition's move number
 * 3. int num = board.getMoveNum();
 * 4. Preconditions: an existing board, use of the returned integer
 * 	  Postconditions: a returned integer
 */
 
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
 
 /* 1. string ChessBoard::lineToString(string line)
 * 2. Converts a line from a FEN position into a string of length 8 representing
 *    that line in the position.
 * 3. board.lineToString(Qd1f3);
 * 4. Preconditions: an existing board, input line in FEN notaiton
 * 	  Postconditions: none
 */
 
 /* 1. string ChessBoard::stringToLine(string str1)
 * 2. Converts a string of length 8 representing a line in the FEN position
 * 	  to the FEN notation equivalent.
 * 3. board.stringToLine(Qd1f3);
 * 4. Preconditions: an existing board, move is in notation obtained from lineToString
 * 	  method.
 * 	  Postconditions: none
 */
 
 /* 1. void ChessBoard::deleteVariation()
 * 2. Deletes a variation branchign from the currentPositon
 * 3. board.deleteVariation();
 * 4. Preconditions: an existing board, a variation in the line to delete
 * 	  Postconditions: a whole line will be deleted form the tree
 */
 
 /* 1. void ChessBoard::moveForward()
 * 2. Moves forward one move through the main variation (the first slot in the vector)
 *    and displays the position.
 * 3. board.moveForward();
 * 4. Preconditions: an existing board, preferrably a move to go forward to.
 * 	  Postconditions: if the currentPosition was not the end of the line, the
 * 	  currentPosition will have been updated to be the next move in the main line.
 */
 
 
/* 1. void ChessBoard::moveBackward()
 * 2. Moves back one move through the main variation (the first slot in the vector)
 *    and displays the position.
 * 3. board.moveBackward();
 * 4. Preconditions: an existing board, preferrably a move to go backward to.
 * 	  Postconditions: if the currentPosition was not the root of the tree, the
 * 	  currentPosition will have been updated to be the previous move in the variation.
 */
 
 /* 1. bool ChessBoard::isValidInputMove(string move)
 * 2. Checks to see if the input move is in the correct format
 * 3. board.isValidInputMove(Qd1f3);
 * 4. Preconditions: an existing board
 * 	  Postconditions: no change made
 */
 
 /* 1. void ChessBoard::showVariations()
 * 2. Displays all variations branching from the currentPosition in the order of the
 *    vector next.
 * 3. board.showVariations();
 * 4. Preconditions: an existing board
 * 	  Postconditions: no change made
 */
 
 /* 1. void ChessBoard::enterVariation()
 * 2. Moves forward one move through the described variation
 *    and displays the position.
 * 3. board.enterVariation(Qd1f3);
 * 4. Preconditions: an existing board, preferrably a variation to go forward to, move is in notation (piece)(start square)(end square)
 *    ex: Nb1c3
 * 	  Postconditions: if the currentPosition was not the end of the line, the
 * 	  currentPosition will have been updated to be the position in the specified variation.
 */
