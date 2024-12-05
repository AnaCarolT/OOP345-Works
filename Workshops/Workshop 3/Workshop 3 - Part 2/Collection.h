/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-01

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <iomanip>

namespace sdds {

	template <typename T, unsigned C>
	class Collection {

		//T: the type of an element of the managed array, called m_items
		//C: an unsigned integer representing the capacity of the collection (the size of the managed array);
		//this is the maximum number of items that can be included in the collection
		T m_items[C]{};
		//size
		unsigned m_size = 0;

		// object of type T to store smallest item.
		static T m_smallestItem;
		//m_largestItem: An object of Type T to store largest item.
		static T m_largestItem;

	protected:

		//a modifier to receive an object of type T, as unmodifiable reference. It sets m_smallestItem to the received object if the received object is smaller than it.
		void setSmallestItem(const T& item) {
			if (item < m_smallestItem)
			{
				m_smallestItem = item;
			}
		}

		//a modifier to receive an object of type T, as unmodifiable reference. It sets m_largestItem to the received object if the received object is larger than it
		void setLargestItem(const T& item) {
			if (item > m_largestItem)
			{
				m_largestItem = item;
			}
		}

		//Part 2

		//a mutator operator to receive an array index and return corresponding element from m_items array
		T& operator[](unsigned index) {
			return m_items[index];
		}

		//a mutator to increase by 1 the size count of elements stored in the collection.
		void incrSize() {
			m_size++;
		}

	public:

		//a query to return current number of items
		unsigned size() const {
			return m_size;
		};

		//a query to return capacity of the collection
		unsigned capacity() const {
			return C;
		};

		//returns the current smallest item stored in the class attribute.
		T getSmallestItem() {
			return m_smallestItem;
		}

		//returns the current largest item stored in the class attribute.
		T getLargestItem() {
			return m_largestItem;
		}

		//a mutator to receive as parameter an unmodifiable reference to object of type T.
		virtual bool operator+=(const T& item) {
			if (m_size < C)
			{
				//adds the received object as a new item to the end of the collection of the collection.
				//updates the size of the collection (number of items stored).
				m_items[m_size++] = item;
				//updates the smallest/largest to the value of parameter by calling the respective private member functions.
				setSmallestItem(item);
				setLargestItem(item);
				return true;
			}
			return false;
		}

		//a query to receive a reference to an ostream object
		void print(std::ostream& os) const {
			os << "[";
			unsigned i; //unsigned because the values that are being compared are unsigned as well
			//i needs to be unsigned or it is not going work, althought it compiles it will appear a lot of errors once in the matrix
			for ( i = 0; i < m_size; ++i)
			{
				os << m_items[i] << std::setprecision(1);
				if (i < m_size -1)
				{
					os << ",";
				}
			}
			os << "]\n";
		}
	};

	//Based in what professor taught in class
	
	//smallest need to be initiated at 9999
	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem{9999};
	//specialization for T = Book and C = 10 - smallest
	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1 , 10000);
	//specialization for T = Book and C = 72 - smallest
	template <>
	Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

	//largest need to be initiated at -9999
	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem {-9999};
	//specialization for T = Book and C = 10 - largest
	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
	//specialization for T = Book and C = 72 - largest
	template<>
	Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

	//specialization for T = Book and C = 10
	template<>
	void Collection<Book, 10>::print(std::ostream& os) const {
		unsigned i;
		os << "| ---------------------------------------------------------------------------|\n";
		for (i = 0; i < size(); ++i)
		{
			os << "| ";
			os << m_items[i] << " |" << "\n";
		}
		os << "| ---------------------------------------------------------------------------|\n";
	}

	//specialization for T = Book and C = 72
	template<>
	void Collection<Book, 72>::print(std::ostream& os) const {
		unsigned i;
		os << "| ---------------------------------------------------------------------------|\n";
		for (i = 0; i < size(); ++i)
		{
			os << "| ";
			os << m_items[i] << " |" << "\n";
		}
		os << "| ---------------------------------------------------------------------------|\n";
	}
}

#endif // !SDDS_COLLECTION_H