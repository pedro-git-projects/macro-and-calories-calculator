#ifndef MACROS
#define MACROS

#include <string>

enum class Macros {
	Carbohydrate,
	Fat,
	Protein
};

struct Macro {
	Macro();
	Macro(Macros type);
	~Macro();

	unsigned int caloriesPerGram() const;		
	std::string name() const;

	private:
		const unsigned int m_carbohydrateCalories = 4;
		const unsigned int m_proteinCalories = 4;
		const unsigned int m_fatCalories = 9;
		std::string m_name;
		unsigned int m_caloriesPerGram;
		Macros m_type;
	};

#endif
