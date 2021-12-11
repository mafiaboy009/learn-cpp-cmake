#include <iostream>
#include <map>

using namespace std;

class number{
    public:
        int i{};
        number(int i_):i{i_}{}
        bool operator<(const number& op1 ) const {
            return i < op1.i;
        }
};
/*
bool operator<(const number& op1, const number& op2){
    return op1.i < op2.i;
}
*/

int main(){

    // key is of int type
    map<int, number> aMap;
    number n1{1},n2{2},n4{5},n3{3};
    aMap.insert(pair{1, n1});
    aMap.insert(pair{6, n2});
    aMap.insert(pair{5, n3});
    aMap.insert(pair{3, n4});
    for( auto& v : aMap ){
        cout << v.first << " " << v.second.i << endl;
    }

    // key is of number type, a user defined type
    map<number, int> aMap1;
    aMap1.insert(pair{n1, 1});
    aMap1.insert(pair{n2, 6});
    aMap1.insert(pair{n3, 5});
    aMap1.insert(pair{n4, 3});
    for( auto& v : aMap1 ){
        cout << v.first.i << " " << v.second << endl;
    }

    return 0;
}


