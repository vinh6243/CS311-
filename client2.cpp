//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Vinh Pham
//Complier:  C++ Compiler
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Given a set of characters , we would like to genernate  //**
//                        Display all possible string consisting of characters.
//Algorithm: ** Take a characters and add them inside the queue. To generate a new strings to the elements.
//Then we will print it out to console and add it back to the queue within the loop. The try and catch
// make sure that the queue is not Overflow and Underflow. Prompt the message to console if needed. 
int main()
{ // ** "A", "B", "C" in the queue
      
      queue characters;// queue objects
      string characterDemo;
      characters.add("A");  //add our first three 'root' elements
      characters.add("B");
      characters.add("C");
      
      while(1==1) 
	{   //an indefinite loop
        try {
             if (!characters.isEmpty()) 
	       {    //remove the string 
                characters.remove(characterDemo); //remove the front element
	       }
            cout << characterDemo << endl;  // and display it
            
            if (!characters.isFull()) 
	      {     
		characters.add(characterDemo + "A"); 
		characters.add(characterDemo + "B");  //add three new string into the queue and repeats
		characters.add(characterDemo + "C");
	      }
	    } // end of try
	     catch(queue::Underflow)
	       { 
		 cout << "Not enough characters." << endl; //** }
		 return 0;
	       }
	     catch (queue::Overflow)
	       {
		 cout << "Queue is full. Too many charaters" << endl;
		 return 0;
	       }
	}// end of while loop 
}// end programs



