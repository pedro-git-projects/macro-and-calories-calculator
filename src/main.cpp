#include <iostream>
#include <ostream>
#include "macros.h"
#include "user.h"

int main() {
	Macro carb{Macros::Carbohydrate};
	std::cout << carb.caloriesPerGram() << std::endl 
		<< carb.name() << std::endl;

	Macro fat{Macros::Fat};
	Macro protein{Macros::Protein};

	User pedro {23, 183.00, 90.00, Gender::Male, ActivityLevel::Moderate};
	std::cout << pedro.activityToString() << std::endl
		<< pedro.genderToString() << std::endl
		<< pedro.calculateBMR() << std::endl
		<< pedro.calculateNeededCalories();
}
