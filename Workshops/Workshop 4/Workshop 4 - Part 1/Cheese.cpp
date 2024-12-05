/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Cheese.h"
#include <iomanip>

using namespace std;

namespace sdds {

	Cheese::Cheese() : m_name("NaC")
	{
		m_weight = 0;
		m_price = 0.0;
		m_features = "";
	}

	Cheese::Cheese(const std::string& str)
	{
		size_t beginning = 0;
		size_t stop;
		size_t i;

		//Get the name
		stop = str.find(',');
		m_name = str.substr(beginning, stop);
		m_name = m_name.substr(m_name.find_first_not_of(" "), m_name.find_last_not_of(" ") + 1);

		//Get the weight
		beginning = stop + 1;
		stop = str.find(',', beginning);
		m_weight = stoi(str.substr(beginning, stop - beginning));

		//Get the price
		beginning = stop + 1;
		stop = str.find(',', beginning);
		m_price = stod(str.substr(beginning, stop - beginning));

		//Get features
		beginning = stop + 1;
		m_features = str.substr(beginning);

		//Get rid of the commas in features
		for ( i = 0; i < m_features.size(); ++i)
		{
			if (m_features[i] == ',')
			{
				m_features[i] = ' ';
			}
		}

		//Get rid of extra spaces
		for ( i = 0; i < m_features.size(); i++)
		{
			if (m_features[i] == ' ' && m_features[i + 1] == ' ')
			{
				m_features.erase(i, 1);
				--i;
			}
		}

		//Remove any extra spaces in the string itself
		m_features = m_features.substr(m_features.find_first_not_of(" "), m_features.find_last_not_of(" ") + 1);
	}

	Cheese Cheese::slice(size_t weight)
	{
		Cheese cheeseInParts;
		if (weight <= static_cast<size_t>(m_weight))
		{
			cheeseInParts.m_name = m_name;
			cheeseInParts.m_weight = static_cast<int>(weight);
			cheeseInParts.m_price = m_price;
			cheeseInParts.m_features = m_features;

			m_weight -= static_cast<int>(weight);
		}
		return cheeseInParts;
	}

	std::string Cheese::getCheeseName() const
	{
		return m_name;
	}

	int Cheese::getCheeseWeight() const
	{
		return m_weight;
	}

	double Cheese::getCheesePrice() const
	{
		return m_price;
	}

	std::string Cheese::getCheeseFeatures() const
	{
		return m_features;
	}

	ostream& operator<<(ostream& os, const Cheese& cheese)
	{
		os << "|" << setw(21) << left << cheese.m_name << "|" << setw(5) << cheese.m_weight << "|" << setw(5) << fixed << setprecision(2) << cheese.m_price
			<< "|" << setw(33) << right << cheese.m_features << " " << "|\n";
		return os;
	}
}
