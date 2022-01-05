# Welcome to the Monty Hall Simulator.
-------------------------------------------------

## What is Monty Hall:
- The Monty Hall Problem is a mind boggling puzzle that seems very simple when first played,
but presents a shocking reaction whenever the probability of its possible outcomes is presented.

- The problem stems from an American TV show called Let's Make a Deal.
- It was named after the show's original host, Monty Hall.
- At the end of the show, Monty presents the player with 3 doors. Two of which have a goat behind them, 
- while the last door has a car. Whatever is behind the door that the player ends up choosing is what they will get to take home.
- The player's task is to obviously pick the door that has the car behind it. Monty, of course, knows which door has a car behind it.
```
---------    ---------    ---------
|       |    |       |    |       |
|       |    |       |    |       |
|   1   |    |   2   |    |   3   |
|       |    |       |    |       |
|       |    |       |    |       |
---------    ---------    ---------
```
- The game starts with the player picking one of the 3 doors.
- Since we have 3 doors, the player has a 33% chance of picking the right door.
- After Picking the first door, Monty opens one of the other two doors revealing that there is a goat behind it.
- Then he gives the player an option to either stay with their original choice or switch to the remaining third door.
- The player at this point will think that there are two closed doors, therefore a 50/50 chance of winning.
- They usually refuse to give up their original choice as they think Monty is playing some sort of a trick on them,
and that it doesn't matter which one of the two doors they end up choosing.

- SPOILER ALERT: When presented with the option whether to switch or stay, one of the options is indeed WAY better that the other.

- This C++ program, allows you to participate in that game while the program itself will act as Monty Hall.

### To run the program:
- clone the repo.
- run ```gcc MontyHall.cpp```
- Once you run the program you will be presented with a menu:
1- How to play.
2- Try it out.
3- Run the simulation.
4- Explanation of this probability puzzle.
5- Exit program.

- To choose one of the options, enter the number corresponding to it. i.e. enter 3 to run the simulation.

#2 on the menu will allow you to try out the game as the player.
#3 will run a randomized simulation that acts as you (the player)
and will randomly make all the decisions that the player needs to make while keeping
track of the wins that result from switching/staying with the original choice.
The simulation is set to run 100 times, but feel free to set
``` const int simulationCOUNT = 100; ```
to a higher number in the program in order to get a bigger sample size.

Play the game to find out whether switching or staying with your original option is better :).
Or run the simulation :).
Or both :).
