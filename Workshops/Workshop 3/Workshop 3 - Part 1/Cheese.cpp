#include "Book.h"

#include <iomanip>

using namespace std;

namespace sdds {

	Book::Book() : m_title("\0"), m_numChapters(0),  m_numPages(0) {}

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

	bool Book::isValid() const
	{
		return (m_title != "") && m_numChapters > 0 && m_numPages > 0;
	}

	ostream& Book::print(ostream& os) const
	{
		if (isValid())
		{
			if (m_numChapters < 10)
			{
				os << setw(50);
			}
			else
			{
				os << setw(49);
			}
			os << right << m_title << "," << m_numChapters << "," << m_numPages << " | (" << fixed << setprecision(6) << static_cast<double>(m_numPages) / m_numChapters << ")    ";
		}
		else
		{
			os << "| Invalid book data";
		}
		return os;
	}


	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		return bk.print(os);
	}

}
