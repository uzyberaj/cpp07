/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:44 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:32:45 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementations des methodes template Array (incluses depuis Array.hpp).

template<typename T>
Array<T>::Array() : _size(0), _array(0)
{
	// Tableau vide : pas d'allocation, size() vaut 0.
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(0)
{
	// Le sujet impose new[] ; () value-initialise chaque element (0 pour int).
	if (n > 0)
		_array = new T[n]();
}

template<typename T>
Array<T>::Array(Array const& other) : _size(other._size), _array(0)
{
	// Copie profonde : l'original et la copie restent independants.
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = 0;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

template<typename T>
T const& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
