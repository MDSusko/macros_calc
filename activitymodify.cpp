//Activity source file for calculations 

#include "activitymodify.h"

double calculateActModify(int useractLevel) {
    switch (useractLevel) {
    case 1:
        return 1.2;
    case 2:
        return 1.375;
    case 3:
        return 1.55;
    case 4:
        return 1.7;
    case 5:
        return 1.9;
    }
}


double calculateRmr(double weightKg, double heightCm, int userAge, char userGender) {
	switch (userGender) {
	case 'M':
	case 'm':
		return 9.99 * weightKg + 6.25 * heightCm - 4.92 * userAge + 5;
	case 'F':
	case 'f':
		return 9.99 * weightKg + 6.25 * heightCm - 4.92 * userAge - 161;
	}
}

double calculateBmr(double rmr, double actModify) {
	return rmr * actModify;
}