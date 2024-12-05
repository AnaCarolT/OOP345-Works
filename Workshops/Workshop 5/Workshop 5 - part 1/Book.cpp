/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Book.h"

using namespace std;

namespace sdds {

	Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_description("")
	{
		//set everything to a default value
	}

	Book::Book(const std::string& strBook)
	{
		//need to get everything that is in the .txt but also print it correctly
		size_t startTrim = 0;
		size_t endTrim;

		//get author first
		endTrim = strBook.find(','); //needs to go until the comma
		m_author = strBook.substr(startTrim, endTrim - startTrim);
		//removing any extra space that may interfere in the output
		m_author = m_author.substr(m_author.find_first_not_of(" "), m_author.find_last_not_of(" ") + 1);
		startTrim = endTrim + 1;

		//get the title
		endTrim = strBook.find(',', startTrim); //should start at the new beginning
		m_title = strBook.substr(startTrim, endTrim - startTrim);
		//get out spaces
		m_title = m_title.substr(m_title.find_first_not_of(" "), m_title.find_last_not_of(" ") + 1);
		startTrim = endTrim + 1;
		//some titles have empty spaces at the end
		m_title = m_title.substr(0, m_title.find_last_not_of(" \t") + 1);
		startTrim = endTrim + 1;

		//get the country
		endTrim = strBook.find(',', startTrim); //should start at the new beginning
		m_country = strBook.substr(startTrim, endTrim - startTrim);
		//get rid of spaces
		m_country = m_country.substr(m_country.find_first_not_of(" "), m_country.find_last_not_of(" ") + 1);
		startTrim = endTrim + 1;

		//get price
		endTrim = strBook.find(',', startTrim); //should start at the new beginning
		m_price = stod(strBook.substr(startTrim, endTrim - startTrim)); //it needs to be a double
		startTrim = endTrim + 1;

		//get year
		endTrim = strBook.find(',', startTrim); //should start at the new beginning
		m_year = stoi(strBook.substr(startTrim, endTrim - startTrim)); //integer
		startTrim = endTrim + 1;

		//get description
		m_description = strBook.substr(startTrim); //last part
		//get rid of unecessary spaces for output
		m_description = m_description.substr(m_description.find_first_not_of(" "), m_description.find_last_not_of(" ") + 1);


	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}


	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		//Using iomanip because it's easier to manipulate data this way
		//author first
		//need 20 spaces
		os << setw(20) << book.m_author << " | "
			//title
			//need 22 spaces
			<< setw(22) << book.m_title << " | "
			//country
			//needs 5 spaces
			<< setw(5) << book.m_country << " | "
			//year
			//needs 4 spaces
			<< setw(4) << book.m_year << " | "
			//price
			//needs 6 spaces
			//we need to make sure it will look like the output, precision 2 and "round" numbers
			<< fixed << setprecision(2)
			<< setw(6) << book.m_price << " | "
			//description is already "filtered"
			//no limit output wise?
			<< book.m_description;

		return os;

	}

}
