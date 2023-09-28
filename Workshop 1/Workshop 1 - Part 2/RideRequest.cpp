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
#include <cstring>
#include <string>
#include "RideRequest.h"

using namespace std;

namespace sdds {

	double g_taxrate; //Need to be initialized or doesn't work
	double g_discount; //Need to be initialized or doesn't work

	RideRequest::RideRequest() : m_rideDescription(nullptr), m_price(0.0), m_discount(false) //They need to be initiliazed in an specific order or I get an error in valgrind
	{
		m_customerName[0] = '\0'; //making sure everything is empty
	}

	RideRequest::~RideRequest() //desconstructor
	{
		delete[] m_rideDescription; //avoid memory leak
	}

	RideRequest::RideRequest(const RideRequest& riderequest)
	{
		//since we are only allocating and reallocating space to the description, I focused on verifying only that
		strcpy(m_customerName, riderequest.m_customerName);
		if (riderequest.m_rideDescription != nullptr) //checking if it's not empty
		{
			m_rideDescription = new char[strlen(riderequest.m_rideDescription) + 1]; //strlen to get the length of the new description
			strcpy(m_rideDescription, riderequest.m_rideDescription); //basic copy
		}
		else
		{
			m_rideDescription = nullptr; //safety measure
		}
		m_price = riderequest.m_price;
		m_discount = riderequest.m_discount;
	}

	RideRequest& RideRequest::operator=(const RideRequest& riderequest)
	{
		//since we are only allocating and reallocating space to the description, I focused on verifying only that

		if (this != &riderequest) //if they are equal, no need to copy
		{
			strcpy(m_customerName, riderequest.m_customerName);

			//We need to open space for the new description
			delete[] m_rideDescription;

			if (riderequest.m_rideDescription != nullptr) //verify
			{
				m_rideDescription = new char[strlen(riderequest.m_rideDescription) + 1]; //allocating
				strcpy(m_rideDescription, riderequest.m_rideDescription); //copy
			}
			else
			{
				m_rideDescription = nullptr;
			}

			m_price = riderequest.m_price;
			m_discount = riderequest.m_discount;
		}
		return *this; //assignment operator always return *this.
	}

	void RideRequest::read(std::istream& in)
	{
		//Temporary variables at the beginning to make it easier to work with
		char discount = '\0'; //initializing my temporary variable to avoid issues in compiling
		char tempDesc[1000] = { '\0' }; //initializing my temporary variable to avoid issues in compiling

		//If the istream is in a good state, this function will attempt to read from the istream and store the information read into the current object.
		if (in)
		{
			in.getline(m_customerName, 11, ','); //retrieving the exactly size plus null terminator

			//We need to open space for the new description
			delete[] m_rideDescription;

			in.getline(tempDesc, 1000, ','); //since we don't know the size, a default of a 1000 was set because usually descriptions are long
			m_rideDescription = new char[strlen(tempDesc) + 1]; //allocating proper size
			strcpy(m_rideDescription, tempDesc); //copy

			in >> m_price; //since pirce is a number we just retrieve the input with no specifications
			in.ignore(); //clean the rest in case there is
			//The discount status can be of two values: 'Y' if a discount should be applied and 'N' otherwise.
			in.get(discount); //checking if it is Y or N 
			if (discount == 'Y') //verifying if it's Y or N to set as true or false
			{
				m_discount = true; //in case it's true
			}
			else
			{
				m_discount = false; //in case it's false
			}
		}
	}

	void RideRequest::display() const
	{
		//use a local-to-function variable that remains in memory for the lifetime of the program
		static int counter = 1; //so the counter can still go instead of resetting
		
		//format: COUNTER. CUSTOMER_NAME|RIDE_DESCRIPTION|PRICE_WITH_TAX|PRICE_WITH_DISCOUNT

		if (m_customerName[0] == '\0') //if it's empty
		{
			cout.width(2); //aligned field of size 2
			cout << left << counter;
			cout << ". No Ride Request" << endl;
		}
		else //if not empty
		{
			//We need to calculate the taxes
			double pricePlusTax = m_price + (m_price * g_taxrate);
			//We may need to calculate the discount
			double pricePlusDiscount = 0.0;

			cout << setw(2) << left << counter << ". ";
			cout.width(10); //left aligned field of size 10
			cout << left << m_customerName << "|";
			if (strlen(m_rideDescription) > 25)
			{
				cout.width(strlen(m_rideDescription)); //Since we don't know the max size anymore
			}
			else
			{
				cout.width(25); //Part 1 stays, left aligned field of size 25
			}
			cout << left << m_rideDescription << "|";
			cout << setw(12) << left << fixed << setprecision(2) << pricePlusTax << "|";

			if (m_discount)
			{
				pricePlusDiscount = pricePlusTax - g_discount; //Calculating the 
				cout.width(13); //right aligned field of size 13
				cout << right << fixed << setprecision(2) << pricePlusDiscount;
			}
			else
			{
				//It says nothing happens so nothing
			}
			//Lil space
			cout << endl;
		}
		//counter needs to up
		counter++;
	}
}