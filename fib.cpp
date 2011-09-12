#include <iostream>

using namespace std;

int fib(int levels)
{
    //X is the first digit,
    //Y is the second digit,
    //Z is the third digit.
    int x = 0, y = 1, z = 0;
    
    if( levels >= 2 )
    {
        cout << x << ", " << y; //First two numbers
        
        //Loop the number of times the user wants
        for( int i = 1; i < levels; i++ )
        {
            cout << ", ";   //formating
            z = x + y; //Third digit is the sum of the previous two digits
            x = y;     //First digit becomes the value of the Second digit
            y = z;     //Second digit becomes the value of the Third digit
            
            cout << z;
        }//end for
        cout << endl; //formatoing
    }//end if
}

int Rec_Fib(int levels)
{
    if( levels == 0 ) return 0;
    else if( levels == 1 ) return 1;
    else return Rec_Fib(levels-1) + Rec_Fib(levels-2);
}

int main(void)
{
    int levels = 0;
    
    cout << "How many numbers do you want to see?: ";
    cin >> levels;
 
    cout << "Final: ";
    cout << Rec_Fib(levels) << endl;
       
    fib(levels);
}
