/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-09-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "RideRequest.h"

using namespace std;

namespace sdds {

	double g_taxrate;
	double g_discount;

	RideRequest::RideRequest() : m_price(0.0), m_discount(false)
	{
		m_customerName[0] = '\0';
		m_rideDescription[0] = '\0';
	}

	void RideRequest::read(std::istream& in)
	{
		if (in)
		{
			in.getline(m_customerName, 11, ',');
			in.getline(m_rideDescription, 26, ',');
			in >> m_price;
			in.ignore();
			char discount = '\0';
			in.get(discount);
			if (discount == 'Y')
			{
				m_discount = true;
			}
			else
			{
				m_discount = false;
			}
		}
	}

	void RideRequest::display() const
	{
		static int counter = 1;
		if (m_customerName[0] == '\0')
		{
			cout.width(2);
			cout << left << counter;
			cout << ". No Ride Request" << endl;
		}
		else
		{
			double pricePlusTax = m_price + (m_price * g_taxrate);
			double pricePlusDiscount = 0.0;

			cout << setw(2) << left << counter << ". ";
			cout.width(10);
			cout << left << m_customerName << "|";
			cout.width(25);
			cout << left << m_rideDescription << "|";
			cout << setw(12) << left << fixed << setprecision(2) << pricePlusTax << "|";

			if (m_discount)
			{
				pricePlusDiscount = pricePlusTax - g_discount;
				cout.width(13);
				cout << right << fixed << setprecision(2) << pricePlusDiscount;
			}
			else
			{
				cout.width(13);
			}
			cout << endl;
		}
		counter++;
	}
}