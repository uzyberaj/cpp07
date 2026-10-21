/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:44 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/10/21 20:15:26 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementations des fonctions de Array (template = une version par type T utilise).

// --- Constructeur par defaut : Array<int> tab; ---
// Le sujet demande un tableau "vide" : aucune case, donc pas de new[].
// _size vaut 0, _array vaut 0 (pointeur nul = "je ne pointe nulle part").
// Si on faisait tab[0] apres ca, operator[] verrait index >= _size et lancerait une exception.

template<typename T>
Array<T>::Array() : _size(0), _array(0)
{
}

// --- Constructeur avec taille : Array<int> tab(5); ---
// On note qu'on a 5 places (_size = 5).
// new T[n]() : le sujet impose new[] ; les () apres [n] disent au compilateur
//   d'initialiser chaque case proprement : int -> 0, bool -> false, string -> "".

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(0)
{
	if (n > 0)
		_array = new T[n]();
}

// --- Constructeur de copie : Array<int> copie(original); ---
// Deep copy :
//   1) meme _size que l'autre
//   2) new T[_size] pour un NOUVEAU bloc
//   3) boucle : copie[i] = original[i] pour chaque i

template<typename T>
Array<T>::Array(Array const& other) : _size(other._size), _array(0)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
}

// --- Operateur = : tab1 = tab2; ---
// tab1 avait peut-etre deja un tableau en memoire -> delete[] d'abord.
// Ensuite on refait comme le constructeur de copie : nouvelle taille, new[], boucle de copie.

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

// --- Destructeur ~Array() ---
// Libere tout le bloc new[].

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

// --- operator[] pour lire/ecrire : tab[i] ---
// index doit etre valide : pour un tableau de taille 3, les index ok sont 0, 1, 2.
// Si index vaut 3 ou plus (index >= _size), le sujet demande throw std::exception().
//   -> pas de lecture au hasard en memoire (segfault).
// On renvoie _array[index] par reference (T&) pour que tab[i] = 42 modifie vraiment la case.

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

// --- operator[] en lecture seule (objet Array const) ---
// Meme test de bornes : index trop grand -> exception.
// T const& = on renvoie la valeur en interdisant de la modifier via cette reference.

template<typename T>
T const& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

// --- size() ---
// Renvoie _size
// La methode est const : elle ne modifie pas l'objet, elle lit juste un nombre.

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
