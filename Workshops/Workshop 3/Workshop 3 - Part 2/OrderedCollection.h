/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-01

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h" //The collection header needs to be included

namespace sdds {

	template <typename T>
	//The OrderedCollection class will always have a capacity of 72 items.
	class OrderedCollection : public Collection<T, 72> {

	public:
		//operator+= was set virtual to make sure it will get the lastest one
		bool operator+=(const T& item) {
			//shadow the function operator+= to place or insert the received item into the array m_items
			//at an appropriate index to ensure that the elements are in ascending order after insertion.
			bool ok = true; //verification
			if (this->size() == this->capacity()) //no space
			{
				ok = false; //exit
			}
			if (this->size() < this->capacity())
			{
				unsigned match;
				unsigned index = 0;
				while (index < this->size() && item > this->operator[](index)) //search for the right space
				{
					index++;
				}

				match = this->size(); //set current size
				while (match > index) //goes until it can insert in the right position
				{
					this->operator[](match) = this->operator[](match - 1); //copy
					match--;
				}
				this->operator[](index) = item;//add the item
				this->incrSize(); //show that an item was added
				this->setSmallestItem(item); //update smallest item
				this->setLargestItem(item); //update largest item
			}
			return ok;
		}
	};
}

#endif // !SDDS_ORDEREDCOLLECTION_H
