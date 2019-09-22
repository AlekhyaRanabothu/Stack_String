#Read me file

prerequisites for execution:

Make sure all these files exist before running the program.

1.main.cpp,SStackcp,SStack.h(Note:header file is modified.Added a member function to print specified number of elements).

2.all.last.txt(to create the stack).

3.all.last2.txt to create the stack that is to be added as part of union operation.

4.savestack.txt to save the elements of the stack to the file.


Process for execution:

Enter the Capacity of the stack and also the length(number of elements to be stored in the stack).
The stack length you enter should be less the stack capacity.
When the screen prompts for the Menu,selects the operation which you need to perform on the stack.

1.Push:Select '1' for Push.If you select push,screen prompts to enter the lastname you want to push to the stack.
       prints the size of the stack and if the size of the stack is more than 5 prints the top 5 elements else prints all the elements.
2.Pop: Select '2' for Pop.If you select pop,asks the user to enter the number of elements to pop.
       If the stack size is more than the number of elements to pop,pops the specified number of elements and prints remaining elements after pop.
	   Otherwise pops all the elements from the stack.
3.Top: Select '3' for Top.This returns the top element of the stack and prints remaining elements other than top element.
4.Union: Select '4' for Union.You can add the last names you need to add to the satck in the file called "all.last2.txt" before execution of the program.This return the addition of the two stacks.
5.Print:Select '5' for Printing all the elements in the stack.
6.Save: Select '6' for saving the contents of the stack to a file('savestack.txt).
7.Quit: Select '7' for deleting the elements of the stack to make sure there is no memory leak.

