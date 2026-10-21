/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:32 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/10/19 17:24:14 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include <string>

// Affiche un element passe en const reference (tableau const ou lecture seule).
template<typename T>
void print(T const& value)
{
	std::cout << value << std::endl;
}

// Modifie un element passe en reference non-const (tableau modifiable).
template<typename T>
void setToFortyTwo(T& value)
{
	value = static_cast<T>(42);
}

// Double la valeur de chaque element (test supplementaire, non-const ref).
void doubleValue(int& value)
{
	value *= 2;
}

// Programme de test pour l'exercice 01.
// Chaque section illustre un point du sujet en lançant ./iter.

int main(void)
{
	// === Test 1 : reproduction du test d'evaluation ===
	// Sujet : iter sur int[], d'abord afficher, puis modifier, puis reafficher.
	// Attendu : 0 1 2 3 4 puis 42 42 42 42 42
	std::cout << "=== Test 1 : test d'evaluation (ex01.cpp) ===" << std::endl;
	{
		int array[] = { 0, 1, 2, 3, 4 };

		::iter(array, 5, print<int>);
		::iter(array, 5, setToFortyTwo<int>);
		::iter(array, 5, print<int>);
	}

	// === Test 2 : tableau const + fonction const ref ===
	// Sujet : la 3e fonction peut prendre son argument en const reference.
	// Attendu : affiche A B C sans erreur de compilation
	std::cout << "\n=== Test 2 : tableau const + const ref ===" << std::endl;
	{
		const char letters[] = { 'A', 'B', 'C' };

		::iter(letters, 3, print<char>);
	}

	// === Test 3 : modification in-place avec non-const ref ===
	// Sujet : la 3e fonction peut aussi prendre une reference non-const.
	// Attendu : 2 4 6 8 10 apres doublement
	std::cout << "\n=== Test 3 : modification in-place (non-const ref) ===" << std::endl;
	{
		int values[] = { 1, 2, 3, 4, 5 };

		::iter(values, 5, doubleValue);
		::iter(values, 5, print<int>);
	}

	// === Test 4 : tableau de std::string ===
	// Sujet : iter doit marcher avec n'importe quel type de tableau.
	// Attendu : affiche les trois chaines dans l'ordre
	std::cout << "\n=== Test 4 : tableau de std::string ===" << std::endl;
	{
		std::string words[] = { "hello", "cpp07", "iter" };

		::iter(words, 3, print<std::string>);
	}

	// === Test 5 : longueur nulle ===
	// Sujet : iter ne doit rien faire si le tableau est vide (length = 0).
	// Attendu : aucune sortie, pas de crash
	std::cout << "\n=== Test 5 : longueur nulle (aucune sortie attendue) ===" << std::endl;
	{
		int empty[] = { 99 };

		::iter(empty, 0, print<int>);
		std::cout << "(fin du test 5)" << std::endl;
	}

	// === Test 6 : fonction classique (pas template) en 3e parametre ===
	// Sujet : le 3e parametre peut etre une fonction template instanciee
	// ou une fonction classique — les deux doivent compiler.
	// Attendu : 10 20 30
	std::cout << "\n=== Test 6 : fonction classique en parametre ===" << std::endl;
	{
		int nums[] = { 10, 20, 30 };

		::iter(nums, 3, print<int>);
	}

	return 0;
}
