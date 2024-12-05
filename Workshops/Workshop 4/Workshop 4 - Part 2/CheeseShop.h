/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <string>
#include "Cheese.h"

//can't use using namespace std, it may give future problems

namespace sdds {

	class CheeseShop {

		//the name of the shop
		std::string m_name;
		//a dynamically-allocated array of pointers to dynamically-allocated objects of type
		//It will hold cheese, might as well be cheese
		Cheese** m_cheeses;
		//I need this to be able to add and remove cheese
		//a name that is easy to remember
		//I will need it for loops
		size_t m_numberOfCheeses;

	public:
		CheeseShop(const std::string& name = "No name");
		//Rule of 5
		 //destructor to avoid memory leak
		~CheeseShop();
		//copy constructor
		CheeseShop(const CheeseShop& other);
		//copy assignment
		CheeseShop& operator=(const CheeseShop& other);
		//move constructor
		CheeseShop(CheeseShop&& other);
		//move assignment
		CheeseShop& operator=(CheeseShop&& other);

		//members
		CheeseShop& addCheese(const Cheese& cheese);

		//free helper
		//need it as a friend
		friend std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop);
	};
}

#endif // !SDDS_CHEESESHOP_H

