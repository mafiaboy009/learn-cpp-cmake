#include <iostream>

class Dog {  // Abstract Target
public:
	virtual ~Dog() = default;
	virtual void performsConversion() const = 0;
};

class DogFemale : public Dog {  // Concrete Target
public:
	virtual void performsConversion() const override { std::cout << "Dog female performs conversion." << std::endl; }
};

class Cat {  // Abstract Adaptee
public:
	virtual ~Cat() = default;
	virtual void performsConversion() const = 0;
};

class CatFemale : public Cat {  // Concrete Adaptee
public:
	virtual void performsConversion() const override { std::cout << "Cat female performs conversion." << std::endl; }
};

class DogNature {
public:
	void carryOutNature(Dog* dog) {
		std::cout << "On with the Dog nature!" << std::endl;
		dog->performsConversion();
	}
};

class ConversionAdapter : public Dog {  // Adapter
private:
	Cat* cat;
public:
	ConversionAdapter(Cat* c) : cat(c) {}
	virtual void performsConversion() const override { cat->performsConversion(); }
};

int main() {  // Client code
	DogFemale* dogFemale = new DogFemale;
	CatFemale* catFemale = new CatFemale;
	DogNature dogNature;
	//	dogNature.carryOutNature (catFemale);  // Will not compile of course since the parameter must be of type Dog*.
	ConversionAdapter* adaptedCat = new ConversionAdapter(catFemale);  // catFemale has adapted to become a Dog!

	dogNature.carryOutNature(dogFemale);
	dogNature.carryOutNature(adaptedCat);  // So now catFemale, in the form of adaptedCat, participates in the dogNature!
				// Note that catFemale is carrying out her own type of nature in dogNature though.

	delete adaptedCat;  // adaptedCat is not needed anymore
	delete catFemale; // catFemale is not needed anymore
	delete dogFemale; // dogFemale is not needed anymore, too
	return 0;
}
