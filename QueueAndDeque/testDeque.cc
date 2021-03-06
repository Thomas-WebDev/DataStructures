/**************************************************************
 * Filename: testDeque.cc
 * Author: CSCI 132 instructor modified by Kevin Thomas Keho
 * Date Modified: September 21, 2016
 * Course: CSCI132
 * Assignment: Homework 3
 * Purpose: Test deque functions
 **************************************************************/

#include <iostream>
#include "deque.h"

using namespace std;

char get_command();
void help();
bool do_command(char, Deque &);

/* Post: Accepts commands from user as a menu-driven demonstration program
   for the class deque.
   Uses: The class deque and the functions introduction, get_command,
   and do_command. 
*/
int main( ) {
   Deque test_deque;
   help( );
   while (do_command(get_command( ), test_deque));
} // end main( )

void help()
/*
   Post: A help screen for the program is printed, giving the meaning of each
   command that the user may enter.
*/
{
   cout << endl
        << "This program allows the user to enter one command" << endl
        << "(but only one)on each input line." << endl
        << "For example, if the command S is entered, then" << endl
        << "the program will serve the front of the queue." << endl
        << endl
        << " The valid commands are:" << endl
        << "A - Append the next input character to the rear." << endl
        << "P - Push the next input character to the front." << endl
        << "S - Serve the front of the queue" << endl
        << "X - Extract the rear of the queue" << endl
        << "R - Retrieve and print the front entry." << endl
        << "W - Retrieve and write the rear entry." << endl
        << "H - This help screen" << endl
        << "Q - Quit" << endl
        << "Press <Enter> to continue." << flush;

   char c;
   do {
       cin.get(c);
   } while (c != '\n');
}  //end help( )

bool do_command(char c, Deque &test_deque)
/*
   Pre: c represents a valid command.
   Post: Performs the given command c on the Deque test_deque.
   Returns false if c == 'q', otherwise returns true.
   Uses: The class Deque.
*/
{
   bool continue_input = true;
   Queue_entry x;
   switch (c){
   case 'h': help();
     break;
   case 'q':
     cout << "Deque demonstration finished." << endl;
     continue_input = false;
     break;
   case 'a': 
     cout << "Enter new key to insert: ";
     cin >> x;
     cout << endl;
     test_deque.append_rear(x);
     cout << x << " appended to rear of deque." << endl << endl;
     break;
   case 'p': 
     cout << "Enter new key to insert: ";
     cin >> x;
     cout << endl;
     test_deque.append_front(x);
     cout << x << " appended to front of deque." << endl << endl;
     break;
   case 's': 
     if(!test_deque.empty()){
       test_deque.serve_front();
       cout << "Successfully served the front of the deque." << endl;
     } else {
       cout << "Serve failed, the deque is empty." << endl;
     }
     break;
   case 'x': 
     if(!test_deque.empty()){
       test_deque.serve_rear();
       cout << "Successfully served the rear of the deque." << endl << endl;
     } else {
       cout << "Serve failed, the deque is empty." << endl << endl;
     }
     break;
   case 'r': 
     if(test_deque.empty()){
       cout << "Deque is empty." << endl << endl;
     } else {
       test_deque.retrieve_front(x); 
       cout << "The first entry is: " << x << endl << endl;
     }
     break;
   case 'w': 
     if(test_deque.empty()){
       cout << "Deque is empty." << endl << endl;
     } else {
       test_deque.retrieve_rear(x);
       cout << "The last entry is: " << x << endl << endl;  
     }
     break;
   } //end switch on deque option

       return continue_input;

} //end do_command()

char get_command()
/*
   Post: Gets a valid command from the user and,
   after converting it to lower case if necessary,
   returns it.
*/
{
   char c = 'q';
   

   cout << endl << "Select command and press <Enter>: ";
   cin >> c;

   if ((c == 'a') || (c == 'A'))
     c = 'a';
   else if ((c == 'p') || (c == 'P'))
     c = 'p';
   else if ((c == 's') || (c == 'S'))
     c = 's';
   else if ((c == 'x') || (c == 'X'))
     c = 'x';
   else if ((c == 'r') || (c == 'R'))
     c = 'r';
   else if ((c == 'w') || (c == 'W'))
     c = 'w';
   else if ((c == 'h') || (c == 'H'))
     c = 'h';
   else if ((c == 'q') || (c == 'Q'))
     c = 'q';
   else {
     cout << "No valid command entered please re-enter a valid command." << endl;
     cout << "The valid commands are..." << endl;
     c = 'h';
   }
   
   return c;
} //end get_command

