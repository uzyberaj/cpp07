/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:40 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/10/21 20:03:44 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

// Array = une classe qui se comporte comme un tableau.
//
// "template<typename T>" : T est un type qu'on choisit plus tard.
//   Exemple : Array<int> numbers(5);  -> T vaut int, 5 cases pour des entiers.
//             Array<std::string> words(3); -> T vaut string, 3 chaines.
// On ecrit le code une seule fois, le compilateur refait la classe pour chaque T.
//
// Le sujet oblige a reserver la memoire avec new[]
// _size = combien de cases ; _array = adresse du debut du bloc en memoire (ou 0 si vide).

template<typename T>
class Array
{
public:
	// Constructeur sans argument : Array<int> vide; -> 0 element, rien alloue.
	Array();

	// Constructeur avec un nombre n
	Array(unsigned int n);

	// Constructeur de copie
	Array(Array const& other);

	// Affectation
	Array& operator=(Array const& other);

	// Destructeur : libere la memoire prise avec new[].
	~Array();

	// Quand on ecrit arr[2] = 10, c'est cette version qui est utilisee.
	// Elle renvoie une reference (alias) sur la vraie case dans _array, donc l'ecriture modifie le tableau.
	T& operator[](unsigned int index);

	// Quand l'Array est const, on a seulement le droit de LIRE
	T const& operator[](unsigned int index) const;

	unsigned int size() const;

private:
	unsigned int	_size;
	T*				_array;
};

// Le code des methodes est dans Array.tpp (fichier separe mais inclus ici).
// Les templates doivent etre visibles par le compilateur entier :
// quand on fait Array<int>, il a besoin de voir comment le constructeur marche pour int.
# include "Array.tpp"

#endif
