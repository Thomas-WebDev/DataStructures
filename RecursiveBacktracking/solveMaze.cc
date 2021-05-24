/*******************************************************************
* Name: Kevin Thomas Kehoe
* Date: 10/31/2017 
* Course: CSCI 132
* Assignment: Assignment 5
* Program: solveMaze.cc
* Purpose:  A maze solver.  This program allows a user to enter size of maze,
* prints said maze. Then calls function solveMaze which determines if there is 
* a path through the maze then prints maze with path marked with Xs or returns
* false if there is no possible path.
***************************************************************************/
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} //if maze not solved
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
                cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program

bool solve(Maze &theMaze, int x, int y) {
/***********************************************************************
* Pre: The second and third parameter specify the starting position.
* Post: The maze layed out will be navigated through recursively until a path
* through is found then the value of the positions of the path are changed from * 0 to 1. Then a result of true is returned and the maze with path is printed
* unless the maze is unsolvable.
* Uses: The class Maze. 
************************************************************************/
  //Recursively solve theMaze from position x, y
  bool flag=false;
  if (theMaze.get_position(x, y) == 2){
    theMaze.print_maze();
    return true;
  }
  else if (theMaze.get_position(x, y) == 1)
    return false;
  else {  
    theMaze.set_position(x, y, 1);
    if (!isWallAbove(theMaze, x, y))
      flag =(solve(theMaze, x, y - 1));
    if (!isWallBelow(theMaze, x, y))
      flag = (solve(theMaze, x, y + 1));
    if (!isWalltoLeft(theMaze, x, y))
      flag = (solve(theMaze, x - 1, y));
    if (!isWalltoRight(theMaze, x, y))	  
      flag = (solve(theMaze, x + 1, y));
    theMaze.set_position(x, y, 0);
  } 
  return flag;
} //end solve

bool isWallAbove(Maze &theMaze, int x, int y) {
  if (y - 1 <= -1)
    return true;
  return theMaze.is_horizontal_wall(x, y - 1);
} //end isWallAbove

bool isWallBelow(Maze &theMaze, int x, int y) {
  if (y + 1 > theMaze.get_height())
    return true;
  return theMaze.is_horizontal_wall(x, y + 1);
} //end isWallBelow

bool isWalltoLeft(Maze &theMaze, int x, int y) {
  if (x - 1 <= -1)
    return true;
  return theMaze.is_vertical_wall(x - 1, y);
} //end isWalltoLeft

bool isWalltoRight(Maze &theMaze, int x, int y) {
  if (x + 1 > theMaze.get_width())
    return true;
  return theMaze.is_vertical_wall(x + 1, y);
} //end isWalltoRight
