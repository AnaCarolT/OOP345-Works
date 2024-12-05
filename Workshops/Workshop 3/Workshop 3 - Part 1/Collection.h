#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <iomanip>

namespace sdds {

	template <typename T, unsigned C>
	class Collection {

		T m_items[C]{};
		unsigned m_size = 0;

		static T m_smallestItem;
		static T m_largestItem;

	protected:

		void setSmallestItem(const T& item) {
			if (item < m_smallestItem)
			{
				m_smallestItem = item;
			}
		}

		void setLargestItem(const T& item) {
			if (item > m_largestItem)
			{
				m_largestItem = item;
			}
		}

	public:

		unsigned size() const {
			return m_size;
		};

		unsigned capacity() const {
			return C;
		};

		T getSmallestItem() {
			return m_smallestItem;
		}

		T getLargestItem() {
			return m_largestItem;
		}

		bool operator+=(const T& item) {
			if (m_size < C)
			{
				m_items[m_size++] = item;
				setSmallestItem(item);
				setLargestItem(item);
				return true;
			}
			return false;
		}

		void print(std::ostream& os) const {
			os << "[";
			unsigned i; //i needs to be unsigned or it is now gonna work
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

	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem{9999};
	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1 , 10000);

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem {-9999};
	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

}

#endif // !SDDS_COLLECTION_H