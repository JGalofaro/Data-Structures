/**
 * Expression_Tree.cpp
 *
 * Version:
 *  0.1.2.0
 *
 * Author: Josh Galofaro
 * Date: 10/18/2011
 **/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

//InfoNode holds either a operator or an operand, using union we can
//easily access one or the other.
enum opType { OPERATOR, OPERAND };
struct infoNode 
{
    opType type;
    union
    {
        char operation;
        int operand;
    };
};

//Typical tree structure node, two pointers and a data object (which in this
//case is an infoNode containing either a char or an int)
struct treeNode
{
    infoNode data;
    treeNode *left;
    treeNode *right;
};

/**
 * Expression_Tree
 *  (Class)
 *
 *  This class creates and manipulates an expression tree, with the ability to
 *  print the tree in either, postfix, prefix or infix notation.
 **/
class Expression_Tree
{
public:
    Expression_Tree( string expression );
    ~Expression_Tree();
    bool isEmpty();
private:
    int eval( treeNode *ptr );
    void scan( char *exp_array, int size );
    void insert( int operand );
    void insert( char operation );
    treeNode *root;
    int numberOfNodes;
};

/**
 * Expression Tree
 *  (Constructor)
 **/
Expression_Tree::Expression_Tree( string expression )
{  
    numberOfNodes = 0;
    char *exp_array = new char[expression.length() + 1];
    strcpy(exp_array, expression.c_str());
    scan(exp_array, expression.length());
    cerr << "Tree created." << endl;
}

void Expression_Tree::scan( char *exp_array, int size)
{
    bool isOperation = false;
    string operand = "";
    char operation = NULL;
    
    //Debug purposes:
    for( int i = 0; i <= size; i++ )
    {
        if( exp_array[i] == '+' || exp_array[i] == '-' 
            || exp_array[i] == '*' || exp_array[i] == '/' )
        {
            operation = exp_array[i];
            isOperation = true;
        } else operand += exp_array[i];
        
        if( isOperation )
        {
            if( operand.size() == 0 )
            {
                cerr << "ERROR: Expression is not in correct form" << endl;
                exit(1);
            }
            int op = atoi(operand.c_str());
            insert( op );
            insert( operation );
            
            isOperation = false;
            operation = NULL;
            operand = "";
        }else if( i == size ) //end of the expression
        {
            if( operand.size() == 0 )
            {
                cerr << "ERROR: Expression is not in correct form" << endl;
                exit(1);
            }
            int op = atoi(operand.c_str());
            insert( op );
        }
    }
}

void Expression_Tree::insert( int operand )
{
    cerr << "INT: " << operand << endl;
}

void Expression_Tree::insert( char operation )
{
    cerr << "CHAR: " << operation << endl;
}
/**
 *  isEmpty
 *      Checks if the tree is empty or not
 **/
bool Expression_Tree::isEmpty()
{
    return (numberOfNodes == 0);
}
/**
 * eval
 *  Calculates the value of the expression tree
 *
 * params: treeNode *ptr - A pointer to a node, should call this method with 
 *                         the root node.
 **/
int Expression_Tree::eval( treeNode *ptr )
{
    switch( ptr->data.type )
    {
        case OPERAND: return ptr->data.operand;
        case OPERATOR:
            switch( ptr->data.operation )
            {
                case '+': return (eval(ptr->left) + eval(ptr->right));
                case '-': return (eval(ptr->left) - eval(ptr->right));
                case '*': return (eval(ptr->left) * eval(ptr->right));
                case '/': return (eval(ptr->left) / eval(ptr->right));
            }
    }
}

/**
 * Expression Tree
 *  (Deconstructor)
 **/
Expression_Tree::~Expression_Tree()
{
    cerr << "Tree destroyed." << endl;
}

int main( void )
{
    cerr << "Compiled." << endl;
    
    string exp = "15+4*2";
    int setAnswer = 18;
    
    Expression_Tree * t = new Expression_Tree(exp);
    cout << "IS EMPTY: " << t->isEmpty() << endl;
    delete t;
    
    return 1;
}
