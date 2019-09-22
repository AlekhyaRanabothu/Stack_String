#ifndef _StackClass_
#define  _StackClass_

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class SStack
{
        public:
                // Constructor
                SStack( int cap);
                // Copy Constructor
               	SStack( const SStack& s );
                ~SStack( ); //destructor

		// The member function push: Precondition:  the stack is not full.
                void push ( const std::string s);

		// The member function pop: Precondition:  the stack is not empty.
                string pop ();

		// The member function top: Precondition:  the stack is not empty.
                string top () const;

                bool IsEmpty () const;

		//printing all the elements in the stack
		void print() const;

		// printing specified number of elementsfrom the top of the stack
		void print(int n) const;

                int size() const;
		int getCapacity() const;


        private:
                int Capacity; // Capacity is the maximum number of items that a stack can hold
                std::string* DynamicStack;
                int used; // How many items are stored in the stack
};


		// NONMEMBER FUNCTIONS for the stack class
		// Postcondition: The stack returned is the union of s1 and s2.
		 SStack operator +(const SStack& s1, const SStack& s2);


#endif
