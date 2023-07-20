#include <iostream>
using namespace std;

int main(){

    /* before C++11 */

    enum apple_old { green_o, red_o};
    enum orange_old { orange_o, green_oo };
    apple_old a_o = green_o;
    orange_old o_o = orange_o;
    if( a_o == o_o){
        cout << "a_o match o_o\n"; // will print this
    }

    /* after C++11 */
    
    enum class apple { green, red};
    enum class orange{ green, orange};
    apple a = apple::green;
    orange o = orange::green;
/*
    if( a == o ){ // compilation error
        cout << "a match o\n";        
    } 
*/
}