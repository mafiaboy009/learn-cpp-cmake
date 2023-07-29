/* compiler generated functions for a class/struct

constructor <-> ctor
 destructor <-> dtor

1. default ctor ------- generated only if no ctor is declared/deleted by user
2. copy ctor ========== generated only if no 5,6
3. copy assignment ---- generated only if no 5,6
4. dtor =============== generated only if no 
5. move ctor ---------- generated only if no 2,3,4,6
6. move assignment ==== generated only if no 2,3,4,5

*/

class Dog{}; //generated: 1,2,3,4,5,6

class Cat { //generated: 3,4
    Cat(const Cat&){} // copy ctor
};

class Duck{ //generated: 4
    Duck(Duck&&) {} // move ctor
};

class Frog{//generated: 4 
    Frog(Frog&&, int = 0){} // this a move ctor in disguise
    Frog(int = 0) {} // default ctor in disguise
    Frog( const Frog&, int =0) {} // copy ctor in disguise
};

class Cow{//generated: 1,2,4
    Cow& operator=(const Cow&) = delete;
};

class Fish{//generated: 1,2,3
    ~Fish(){}
};