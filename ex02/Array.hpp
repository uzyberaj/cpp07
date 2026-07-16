/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:40 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:32:41 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

// Classe template Array : tableau dynamique de taille fixe alloue avec new[].
// T = type stocke dans le tableau (int, std::string, etc.).
template<typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const& other);
	Array& operator=(Array const& other);
	~Array();

	// Acces en lecture/ecriture (tableau non-const).
	T& operator[](unsigned int index);
	// Acces en lecture seule (tableau const).
	T const& operator[](unsigned int index) const;

	// Retourne le nombre d'elements ; ne modifie pas l'objet.
	unsigned int size() const;

private:
	unsigned int	_size;
	T*				_array;
};

# include "Array.tpp"

#endif
