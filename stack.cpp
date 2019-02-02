//CS311 Yoshii 
//INSTRUCTION:
// Look for ** to complete the program (do control-S)
// Update the comments using the HOW TO COMMENT file, 
// When done, compile stack.cpp to make sure there are no syntax errors.
// NOTE: functions are called instead of repeating
// the same lines of code.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Vinh Pham
//Complier:  g++
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
  top = -1; // indicate an empty stack 
}
  
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ 
// nothing, Destructor
}
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{ 
  if ( top == -1) 
    return true; 
  else 
return false; 
}
    
//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{  
  if (top == MAX-1 ) 
    return true; 
  else return false; 
}
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
  if (isFull()) 
    {
       throw Overflow(); //** Throwing the overflow exception.
    }       
   else 
     { 
       top++; el[top] = elem; 
     }
}
 
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  if (isEmpty())
    throw Underflow() ; //** throwing the exception for underflow.
  else 
    { 
      elem = el[top]; top--;
    }
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ if (isEmpty()) 
    throw Underflow(); //**  throws an exception (underflow) 
   else 
     { 
       elem = el[top];
     }
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//         Otherwise, diplays the elements vertically.
void stack::displayAll()
{  cout << "STACK:---------" << endl;
   if (isEmpty()) cout << "[ empty ]" << endl;
   else 
     for (int i = top; i > -1; i--) // ** displaying the stack from top to the bottom
      { 
	cout << el[i] << endl; 
      }
   cout << "--------------" << endl;
}
 
 
//PURPOSE: pops all elements from the stack until 
// it is empty 
void stack::clearIt()
{
   el_t temp;  // ** comment a local variable here
   //**    // do not do top = -1, use a loop
   for(int i = top; i >-1; i--)
     {
       temp = el[top] ; top--;
     }
}
 

