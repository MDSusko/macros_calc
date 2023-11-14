/*Program to take client information such as age, height, weight and other fitness / health biometrics to calculate macronutrient and caloric intake,
Written and tested by Markus Susko. Copyright 2023. plurfxla@gmail.com*/

//Main program file


#include "userconvert.h"
#include "activitymodify.h"
#include "nutrition.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

//Define variables 
char userGender;
char userData;
int userAge;
double userWeight;
double userHeight;
double userbodyFat;
int useractLevel;
int userfitGoal;
double actModify;
int totalMeals;
double proPercent, carbPercent, fatPercent;
bool userInput = true;




int main(){

	while (userInput = true) {

		//Get user gender
		std::cout << "Input user gender, for male put 'M', for female put 'F'";
		std::cin >> userGender;

		//Error check user input for userGender and end program
		if ((userGender != 'M' && userGender != 'm') && (userGender != 'F' && userGender != 'f') || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "Input user gender, for male put 'M', for female put 'F'";
			std::cin >> userGender;
			if ((userGender != 'M' && userGender != 'm') && (userGender != 'F' && userGender != 'f') || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Get user age
		std::cout << "User age: ";
		std::cin >> userAge;
		
		//Error check user input for userAge and end program
		if ((userAge <= 0 || userAge >= 99) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "User age: ";
			std::cin >> userAge;
			if ((userAge <= 0 || userAge >= 99) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}
		
		//Get user weight in lbs
		std::cout << "User weight (in lbs.): ";
		std::cin >> userWeight;
		
		//Error check user input for userWeight and end program
		if ((userWeight <= 0) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "User weight (in lbs.): ";
			std::cin >> userWeight;
			if ((userWeight <= 0) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Get user height in inches
		std::cout << "User height (in inches): ";
		std::cin >> userHeight;

		//Error check user input for userHeight and end program
		if ((userHeight <= 0) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "User height (in inches): ";
			std::cin >> userHeight;
			if ((userHeight <= 0) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Get user body fat
		std::cout << "User body fat % (Enter as ##.##): ";
		std::cin >> userbodyFat;

		//Error check user input for userbodyFat and end program
		if ((userbodyFat <= 0) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "User body fat % (Enter as ##.##): ";
			if ((userbodyFat <= 0) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Stop loop for getting user data
		std::cout << std::endl;
		std::cout << "Has all data been entered correctly? (Y/N): ";
		std::cout << std::endl;
		std::cin >> userData;

		//Error check user input for userData and end program
		if ((userData == 'Y') || (userData == 'y')) {
			userInput = false;
			std::cout << std::endl;
			std::cout << "All data for user has been entered and saved." << std::endl;
			break;
		}
		else {
			userInput = true; //Reloop to re-enter data
		}

	}

	//Call Functions for calculations
	double heightCm = calculateHeightCm(userHeight);
	double bodyFat = calculateBodyFat(userbodyFat);
	double weightKg = calculateWeightKg(userWeight);
	double fatMass = calculateFatMass(userWeight, bodyFat);
	double lbm = calculateLbm(userWeight, fatMass);

	//Set decimal data and reset userInput to true
	std::cout << std::fixed << std::setprecision(2);
	userInput = true;

	while (userInput = true) {

		//Get activity modifier user data
		std::cout << "User activity level, for Sedentary enter 1, for mild activity enter 2, for moderate activity enter 3,";
		std::cout << "for heavy activity enter 4, for very heavy-extreme activity enter 5.: ";
		std::cin >> useractLevel;

		//Error check and exit code 
		if ((useractLevel <= 0 || useractLevel >= 6) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "User activity level, for Sedentary enter 1, for mild activity enter 2, for moderate activity enter 3,";
			std::cout << "for heavy activity enter 4, for very heavy-extreme activity enter 5.: ";
			std::cin >> useractLevel;
			if ((useractLevel <= 0 || useractLevel >= 6) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		} 
			//Stop loop for getting user data
			std::cout << std::endl;
			std::cout << "Has all data been entered correctly? (Y/N): ";
			std::cout << std::endl;
			std::cin >> userData;

			//Error check user input for userData and end program
			if ((userData == 'Y') || (userData == 'y')) {
				userInput = false;
				std::cout << std::endl;
				std::cout << "All data for user has been entered and saved." << std::endl;
				break;
			}
			else {
				userInput = true; //Reloop to re-enter data
			}
		
	}

	//Call Functions for calculations
	double actModify = calculateActModify(useractLevel);
	double rmr = calculateRmr(weightKg, heightCm, userAge, userGender);
	double calcBmr = calculateBmr(rmr, actModify);

	//Output RMR/BMR Data to Screen 
	std::cout << std::endl;
	std::cout << "Users RMR is: " << rmr << " kcals/day." << std::endl;
	std::cout << "Users BMR is: " << calcBmr << " kcals/day." << std::endl;
	std::cout << "Users Lean Body Mass (LBM) in pounds is: " << lbm << std::endl;
	std::cout << "Users Fat Mass (FM) in pounds is: " << fatMass << std::endl;
	std::cout << std::endl;

	//Reset User Input to true and get fitness goal data
	userInput = true;

	while (userInput = true) {

		//Get user goal data
		std::cout << "Enter fitness goal. For maintence enter 1, for cut/fat loss enter 2, for bulk/LBM gain enter 3: ";
		std::cin >> userfitGoal;

		//Error check
		if ((userfitGoal <= 0 || userfitGoal > 3) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "Enter fitness goal. For maintence enter 1, for cut/fat loss enter 2, for bulk/LBM gain enter 3: ";
			std::cin >> userfitGoal;
			if ((userfitGoal <= 0 || userfitGoal > 3) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Get user meals per day 
		std::cout << "Enter meals per day: ";
		std::cin >> totalMeals;

		//Error check meals/day
		if ((totalMeals <= 0 || totalMeals >= 9) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "Enter meals per day: ";
			std::cin >> totalMeals;
			if ((totalMeals <= 0 || totalMeals >= 9) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Get percentage of macro data from user 
		std::cout << "Enter percentage of current macros for protein: ";
		std::cin >> proPercent;
		std::cout << "Enter percentage of current macros for carbs: ";
		std::cin >> carbPercent;
		std::cout << "Enter percentage of current macros for fats: ";
		std::cin >> fatPercent;

		//Error Check 
		if ((proPercent <= 0 || carbPercent <= 0 || fatPercent <= 0) || (proPercent >= 100 || carbPercent >= 100 || fatPercent >= 100) || (!std::cin)) {
			userInput = false;
			std::cout << "Invalid input...Try again" << std::endl;
			std::cin.clear(); //Reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
			std::cout << "Enter percentage of current macros for protein: ";
			std::cin >> proPercent;
			std::cout << "Enter percentage of current macros for carbs: ";
			std::cin >> carbPercent;
			std::cout << "Enter percentage of current macros for fats: ";
			std::cin >> fatPercent;
			if ((proPercent <= 0 || carbPercent <= 0 || fatPercent <= 0) || (proPercent >= 100 || carbPercent >= 100 || fatPercent >= 100) || (!std::cin)) {
				userInput = false;
				std::cout << "Invalid input...Exiting program" << std::endl;
				break;
			}
		}

		//Stop loop for getting user data
		std::cout << std::endl;
		std::cout << "Has all data been entered correctly? (Y/N): ";
		std::cout << std::endl;
		std::cin >> userData;

		//Error check user input for userData and end program
		if ((userData == 'Y') || (userData == 'y')) {
			userInput = false;
			std::cout << std::endl;
			std::cout << "All data for user has been entered." << std::endl;
			break;
		}
		else {
			userInput = true; //Reloop to re-enter data
		}
	}

	//Call Macro function
	calculateMacros(calcBmr, userfitGoal, proPercent, carbPercent, fatPercent, totalMeals);

	return 0;
}