#include "builder.hpp"

// Implement the Coffee classes "create" method
CoffeeBuilder Coffee::create(std::string requestorName) {
	return CoffeeBuilder{requestorName};
}

// Builder methods
CoffeeBuilder&  CoffeeBuilder::makeHot() {
	coffee.isHot = true;
	return *this;
};

CoffeeBuilder&  CoffeeBuilder::addSugar() {
	coffee.hasSugar = true;
	return *this;
};

CoffeeBuilder&  CoffeeBuilder::addMilk() {
	coffee.hasMilk = true;
    return *this;
};

CoffeeBuilder&  CoffeeBuilder::costs(double cost) {
    coffee.cost = cost; 
    return *this;
};


int main() { 
    Coffee coffee = Coffee::create("Zachary")
							  .makeHot()
							  .addSugar()
							  .addMilk()
							  .costs(4.00);

    Coffee coffee2 = Coffee::create("Jennifer")
							  .makeHot()
							  .costs(3.50);

    std::cout << coffee.cost << std::endl;
    std::cout << coffee2.cost << std::endl;

    return 0;
}
