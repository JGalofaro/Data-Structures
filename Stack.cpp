/*
 * Stack.cpp
 *
 *  Created on: Sep 3, 2011
 *      Author: Josh Galofaro
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

struct StackStruct
{
	int size, index;
};

/** Global Variables **/
const int START_SIZE = 50;

template <class T>
class Stack
{
public:
	Stack(void);
	~Stack(void);
	void push(T obj);
	T pop();
	int getSize();
	void makeEmpty();
	bool isEmpty();
	bool isFull();

private:
	T * theStack;
	StackStruct theStruct;
	void resize();
	int regenerations;
};

template <class T>
Stack<T>::Stack(void)
{
	theStack = new T[START_SIZE];
	theStruct.size = START_SIZE;
	theStruct.index = -1;
	regenerations = 1;

	cout << "Constructed\n";
}

template <class T>
void Stack<T>::push(T obj)
{
	if(theStruct.index >= theStruct.size) resize();

	theStack[theStruct.index] = obj;
	theStruct.index++;
}

/** Need a check to stop a pop on an empty stack **/
template <class T>
T Stack<T>::pop()
{
    if( theStruct.index >= 0 )
    {
        T obj = theStack[theStruct.index];
        theStruct.index--;
	    return obj;
    }
    else return -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if( theStruct.index == -1 ) return true;
    else return false;
}

template <class T>
void Stack<T>::makeEmpty()
{
    theStruct.index == -1;
}

template <class T>
bool Stack<T>::isFull()
{
    return theStruct.index == theStruct.size;
}


template <class T>
void Stack<T>::resize()
{
	regenerations++;	//multiplier
	int newSize = START_SIZE * regenerations;

	T * tempStack = new T[newSize];

	for( int i = 0; i < theStruct.size; i++ )
	{
		tempStack[i] = theStack[i];
	}
	//memcpy( tempStack, theStack, theStruct.size);
	theStruct.size = newSize;
	cout << "Resized" << endl;
	delete theStack;
	theStack = new T[theStruct.size];
	for( int i = 0; i < theStruct.index; i++ )
	{
		theStack[i] = tempStack[i];
	}
	//theStack = tempStack;
	delete tempStack;
}

template <class T>
int Stack<T>::getSize()
{
	return theStruct.size;
}

template <class T>
Stack<T>::~Stack()
{
	cout << "Destroyed\n";
}

int main(void)
{
	Stack<int> * s = new Stack<int>;
	for( int i = 0; i <= 50; i++ )
	{
		s->push(i);
	}

	cout << s->getSize() << endl;
    cout << "first empty: " << s->isEmpty() << endl;

	int x = 0;
	for( int i = 50; i >= 0; i-- )
	{
		x = s->pop();
		cout << x << endl;
	}
	    
	x = s->pop();
	cout << x << endl;
	
	
    s->makeEmpty();
	cout << "second empty: " << s->isEmpty() << endl;
	
	for( int i = 0; i <= 50; i++ )
	{
		s->push(i);
	}

	cout << s->getSize() << endl;
    cout << "first empty: " << s->isEmpty() << endl;
    
	//delete s;
	cout << "Test" << endl;
	return 1;
}

