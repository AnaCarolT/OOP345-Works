/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
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
		//the name (a string): the name of the cheese, defaults to NaC - "Not a Cheese"
		std::string m_name;
		//the weight (an integer): the weight/amount in grams of the cheese
		int m_weight;
		//the price (a floating-point number in double precision): the price per gram of the cheese
		double m_price;
		//the features (a string): a description of the features/qualities of the cheese
		std::string m_features;

	public:
		//a default constructo
		Cheese();
		//A constructor that receives the cheese's details as a string
		Cheese(const std::string& str);
		//a modifier that receives as a parameter a weight/amount of cheese to slice from the current cheese object.
		Cheese slice(size_t weight);

		//A set of queries to retrieve the value of each attribute of the cheese.
		//name
		std::string getCheeseName() const;
		//weight
		int getCheeseWeight() const;
		//price
		double getCheesePrice() const;
		//features
		std::string getCheeseFeatures() const;

		//this need to be a friend because I need a way to get access of the cheese descriptions
		friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
	};
}

#endif // !SDDS_CHEESE_H

