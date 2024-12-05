/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-01

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {

	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};

	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);

		// TODO: In completing Part 1, add here the missing 
		// member prototypes that would be necessary for the 
		// Collection module code and tester module w3_p1.cpp 
		// to manage Book-type objects. 

		//Creating a function to make it easier to make the validation
		bool isCorrect() const;

		// In completing Part 2, add here the missing 
		// member prototypes that would be necessary for 
		// OrderedCollection module code and tester module 
		// w3_p2.cpp to manage Book-type object. 
		//
		// Write the implementations of these functions 
		// in Book.cpp file

		//We need this for OrderedCollection to work, because we are comparing.
		bool operator<(const Book& comp) const;
		bool operator>(const Book& comp) const;

		std::ostream& print(std::ostream& os) const;

	};

	std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // !SDDS_BOOK_H

