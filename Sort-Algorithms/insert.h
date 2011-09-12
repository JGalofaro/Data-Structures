#ifndef INSERT
#define INSERT

#include <iostream>
using namespace std;

template <class T>
class insert
{
public:
    void Sort(T Array[], int size);
};

/**
 * Author: Josh Galofaro
 * Date: 09-13-2011
 *
 * This will sort any type of array using the Insertion Sort algorithm
 *
 * T array[] - the array to be sorted
 * int size  - the size of the array to be sorted
 **/
template <class T>
void insert<T>::Sort(T array[], int size)
{
    //Walker and Key will index objects in the array
    int walker = 0, key = 0;
    
    //Traverse the size of the array
    for( int i = 0; i < size; i++ )
    {
        //Set key to current spot in the array
        key = array[i];
        //Walker will be one behind the key
        walker = i-1;
        
        //While walker is an index at or below zero AND the object at index
        //Walker is larger than the object at index
        while((walker >= 0) && (array[walker] > key))
        {
            array[walker+1] = array[walker];
            walker = walker - 1;
        }//end while
        array[walker+1] = key;
    }//end for
}//end method

#endif
