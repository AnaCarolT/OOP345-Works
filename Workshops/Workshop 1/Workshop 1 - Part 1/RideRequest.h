/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-09-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>

namespace sdds {

	//Global variables
	//Floating-point numbers in double precision
	extern double g_taxrate;
	extern double g_discount;

	//RideRequest in the namespace sdds
	class RideRequest {

		//a C-style null-terminated string of up to 10 characters including the null byte terminator representing the name of the customer.
		char m_customerName[11]{};
		//a C-style null-terminated string of up to 25 characters including the null byte terminator
		//representing the extra details about the ride (e.g., a description or special requirements the customer made).
		char m_rideDescription[26]{};
		//the price of the ride as a floating-point number in double precision.
		double m_price{};
		//a Boolean flag indicating whether the ride receives a discount
		bool m_discount{};
		
	public:
		//Default constructor
		RideRequest();
		//read(): a modifier that receives an istream reference
		void read(std::istream& in);
		//display(): a query that displays to the screen the content of an Ride Request instance
		void display() const;
	};
}

#endif // !SDDS_RIDEREQUEST_H

