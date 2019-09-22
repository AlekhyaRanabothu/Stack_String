#include <cstdlib>
#include <string>
#include <iostream>
#include "SStack.h"
#include <fstream>
using namespace std;

int main()
{
	int stack_cap,stack_len;       // stack_cap is maximum size of the stack and stack_len is number of elements to be stored in the satck
	int op;               		  //selection of operation in Menu
	string pushlastname;         // last name to be pushed on to the stack by the user
	int num_pop;                // number of elements to pop

	cout << "Enter the capacity of the stack in the order of 100" << endl;
	cin >> stack_cap;
	cout << "Enter the length of the stack in the order of 100 and less than the capacity" << endl;
	cin >> stack_len;
	if (stack_len > stack_cap)
    {
     cerr << "Enter stack length less than the stack capacity" << endl;       //check if the number of elements to be stored in the stack is less than the capacity of the stack
    }
    else
    {
	SStack stack1(stack_cap);
    cout << "stack is initialised with capcity : " << stack_cap << endl;
	ifstream Lastnamein;
	ofstream Lastnameout;
    Lastnamein.open("all.last.txt");						//read the lastnames from the text file
	if(Lastnamein.fail())
	{
    cerr << "Failed to open the file" << endl;               //check if the fail can be opened and read
	}

	cout << "file is opened" << endl;
	string line;
	for (int i = 1;i <= stack_len;i++)
	{
    std::getline(Lastnamein,line);							//push the specified number of elements from the file to stack 
    stack1.push(line);
    }
    cout << "file is read and pushed to the stack"<< endl;
   cout << " The stack created is :"  << endl;
   stack1.print();											//print the stack
   SStack stack2(stack1);									//copy the created stack to another stack
   SStack stack3(stack_cap);								//third stack to be appended while calling the union function
   SStack tempstack(stack_cap);   							// stack to store the union stack
   
   ifstream unionin;
   unionin.open("all.last2.txt");							//read the names from a file and push to the stack that is to be added						
   if(unionin.fail())
	{
    cerr << "Failed to open the file" << endl;
	}
	cout << "file is opened" << endl;
	string line_t;
	while(!unionin.eof())
    {
    std::getline(unionin,line_t);
    stack3.push(line_t);
    }
 // Menu for the user to select the operations of stack
 
	cout << "Select any number of the following operations : \n 1 for Push \n 2 for Pop \n 3 for Top \n 4 for Union \n 5 for Print \n 6 for Save \n 7 for Quit" << endl;
    cin >> op;
	switch(op)
	{
		case 1 : cout << "you have selected Push operation" << endl;
		         cout << "Enter the last name to be pushed on to the stack" << endl;
				 cin >> pushlastname ;														//asks the user for last name to push
				 stack1.push(pushlastname);
				 cout << "The number of elements in the stack are : " << endl;				//prints the size of the stack
				 cout << stack1.size() << endl;												
				 if (stack1.size() > 5)							// if the size of the stack is more than 5 prints the top 5 elements else prints all the elements							
				 {
                  cout << "the top 5 elements in the stack are :" << endl;
                  stack1.print(5);
                  }

				 else stack1.print();
				 break ;

		case 2 : cout << "you have selected Pop operation" << endl;
		         cout << "Enter the number of elements to pop" << endl;
				 cin >> num_pop ;											// asks the user to enter the number of elements to pop
				 if (stack1.size() >= num_pop)								//if the stack size is more than the number of elements to pop,pops the specified number of elements
				 {
				 for ( int k = 0; k < num_pop;k++)
				 {
				  cout << "popped : " << stack1.pop() << endl;
                 }
				 cout << "The remaining number of elements in the stack is :" << stack1.size() << endl;  //prints remaining elements after pop
				 }
				 else
                 {
				 for(int b = stack1.size(); b > 0; b--)						//otherwise pops all the elements from the stack
				 {
                 cout << " popped : " << stack1.pop() << endl;
                 }
                 }
                 break ;

		case 3 : cout << "you have selected Top operation" << endl;
		         stack1.top();												//returns the top element of the stack
				 cout << "The remaining elements of the stack other than the top element are : " << stack1.size()- 1 << endl;  //prints remaining elements other than top element
                 break ;

		case 4 : cout << "you have selected union operation" << endl;

                cout << "stack is initialised with capcity" << stack_cap << endl;
                cout << "stack to be appended is " << endl;
                stack3.print();												//prints the stack which is to be added
                tempstack = stack2 +stack3;
                tempstack.print();											//union of the two stacks
                cout << "The stack is added " << endl;
                 break ;

        case 5 : cout << "you have selected Print operation" << endl;		//prints all the elements of the stack
                 stack1.print();
                 break;

        case 6 : cout << "you have selected save operation" << endl;    //saves the stack to a file
                 Lastnameout.open("savestack.txt");
                 if(Lastnameout.fail())
	             {
                 cerr << "Failed to open the file" << endl;
	             }
	             cout << "file is opened" << endl;
                 cout << " the contents of the stack is" << endl;
	             stack1.print();
                 int p;
                 p = stack1.size();
	             for (int i = 1;i <=p;i++)
	             {
                 Lastnameout << stack1.pop()<< '\n';

                }
                cout << "the stack is saved to a file" << endl;
	            break;

         case 7 : cout <<"You have selected quit operation " << endl;        //delete the stack
                  stack1.~SStack();
                  cout << "cleared and deleted the stack successfully " << endl;
                  break;

        default : cout<< "no operation is selected from the menu" << endl;
                  break ;
	}
    }
}



