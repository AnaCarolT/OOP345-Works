/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

	int SpellChecker::m_counter[limit] = { 0 }; //need to initialize

	SpellChecker::SpellChecker(const char* txt)
	{
		for (size_t i = 0; i < limit; i++) {
			m_badWords[i] = "";
			m_goodWords[i] = "";
		}
		std::ifstream file(txt);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			std::string temp;
			size_t i = 0;
			while (file && i < limit) {
				getline(file, m_badWords[i], ' ');
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
			}
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& txt)
	{
		for (size_t i = 0; i < limit; i++)
		{
			size_t line = 0;
			while ((line = txt.find(m_badWords[i], line)) != std::string::npos)
			{
				txt.replace(line, m_badWords[i].length(), m_goodWords[i]);
				m_counter[i]++;
				line += m_goodWords[i].length();
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& os) const
	{
		os << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < limit; i++)
		{
			os << right << setw(15) << m_badWords[i] << ":";
			os << setw(2) << m_counter[i] << " replacements" << endl;
		}
	}
}
