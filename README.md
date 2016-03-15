Caltech CS2 Assignment 9: Othello
Contributions
Alix: She initialized the required variabes for the initial assignment. She also fine-tuned the heuristic, assisted with debugging the main function, edited the main function, and wrote new helper functions to assist the AI. She also made sure that the Github repository was always up to date. 
Andrew: He initially wrote the main function, using the variable declarations created by Alix. He also wrote the heuristic, assisted with debugging the helper functions and the constructor, and recorded trial data to verify the performance of the AI.  
Improvements:
We made limited improvements to our AI for the second week. We tweaked the numbers on the heuristic to better reflect their actual importance to board control. We also wrote a helper function for the heuristic which, upon a corner square being taken by either player, changes the values of the squares near the corner from negative to positive (as they no longer give up corner control if claimed, since the corner has already been taken). We also needed to debug some issues with popped up with editing the heuristic.

Our AI seems to partially give up board control early but makes very strong late game moves due to priorizing the squares near the corners once the corners have been taken. This seems to be quite effective against the more basic AI's. 

We started to make our heuristic more complicated to account for more variables, but some of our changes caused segfaults and others did not noticeably improve performance, so we elected to try other approaches for our heuristic. 



See [assignment9_part1.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part1.html) and [assignment9_part2.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part2.html)


