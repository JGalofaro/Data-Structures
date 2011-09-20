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
    void formatFileNames(string file_name);
    string original_file_name, output_file_unsorted, output_file_sorted;
};

void generator::generate(int number_of_tests, string file_name)
{
    int size = 0;
    original_file_name = file_name;
    formatFileNames(file_name);

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

void generator::formatFileNames(string file_name)
{
    size_t extension = 0;
    string uns = "_unsorted";
    string sor = "_sorted_";

    /** TO BE IMPLEMENTED **/
    /**
    if( sortType == 1 ) append Select Sort
    else if( sortType == 2 ) append Bubble Sort
    else if( sortType == 3 ) append Insert Sort
    else if( sortType == 0 ) append All
    **/

    //If file_name is empty, assign default name
    if( file_name.empty() ) file_name = "SortTest_Output.txt";

    extension = file_name.find_last_of(".");
    cout << extension << endl;
    output_file_unsorted = file_name;
    output_file_unsorted.insert(extension, uns);

    cout << output_file_unsorted << endl;
}
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

int main( int argc, char* argv[] )
{
    // First argument: Number of Random Tests
    int N = atoi(argv[1]);
    // Second argument: File name to output
    string file = argv[2];
    // Third argument: Sorting algorithm to use
    int sortType = atoi(argv[3]);    
    
    /** Testing Purposes
    cout << "Argument 1: " << N << endl;
    cout << "Argument 2: " << file << endl;
    cout << "ARgument 3: " << sortType << endl;
    **/

    generator* gen = new generator();
    gen->generate( N, file );
    
    /** 09-20-2011: This should be implemented **/
    /**
    if( sortType == 1 ) run Select Sort
    else if( sortType == 2 ) run Bubble Sort
    else if( sortType == 3 ) run Insert Sort
    else if( sortType == 0 )
    {
         run Select Sort;
         run Bubble Sort;
         run Insert Sort;
    }
    **/
    return 1;
}//end method
