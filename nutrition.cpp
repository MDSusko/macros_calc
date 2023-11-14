//Source file for macro calculations 

#include <iostream>
#include "nutrition.h"

double convproteinPercent, convcarbPercent, convfatPercent, protein, carb, fat, totalCals, meals;

double calculateMacros(double calcBmr, int userfitGoal, double proPercent, double carbPercent, double fatPercent, int totalMeals)
{
	//Error check macro % == 100
    if (proPercent + carbPercent + fatPercent == 100) {

        //Calc grams of macros + caloric data
        convproteinPercent = proPercent / 100.00;
        protein = (calcBmr * convproteinPercent);
        convcarbPercent = carbPercent / 100.00;
        carb = (calcBmr * convcarbPercent);
        convfatPercent = fatPercent / 100.00;
        fat = (calcBmr * convfatPercent);
    }

    // Output pre-goal ratios
    protein = protein / 4;
    carb = carb / 4;
    fat = fat / 9;


    //Output to screen 
    std::cout << std::endl;
    std::cout << "Based on user inputted ratios, macro intake per day is:" << std::endl;
    std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
    std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
    std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
    std::cout << std::endl;

    switch (userfitGoal) {
    case 1:
    //Calc Ratios
    protein = (calcBmr * .30) / 4;
    carb = (calcBmr * .40) / 4;
    fat = (calcBmr * .30) / 9;

    //Update Variables 
    totalCals = calcBmr;
    meals = totalCals / totalMeals;

    //Output to screen
    std::cout << "For maintence user should consume: " << std::endl;
    std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
    std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
    std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
    std::cout << std::endl;
    std::cout << "As well as keep caloric intake to: " << totalCals << " k/cals a day.";
    std::cout << "You will eat " << totalMeals << "meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
    break;

    case 2:
    //Calc Ratios
    protein = ((calcBmr - 500) * .50) / 4;
    carb = ((calcBmr - 500) * .15) / 4;
    fat = ((calcBmr - 500) * .35) / 9;
    
    //Update Variables 
    totalCals = calcBmr - 500;
    meals = totalCals / totalMeals;
    
    //Output to screen
    std::cout << "For fat loss/cutting user should consume: " << std::endl;
    std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
    std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
    std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
    std::cout << std::endl;
    std::cout << "As well as decrease caloric intake to: " << totalCals << " k/cals a day.";
    std::cout << "You will eat " << totalMeals << "meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
    break;

    case 3:
    //Calc Ratios
    protein = ((calcBmr + 500) * .30) / 4;
    carb = ((calcBmr + 500) * .50) / 4;
    fat = ((calcBmr + 500) * .20) / 9;

        //Update Variables 
        totalCals = calcBmr + 500;
        meals = totalCals / totalMeals;

        //Output to screen
        std::cout << "For bulking/ LBM gain user should consume: " << std::endl;
        std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
        std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
        std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
        std::cout << std::endl;
        std::cout << "As well as increase caloric intake to: " << totalCals << " k/cals a day." << std::endl;
        std::cout << "You will eat " << totalMeals << " meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
    break;
    }
    return 0.0;
}