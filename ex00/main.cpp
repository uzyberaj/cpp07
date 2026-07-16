/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:16 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:32:17 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

#include <iostream>
#include <string>

// Programme de test pour l'exercice 00.
// Chaque section illustre un point du sujet en lançant ./whatever.

int main(void)
{
	// === Test 1 : exemple du sujet avec int ===
	// Sujet : swap, min et max sur deux int (a=2, b=3).
	// Attendu : a=3 b=2, min=2, max=3
	std::cout << "=== Test 1 : exemple du sujet avec int ===" << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	// === Test 2 : exemple du sujet avec std::string ===
	// Sujet : les templates doivent aussi marcher avec des types "complexes".
	// Attendu : c=chaine2 d=chaine1, min=chaine1, max=chaine2
	std::cout << "\n=== Test 2 : exemple du sujet avec std::string ===" << std::endl;
	{
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}

	// === Test 3 : min/max quand les valeurs sont egales ===
	// Sujet : si a == b, min et max doivent retourner la seconde valeur (b).
	// Attendu : min(5, 5) = 5 et max(5, 5) = 5 (meme affichage, regle du sujet)
	std::cout << "\n=== Test 3 : min/max avec valeurs egales (int) ===" << std::endl;
	{
		int x = 5;
		int y = 5;

		std::cout << "min( x, y ) = " << ::min(x, y) << std::endl;
		std::cout << "max( x, y ) = " << ::max(x, y) << std::endl;
	}

	// === Test 4 : swap avec char ===
	// Sujet : n'importe quel type comparable doit fonctionner.
	// Attendu : apres swap, a='Z' et b='A'
	std::cout << "\n=== Test 4 : swap avec char ===" << std::endl;
	{
		char a = 'A';
		char b = 'Z';

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	// === Test 5 : min/max avec float ===
	// Sujet : tester un autre type simple avec operateurs de comparaison.
	// Attendu : min=1.5, max=9.9
	std::cout << "\n=== Test 5 : min/max avec float ===" << std::endl;
	{
		float f1 = 9.9f;
		float f2 = 1.5f;

		std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
		std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;
	}

	// === Test 6 : swap avec double ===
	// Sujet : swap ne retourne rien, on verifie juste l'echange en place.
	// Attendu : d1=42.42 d2=3.14
	std::cout << "\n=== Test 6 : swap avec double ===" << std::endl;
	{
		double d1 = 3.14;
		double d2 = 42.42;

		::swap(d1, d2);
		std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
	}

	return 0;
}
