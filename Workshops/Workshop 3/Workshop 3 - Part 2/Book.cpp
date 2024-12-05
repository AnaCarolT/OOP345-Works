/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-01

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Book.h"

#include <iomanip>

using namespace std;

namespace sdds {

	Book::Book() : m_title("\0"), m_numChapters(0),  m_numPages(0) {} //no argument constructor

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {} //three argument constructor

	bool Book::isCorrect() const //validation for the print
	{
		return (m_title != "") && m_numChapters > 0 && m_numPages > 0;
	}

	bool Book::operator<(const Book& comp) const //less than
	{
		return (static_cast<double>(m_numPages) / m_numChapters < static_cast<double>(comp.m_numPages) / comp.m_numChapters); //less than
	}

	bool Book::operator>(const Book& comp) const //greater than
	{
		return (static_cast<double>(m_numPages) / m_numChapters > static_cast<double>(comp.m_numPages) / comp.m_numChapters); //greater than
	}

	ostream& Book::print(ostream& os) const //print based on the data received
	{
		if (isCorrect()) //validation
		{
			//56 spaces should be reserved for the title + chapter + pages
			//We need to consider the counter number

			//Workshop asked to try these:
			/*std::to_string()
			std::string
			std::string::operator+()
			std::string::operator+=()*/

			string front;
			front = m_title + "," + to_string(m_numChapters) + "," + to_string(m_numPages);
			os << right << setw(56) << front;
			os << " | (" << fixed << setprecision(6) << static_cast<double>(m_numPages) / m_numChapters << ")    "; //string was setting the double as an int later
		}
		else
		{
			//in case t;s invalid
			os << "| Invalid book data";
		}
		return os;
	}


	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		//default for operator <<
		return bk.print(os);
	}

}
