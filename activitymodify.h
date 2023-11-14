//Activity modifer code 

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <cmath>

// Declare functions for calculations
double calculateActModify(int useractLevel);
double calculateRmr(double weightKg, double heightCm, int userAge, char userGender);
double calculateBmr(double rmr, double actModify);

#endif
