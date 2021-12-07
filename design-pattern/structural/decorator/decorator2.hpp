#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Interface {
	public:
		virtual ~Interface() { }
		virtual void write (string&) = 0;
};

class Core : public Interface {
	public:
	   	~Core() {
            cout << "Core destructor called.\n";
        }

	   	virtual void write (string& text) override {};  // Do nothing.
};

class Decorator : public Interface {
	private:
	   	unique_ptr<Interface> interface;
	public:
	   	Decorator (unique_ptr<Interface> c) {
            interface = move(c);
            cout << "Decorator constructor called.\n";
        }

	   	virtual void write (string& text) override {
            interface->write(text);
        }

        ~Decorator(){ 
            cout << "Decorator destructor called.\n";
        }
};

class MessengerWithSalutation : public Decorator {
	private:
	   	string salutation;
	public:
	   	MessengerWithSalutation (unique_ptr<Interface> c, const string& str) : Decorator(move(c)), salutation(str) {
            cout << "MessengerWithSalutation constructor called.\n";
        }

	   	~MessengerWithSalutation() {
            cout << "MessengerWithSalutation destructor called.\n";
        }

	   	virtual void write (string& text) override {
		   	text = salutation + "\n\n" + text;
		 	Decorator::write(text);
		}
};

class MessengerWithValediction : public Decorator {
	private:
	   	string valediction;
	public:
	   	MessengerWithValediction (unique_ptr<Interface> c, const string& str) : Decorator(move(c)), valediction(str) {
            cout << "MessengerWithValediction constructor called.\n";
        }

	   	~MessengerWithValediction() {
            cout << "MessengerWithValediction destructor called.\n";
        }

	   	virtual void write (string& text) override {
		 	Decorator::write(text);
			text += "\n\n" + valediction;
		}
};
