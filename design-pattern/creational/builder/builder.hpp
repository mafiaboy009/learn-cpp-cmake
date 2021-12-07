#pragma once
#include <iostream>
#include <string>

// Forward declare CoffeeBuilder class here to avoid compilation errors
class CoffeeBuilder;

// Coffee class declaration
class Coffee {
	std::string requestorName;

	public:
		bool isHot;
		bool hasMilk;
		bool hasSugar;
		double cost;

		Coffee(std::string requestorName) : requestorName(requestorName) {}

		friend class CoffeeBuilder;
		static CoffeeBuilder create(std::string requestorName); // returns an instance of CoffeeBuilder
};

// CoffeeBuilder class declaration - responsible for building a Coffee
class CoffeeBuilder {
    Coffee coffee;

	public:
		CoffeeBuilder(std::string requestorName) : coffee(Coffee(requestorName)) {}

		// This operator allows us to convert from a CoffeeBuilder to a Coffee 
		operator Coffee() const { return std::move(coffee); }

		CoffeeBuilder&  makeHot();
		CoffeeBuilder&  addMilk();
		CoffeeBuilder&  addSugar();
		CoffeeBuilder&  costs(double cost);
};
