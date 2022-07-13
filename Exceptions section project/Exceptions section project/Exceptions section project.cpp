#include <iostream>
using namespace std;

class StackOverflow : exception {};
class StackUnderflow : exception {};

class Stack
{
private:
	int stackSize;
	int stackCount;
	int topMember;
	int* privatePointer;

public:
	Stack(int newStackSize=0)
	{
		stackSize = newStackSize;
		stackCount = 0;
		topMember = 0;
	}

	int stackObjectSize()
	{
		return stackSize;
	}

	void pushIntoStack(int newMember)
	{
		try
		{
			if (stackSize == stackCount)
				throw StackOverflow();
		}
		catch (StackOverflow) {
			cout << "Stack has overflown! Error message 88" << endl;
		}
		stackCount++;
		topMember = newMember;
		cout << newMember << " has been added to the stack and is the top Member." << endl;
	}

	int topPointerFunction()
	{
		cout << "topPointer of firstStack object pointing on topPointerFunction is " << topMember << endl;
		return 0;
	}

	void popOffStack()
	{
		try
		{
			if (stackCount - 1 < 0)
				throw StackUnderflow();
		}
		catch (StackUnderflow) {
			cout << "Stack is now Empty. Error message 22" << endl;
		}
		stackCount--;
		cout << "Stack decreased by 1." << endl;
	}
	void queryNewestMember()
	{
		cout << "The top member is " << topMember << endl;
	}
	void queryStackOccupiedSpace()
	{
		cout<<"Current occupied space is "<<stackCount<<endl;
	}
};

int main()
{
	Stack firstStack(2);
	Stack* topPointer;
	topPointer = &firstStack;
	firstStack.pushIntoStack(7);
	topPointer->topPointerFunction();
	firstStack.pushIntoStack(3);
	topPointer->topPointerFunction();
	firstStack.pushIntoStack(9);
	topPointer->topPointerFunction();
	Stack secondStack(1);
	secondStack.pushIntoStack(88);
	secondStack.popOffStack();
	secondStack.popOffStack();
}