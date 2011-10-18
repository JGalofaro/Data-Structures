/**
 * Heap.cpp
 *
 * Version:
 *      0.1.2
 * Auhtor: Josh Galofaro
 * Date: 10/18/2011
 **/
#include <iostream>
using namespace std;

//Node structure, holds the data and its two pointers
template <class T>
struct node
{
    T data;
    node<T> *left;
    node<T> *right;
    node<T> *parent;
};

/**
 * Heap
 *  Creates and manipulates a heap object
 **/
template <class T>
class Heap
{
public:
    Heap();
    ~Heap();
    void insert(T obj);
    void printHeap();
    void getRoot();
private:
    node<T> *root;
    void insertAssistant(T obj, node<T> *ptr);
    void reheapChecker(node<T> *ptr);
    void reheapUp(node<T> *ptr);
    void printAssistant(node<T> *ptr);
};

//Constructor
template <class T>
Heap<T>::Heap()
{
    root = NULL;
    
    cerr << "DEBUG>>Heap created" << endl;
}

template <class T>
void Heap<T>::insert(T obj)
{
    node<T> *temp = new node<T>;
    temp->data = obj;
    
    if( root == NULL )  //first insert
    {
        root = temp;   
    }
    else insertAssistant(obj, root);
}

template <class T>
void Heap<T>::insertAssistant(T obj, node<T> *ptr)
{
    cerr << "DEBUG>>Reached insert assistant" << endl;
    
    node<T> *temp = new node<T>;
    temp->data = obj;
    

    if( ptr->left == NULL )         //Check if the left node is empty
    {
        ptr->left = temp;
        ptr->left->parent = ptr;
        reheapChecker( ptr->left );
    }
    else if( ptr->left != NULL )    //If left node is full, check right node
    {
        if( ptr->right == NULL )    //If right node is empty
        {
            ptr->right = temp;
            ptr->right->parent = ptr;
            reheapChecker( ptr->right );
        }
        else if( ptr->right != NULL )   //If both nodes are full:
        {
            insertAssistant(obj, ptr->left);    //Jump down a level
        }
    }
}

template <class T>
void Heap<T>::reheapChecker( node<T> *ptr )
{   
    if( (ptr != root) && (ptr->data > ptr->parent->data) )
    {
        reheapUp(ptr);
    }
    
    cerr << "DEBUG>>Reheap Checker" << endl;
}

template <class T>
void Heap<T>::reheapUp( node<T> *ptr )
{
    node<T> *temp = new node<T>;

    temp->data = ptr->parent->data;
    ptr->parent->data = ptr->data;
    ptr->data = temp->data;
    
    cerr << "DEBUG>>Parent and Child switched" << endl;
    if( ptr != root ) reheapChecker( ptr->parent );
}

template <class T>
void Heap<T>::printHeap()
{
    printAssistant(root);
}

template <class T>
void Heap<T>::printAssistant(node<T> *ptr)
{
    if( ptr != NULL )
    {
        cout << ptr->data << endl;
        
        printAssistant( ptr->left );
        
        printAssistant( ptr->right);
    }

}

template <class T>
void Heap<T>::getRoot()
{
    cerr << "DEBUG>>Root: " << root->data << endl;
}

//Destructor
template <class T>
Heap<T>::~Heap()
{
    cerr << "DEBUG>>Heap Destroyed." << endl;
}

int main( void )
{
    cerr << "DEBUG>>Compiled" << endl;
    
    Heap<int> *h = new Heap<int>();    
    h->insert(5);
    h->insert(6);
    h->insert(4);
    h->insert(7);
    
    h->getRoot();
    h->printHeap();
    
    delete h;
    return 1;
}
