***readme.txt***

COMP2012H Project 2
Name:			Hong Wing PANG
Stu ID:			20315504
Last updated:	12-10-2016

--------------
 Introduction
--------------

As the title suggests, this program is largely based on the classic game Tetris. The controls and GUI closely follows the guidelines given in the project website.

There is one major difference between the two: in my version, when the game is over, it will not draw another block at the top that overlaps with existing blocks. Instead, the level QLabel will be replaced by the message "Game Over!" instead, which I believe is slightly more user-friendly. Other details remain unchanged as far as I am aware.

--------------
  Structure
--------------

The project consists of three classes, namely Row, TetrisWindow and TetrisControl.
Each type of cube is represented by a integer, which will be further introduced below.
1) Row object contains 10 integers, and as its name suggests, represents a row in the game.
2) TetrisControl class manages the core game components, and uses utility functions to operate the game. It does this with a map, which is simply speaking an array of 20 Row objects. QTimer is used to constantly update gameplay at a time interval that depends on the current player level.
3) TetrisWindow is the user interface, which is shown when main.cpp is run. It provides two main functions, to draw to the screen and to generate responses to keypress events.

--------------
    Design
--------------

My design is based on a 2d map, each value representing one cell in the game. The int value can be either 0, to represent empty space; or can be a value from 1 to 7 which represents the seven blocks in the order outlined at the course website.

Originally my idea is to represent one falling block as one object. A problem soon arises, as I do not know how to represent this object once some rows are cancelled and only parts of the block is left. Therefore, I decided to store the location of the current block as a property of the TetrisControl class. I also included another 2d array to store the coordinates of each cube in a falling block, relative to the rotational center; so that I can define the block location with one set of coordinates, and draw out its shape in the map.

Another problem is how to perform rotation on the blocks. Hard-coding all the possible shapes is an inelegant solution that is difficult to maintain and extend in the future. Hence, I used rotation matrices to calculate the new positions of the blocks. This is easy as the orientation is confined to 90-degrees, so the matrices only contained 1, 0 and -1.

The idea of assigning one row as an object is intentional in making the cancelling of rows easier. Since I use a map, cancelling one row will shift all the map cells downwards, of which a lot of repetitive movements will be made. Hence, I have used dynamically allocated objects to simplify this situation. Whenever a row is cancelled I can call delete on it as it is never used again; then I can simply shift the pointers of the Row objects instead of shifting every value in the map, which is more efficient in my opinion.

In retrospect, although gameplay and interface has been isolated from each other, I feel that there is still much space of improvement in terms of OOP design. Many aspects of the game, such as the preview board, scoring system etc. can be seperated as different classes, instead on being stuck into the TetrisControl class, making it more troublesome to debug. The extendability of the game is also not very high, e.g. it is currently confined to blocks with a size of 4 cubes only. I will consider these aspects and plan earlier when doing future projects.