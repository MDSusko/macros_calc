//Header file to take user data and convert data

#ifndef USER_CONVERT_H
#define USER_CONVERT_H

#include <cmath>

// Declare functions for calculations
double calculateHeightCm(double userHeight);
double calculateBodyFat(double userbodyFat);
double calculateWeightKg(double userWeight);
double calculateFatMass(double userWeight, double bodyFat);
double calculateLbm(double userWeight, double fatMass);

#endif


