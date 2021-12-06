#include "decorator2.hpp"

int main() {

	const string salutation = "Greetings,";
	const string valediction = "Sincerly, Andy";

	string message1 = "This message is not decorated.";
	string message2 = "This message is decorated with a salutation.";
	string message3 = "This message is decorated with a valediction.";
	string message4 = "This message is decorated with a salutation and a valediction.";
	string message5 = "This message is decorated with a salutation and a valediction.";

	unique_ptr<Interface> messenger1 = make_unique<Core>();

	unique_ptr<Interface> messenger2 = make_unique<MessengerWithSalutation> (make_unique<Core>(), salutation);

	unique_ptr<Interface> messenger3 = make_unique<MessengerWithValediction> (make_unique<Core>(), valediction);

	unique_ptr<Interface> messenger4 = 
        make_unique<MessengerWithValediction>( 
                make_unique<MessengerWithSalutation>( make_unique<Core>(), salutation ), 
                valediction );

	unique_ptr<Interface> messenger5 = 
        make_unique<MessengerWithSalutation>( 
                make_unique<MessengerWithValediction>( make_unique<Core>(), valediction ), 
                salutation );
	
	cout << "\n------------start-------------\n\n";
	messenger1->write(message1);
	cout << "message1\n" << message1 << '\n';
	cout << "\n------------------------------\n\n";

	cout << "\n------------start-------------\n\n";
	messenger2->write(message2);
	cout << "message2\n" << message2 << '\n';
	cout << "\n------------------------------\n\n";

	cout << "\n------------start-------------\n\n";
	messenger3->write(message3);
	cout << "message3\n" << message3 << '\n';
	cout << "\n------------------------------\n\n";

	cout << "\n------------start-------------\n\n";
	messenger4->write(message4);
	cout << "message4\n" << message4 << '\n';
	cout << "\n------------------------------\n\n";

	cout << "\n------------start-------------\n\n";
	messenger5->write(message5);
	cout << "message5\n" << message5 << '\n';
	cout << "\n------------------------------\n\n";

    return 0;
}
