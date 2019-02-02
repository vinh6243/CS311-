//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Vinh Pham
//Complier: g++   
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Solve postfix equation 
//Algorithm:  Using a while loop to check each character to match with one of the operator
//and adding them into the stack.

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  //prompt the user input.
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1
	 //2.If it is an operand (number), 
	 //push it (you might get Overflow exception)
	 if(isdigit(item))
	   {    
	     if(!postfixstack.isFull())
	       {
		 postfixstack.push(item - '0');
	       }
	   }

	 //3.else if it is an operator,
	 //pop the two operands (you might get Underflow exception), and
	 //apply the operator to the two operands, and
	 //push the result.
	 else if ((item == '+') || (item == '-') || (item == '*'))
	   {
	     int answer;
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     
	     //cases of the operators:
	     //if spotted the '+'
	     if(item == '+')
	       {
		 answer = box2 + box1;
	       }
	     //if spotted '-'
	     else if(item == '-')
	       {
		 answer = box2 - box1;
	       }
	     //if spotted '*'
	     else if(item == '*')
	       {
		 answer = box2 * box1;
	       }
	     
	     //push the answer on screen
	     postfixstack.push(answer);

	   }
	 else throw stack::Underflow();
	 
       } // this closes try

      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{//**
	  cout << "**Error**: Too many number in this expression." << endl;
	  return 0;
	}
      catch (stack::Underflow)
	{//** 
	  cout << "**Error**: Not enough number in this expression." << endl;
	  return 0;
	}
      catch (char const* errormsg ) // for invalid item case
	{ 
	  cout << "**Error**: Invalid input. " << endl;
	}

      // go back to the loop after incrementing i
      //**
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
 // 1.The result will be at the top of the stack so pop it and show it.
 // 2.If anything is still left on the stack, an incomplete expression 
 //   was found, so inform the user.
 // If anything is left on the stack, an incomplete expression
 // was found so inform the user.
  // **


  int answer;
  if(!postfixstack.isEmpty())
    {
      postfixstack.pop(answer);
      if(postfixstack.isEmpty())
	{
	  cout << "Stack result: " << answer << endl;
	}
      else 
	{
	  cout << "**Error**: expression not complete." << endl;
	}
    }
}// end of the program
