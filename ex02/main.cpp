/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:47 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:32:48 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>
#include <string>

// Programme de test pour l'exercice 02.
// Chaque section illustre un point du sujet en lançant ./array.

int main(void)
{
	// === Test 1 : constructeur par defaut (tableau vide) ===
	// Sujet : construction sans parametre cree un tableau vide.
	// Attendu : size() == 0
	std::cout << "=== Test 1 : constructeur par defaut ===" << std::endl;
	{
		Array<int> empty;

		std::cout << "size() = " << empty.size() << std::endl;
	}

	// === Test 2 : constructeur avec taille + initialisation par defaut ===
	// Sujet : n elements initialises par defaut (int -> 0 avec new T[n]()).
	// Attendu : size() == 5, chaque element vaut 0
	std::cout << "\n=== Test 2 : constructeur avec taille (int) ===" << std::endl;
	{
		Array<int> numbers(5);

		std::cout << "size() = " << numbers.size() << std::endl;
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	// === Test 3 : acces en lecture/ecriture via operator[] ===
	// Sujet : les elements sont accessibles avec [].
	// Attendu : apres ecriture, les valeurs sont conservees
	std::cout << "\n=== Test 3 : acces lecture/ecriture ===" << std::endl;
	{
		Array<int> values(3);

		values[0] = 10;
		values[1] = 20;
		values[2] = 30;
		std::cout << values[0] << " " << values[1] << " " << values[2] << std::endl;
	}

	// === Test 4 : acces const (lecture seule) ===
	// Sujet : lecture possible sur une instance const.
	// Attendu : affiche 7 8 9 sans erreur de compilation
	std::cout << "\n=== Test 4 : acces const ===" << std::endl;
	{
		Array<int> source(3);

		source[0] = 7;
		source[1] = 8;
		source[2] = 9;
		Array<int> const copyConst = source;
		std::cout << copyConst[0] << " " << copyConst[1] << " " << copyConst[2] << std::endl;
	}

	// === Test 5 : index hors limites ===
	// Sujet : acces out of bounds -> std::exception.
	// Attendu : message d'exception affiche
	std::cout << "\n=== Test 5 : index hors limites ===" << std::endl;
	{
		Array<int> small(2);

		try
		{
			std::cout << small[5] << std::endl;
			std::cout << "ERREUR : aucune exception levee" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception attrapee (index invalide)" << std::endl;
		}
	}

	// === Test 6 : constructeur de copie (independance) ===
	// Sujet : modifier la copie ne doit pas affecter l'original.
	// Attendu : original[0] = 1, copie modifiee = 99
	std::cout << "\n=== Test 6 : constructeur de copie ===" << std::endl;
	{
		Array<int> original(2);

		original[0] = 1;
		original[1] = 2;
		Array<int> duplicate(original);

		duplicate[0] = 99;
		std::cout << "original[0] = " << original[0] << std::endl;
		std::cout << "duplicate[0] = " << duplicate[0] << std::endl;
	}

	// === Test 7 : operateur d'affectation (independance) ===
	// Sujet : apres =, original et copie restent independants.
	// Attendu : original[0] = 5, assigned[0] = 100
	std::cout << "\n=== Test 7 : operateur d'affectation ===" << std::endl;
	{
		Array<int> original(2);
		Array<int> assigned(1);

		original[0] = 5;
		original[1] = 6;
		assigned = original;
		assigned[0] = 100;
		std::cout << "original[0] = " << original[0] << std::endl;
		std::cout << "assigned[0] = " << assigned[0] << std::endl;
	}

	// === Test 8 : type complexe (std::string) ===
	// Sujet : Array doit fonctionner avec des types simples ET complexes.
	// Attendu : affiche les chaines stockees
	std::cout << "\n=== Test 8 : type complexe (std::string) ===" << std::endl;
	{
		Array<std::string> words(3);

		words[0] = "cpp";
		words[1] = "module";
		words[2] = "07";
		for (unsigned int i = 0; i < words.size(); ++i)
			std::cout << words[i] << std::endl;
	}

	// === Test 9 : copie de std::string (independance) ===
	// Sujet : copie profonde sur type complexe.
	// Attendu : original garde "hello", copie affiche "world"
	std::cout << "\n=== Test 9 : copie std::string ===" << std::endl;
	{
		Array<std::string> original(1);

		original[0] = "hello";
		Array<std::string> duplicate(original);

		duplicate[0] = "world";
		std::cout << "original[0] = " << original[0] << std::endl;
		std::cout << "duplicate[0] = " << duplicate[0] << std::endl;
	}

	return 0;
}
