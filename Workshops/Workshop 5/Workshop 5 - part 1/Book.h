/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

	class Book {
		//since the workshop recommended using certain commands, I prefered to use string in this situation.
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;

	public:
		Book();
		Book(const std::string& strBook);

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		//helper for operator<<
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}

#endif // !SDDS_BOOK_H

