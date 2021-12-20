#include "binary.hpp"

int main(){
    BinarySearchTree bst;
    bst.inOrderDisplay( &bst.root );
    cout << endl;
    bst.insert( 2, &bst.root );
    bst.insert( 1, &bst.root );
    bst.insert( 8, &bst.root );
    bst.insert( 5, &bst.root );
    bst.insert( 4, &bst.root );
    bst.insert( 4, &bst.root );
    bst.insert( 105, &bst.root );
    bst.inOrderDisplay( &bst.root );
    cout << endl;
    bst.preOrderDisplay( &bst.root );
    cout << endl;
    bst.postOrderDisplay( &bst.root );
    cout << endl;

    return 0;
}
