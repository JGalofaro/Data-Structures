#include <iostream>
#include <fstream>
using namespace std;

template <class T>
struct TreeNode
{
       TreeNode<T>* left;
       TreeNode<T>* right;
       TreeNode<T>* parent;
       T data;
};

template <class T>
class Tree
{
      public:
             Tree();
             ~Tree();
             bool isEmpty();
             int numberOfNodes();
             void insertItem( T item );
             void deleteItem( T item );
             void retrieveItem( T& item, bool& found );
             void printTree( ofstream & outFile );
             void whatTheHellIsRoot();
      private:
              int numOfNodes;
              TreeNode<T>* root;
              void printHelper( TreeNode<T>* ptr, ofstream& outFile);
              void insertHelper( TreeNode<T>*& ptr, T item);
              void deleteHelper( TreeNode<T>* ptr, TreeNode<T>* parent, T& item );
              void retrieveHelper( TreeNode<T>* ptr, T& item, bool& found);
              void findMinimum(TreeNode<T>*& Min);
};

template <class T>
Tree<T>::Tree()
{
     root = NULL;
     numOfNodes = 0;          
}

template <class T>
int Tree<T>::numberOfNodes()
{
    return numOfNodes;
}

template <class T>
void Tree<T>::whatTheHellIsRoot()
{
     cout << root->data << endl;
}

template <class T>
void Tree<T>::insertItem( T item )
{
      insertHelper( root, item );
}

template <class T>
void Tree<T>::insertHelper( TreeNode<T>*& ptr, T item)
{
     /** Insert Here **/
     if  ( ptr == NULL ) 
     {      
           //cout << "null" << endl;
             ptr = new TreeNode<T>;
             ptr->right = NULL;
             ptr->left = NULL;
             ptr->data = item;
           numOfNodes++;
     }
     /** Traverse left **/
     else if  ( item  <  ptr->data )
     {
          //cout << "Left" << endl;           
            insertHelper( ptr->left , item );
     }
     /** Traverse right **/
     else if  ( item  >  ptr->data )
     {
          //cout << "Right" << endl;            
             insertHelper( ptr->right , item );
     }
}

template <class T>
void Tree<T>::retrieveItem(T& item, bool& found)
{
     retrieveHelper( root, item, found );
}

template <class T>
void Tree<T>::retrieveHelper(TreeNode<T>* ptr, T& item, bool& found)
{
     if  ( ptr == NULL )
     {
         //cout << "NULL" << endl; 
           found = false;
     }
     /** Go left **/
     else if  ( item  <  ptr->data )
            retrieveHelper( ptr->left , item,  found );
     /** Go right **/
     else if  ( item  >  ptr->data )
            retrieveHelper( ptr->right , item,  found );
     else
     {     item = ptr->data;
          // cout << "Found" << endl;
             found = true;
     }
}

template <class T>
void Tree<T>::deleteItem(T item)
{
     deleteHelper(root, root,item);
}

template <class T>
void Tree<T>::findMinimum(TreeNode<T>*& Min)
{
     if( Min->left != NULL )
     {
         Min = Min->left;
         findMinimum(Min);
     }
}

template <class T>
void Tree<T>::deleteHelper(TreeNode<T>* ptr, TreeNode<T>* parent, T& item)
{
    
     if( ptr->data == item )
     {
       cout << "Found Item" << endl;
       /** If node has two children **/
       if( ptr->left != NULL && ptr->right != NULL )
       {
           TreeNode<T> *min = new TreeNode<T>;
           min = ptr->right;
           findMinimum(min);         //Minimum is smallest in right subtree of ptr
           ptr = min;
           deleteHelper(ptr->right, ptr, min->data);
       }
       /** If node has one child (on the right) **/
       if( ptr->left == NULL && ptr->right != NULL )
       {
           if( parent->left->data == item ) parent->left = ptr->right;
           else if( parent->right->data == item) parent->right = ptr->right;
       }
       /** If node has one child (on the left) **/
       if( ptr->left != NULL && ptr->right == NULL )
       {
           if( parent->left->data == item ) parent->left = ptr->left;
           else if( parent->right->data == item) parent->right = ptr->left;
       }
       /** If Node is a leaf **/
       if( ptr->left == NULL && ptr->right == NULL )
       {
           cout << "Found node" << endl;
           if( parent->left != NULL ) parent->left = NULL;
           else if( parent->right != NULL ) parent->right = NULL;
           delete ptr;
       }
     }else if( item < ptr->data ) deleteHelper(ptr->left, ptr, item);
     else if( item > ptr->data ) deleteHelper( ptr->right, ptr, item);
}

template <class T>
void Tree<T>::printTree(ofstream& outFile)
{
     printHelper(root, outFile);
     outFile.close();
}

template <class T>
void Tree<T>::printHelper(TreeNode<T>* ptr, ofstream& outFile)
{
     if( ptr != NULL )
     {
         printHelper(ptr->left, outFile);

         outFile << ptr->data;

         printHelper(ptr->right, outFile);
     }
}

template <class T>
bool Tree<T>::isEmpty()
{
     return( root == NULL );
}

template <class T>
Tree<T>::~Tree()
{
    //Delete Tree
}

int main()
{
    int wait, catcher=9;
    bool isFound = false;

    cout << "Compiled!" << endl;
    cout << "True = " << true << endl;
    cout << "False = " << false << endl;

    Tree<int>* t = new Tree<int>();
  

    cout << t->isEmpty() << endl;
    cout << t->numberOfNodes() << endl;

    t->insertItem(5);
    t->insertItem(4);
    t->insertItem(7);
    t->insertItem(9);
    t->insertItem(1);
    t->insertItem(2);


   
    cout << t->isEmpty() << endl;
    cout << t->numberOfNodes() << endl;

    t->retrieveItem(catcher, isFound);
    cout << "is found: " << isFound << endl;

    t->whatTheHellIsRoot();

    ofstream file("treeFile.txt");
    t->printTree(file);

    ofstream dFile("deletedTreeFile.txt");
    t->deleteItem(7);
    t->printTree(dFile);

    t->insertItem(20);
    //ofstream file("treeFile.txt");
    file.open("treeFile.txt");
    t->printTree(file);
    cin >> wait;

    return 1;
}
