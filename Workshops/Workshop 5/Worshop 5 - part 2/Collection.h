/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-10-22

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {

	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_item{};
		size_t m_counter{};
		void (*m_observer)(const Collection<T>&, const T&) { nullptr };

	public:

		Collection(const std::string& name) {
			m_name = name;
			m_item = nullptr;
			m_counter = 0;
			m_observer = nullptr;
		}

		Collection(Collection&) = delete; //not implemented

		Collection& operator=(Collection&) = delete;

		~Collection() {
			delete[] m_item;
			m_item = nullptr;
		}

		const std::string& name() const
		{
			return m_name;
		}

		size_t size() const {
			return m_counter;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;

		}

		Collection<T>& operator+=(const T& item) {
			bool ok = false;
			//checking if there is a repeated title
			for (size_t i = 0; i < m_counter; ++i)
			{
				if (m_item[i].title() == item.title())
				{
					ok = true;
					break;
				}
			}

			if (!ok)
			{
				//if title is not there add to the collection
				T* tempArray = new T[m_counter + 1];

				//transter the ones that we already there
				for (size_t i = 0; i < m_counter; ++i)
				{
					tempArray[i] = m_item[i];
				}

				//add new item
				tempArray[m_counter] = item;
				//get rid of the other array
				delete[] m_item;
				//update
				m_item = tempArray;

				//counter need to move
				m_counter++;

				//notify
				if (m_observer != nullptr)
				{
					m_observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t index) const {
			if (index >= m_counter || index < 0)
			{
				throw std::out_of_range("Bad index [" + std::to_string(index) + " ]. " + "Collection has [" + std::to_string(m_counter) + "] items.");
			}
			else
			{
				return m_item[index];
			}
		}

		T* operator[](std::string title) const {
			int ok = -1;
			for (size_t i = 0; i < m_counter; ++i)
			{
				if (m_item[i].title() == title)
				{
					ok = 1;
				}
			}
			if (ok == -1)
			{
				return nullptr;
			}
			else
			{
				return &m_item[ok];
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& collection)
		{
			for (size_t i = 0; i < collection.size(); ++i)
			{
				os << collection.m_item[i];
			}
			return os;
		}
	};
}
#endif // !SDDS_COLLECTION_H

