At first, I stuck to the minimax tree, and the naive evaluation function of comparing the number of stones

I quickly created a better evaluation function, and optimized all the square values according to a table I found on the internet. It worked pretty well, but couldn't beat BetterPlayer

I implemented AlphaBeta pruning and Negamax, since it was easier to code and worked better. It could also get up to like 10 ply. Negamax is simpler than minimax, taking advantage of the fact that Othello is a 0 sum game and the score of a side is the negative of the other sides score. Pruning makes it so useless branches are not searched.

Now I focused on the evaluation function, making it return positive or negative infinity if the game is currently won by this side or the other side, since the normal evaluation function might accidentally return a favorable value when losing is definitely bad.

Next I drastically increased the search depth if only a certain number of squares are still empty, allowing for perfect end game play.

Next I completely changed the evaluation function to take into account number of possible moves and corner control more, as the pieces themselves are unimportant, as lots of pieces can simply be cannon fodder for the opposition. Now it can beat BetterPlayer, and I think It'll do well in the tournament. I wish I had time to do a neural network though...