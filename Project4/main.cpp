#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <curses.h>
#include "getChar.hpp"
#include "Worm.hpp"
#include "freePool.hpp"
#include "Screen.hpp"
#include "Food.hpp"

void setScreen(int, int, Food, Worm);
void terminate(Worm);
void initializeBoard(Screen&, freePool&, Worm&, Food&);

int main(int argc, char *argv[])
{
    char theCharacter;

    if(argv[1] == nullptr || argv[2] == nullptr){
        std::cout << "Missing arguments for either rows or columns." << std::endl;
        exit(1);
    }
    std::string rowValue = argv[1];
    std::string colValue = argv[2];
    int rows = stoi(rowValue);
    int cols = stoi(colValue);

    if((rows < 9 || rows > 25) || (cols < 9 || cols > 80)){
        std::cout << "A value for either rows or columns has been entered that doesn't fit criteria." << std::endl;
        exit(2);
    }
    Worm theWorm;
    Screen theScreen(rows, cols); // currently breaks at theScreen initialization.
    freePool thePool(rows, cols);
    Food theFood;

    //Sets the size of worm, initializes values on the internal screen, and sets the row and column values to their
    //corresponding position within the freePool.
    initializeBoard(theScreen, thePool, theWorm, theFood);

    //Preps the curses and sets the screen to have the proper layout for Worm.
    setScreen(rows, cols, theFood, theWorm);


    refresh();

    while(!theWorm.isDead()){
        //Only saves valid user inputs to theCharacter.
        if(theWorm.isImportantChar(getChar())){
            theCharacter = getChar();
        }

        //move the worm.
        if(theWorm.hasFood()){
            mvaddch(theWorm.getPosition(theWorm.getTail()).first + 1, theWorm.getPosition(theWorm.getTail()).second, 'o');
            theWorm.foodMove(theCharacter);
        }
        else{
            mvaddch(theWorm.getPosition(theWorm.getTail()).first + 1, theWorm.getPosition(theWorm.getTail()).second, ' ');
            theWorm.foodlessMove(theCharacter);
        }

        //Set indexPosition for theWorm.
        theWorm.setIndexPosition(theScreen.getPositionValue(theWorm.getPosition(theWorm.getHead() - 1)));

        //Change the player screen to reflect the worm's new position.
        mvaddch(theWorm.getPosition(theWorm.getHead() - 1).first + 1, theWorm.getPosition(theWorm.getHead() - 1).second, '@');
        //Change the previous head's location to the body symbol if we have picked up at least one food.
        if(theWorm.getScore() > 0){
            mvaddch(theWorm.getPosition(theWorm.getHead() - 2).first + 1, theWorm.getPosition(theWorm.getHead() - 2).second, 'o');
        }

        //Check to see if we hit something we weren't supposed to. Doesn't check if the worm hasn't moved though.
        if(theScreen.getPositionValue(theWorm.getPosition(theWorm.getHead() - 1)) == -1 && theWorm.getPosition(theWorm.getHead() - 1) != theWorm.getPosition(theWorm.getHead() - 2)){
            theWorm.isDead() = true;
        }
        
        //Change the internal screen so the worm's new position is considered full.
        if(theWorm.hasFood()){
            theScreen.overridePositionValue(theWorm.getPosition(theWorm.getHead() - 1), thePool.at(thePool.getIndex() - 1), theScreen.getPositionValue(theWorm.getPosition(theWorm.getHead() - 1)));
            thePool.swapValue(theWorm.getIndexPosition(), thePool.getIndex() - 1);
            thePool.setIndex(-1);
        }
        else{
            theScreen.swapPositionValue(theWorm.getPosition(theWorm.getTail() - 1), theWorm.getPosition(theWorm.getHead() - 1), theScreen.getPositionValue(theWorm.getPosition(theWorm.getTail() - 1)), theScreen.getPositionValue(theWorm.getPosition(theWorm.getHead() - 1)));
            thePool.setValue(theScreen.getPositionValue(theWorm.getPosition(theWorm.getTail() - 1)), theWorm.getPosition(theWorm.getTail() - 1).first, theWorm.getPosition(theWorm.getTail() - 1).second);
        }

        //Check to see if we have filled up the entire board's freePool.
        if(thePool.getIndex() == 0){
            theWorm.isDead() = true;
        }

        //Check to see if we got food.
        if(theWorm.getPosition(theWorm.getHead() - 1) == theFood.getPosition()){
            theWorm.setFoodValue(theFood.getFoodValue());
            theWorm.setScore(theFood.getFoodValue());
            theWorm.hasFood() = true;
            theFood.setFoodValue();
            if((thePool.getIndex() - 1) > 0){
                theFood.setPosition(thePool.at(rand() % thePool.getIndex() - 1));
            }
            else{
                theFood.setPosition(thePool.at(0));
            }
            
            mvaddstr(theFood.getPosition().first + 1, theFood.getPosition().second, std::to_string(theFood.getFoodValue()).c_str());
        }

        //Check to see if we have used up all our food moves.
        if(theWorm.getFoodValue() == 0){
            theWorm.hasFood() = false;
        }
        //Update scoreboard
        mvaddstr(0, cols - 1, std::to_string(theWorm.getScore()).c_str());
        refresh();
    }
    mvaddch(theWorm.getPosition(theWorm.getHead() - 1).first + 1, theWorm.getPosition(theWorm.getHead() - 1).second, '@');
    refresh();
    terminate(theWorm);
}

void setScreen(int rows, int cols, Food theFood, Worm theWorm)
{
    initscr();	 /* activate the curses */
    curs_set(0);/* do not display the cursor */
    clear();	 /* clear the screen that curses provides */
    noecho();	 /* prevent the input chars to be echoed to the screen */
    cbreak();	 /* change the stty so that characters are delivered to the
                    program as they are typed--no need to hit the return key!*/
    
    move(0, 0);
    //insert game title.
    addstr("worm");
    //insert score placement.
    mvaddstr(0, cols - 7, "score:");
    move(1, 0);
    //prints top wall of game.
    for(int i = 0; i < cols; i++){
        mvaddch(1, i, '*');
    }
    //prints right wall of game.
    for(int i = 1; i <= rows; i++){
        mvaddch(i, cols - 1, '*');
    }
    //prints bottom wall of game.
    for(int i = cols - 1; i >= 0; i--){
        mvaddch(rows, i, '*');
    }
    //prints left wall of game.
    for(int i = rows; i >= 1; i--){
        addch('*');
        move(i, 0);
    }
    //prints theFood at its position on the board.
    mvaddstr(theFood.getPosition().first + 1, theFood.getPosition().second, std::to_string(theFood.getFoodValue()).c_str());
    //prints theWorm at its local position on the board.
    mvaddch(theWorm.getPosition(theWorm.getHead() - 1).first + 1, theWorm.getPosition(theWorm.getHead() - 1).second, '@');
    //prints the score to the board.
    mvaddstr(0, cols - 1, std::to_string(theWorm.getScore()).c_str());
}

void terminate(Worm theWorm)
{
    mvcur( 0, COLS - 1, LINES - 1, 0 );
    clear();
    refresh();
    endwin();
    std::cout << "Your worm has died since it ran into something!" << std::endl;
    std::cout << "Your final score was: " << theWorm.getScore() << std::endl;
}

void initializeBoard(Screen &theScreen, freePool &thePool, Worm &theWorm, Food &theFood){
    for(int i = 1; i < theScreen.getRows() - 1; i++){
        for(int j = 1; j < theScreen.getCols() - 1; j++){
            theScreen.setPositionValue(i, j, thePool.getIndex());
            thePool.setValue(thePool.getIndex(), i, j);
            thePool.setIndex(1);
        }
    }
    theWorm.setSize(thePool.getIndex());

    int spawnIndexPosition = rand() % thePool.getIndex();
    std::pair<int, int> spawnPosition = thePool.at(spawnIndexPosition);
    //Spawn the worm.
    theWorm.spawn(spawnPosition.first, spawnPosition.second);
    //Change the internal screen so that theWorm's position is considered full. 
    theScreen.overridePositionValue(spawnPosition, thePool.at(thePool.getIndex() - 1), theScreen.getPositionValue(spawnPosition));
    //Change the free pool so that each value references the updated values from theScreen
    thePool.swapValue(spawnIndexPosition, thePool.getIndex() - 1);
    thePool.setIndex(-1);
    //Find a random position for theFood and generate a random value for the food.
    spawnIndexPosition = rand() % thePool.getIndex();
    spawnPosition = thePool.at(spawnIndexPosition);
    theFood.setPosition(spawnPosition);
    theFood.setFoodValue();
}
