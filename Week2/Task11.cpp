#include <iostream>
#include <string>
#include <vector>

//an exercise in not using namespace std

struct Stats {

	int fear = 0;
	int stamina = 100;
	std::vector<std::string> inventory;

};

enum House {

	Yard = 1,
	Lobby = 10,
	WestRoom,
	EastRoom,
	NorthRoom,
	SouthRoom,
	Stairs = 100,
	Garden = 11

};

int playStory(int user);
int textAdventure();

int textAdventure() {

	int userInput = 1;
	int sunDown = 10; // 10 hours to sundown
	Stats* player = new Stats;
	std::cout << "--Is this thing on? Yes? Ahem--Hello!"
		<< "\nThis is Max. Boss must've mentioned an additional briefing, right?"
		<< "\nBefore we start, check your phone. Dead, huh? This place's got a special frequency or something, that's why Boss sent you one of our pagers."
		<< "\nAt least you'll have a throwable if something pops out, haha! Uh, not that anything will... Anyway, be careful not to trigger anything while you're looking."
		<< "\nThe previous owners were a little eccentric, so keep an eye out and expect the unexpected. Don't worry, I heard the traps are all trauma and non-lethal."
		<< "\nAnyway, you know, right? You're looking for an old, emerald brooch. Should be somewhere in the West wing."
		<< "Try to find it before sundown and you get too spooked.--" << std::endl;

	std::cout << "\n\nYou, antique hunter, have landed a job at the __ manor. Your task: Retrieve a heart-sized emerald brooch, the family heirloom." << std::endl;
	playStory(userInput);

	return 0;
}

int playStory(int user) {

	switch (user) {
	case 1:
		std::cout << "You are standing on the front porch. To your left is the __ forest. Ahead of you is the __ manor's front door. To your right is __."
			<< "Behind you is the road back.\nThere are currently __ hours until sundown." << std::endl;
		break;
	}
	return 0;
}