#include "macros.h"

Macro::Macro(){};

Macro::Macro(Macros type) : m_type{type}
{
    if(type == Macros::Carbohydrate) {
        m_caloriesPerGram = m_carbohydrateCalories;
        m_name = QString{"Carbohydrate"};
    }
    if(type == Macros::Protein) {
        m_caloriesPerGram = m_proteinCalories;
        m_name = QString{"Protein"};
    }
    if(type == Macros::Fat) {
        m_caloriesPerGram = m_fatCalories;
        m_name = QString{"Fat"};
    }

}

unsigned int Macro::caloriesPerGram() const
{
    return m_caloriesPerGram;
}

QString Macro::name() const
{
    return m_name;
}
