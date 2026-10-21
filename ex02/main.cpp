/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:47 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/10/21 20:21:09 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>
#include <string>

int main(void)
{
	// === Test 1 : constructeur par defaut (tableau vide) ===
	// Array<int> empty; sans (n) : pas de new[], juste _size=0.
	// Attendu : size() = 0.
	std::cout << "=== Test 1 : constructeur par defaut ===" << std::endl;
	{
		Array<int> empty;

		std::cout << "size() = " << empty.size() << std::endl;
	}

	// === Test 2 : constructeur avec taille + initialisation par defaut ===
	// Array<int> numbers(5) alloue 5 int avec new int[5]() -> tous a 0 au depart.
	// On parcourt avec [] pour montrer qu'on peut lire chaque case.
	std::cout << "\n=== Test 2 : constructeur avec taille (int) ===" << std::endl;
	{
		Array<int> numbers(5);

		std::cout << "size() = " << numbers.size() << std::endl;
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	// === Test 3 : acces en lecture/ecriture via operator[] ===
	// values[0] = 10 utilise operator[] qui renvoie une reference : ca modifie le tableau.
	// Puis j'affiche : si j'obtiens 10 20 30, l'ecriture a bien marche.
	std::cout << "\n=== Test 3 : acces lecture/ecriture ===" << std::endl;
	{
		Array<int> values(3);

		values[0] = 10;
		values[1] = 20;
		values[2] = 30;
		std::cout << values[0] << " " << values[1] << " " << values[2] << std::endl;
	}

	// === Test 4 : acces const (lecture seule) ===
	// copyConst est const : je peux faire copyConst[0] pour LIRE (operator[] const)
	// mais pas copyConst[0] = 99 (le compilateur refuserait). Affichage 7 8 9.
	std::cout << "\n=== Test 4 : acces const ===" << std::endl;
	{
		Array<int> source(3);

		source[0] = 7;
		source[1] = 8;
		source[2] = 9;
		Array<int> const copyConst = source;
		// copyConst[0] = 99; // ne compile pas : operator[] const = lecture seule
		std::cout << copyConst[0] << " " << copyConst[1] << " " << copyConst[2] << std::endl;
	}

	// === Test 5 : index hors limites ===
	// small a 2 cases (index 0 et 1). small[5] est invalide -> throw dans operator[].
	// try/catch : si ca marche, j'affiche "Exception attrapee" et le programme continue.
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
	// duplicate(original) fait une copie profonde. Je change duplicate[0] a 99.
	// original[0] doit rester 1 : preuve que ce ne sont pas les memes cases en memoire.
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
	// assigned = original recopie le contenu (pas seulement le pointeur).
	// assigned[0] = 100 ne doit pas changer original[0] (toujours 5).
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
	// Meme classe Array, mais T = std::string : le template s'adapte sans reecrire Array.
	// J'assigne des mots avec [] comme pour des int.
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
	// Meme test que le 6 mais avec des chaines : duplicate[0]="world" ne touche pas original[0]="hello".
	std::cout << "\n=== Test 9 : copie std::string ===" << std::endl;
	{
		Array<std::string> original(1);

		original[0] = "hello";
		Array<std::string> duplicate(original);

		duplicate[0] = "world";
		std::cout << "original[0] = " << original[0] << std::endl;
		std::cout << "duplicate[0] = " << duplicate[0] << std::endl;
	}

	// === Test 10 : lecture/ecriture avec std::string (comme test 3 pour int) ===
	// operator[] renvoie string& : words[0] = "foo" modifie vraiment la case du tableau.
	// Je reecris words[1] pour montrer qu'on peut lire et ecrire plusieurs fois.
	std::cout << "\n=== Test 10 : lecture/ecriture std::string ===" << std::endl;
	{
		Array<std::string> words(3);

		words[0] = "bonjour";
		words[1] = "42";
		words[2] = "string";
		std::cout << words[0] << " | " << words[1] << " | " << words[2] << std::endl;

		words[1] = "Paris";
		std::cout << "apres modification words[1] : " << words[0] << " | " << words[1]
			<< " | " << words[2] << std::endl;
	}

	// === Test 11 : lecture seule sur std::string (comme test 4 pour int) ===
	// Je remplis source avec operator[] normal, puis je copie dans un Array<string> const.
	// readOnly[i] appelle operator[] const : je peux afficher les chaines.
	// mais pas readOnly[0] = "autre" (le compilateur refuserait). Affichage : lire sans ecrire.
	std::cout << "\n=== Test 11 : lecture seule std::string (const) ===" << std::endl;
	{
		Array<std::string> source(3);

		source[0] = "lire";
		source[1] = "sans";
		source[2] = "ecrire";
		Array<std::string> const readOnly = source;
		// readOnly[0] = "autre"; // ne compile pas : operator[] const = lecture seule
		std::cout << readOnly[0] << " " << readOnly[1] << " " << readOnly[2] << std::endl;
	}

	return 0;
}
