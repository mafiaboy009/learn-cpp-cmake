#include <iostream>

class dog;
class cat;
class petVisitor{
    public:
    virtual void visit(cat *c) = 0;
    virtual void visit(dog *c) = 0;
};

class pet{
    public:
    virtual void accept(petVisitor& v) = 0;
};

class dog: public pet
{
    public:
    void accept(petVisitor& v){
        v.visit(this);
    }
};

class cat: public pet
{
    public:
    void accept(petVisitor& v){
        v.visit(this);
    }
};

class feedPetVisitor: public petVisitor
{
    public:
    void visit(cat *c){
        std::cout << "Feeding Tuna\n";
    }

    void visit(dog *d){
        std::cout << "Feeding Chicken\n";
    }

};

class makeSound: public petVisitor
{
    public:
    void visit(dog *d) override{
        std::cout << "Wuf wuf\n";
    }

    void visit(cat *c) override{
        std::cout << "Meow meow\n";
    }
};

int main()
{
    
    feedPetVisitor fv;
    makeSound ms;

    cat c;
    c.accept(fv);
    c.accept(ms);

    dog d;
    d.accept(fv);
    d.accept(ms);

    return EXIT_SUCCESS;
}