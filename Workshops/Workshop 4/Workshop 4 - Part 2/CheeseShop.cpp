/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "CheeseShop.h"

using namespace std;

namespace sdds {
	
	CheeseShop::CheeseShop(const string& name) :m_name(name)
	{ //setting everything to a safe state
		m_cheeses = nullptr;
		m_numberOfCheeses = 0;
	}

	CheeseShop::~CheeseShop()
	{
		//making sure the destructor gets everything to avoid memory leak
		size_t i = 0;
		for ( i = 0; i < m_numberOfCheeses; ++i)
		{
			delete m_cheeses[i]; //making the previous cheeses obj are handled
		}
		delete[] m_cheeses; //make sure the array of pointer is deallocated
	}

	//warning
	CheeseShop::CheeseShop(const CheeseShop& other) :m_name(other.m_name), m_numberOfCheeses(other.m_numberOfCheeses)
	{
		//*this = other will not work in this case, may need to adjust cheese
		size_t i = 0;
		//needs to pass the condition to change anything
		if (other.m_cheeses)
		{
			m_cheeses = new Cheese * [m_numberOfCheeses];
			for ( i = 0; i < m_numberOfCheeses; ++i)
			{
				//making sure it's allocted right
				m_cheeses[i] = new Cheese(*other.m_cheeses[i]);
			}
		}
	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& other)
	{
		//check if they are not similar
		if (this != &other)
		{
			size_t i = 0;
			//clean any existing thing in the object
			for ( i = 0; i < m_numberOfCheeses; ++i)
			{
				delete m_cheeses[i];
			}
			delete[] m_cheeses;

			//copy everything from the other object
			m_name = other.m_name;
			m_numberOfCheeses = other.m_numberOfCheeses;

			//if cheese is found, add it to their place
			if (other.m_cheeses)
			{
				m_cheeses = new Cheese * [m_numberOfCheeses];
				for ( i = 0; i < m_numberOfCheeses; ++i)
				{
					//create new object to add the content
					m_cheeses[i] = new Cheese(*other.m_cheeses[i]);
				}
			}
		}
		//Reminder it needs to return
		return *this;
	}

	//warning
	//we will need move contructor for the name
	CheeseShop::CheeseShop(CheeseShop&& other) : m_name(move(other.m_name)), m_cheeses(other.m_cheeses), m_numberOfCheeses(other.m_numberOfCheeses)
	{
		other.m_cheeses = nullptr; // reset pointer
		other.m_numberOfCheeses = 0; //make sure it's not a garbage number
	}

	CheeseShop& CheeseShop::operator=(CheeseShop&& other)
	{
		size_t i = 0;
		if (this != &other) //check if it's not similar
		{
			//delete any exisitng content
			for ( i = 0; i < m_numberOfCheeses; ++i)
			{
				delete m_cheeses[i];
			}
			delete[] m_cheeses;

			//add the proper content
			m_name = move(other.m_name);
			m_cheeses = other.m_cheeses;
			m_numberOfCheeses = other.m_numberOfCheeses;

			//put those in a safe state and make sure tehre is no pointer
			other.m_cheeses = nullptr;
			other.m_numberOfCheeses = 0;
		}
		//reminder it needs to return
		return *this;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& cheese)
	{
		size_t i = 0;
		//We need an array with an extra cheese
		Cheese** addedCheese = new Cheese * [m_numberOfCheeses + 1];
		for ( i = 0; i < m_numberOfCheeses; ++i)
		{
			addedCheese[i] = m_cheeses[i];
		}
		addedCheese[m_numberOfCheeses] = new Cheese(cheese);
		++m_numberOfCheeses;

		//old array need to be get ridden  off
		delete[] m_cheeses;
		//m_cheeses need to get the new cheese
		m_cheeses = addedCheese;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop)
	{
		size_t i = 0;
		//top
		os << "--------------------------\n";
		if (cheeseShop.m_name == "No name")
		{
			//we have no name as default, coulde be just empty that would work
			os << "";
		}
		else
		{
			//if has name
			os << cheeseShop.m_name << "\n";
		}
		//still top
		os << "--------------------------\n";
		if (cheeseShop.m_numberOfCheeses == 0)
		{
			//when there is no cheese, print no cheese
			os << "This shop is out of cheese!\n";
		}
		else
		{
			//loop to get the cheese content
			for ( i = 0; i < cheeseShop.m_numberOfCheeses; ++i)
			{
				os << *(cheeseShop.m_cheeses[i]);
			}
		}
		//bottom
		os << "--------------------------\n";
		return os;
	}

}
