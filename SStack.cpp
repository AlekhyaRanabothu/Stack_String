#include <iostream>
#include <cstdlib>
#include <string>
#include "SStack.h"
using namespace std;

	SStack::SStack( int cap)
	{
	 DynamicStack = new std::string[cap];
	 Capacity = cap;         // Constructor to set the stack to a given capacity
	 used = 0;
	 DynamicStack[0] = "LastName";
	 cout << "stack is initialsed" << endl;
	}

	SStack::SStack( const SStack& s )
	{
	 DynamicStack = new std::string[s.Capacity];
	 Capacity = s.Capacity;                         // copy constructor with the specified capacity
	 used = s.used;
	 for (int a =0;a < used;a++)
     {
      DynamicStack[a] = s.DynamicStack[a];
     }
	}

	void SStack:: push( const string s)
	{
	if (used == Capacity)                                           //check if the stack has reached the Capacity of the stack
	{
    cout << "Stack is full.Cannot push the last name" << endl;
	}
	else
    {
      DynamicStack[used] = s;                                       //push an element to the stack

	used = used + 1;
    }
	}

	bool SStack::IsEmpty () const
	{
	if (used == 0)                                                //Check if the stack is empty
	return true;
    else
	return false;
	}

	string SStack::pop ()
	{
	if (!IsEmpty())                                            //Check if the stack is empty
	{
	string temp;
	DynamicStack[used]=DynamicStack[used-1];
	temp=DynamicStack[used];                                  //Pop the element from the stack
	used=used-1;
	return temp;
	}
	else cout << " The stack is empty " << endl;
	}

	string SStack::top () const
	{
	if (!IsEmpty()) 												//Check if the stack is empty
	{
    cout << "The top Element is : "<< DynamicStack[used-1] << endl;		//Point to the top element of the stack
	return DynamicStack[used-1];
	}
	else cout << " The stack is empty " << endl;

	}



	void SStack::print() const
	{
	if (!IsEmpty())															//Check if the stack is empty
	  {
        for (int i = used-1; i >= 0; i--)
	     {
         cout << DynamicStack[i] << endl;									//Print all the elements in the stack
		 }
	  }
	 else
		 cout << "The stack is empty" << endl;
	}

	void SStack::print(int n) const
	{
	 if (!IsEmpty())														//Check if the stack is empty
	  {
	   for (int m = used; m > used-n; m--)
	     {
          cout << "The" << m <<"th element of the stack is :" << endl;		//Print the specified number of elements from the stack
		  cout << DynamicStack[m-1] << endl;
		 }
	  }
	 else
		 cout << "The stack is empty" << endl;
	}


	int SStack::size() const										//returns the size of the stack
	{
	 return used;
	}


	int SStack::getCapacity() const									//returns the capacity of the stack
	{
	 return Capacity;
	}

     SStack operator +(const SStack& s1, const SStack& s2)
	{
	    SStack unionstack(s1.getCapacity()+s2.getCapacity());
	    SStack tempstack1(s1);
	    SStack tempstack2(s2);

	    for (int a = s2.size();a > 0;a--)							//returns union of the two stacks
       {
       unionstack.push(tempstack2.pop());
       }
       for (int a =unionstack.size();a > 0;a--)
       {
       tempstack1.push(unionstack.pop());
       }
       return tempstack1;
	}

  SStack::~SStack()														//Calls the destructor automatically
	{
	cout << "Destructor is called to clear the elements of the stack" << endl;
	}

