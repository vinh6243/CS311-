//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Vinh Pham
//Complier:  C++ Compiler
//File type: Queue implementation file  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0) 
    {
      return true; //return true if element is empty
    }
  else 
    {
      return false; // else return false
    }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)
    {
      return true;  // Check if the amount if element at max size
    }
  else 
    {
      return false; //otherwise, if it is not at max return false.
    }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if (isFull()) 
    {     
      throw Overflow(); // catch overflow if queue is full
    }
  else
    { 
      rear = (rear + 1) % MAX_SIZE; // each time you want to enter an element
      el[rear] = newElem;
      count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if (isEmpty()) 
    {       
      throw Underflow(); //catch if is empty 
    }
  else 
    {
      el_t temp = el[front]; // temp variables to hold position of the fron element
      front = (front + 1) % MAX_SIZE; //set a new front
      count --;// reducing the count
      removedElem =  temp; // returning the old front elment 
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if (isEmpty()) 
    {
      throw Underflow();
    }
  else 
    {
      theElem = el[front];    //otherwise, the front element is returned
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count; // get the size
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  
  if (isEmpty()) // checking empty 
    {
      cout << "[ Empty ]" << endl;
    }
  else
    {
      int j = front;
      cout << "[";
      for (int i = 1; i <= count; i++)
	{ //**
	  cout << el[((front + i) % MAX_SIZE)] + " ";
	}
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{           // ** comment a local variable

  if(isEmpty())
    {
      throw Underflow();
    }
  else if(count == 1)
    {
      return;
    }
  el_t goBack; // local variables
  remove(goBack); // remove an element and store it back to local variables we created
  add(goBack); // add to local varibales back to the queue;
}

