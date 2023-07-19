//C++ Functor With Return Type and Parameters
#include <iostream>
using namespace std;

class Add {

  public:
    // overload function call operator
    // accept two integer arguments
    // return their sum
    int operator() (int a, int b) {
      return a + b;
    }
};

int main() {

  // create an object of Add class
  Add add;

  // call the add  object
  int sum = add(100, 78);// OR add.operator()(100, 78);

  cout << "100 + 78 = " << sum;

  return 0;
}