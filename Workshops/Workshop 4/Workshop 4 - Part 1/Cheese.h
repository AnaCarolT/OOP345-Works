/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>
#include <string>

namespace sdds {

	class Cheese {
		std::string m_name;
		int m_weight;
		double m_price;
		std::string m_features;

	public:
		Cheese();
		Cheese(const std::string& str);
		Cheese slice(size_t weight);

		std::string getCheeseName() const;
		int getCheeseWeight() const;
		double getCheesePrice() const;
		std::string getCheeseFeatures() const;

		friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
	};
}

#endif // !SDDS_CHEESE_H

