#ifndef USER_H
#define USER_H

#include <ostream>

enum class Gender {
	Male,
	Female
}; 

enum class ActivityLevel {
	Sedentary,
	Light,
	Moderate,
	Active,
	VeryActive
};

struct User {
		User();
		User(unsigned int age, float height, float weight, Gender gender, ActivityLevel activityLevel);
		unsigned int age() const;
		float height() const;
		Gender gender() const;
		ActivityLevel activityLevel() const;
		float calculateBMR() const;
		float calculateNeededCalories();
		float caloriesNeeded() const;
		friend std::ostream& operator << (std::ostream& os, const Gender& g);
		friend std::ostream& operator << (std::ostream& os, const ActivityLevel& al);
		std::string genderToString();	
		std::string activityToString();	
	private:
		unsigned int m_age;
		float m_height; 
		float m_weight;
		float m_BMR;
		float m_caloriesNeeded;
		Gender m_gender;
		ActivityLevel m_activityLevel;
};

#endif
