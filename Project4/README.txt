Program made by: Matthew Berlin
All the code within this program was created by myself. I have also not shared any code related to this project with
any of my peers.
Program purpose: The purpose of this program is to run the game worm on a terminal. The program accepts an input of two
numbers representing the rows and columns, with acceptable values being between 9 and 25 inclusive for rows
and between 9 and 80 for columns. The program takes these values and makes an internal representation of the screen
that will run the game, and internal representation of the available spaces on the board, an internal representation
of the worm that moves on the screen, and an internal representation of the food that the worm eats throughout the
game. The program then takes these data structures and presents them on the terminal in the proper format. The worm
moves across the game board using the keys 'h' or 'a' to move left, 'j' or 's' to move down, 'k' or 'w' to move up,
and 'l' or 'd' to move right. The program will only accept these valid inputs to move the worm across the board, 
ignoring any inputs that don't fit these qualifications and saving the last valid input to keep the worm moving across
the board at all times. A food item with a value between 1 and 9 will be randomly assigned an open spot from the
freePool, where upon the worm reaching that spot, the worm will grow in size based on the value assigned to the food
and will increase the player's score. A new position in the freePool will then be immediately assigned to the food
again and displayed on the board. If the worm's head enters a position on the board where its body already is or if 
the worm's head hits a wall on the screen, the worm will die and the game will end, removing the display of the
screen and displaying a message saying that the worm has died, followed by telling the player their final score in 
the game. 