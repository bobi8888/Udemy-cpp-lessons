#include <iostream>
using namespace std;

template<class stackTemplate>
//a template of class "stackTemplate"

class Stack
{
private:
	stackTemplate* stackPointer;
	//stackTemplate makes this data item be whatever datatype at object creation
	int top;
	int size;

public:
	Stack(int desiredSize)
	{
		size = desiredSize;
		top = -1;
		stackPointer = new int[size];
	}
	void push(stackTemplate x);
	stackTemplate pop();
};

template<class stackTemplate>
//when a template is to be used outside the scope, each time the template must be issued
void Stack<stackTemplate>::push(stackTemplate x)
//when a function is written for an object outside it's scope, the template must be <invoked>after writting the object and the :: resolution 
{
	if (top == size - 1)
		cout << "The stack is full." << endl;
	else
	{
		top++;
		stackPointer[top] = x;
	}
}

template <class stackTemplate>
stackTemplate Stack<stackTemplate>::pop()
//stackTemplate datatype, Stack class, invoking template outside of scope resolution
{
	stackTemplate x = 0;
	if (top == -1)
		cout << "The stack is empty.";
	else
	{
		x = stackPointer[top];
		top--;
	}
	return x;
}

int main()
{
	Stack<int> firstStack(10);
	//firstStack datatypes are now all int due to template
	Stack<float> secondStack(20);
	//secondStack object datatypes are all floats due to template
	firstStack.push(88);
	secondStack.push(2.22);
	}