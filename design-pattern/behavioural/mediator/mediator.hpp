#pragma once

#include <iostream>
#include <string>
#include <list>

class MediatorInterface;

class ColleagueInterface {
		std::string name;
	public:
		ColleagueInterface (const std::string& newName) : name (newName) {}
		std::string getName() const {return name;}
		virtual void sendMessage (const MediatorInterface&, const std::string&) const = 0;
		virtual void receiveMessage (const ColleagueInterface*, const std::string&) const = 0;
};

class Colleague : public ColleagueInterface {
	public:
		using ColleagueInterface::ColleagueInterface;
		virtual void sendMessage (const MediatorInterface&, const std::string&) const override;
	private:
		virtual void receiveMessage (const ColleagueInterface*, const std::string&) const override;
};

class MediatorInterface {
    private:
		std::list<ColleagueInterface*> colleagueList;
    public:
    	const std::list<ColleagueInterface*>& getColleagueList() const {return colleagueList;}
		virtual void distributeMessage (const ColleagueInterface*, const std::string&) const = 0;
		virtual void registerColleague (ColleagueInterface* colleague) {colleagueList.emplace_back (colleague);}
};

class Mediator : public MediatorInterface {
    virtual void distributeMessage (const ColleagueInterface*, const std::string&) const override;
};

void Colleague::sendMessage (const MediatorInterface& mediator, const std::string& message) const {
	mediator.distributeMessage (this, message);
}

void Colleague::receiveMessage (const ColleagueInterface* sender, const std::string& message) const {
 	std::cout << getName() << " received the message from " << sender->getName() << ": " << message << std::endl;			
}

void Mediator::distributeMessage (const ColleagueInterface* sender, const std::string& message) const {
	for (const ColleagueInterface* x : getColleagueList())
		if (x != sender)  // Do not send the message back to the sender
			x->receiveMessage (sender, message);
}
