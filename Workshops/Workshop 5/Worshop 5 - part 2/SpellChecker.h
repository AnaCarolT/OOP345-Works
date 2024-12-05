/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

const int limit = 6;

namespace sdds {

	class SpellChecker
	{
		std::string m_badWords[limit];
		std::string m_goodWords[limit];
		static int m_counter[limit];
	public:
		SpellChecker(const char* txt);
		void operator()(std::string& txt);
		void showStatistics(std::ostream& os) const;
	};
}

#endif // !SDDS_SPELLCHECKER_H

