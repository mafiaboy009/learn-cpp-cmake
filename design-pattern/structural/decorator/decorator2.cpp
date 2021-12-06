#include <iostream>
#include <string>
#include <memory>

class Interface {
	public:
		virtual ~Interface() { }
		virtual void write (std::string&) = 0;
};

class Core : public Interface {
	public:
	   	~Core() {std::cout << "Core destructor called.\n";}
	   	virtual void write (std::string& text) override {};  // Do nothing.
};

class Decorator : public Interface {
	private:
	   	std::unique_ptr<Interface> interface;
	public:
	   	Decorator (std::unique_ptr<Interface> c) {interface = std::move(c);}
	   	virtual void write (std::string& text) override {interface->write(text);}
};

class MessengerWithSalutation : public Decorator {
	private:
	   	std::string salutation;
	public:
	   	MessengerWithSalutation (std::unique_ptr<Interface> c, const std::string& str) : Decorator(std::move(c)), salutation(str) {}
	   	~MessengerWithSalutation() {std::cout << "Messenger destructor called.\n";}
	   	virtual void write (std::string& text) override {
		   	text = salutation + "\n\n" + text;
		 	Decorator::write(text);
		}
};

class MessengerWithValediction : public Decorator {
	private:
	   	std::string valediction;
	public:
	   	MessengerWithValediction (std::unique_ptr<Interface> c, const std::string& str) : Decorator(std::move(c)), valediction(str) {}
	   	~MessengerWithValediction() {std::cout << "MessengerWithValediction destructor called.\n";}
	   	virtual void write (std::string& text) override {
		 	Decorator::write(text);
			text += "\n\n" + valediction;
		}
};

int main() {
	const std::string salutation = "Greetings,";
	const std::string valediction = "Sincerly, Andy";
	std::string message1 = "This message is not decorated.";
	std::string message2 = "This message is decorated with a salutation.";
	std::string message3 = "This message is decorated with a valediction.";
	std::string message4 = "This message is decorated with a salutation and a valediction.";

	std::unique_ptr<Interface> messenger1 = std::make_unique<Core>();
	std::unique_ptr<Interface> messenger2 = std::make_unique<MessengerWithSalutation> (std::make_unique<Core>(), salutation);
	std::unique_ptr<Interface> messenger3 = std::make_unique<MessengerWithValediction> (std::make_unique<Core>(), valediction);
	std::unique_ptr<Interface> messenger4 = std::make_unique<MessengerWithValediction> (std::make_unique<MessengerWithSalutation>
  						                  (std::make_unique<Core>(), salutation), valediction);
	
	messenger1->write(message1);
	std::cout << message1 << '\n';
	std::cout << "\n------------------------------\n\n";

	messenger2->write(message2);
	std::cout << message2 << '\n';
	std::cout << "\n------------------------------\n\n";

	messenger3->write(message3);
	std::cout << message3 << '\n';
	std::cout << "\n------------------------------\n\n";

	messenger4->write(message4);
	std::cout << message4 << '\n';
	std::cout << "\n------------------------------\n\n";
}
