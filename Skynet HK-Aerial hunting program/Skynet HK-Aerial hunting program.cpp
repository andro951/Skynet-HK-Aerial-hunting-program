//Name: Skynet HK-Aerial hunting program.
//Author: Isaac Richards.
//Date: 13OCT18.

//Header.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using std::cout;
using std::cin;
using std::time;
using std::string;


int main()
{
	bool repeatProgram = false; //By defalut, the repeatProgram loop will not repeat.

	//repeatProgram loop.  Repeats the entire program if desired by the user.
	do
	{
		int gridSizeX; //Represents the width of the grid.
		cout << "Enter the grid size X value: ";
		cin >> gridSizeX;

		int gridSizeY; //Represents the length of the grid.
		cout << "Enter the grid size y value: ";
		cin >> gridSizeY;

		cout << "\n";

		int searchGridLowNumber = 1; //Initial low number.  Used to calculate targetLocation and targetLocationPrediction.
		int searchGridHighNumber = gridSizeX * gridSizeY; //Initial High number.  Used to calculate targetLocation and targetLocationPrediction.
		srand(static_cast<unsigned int>(time(0))); //Create a seed for rand() based on the current time.
		int randomNumber = rand(); //Create a random number with rand().
		int targetLocation = searchGridLowNumber + randomNumber % searchGridHighNumber; //Generates a random enemy location within the grid.

		cout << "Generating random enemy location on " << gridSizeX << "x" << gridSizeY << " grid....\n"
			 << "The enemy is located at location #" << targetLocation << " on " << gridSizeX << "x" << gridSizeY << " grid with " << searchGridLowNumber << "-" << searchGridHighNumber << " sectors.\n"
			 << "Skynet HK-Aerial initializing software.....\n"
			 << "===============================================================\n";

		bool searchingForTarget = true; //Causes the searchingForTarget loop to repeat until the enemy is found.
		int ping = 0; //The number of radar pings.  Resets each time the repeatProgram loop repeats.  Used to count the number of target location predictions requried to find the enemy.
																						   
		//searchingForTarget loop.  Repeats until the enemy is found.
		do
		{
			int targetLocationPrediction = ((searchGridHighNumber + searchGridLowNumber) / 2); //Takes the average of the low and high number to create a target location prediction.
			++ping; //Increment ping each time searchingForTarget loop runs.
			cout << "Skynet HK-Aerial sending out ping #" << ping << ".\n";

			if (targetLocationPrediction > targetLocation) //prediction is too high.
			{
				searchGridHighNumber = targetLocationPrediction - 1; //lower the searchGridHighNumber to just below the prediction which was too high.
				cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << targetLocation << ".\n"
					 << "The new searchGridHighNumber =" << searchGridHighNumber << ".\n"
					 << "---------------------------------------------------------------\n";
			}
			else if (targetLocationPrediction < targetLocation) //prediction is too low.
			{
				searchGridLowNumber = targetLocationPrediction + 1; //raise the searchGridLowNumber to just above the prediction which was too low.
				cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << targetLocation << ".\n"
					 << "The new searchGridLowNumber =" << searchGridLowNumber << ".\n"
					 << "---------------------------------------------------------------\n";
			}
			else //target found.
			{
				cout << "Enemy was hiding at location #" << targetLocation << ".\n"
					 << "target was found at location #" << targetLocationPrediction << ".\n"
					 << "Skynet HK-Aerial Software took " << ping << " predictions to find the enemy location on a grid size of " << gridSizeX << "x" << gridSizeY << "(" << gridSizeX * gridSizeY << ").\n";
				searchingForTarget = false; //The target was found, so end the searchingForTarget loop.
			}
		} while (searchingForTarget);

		bool waitingForValidInput = true; //Used to determine if the waitingForValidInput loop needs to repeat.

			//waitingForValidInput loop.
			do
			{
				cout << "Would you like to run another simulation? (type yes or no)\n";
				string userAnswer; //Stores the user's answer to the above question.
				cin >> userAnswer;

				if (userAnswer == "yes" || userAnswer == "Yes" || userAnswer == "YES") //If yes is entered, repeat the repeatProgram loop.
				{
					repeatProgram = true;
					waitingForValidInput = false; //Valid input was recieved.  End the waitingForValidInput loop.
					cout << "===============================================================\n";
				}
				else if (userAnswer == "no" || userAnswer == "No" || userAnswer == "NO") //If no is entered, end the repeatProgram loop and exit the program.
				{
					repeatProgram = false;
					waitingForValidInput = false; //Valid input was recieved.  End the waitingForValidInput loop.
				}
				else //If anything other than yes or no is entered, repeat the waitingForValidInput loop.
				{
					cout << "\nInvalid input.\n\n";
				}
			} while (waitingForValidInput);
	} while (repeatProgram);
}
 