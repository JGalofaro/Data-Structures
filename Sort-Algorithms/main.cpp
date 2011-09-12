#include "insert.h"
#include "bubble.h"
#include "selection.h"
#include <iostream>
using namespace std;

int main(void)
{
    insert<int> Insertion;
    bubble<int> Bubble;
    //selection<int> Selection;
    
    char a[6] = {'f', 'e', 'd', 'c', 'b', 'a'};
    bool b[6] = {true, true, false, true, false, false};
    int in[6] = {6, 5, 4, 3, 2, 1};
    int bu[6] = {6, 5, 4, 3, 2, 1};
    int se[6] = {6, 5, 4, 3, 2, 1};
    int size = 6;
    
    /** Test Case A **/
    cout << "Original Insertion Array: ";
    cout << in[0];
    for( int i = 1; i < 6; i++ )
    {
        cout << ", " << in[i];
    }
    cout << endl;
    
    cout << "Original Bubble Array: ";
    cout << bu[0];
    for( int i = 1; i < 6; i++ )
    {
        cout << ", " << bu[i];
    }
    cout << endl << endl;
    
    Insertion.Sort(in, size);
    Bubble.Sort(bu, size);
    //Selection.Sort(c, size);
    
    cout << "Sorted Insertion Array: ";
    cout << in[0];
    for( int i = 1; i < 6; i++ )
    {
        cout << ", " << in[i];
    }
    cout << endl;
    
    cout << "Sorted Bubble Array: ";
    cout << bu[0];
    for( int i = 1; i < 6; i++ )
    {
        cout << ", " << bu[i];
    }
    cout << endl;
    
    return 1;
    
}
