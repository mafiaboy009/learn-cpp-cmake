#include <iostream>
#include <vector>
using namespace std;

template <typename func, typename T>
void filter_fn(func f, vector<T> vec){
    for(auto i: vec){
        if( f(i) ){
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main(){
    vector<int> intVec{1,2,3,4,5,6,7,8,9,10};
    filter_fn([](int x){return (x>3);}, intVec);
    filter_fn([](int x){return (x>2 && x<8);}, intVec);

    int y=4;
    filter_fn([&](int x){return (x>y);}, intVec);
}