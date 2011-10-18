/**
 * Expression_Tree.cpp
 *
 * Version:
 *  0.1.1.0
 *
 * Author: Josh Galofaro
 * Date: 10/18/2011
 **/
#include <iostream>
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
 *  print the tree in either, postfix, prefix or inorder notation.
 **/
class Expression_Tree
{
public:
    Expression_Tree();
    ~Expression_Tree();
    bool isEmpty();
private:
    int eval( treeNode *ptr );
    treeNode *root;
    int numberOfNodes;
};

/**
 * Expression Tree
 *  (Constructor)
 **/
Expression_Tree::Expression_Tree()
{  
    numberOfNodes = 0;
    
    cerr << "Tree created." << endl;
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
    
    Expression_Tree * t = new Expression_Tree();
    cout << "IS EMPTY: " << t->isEmpty() << endl;
    delete t;
    
    return 1;
}
