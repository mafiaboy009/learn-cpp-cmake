#include "mediator.hpp"

int main() {
	Colleague *bob = new Colleague ("Bob"), 
              *sam = new Colleague ("Sam"),  
              *frank = new Colleague ("Frank"),
              *tom = new Colleague ("Tom");

	Colleague* staff[] = {bob, sam, frank, tom};

	Mediator mediatorStaff, mediatorSamsBuddies;

	for (Colleague* x : staff){
		mediatorStaff.registerColleague(x);
    }

	bob->sendMessage (mediatorStaff, "I'm quitting this job!");

    // Sam's buddies only
	mediatorSamsBuddies.registerColleague (frank);
    mediatorSamsBuddies.registerColleague (tom);  

	sam->sendMessage (mediatorSamsBuddies, "Hooray!  He's gone!  Let's go for a drink, guys!");	

	return 0;
}
