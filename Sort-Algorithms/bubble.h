#ifndef BUBBLE
#define BUBBLE

#include <iostream>
using namespace std;

template <class T>
class bubble
{
public:
    void Sort(T array[], int size);    
};

/**
 * Author: Josh Galofaro
 * Date: 09-13-2011
 *
 * This will sort any type of array using the Bubble Sort algorithm
 *
 * T array[] - the array to be sorted
 * int size  - the size of the array to be sorted
 **/
template <class T>
void bubble<T>::Sort(T array[], int size)
{
    //Walker and Current will be indexs for back-to-back places on the array.
    int walker = 0, current = 0;
    //Temp will be used as a hold for swapping two objects in the array.
    T temp;
    //NeedsToBeSorted will indicate if we have traversed the array without
    //any changes, or if we need to run the loop once more.
    bool needsToBeSorted = true;    
 
    //Continuously traverse the array, untill we no longer have objects to swap
    while( needsToBeSorted )        
    {   
        //Reset to false, if no swap occurs we will not need to enter the while
        //loop again
        needsToBeSorted = false; 
        for( int i = 1; i < size; i++ )
        {
            //If a swap is needed
            if( array[i-1] > array[i] )
            {
                //Dump one object into a temp slot and swap the two objects
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
                //A swap has occured so we need to traverse the array once more
                needsToBeSorted = true;
            }//end if
        }//end for
    }//end while
}//end method

#endif
