/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Movie.h"

using namespace std;

namespace sdds {

	Movie::Movie(const string& strMovie)
	{
		if (!strMovie.empty())
		{
			size_t finalTitle = strMovie.find(','); //goes until comma
			if (finalTitle != strMovie.find(','))
			{
				m_title = strMovie.substr(0, finalTitle); //catch it
				m_title = m_title.substr(m_title.find_first_not_of(' ')); //clean spaces beginning
				m_title = m_title.substr(0, m_title.find_last_not_of(' ') + 1); //clean spaces beginning end
			}

			size_t catchYear = finalTitle + 1; //we need to manage to track the year now
			size_t finalYear = strMovie.find(',', catchYear); //new start and until comma
			if (finalYear != string::npos)
			{
				string transInt = strMovie.substr(catchYear, finalYear - catchYear);
				m_year = stoi(transInt); //make it into an int
			}

			size_t rest = finalYear + 1; //getting rest/description
			m_description = strMovie.substr(rest);
			m_description = m_description.substr(m_description.find_first_not_of(' ')); //no extra spaces start
			m_description = m_description.substr(0, m_description.find_last_not_of(' ') + 1); //no extra spaces end
		}
		else
		{
			*this = Movie();
		}
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}


	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		//movie title
		//40 spaces
		os << setw(40) << movie.m_title << " | ";
		//movie year
		//4 spaces
		os << setw(4) << movie.m_year << " | ";
		//description/rest
		os << movie.m_description << endl;
		return os;
	}

}
