/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include "Cheese.h"

namespace sdds {

	class CheeseParty {

		//cheeses
		const Cheese** m_cheeses;
		//I need how many cheeses so i can loop
		size_t m_numberOfCheeses;

	public:
		//constructor
		CheeseParty();
		//destructor
		~CheeseParty();

		//copy contructor
		CheeseParty(const CheeseParty& other);
		//copy assignment
		CheeseParty& operator=(const CheeseParty& other);
		//move constructor
		CheeseParty(CheeseParty&& other);
		//move assignment
		CheeseParty& operator=(CheeseParty&& other);

		//a modifier that adds a cheese object to the array of pointers.
		CheeseParty& addCheese(const Cheese& cheese);
		//we need to be able to remove a cheese
		void removeCheese();

		//friend so can access private members
		friend std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty);
	};
}

#endif // !SDDS_CHEESEPARTY_H

