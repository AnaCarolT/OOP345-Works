/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "CheeseParty.h"

using namespace std;

namespace sdds {

	CheeseParty::CheeseParty(): m_cheeses(nullptr), m_numberOfCheeses(0)
	{
		//already set everything to a safe state
	}

	CheeseParty::~CheeseParty()
	{
		//get rid if the array of pointers
		delete[] m_cheeses;
	}

	CheeseParty::CheeseParty(const CheeseParty& other) : m_cheeses(nullptr), m_numberOfCheeses(other.m_numberOfCheeses)
	{
		size_t i = 0;
		//if there is cheese
		if (other.m_cheeses)
		{
			//allocate memory for the array of pointers
			m_cheeses = new const Cheese * [m_numberOfCheeses];
			for (i = 0; i < m_numberOfCheeses; ++i)
			{
				//copy each cheese
				m_cheeses[i] = other.m_cheeses[i];
			}
		}
	}

	CheeseParty& CheeseParty::operator=(const CheeseParty& other)
	{
		size_t i = 0;
		//check if they are equal
		if (this != &other)
		{
			//deallocate the memory
			delete[] m_cheeses;

			//make sure the number of cheeses is updated
			m_numberOfCheeses = other.m_numberOfCheeses;

			if (other.m_cheeses) //if there is cheese
			{
				//allocate memory for the array of pointers
				m_cheeses = new const Cheese * [m_numberOfCheeses];
				for (i = 0; i < m_numberOfCheeses; ++i)
				{
					//copy each cheese
					m_cheeses[i] = other.m_cheeses[i];
				}
			}
		}
		//reminder to return
		return *this;
	}

	//warning
	CheeseParty::CheeseParty(CheeseParty&& other) : m_cheeses(other.m_cheeses), m_numberOfCheeses(other.m_numberOfCheeses)
	{
		//move/ownership 
		other.m_cheeses = nullptr; //set for no pointer
		other.m_numberOfCheeses = 0; //safe state
	}

	//warning
	CheeseParty& CheeseParty::operator=(CheeseParty&& other)
	{
		//check if they are equal
		if (this != &other)
		{
			//clean up
			delete[] m_cheeses;

			//transfer other to this
			m_cheeses = other.m_cheeses;
			m_numberOfCheeses = other.m_numberOfCheeses;

			//safe state
			other.m_cheeses = nullptr; //no pointer
			other.m_numberOfCheeses = 0;
		}
		//reminder to return this
		return *this;
	}

	CheeseParty& CheeseParty::addCheese(const Cheese& cheese)
	{
		size_t i = 0;
		//check if that cheese was already added
		for ( i = 0; i < m_numberOfCheeses; ++i)
		{
			//if yes get back
			if (m_cheeses[i] == &cheese)
			{
				//get back
				return *this;
			}
		}

		//if not
		//allocated
		const Cheese** addedCheeses = new const Cheese * [m_numberOfCheeses + 1];
		for ( i = 0; i < m_numberOfCheeses; ++i)
		{
			//copy existing cheese
			addedCheeses[i] = m_cheeses[i];
		}
		//add the new cheese
		addedCheeses[m_numberOfCheeses] = &cheese;
		++m_numberOfCheeses;
		//delete the old array
		delete[] m_cheeses;
		//replace with ne one
		m_cheeses = addedCheeses;
		//reminder to return
		return *this;
	}

	void CheeseParty::removeCheese()
	{
		size_t i = 0;
		size_t tempNumCheeses = 0;
		//create a new array to to hold the update
		const Cheese** addedCheeses = new const Cheese * [m_numberOfCheeses];

		for ( i = 0; i < m_numberOfCheeses; ++i)
		{
			//check if the weight of the cheese is over 0 so it can stay in the array
			if (m_cheeses[i]->getCheeseWeight() > 0)
			{
				//get the new size of the arrayvwhile adding cheese
				addedCheeses[tempNumCheeses] = m_cheeses[i];
				++tempNumCheeses;
			}
		}

		//Delete the old stuff and add the updated one
		delete[] m_cheeses;
		//update
		m_cheeses = addedCheeses;
		//update
		m_numberOfCheeses = tempNumCheeses;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty)
	{
		size_t i = 0;
		//top
		os << "--------------------------\n";
		os << "Cheese Party\n";
		os << "--------------------------\n";
		//middle
		if (cheeseParty.m_numberOfCheeses == 0)
		{
			//output
			os << "This party is just getting started!\n";
		}
		else
		{
			//show the cheese
			for (i = 0; i < cheeseParty.m_numberOfCheeses; ++i)
			{
				os << *(cheeseParty.m_cheeses[i]);
			}
		}
		//bottom
		os << "--------------------------\n";
		return os;
	}
}
