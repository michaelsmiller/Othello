The C++ files are for the AI, while the Java files are implementations of the actual Othello game, with the GUI and all, which were not written by me.

At first, I stuck to the minimax tree, and the naive evaluation function of comparing the number of stones

I quickly created a better evaluation function, and optimized all the square values according to a table I found on the internet.

I implemented AlphaBeta pruning and Negamax, since it was easier to code and worked better. It could also get up to about 10 ply. Negamax is simpler than minimax, taking advantage of the fact that Othello is a 0 sum game and the score of a side is the negative of the other sides score. Pruning makes it so useless branches are not searched further.

Now I focused on the evaluation function, making it return positive or negative infinity if the game is currently won by this side or the other side, since the normal evaluation function might accidentally return a favorable value when losing is definitely bad.

Next I drastically increased the search depth if only a certain number of squares are still empty, allowing for perfect end game play.

Next I completely changed the evaluation function to take into account number of possible moves and corner control more, as the pieces themselves are unimportant, as lots of pieces can simply be cannon fodder for the opposition.
