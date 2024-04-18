#pragma once

#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array<T>(void) :
			m_size(0),
			m_elements(NULL)
		{
		}

		Array<T>(unsigned int n) :
			m_size(n),
			m_elements(new T[n])
		{
			for (size_t i = 0; i < n; ++i)
				m_elements[i] = T();
		}

		Array<T>(const Array<T> &o) :
			m_size(0),
			m_elements(NULL)
		{
			*this = o;
		}

		~Array<T>(void)
		{
			delete[] m_elements;
		}

		Array<T>	&operator=(const Array<T> &o)
		{
			if (this == &o)
				return (*this);
			m_size = o.m_size;
			delete[] m_elements;
			m_elements = new T[m_size];
			for (size_t i = 0; i < m_size; ++i)
				m_elements[i] = o.m_elements[i];
			return (*this);
		}

		T	&operator[](unsigned int index) const
		{
			if (index >= m_size)
				throw std::out_of_range("Index out of range.");
			return (m_elements[index]);
		}

		unsigned int	size(void) const
		{
			return (m_size);
		}
	
	private:
		unsigned int	m_size;
		T				*m_elements;
};
