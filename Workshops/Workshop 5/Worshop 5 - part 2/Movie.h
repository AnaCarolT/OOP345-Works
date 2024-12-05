/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
	public:
		Movie() = default;
		Movie(const std::string& strMovie);
		const std::string& title() const;
		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}

#endif // !SDDS_MOVIE_H

