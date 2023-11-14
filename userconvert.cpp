#include "userconvert.h"

//Calculations

double calculateHeightCm(double userHeight)
{
	return userHeight * 2.54;
}

double calculateBodyFat(double userbodyFat)
{
	return userbodyFat / 100.00;
}

double calculateWeightKg(double userWeight)
{
	return userWeight / 2.20;
}

double calculateFatMass(double userWeight, double bodyFat)
{
	return userWeight * bodyFat;
}

double calculateLbm(double userWeight, double fatMass)
{
	return userWeight - fatMass;
}
