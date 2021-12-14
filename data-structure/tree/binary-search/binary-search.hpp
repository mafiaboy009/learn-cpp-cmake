#include <iostream>

using namespace std;

struct Node{
    int data{};
    Node *left{};
    Node *right{};

    Node( int data ):data{data}, left{nullptr}, right{nullptr}{}
    ~Node(){
        cout << "destructing data node " << data << endl;
    }
};

struct BinarySearchTree{
    Node *root{};

    BinarySearchTree():root{nullptr}{}

    void insert( int data, Node **root1 ){
        if( *root1 == nullptr ){
            *root1 = new Node( data );
            return;
        }
        else{
            if( data < (*root1)->data ){
                insert( data, &(*root1)->left );
                return;
            }
            else if( data == (*root1)->data ){
                return;
            }
            else{
                insert( data, &(*root1)->right );
                return;
            }
        }
    }

    void inOrderDisplay( Node **root1 ){
        if( *root1 == nullptr ){
            return;
        }
        if( (*root1)->left ){
            inOrderDisplay( &(*root1)->left );
        }
        cout << (*root1)->data << " ";
        if( (*root1)->right ){
            inOrderDisplay( &(*root1)->right );
        }
    }

    void preOrderDisplay( Node **root1 ){
        if( *root1 == nullptr ){
            return;
        }
        cout << (*root1)->data << " ";
        if( (*root1)->left ){
            preOrderDisplay( &(*root1)->left );
        }
        if( (*root1)->right ){
            preOrderDisplay( &(*root1)->right );
        }
    }

    void postOrderDisplay( Node **root1 ){
        if( *root1 == nullptr ){
            return;
        }
        if( (*root1)->left ){
            postOrderDisplay( &(*root1)->left );
        }
        if( (*root1)->right ){
            postOrderDisplay( &(*root1)->right );
        }
        cout << (*root1)->data << " ";
    }

    void purgeNodes( Node **root1 ){
        if( *root1 == nullptr ){
            return;
        }
        if( (*root1)->left ){
            purgeNodes( &(*root1)->left );
        }
        if( (*root1)->right ){
            purgeNodes( &(*root1)->right );
        }
        delete (*root1);
    }

    ~BinarySearchTree( ){
        purgeNodes( &root );
    }
};
