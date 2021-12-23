#include <iostream>
#include <random>
#include <functional>

using namespace std;

bool randomDecider( ){
    //auto gen = bind(uniform_int_distribution<>(0,1),default_random_engine());
    std::random_device seed{};
	std::mt19937 engine{seed()};
	std::uniform_int_distribution<> dis{0, 1};
    //return static_cast<bool>( gen() );
    return dis( engine );
}

struct Node{
    int data{};
    Node *left{};
    Node *right{};

    Node( int data ):data{data}, left{nullptr}, right{nullptr}{}

    ~Node(){
        //cout << "destructing data node " << data << endl;
    }
};

struct BinaryTree{
    Node *root{};

    BinaryTree():root{nullptr}{}

    void insert( int data, Node **root1 ){
        if( *root1 == nullptr ){
            *root1 = new Node( data );
            return;
        }
        else{
            if( randomDecider() ){
                //cout << " left ";
                insert( data, &(*root1)->left );
                return;
            }
            else{
                //cout << " right ";
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

    ~BinaryTree( ){
        purgeNodes( &root );
    }
};

