#ifndef MACROS_H
#define MACROS_H

#include<QString>

enum class Macros
{
    Carbohydrate,
    Fat,
    Protein
};

struct Macro
{
    Macro();
    Macro(Macros type);
    ~Macro();

    unsigned int caloriesPerGram() const;
    QString name() const;

private:
    const unsigned int m_carbohydrateCalories = 4;
    const unsigned int m_proteinCalories = 4;
    const unsigned int m_fatCalories = 4;
    QString m_name;
    unsigned int m_caloriesPerGram;
    Macros m_type;
};

#endif // MACROS_H
