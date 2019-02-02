//CS311 Yoshii 
//INSTRUCTION:
//Stack class header file template based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Vinh Pham
// Compiler:  g++ 
// File type: headher file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

//********************************************************************
/*changed typedef ** ek_t; to typedef char el_t;  */
 
typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
 
   //******************************************************************************************* 
  // Here are all exceptions that can happen in my stack class
   //**
   class Overflow {};  // empty class – used as an exception name only
   class Underflow {};     // empty class – used as an exception name only

 //end of exception handling class name
 //**************************************************************************************************
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: **gives back the top element without popping it (by ref)
  void topElem(el_t&);
  
  // ** Must add good comments for each function - See Notes1B

  //PURPOSE: returns true if stack is empty else false; 
  //
  //PARAMETER: NONE
  bool isEmpty();

  //PURPOSE: returns true if the stack is empty else false;
  //
  //PARAMETERS: NONE
  bool isFull();
  

  //PURPOSE: Display the stack in vertically order.
  //
  //PARAMETER: NONE
  void displayAll();

  //PURPOSE: Clear the stack removing every element inside the stack
  //
  //PARAMETER: NONE
  void clearIt();
  
};  
// Note: semicolon is needed at the end of the header file
