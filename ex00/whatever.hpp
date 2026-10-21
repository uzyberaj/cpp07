/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:43:53 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/10/21 20:43:56 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// --- swap ---
// Fonction template : le type T est deduit automatiquement a l'appel.
// Le sujet demande d'echanger deux valeurs du meme type, sans rien retourner.
template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// --- min ---
// Retourne la plus petite des deux valeurs.
// Si elles sont egales, le sujet demande de retourner la seconde (b).
template<typename T>
T min(T const& a, T const& b)
{
	if (a < b)
		return a;
	return b;
}

// --- max ---
// Retourne la plus grande des deux valeurs.
// Si elles sont egales, le sujet demande de retourner la seconde (b).
template<typename T>
T max(T const& a, T const& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
