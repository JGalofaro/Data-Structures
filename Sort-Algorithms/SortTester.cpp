#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

/**
 * TO ADD:
 *  * Main Parameters:
 *      * # of tests
 *      * output file name (will add postfix: unsorted or sorted_[sort-type])
 *      * sort type ('*' or some simillar key to sort with every possible algoritm)
 *  * Sort arrays and output sorted to file
 **/
using namespace std;

class generator
{
public:
    void generate(int number_of_tests, string file_name);
private:
    void output(string file_name, int array[], int size);
};

void generator::generate(int number_of_tests, string file_name)
{
    int size = 0;
    
    //Initialize random seed:
    srand( time(NULL) );
        
    for( int i = 0; i <= number_of_tests; i++ )
    {
        //generate size of test array
        size = rand() % 10;
        
        int rand_array[size];
        
        //Populate the test array
        for( int j = 0; j <= size; j++ )
        {
            rand_array[j] = rand() % 100;
        }//end for
        
        output( file_name, rand_array, size );
    }//end for
}//end method

void generator::output(string file_name, int array[], int size)
{
    ofstream ofile;
//    char *const file_name_char = "test_generator_1.txt";
    ofile.open(file_name.c_str(), ios::app);
    
    if( ofile.is_open() )
    {
        ofile << (size+1) << " ";
        ofile << array[0];
        for( int i = 1; i <= size; i++ )
        {
            ofile << "," << array[i];
        }//end for
        ofile << "\n";
    }//end if
    
    ofile.close();
}//end method

int main( void )
{
    const static int N = 5;
    const static string file = "test_generator_1.txt";
    generator* gen = new generator();
    gen->generate( N, file );
    return 1;
}//end method
