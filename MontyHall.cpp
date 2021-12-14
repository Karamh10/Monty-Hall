#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
const int simulationCOUNT = 100;	//How many times the simulator will run the program

//print the menu for the user to pick what they want to do
int print_menu () {
	int choice;
	cout << "\t ************" << endl;
	cout << "Welcome to the Monty Hall Problem Simulator." << endl;
	cout << "Please choose from the menu below: " << endl;
	cout << "1- How to play." << endl;
	cout << "2- Try it out." << endl;
	cout << "3- Run the simulation." << endl;
	cout << "4- Explanation of this probability puzzle." << endl;
	cout << "5- Exit program." << endl;
	cin >> choice;
	return choice;
}

//print the doors to add some more visuals for the user
void print_doors () {

	cout << " --------" << "    " << " --------" << "    " << " --------" << endl;
	cout << "|       |" << "    " << "|       |" << "    " << "|       |" << endl;
	cout << "|       |" << "    " << "|       |" << "    " << "|       |" << endl;
	cout << "|   1   |" << "    " << "|   2   |" << "    " << "|   3   |" << endl;
	cout << "|       |" << "    " << "|       |" << "    " << "|       |" << endl;
	cout << "|       |" << "    " << "|       |" << "    " << "|       |" << endl;
	cout << " --------" << "    " << " --------" << "    " << " --------" << endl;
	cout << "One of these doors have a car behind them, the other two have goats." << endl;

}

//print the rules and explanation of how to play
void how_to_play () {
	/* print how to play*/
	cout << "\t ************" << endl;
	cout << "This is the Monty Hall Simulator:" << endl;
	cout << "- Once you run the program you will be prompted to select a number from the menu." << endl;
	cout << "- The two main functionalities are: run the simulation, or play the game." << endl;
	cout << "- To play the game, you will be prompted to pick one out of 3 doors; " << endl;
	cout << "two of which have goats behind them and the last one has a car." << endl;
	cout << "- Whatever is behind the door you choose is what you will take home." << endl;
	cout << "- Once you pick your initial door, one of the two remaining doors will opend" << endl;
	cout << "presenting you with an additional piece of information; that the opened door has a goat behind it." << endl;
	cout << "- Then you will be presented with an oppurtunity to either switch or stay with your initial pick" << endl;
	cout << "before finally revealing what you will be going home with." << endl;
	cout << "- You might not notice it at first, but there indeed is a better choice that will be better seen when" << endl;
	cout << "choosing to Run the Simulation which will randomly make all the decisions" << endl;
	cout << "and run the program for a total of " << simulationCOUNT << " times." << endl;
	cout << "\t ************" << endl;

}

//This function is called when the user is playing the game
//it is used to get the first initial pick of the user
int player_choice () {
	int playerChoice;
	cout << "pick a door where you think the car is" << endl;
	cout << "enter 1, 2, or 3 to pick a corresponding door: " << endl;
	cin >> playerChoice;	//get user input
	return playerChoice;
}

//this is used when the user is playing the game
//it is used to ask the user if they would like to switch doors or stay with thier initial pick
//it is also used to present to the user one of the doors that have a goat behind it.
int player_sOs (int openDoor, int *firstPick, int thirdDoor) {

	int switch_or_stay;
	cout << "\t ************" << endl;
	cout << "Door #" << openDoor << " has a goat behind it" << endl;
	cout << "Knowing that additional piece of information, would you like to stay" << endl;
	cout << "with door #" << *firstPick << " or would you switch to door #" << thirdDoor << endl;
	cout << "\t ***********" << endl;
	cout << "Enter 1 to stay or 2 to switch" << endl;
	cin >> switch_or_stay;

	while (true) {
		if (switch_or_stay != 1 && switch_or_stay != 2) {  	//Account for input error
			cout << endl;
			cout << "Invalid Input!" << endl;
			cout << "Knowing that additional piece of information, would you like to stay" << endl;
			cout << "with door #" << *firstPick << " or would you switch to door #" << thirdDoor << endl;
			cout << "\t ***********" << endl;
			cout << "Enter 1 to stay or 2 to switch" << endl;
		} else if (switch_or_stay == 2) { 		//if the user wants to switch. switch their initial pick
			*firstPick = thirdDoor;
			break;
		} else if (switch_or_stay == 1) {		//break if the user does not want to switch
			break;
		}
	}
	return switch_or_stay;

}

//This function is used when the simulation is running
//It is used to randomly pick whether the player wants to switch or stay
int rand_sOs (int *firstPick, int thirdDoor) {
	int switch_or_stay = rand () % 2 + 1;
	if (switch_or_stay == 2) {
		*firstPick = thirdDoor;
	}
	return switch_or_stay;
}

//This function is used when the simulation is running
//It is used to randomly pick the initial choice of the player during the simulation
int rand_choice () {
	int random_choice = rand() % 3 + 1;
	return random_choice;
}  

//Randomly pick what door to open
//This function makes sure that the door that is about to be opened
//is not the same door that has a car behind it or the door that was first picked
int get_open_door (int carDoor, int firstPick) {
	int openDoor = rand() % 3 + 1;
	while (openDoor == carDoor || openDoor == firstPick) {
		openDoor = rand() % 3 + 1;
	}
	return openDoor;
}

//This function returns the third door
//the third door meaning not the door that was picked first
//nor the door that was opened
int get_third_door (int openDoor, int firstPick) {
	int thirdDoor = rand() % 3 + 1;
	while (thirdDoor == openDoor || thirdDoor == firstPick) {
		thirdDoor = rand() % 3 + 1;
	}
	return thirdDoor;
}

//Print the header to the table that presents the simulation
//iteration results
void print_header() {
	cout << "\t****************" << endl;
	cout << "Car\t" << "initial\t" << "opened\t" << "switch\t" << "\tCar" << endl;
	cout << "door \t" << "pick \t" << "door \t" << "or stay \t" << "won?" << endl;
	cout << "---------------------------------------------" << endl;
}

//This function takes in an array that has the results of the simulation/game
//it also takes in a boolean that indicates whether we are printing simulation results
//or the game results. And lastly, it takes in two intgeres to keep track of the 
//win count when switching vs staying with the intitial option.
void game_results(int arr[], bool simulation, int &stay_win, int &switch_win) {

	int openDoor = arr[0];
	int firstPick = arr[1];
	int thirdDoor = arr[2];
	int carDoor = arr[3];
	int switch_or_stay = arr[4];

	if (!simulation) { //if it's not a simulation, then print out the results for the game
		cout << "\t ***********" << endl;
		if (firstPick == carDoor && switch_or_stay == 1) {  	//if the door that the user ended with is the one with the car and the user did not switch
			cout << "Congrats! Even though the odds are stacked against you, you stayed with your initial choice and won the car!" << endl;
		} else if (firstPick == carDoor && switch_or_stay == 2) { //if the door that the user ended with is the one with the car and the user did switch
			cout << "Congrats! You made the better choice by switching and won the car!" << endl;
		} else if (firstPick != carDoor && switch_or_stay == 1) { //if the door that the user ended with is not the one with the car and the user did not switch
			cout << "You should have switched as the odds are stacked against you when you stay with your initial choice. You won a goat!" << endl;
		} else if (firstPick != carDoor && switch_or_stay == 2 ) { //if the door that the user ended with is not the one with the car and the user did switch
			cout << "You made the better choice by switching doors as the odds are in your favor, but unfortunately it is a probability game" << endl;
			cout << "and sadly, you ended up with a goat." << endl;
		}
	} else if (simulation) {	//if it is a simulation, then print out the results for the simulation
		if (firstPick == carDoor && switch_or_stay == 2) {
			switch_win = switch_win + 1;
			cout << carDoor << "\t" << firstPick << "\t" << openDoor << "\t" << switch_or_stay << "\t" << "\tYES" << endl;
		} else if (firstPick != carDoor && switch_or_stay == 1) {
			switch_win = switch_win + 1;
			cout << carDoor << "\t" << firstPick << "\t" << openDoor << "\t" << switch_or_stay << "\t" << "\tNO" << endl;
		} else if (firstPick == carDoor && switch_or_stay == 1) {
			stay_win = stay_win + 1;
			cout << carDoor << "\t" << firstPick << "\t" << openDoor << "\t" << switch_or_stay << "\t" << "\tYES" << endl;
		} else if (firstPick != carDoor && switch_or_stay == 2) {
			stay_win = stay_win + 1;
			cout << carDoor << "\t" << firstPick << "\t" << openDoor << "\t" << switch_or_stay << "\t" << "\tNO" << endl;
		}
	}
}

//this function prints out the statistical results of the simulation
void simulation_ratio (int stayW, int switchW) {
	cout << "After running the simulation a total of " << simulationCOUNT << " , the results are:" << endl;
	cout << "- Total wins from switching when asked: " << switchW << endl;
	cout << "- Total wins from staying with the original pick when asked: " << stayW << endl;
	cout << "\t ***********" << endl;
	int switch_percentage = ((double)switchW / simulationCOUNT) * 100;
	int stay_percentage = ((double)stayW / simulationCOUNT) * 100; 
	cout << "- Winning percentage due to switching: " << switch_percentage << "%" << endl;
	cout << "- Winning percentage due to staying: " << stay_percentage << "%" << endl;
	cout << "\t ***********" << endl;
	cout << "- Switching over Staying ratio: " << static_cast<double>(switchW)/stayW << endl;
}

//This function gets called when the user chooses to either run the simulation
//or to play the game. It takes in a boolean argument that indicates whether
//the user is running a simulation(true) or just playing the game(false).
//It also takes in two parameters to keep the win count when switching or when staying.
void execute (bool simulation, int &stayW, int &switchW) {

	int first_pick;	
	int car_door = rand() % 3 + 1;		//randomizely select where the car is placed
	int open_door; 
	int third_door;
	int sOs;  /*switch or stay */

	if (!simulation) {			//if the user is playing the game and not running a simulation
		print_doors();
		first_pick = player_choice();		//ask the user to pick a door for their first pick
	} else if (simulation) {				//if the user is running a simulation	
		first_pick = rand_choice();			//randomly select the first pick
	}
	
	open_door = get_open_door(car_door, first_pick);		//get the door that is going to reveal the goat behind it
	third_door = get_third_door(open_door, first_pick);		//get the third door that is left
	
	int results[] = {open_door, first_pick, third_door, car_door, sOs};
	if (!simulation) {			//if the user is not running a simulation
		sOs = player_sOs(open_door, &first_pick, third_door);	//ask the user whether they want to switch or stay with their initial pick
		results[4] = sOs;
		results[1] = first_pick;
		game_results(results, false, stayW, switchW);			//print out the results of the game
	} else if (simulation) {							//if the user is running a simulation
		sOs = rand_sOs(&first_pick, third_door);		//randomly select whether the program is switching or sticking with the intial pick or 
		results[4] = sOs;
		results[1] = first_pick;
		game_results(results, true, stayW, switchW);	//print out the results of the simulation
	}
}	

//This function prints the explanation to the results
void print_explanation () {
	/*print explanation*/
	cout << "\t ***********" << endl;
	cout << "This is a beautiful statistics problem as the results are shocking pretty shocking:" << endl;
	cout << "- When we run the simulation, we will notice that the car winning percentage" << endl;
	cout << "when switching door is higher than staying with the initial pick as many people tend to do." << endl;
	cout << "- When making the initial pick, we have a 33% chance of choosing the door with the car." << endl;
	cout << "- Once one of the doors opens up revealing a goat behind it, things change." << endl;
	cout << "- Say we initially picked door #1. There is a 33% chance of that door being the right door." << endl;
	cout << "- That means that there is a 66% chance of the car being behind the other two doors, #2 and #3." << endl;
	cout << "- Once one of these doors, say door #3, opens up revealing that there is a goat behind it," << endl;
	cout << "the odds change. Most people think that there is a 50/50 chance when given the chance to stick with" << endl;
	cout << "door #1 or switching to door #2." << endl;
	cout << "- Door #1 still has a 33% chance of being the correct door while door #2 now has a shocking 66% chance." << endl;
	cout << "- This is due a concept called Concetrated Probability." << endl;
	cout << "- Since the car had a 66% chance of being behind both doors #2 and #3" << endl;
	cout << "but door #3 was revealed to have a goat behind it, then the probability gets " << endl;
	cout << "concetrated on door #2 " << endl;
	cout << "- Therefore, switching when given the chance to has a 66% chance of being the better option." << endl;
	cout << "- That can of course be seen when we run the simulation." << endl;

}
int main() {

	srand(time(NULL));
	bool is_simulation; 	//whether the user is running a simulation or not
	int menu_choice;		//what the user chooses to do from the menu
	int switchWin;			//the win count when we switch doors
	int stayWin;			//the win count when we stay at our initial choice

	while (true) {
		menu_choice = print_menu();
		switchWin = 0;
		stayWin = 0;
		if (menu_choice == 1) {			//if the user selects 1, print how to play
			how_to_play();
		} else if (menu_choice == 2) {			//if the user selects 2, the user wants to play the game
			is_simulation = false;
			execute(is_simulation, stayWin, switchWin);		//set the is_simulation flag to false and execute
		} else if (menu_choice == 3) {			//if the user selects 3, the user wants to run the simulation
			is_simulation = true;
			cout << "The computer will now run a randomized simulation " << simulationCOUNT << "times." << endl;
			print_header();
			for (int i = 1; i <= simulationCOUNT; i++) {
				execute(is_simulation, stayWin, switchWin);		//set the is_simulation flag to true and execute
			}
			print_header();
			cout << "\t ***********" << endl;
			simulation_ratio(stayWin, switchWin);
		} else if (menu_choice == 4) {			//if the user selects 4, print the explanation of the probability
			print_explanation();
		} else if (menu_choice == 5) {			//if the user selects 5, end the program
			break;
		}
	}
}