# ChessBoardGame


This is a prototype of a chess board game. It is not optimized. This allows a player to make any valid move and play chess, however it does not check for a check/checkmate. Nor does it end, it is up to the user to determine this. There are a lot of problems with this such as not freeing memory when a piece is taken, messy code, mispelled file names, etc. That being said this was an initial attempt so that I could first understand some of the minor things about chess that I would need to know before starting. I plan on making a new project with a GUI and that is where this project will continue


Included is a commandline display of a board
The player inputs what piece he would like to move, then inputs where he would like to move it to.
The program then checks if that piece is capable of moving to that square, and if there is any piece in the way.
This handles Castling, Empassant, Pawn moving forward 1/2, as well as all other basic movement. 

Not included: Promotions and check/checkmate.
