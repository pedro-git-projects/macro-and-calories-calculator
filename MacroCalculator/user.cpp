#include "user.h"

#include<stdexcept>

User::User(){};

User::User(unsigned int age, float height, float weight, Gender gender, ActivityLevel activityLevel) :
    m_age{age}, m_height{height}, m_weight{weight}, m_gender{gender}, m_activityLevel{activityLevel}
{
    m_BMR = calculateBMR();
    m_caloriesNeeded = calculateNeededCalories();
}

QString User::genderToString()
{
    QString s{};
    switch (m_gender) {
    case Gender::Male:
        s =  QString{"male"};
        break;
    case Gender::Female:
        s = QString{"female"};
        break;
    }
    return s;
}

QString User::activityToString()
{
    QString s{};
    switch (m_activityLevel) {
    case ActivityLevel::Sedentary:
        s = QString{"sedentary"};
        break;
    case ActivityLevel::Light:
        s = QString{"light"};
        break;
    case ActivityLevel::Moderate:
        s = QString{"moderate"};
        break;
    case ActivityLevel::Active:
        s = QString{"active"};
        break;
    case ActivityLevel::VeryActive:
        s = QString{"very active"};
        break;
    }
    return s;
}


unsigned int User::age() const
{
    return m_age;
}

float User::height() const
{
    return m_height;
}

Gender User::gender() const
{
    return m_gender;
}

ActivityLevel User::activityLevel() const
{
    return m_activityLevel;
}

float User::calculateBMR() const
{
    if(m_gender == Gender::Male) return 66.5 + (13.75 * m_weight) + (5.003 * m_height) - (6.75 * m_age);
    if(m_gender == Gender::Female) return 655.1 + (9.563 *  m_weight) + (1.850 * m_height) - (4.676 * m_age);
    throw std::runtime_error("Invalid gender");
}

float User::calculateNeededCalories()
{
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
