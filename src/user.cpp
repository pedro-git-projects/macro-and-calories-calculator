#include "user.h"
#include <stdexcept>
#include <string>

User::User(){};

User::User(unsigned int age, float height, float weight, Gender gender, ActivityLevel activityLevel) :
	m_age{age}, m_height{height}, m_weight{weight}, m_gender{gender}, m_activityLevel{activityLevel} {
		m_BMR = calculateBMR();
		m_caloriesNeeded = calculateNeededCalories();
	}


std::ostream& operator << (std::ostream& os, const Gender& g) {
	std::string s{};
	std::string m{"male"};
	std::string f{"female"};
	switch (g) {
		case Gender::Male:
			s =  m;	
			break;
		case Gender::Female:
			s = f;
			break;
	}
	os << s;
	return os;
}

std::ostream& operator << (std::ostream& os, const ActivityLevel& al) {
	std::string s{};
	switch (al) {
		case ActivityLevel::Sedentary:
			s = std::string{"sedentary"};
			break;
		case ActivityLevel::Light:
			s = std::string{"light"};	
			break;
		case ActivityLevel::Moderate:
			s = std::string{"moderate"};
			break;
		case ActivityLevel::Active:
			s = std::string{"active"};
			break;
		case ActivityLevel::VeryActive:
			s = std::string{"very active"};
			break;
	}
	os << s;
	return os;
}

std::string User::genderToString() {
	std::string s {};
	switch (m_gender) {
		case Gender::Male:
			s =  "male";	
			break;
		case Gender::Female:
			s = "female";
			break;
	}
	return s;
}

std::string User::activityToString() {
	std::string s{};
	switch (m_activityLevel) {
		case ActivityLevel::Sedentary:
			s = std::string{"sedentary"};
			break;
		case ActivityLevel::Light:
			s = std::string{"light"};	
			break;
		case ActivityLevel::Moderate:
			s = std::string{"moderate"};
			break;
		case ActivityLevel::Active:
			s = std::string{"active"};
			break;
		case ActivityLevel::VeryActive:
			s = std::string{"very active"};
			break;
	}
	return s;
}


unsigned int User::age() const {
	return m_age;
}

float User::height() const {
	return m_height;
}

Gender User::gender() const {
	return m_gender;
}

ActivityLevel User::activityLevel() const {
	return m_activityLevel;
}

float User::calculateBMR() const {
	if(m_gender == Gender::Male) return 66.5 + (13.75 * m_weight) + (5.003 * m_height) - (6.75 * m_age);
	if(m_gender == Gender::Female) return 655.1 + (9.563 *  m_weight) + (1.850 * m_height) - (4.676 * m_age);
	throw std::runtime_error("Invalid gender");
}

float User::calculateNeededCalories() {
	switch (m_activityLevel) {
		case ActivityLevel::Sedentary:
			return m_BMR * 1.2;
			break;
		case ActivityLevel::Light:
			return m_BMR * 1.375;
			break;
		case ActivityLevel::Moderate:
			return m_BMR * 1.55;
			break;
		case ActivityLevel::Active:
			return m_BMR * 1.725;
			break;
		case ActivityLevel::VeryActive:
			return m_BMR * 1.9;
			break;
		default:
			throw std::runtime_error("Invalid activity level");
	}
}
