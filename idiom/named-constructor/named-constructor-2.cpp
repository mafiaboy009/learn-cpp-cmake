/*
Q. How can I force objects of my class to always be created via new rather than as local, namespace-scope, global, or static?
Ref: https://isocpp.org/wiki/faq/freestore-mgmt#static-create-methods
*/
#include <iostream>

using namespace std;
class Fred {
public:
  // The create() methods are the "named constructors":
  static Fred* create()                 { return new Fred();     }
  static Fred* create(int i)            { return new Fred(i);    }
  static Fred* create(const Fred& fred) { return new Fred(fred); }
  // ...
  ~Fred(){}
private:
  // The constructors themselves are private or protected:
  Fred(){};
  Fred(int i){};
  Fred(const Fred& fred){};
  // ...
};

int main()
{
  Fred* p = Fred::create(5);
  // ...
  delete p;
  // ...
}

/*
Note: Make sure your constructors are in the protected section if you expect Fred to have derived classes.
*/