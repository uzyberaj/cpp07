/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:32:29 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 17:32:30 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// --- iter ---
// Fonction template generique : parcourt un tableau et applique une fonction
// sur chaque element. T = type des elements, F = type de la fonction passee.
// Le sujet demande que ca marche avec const ref ET non-const ref :
// si le tableau est const, T devient "const int" par exemple.
template<typename T, typename F>
void iter(T* array, std::size_t const& length, F func)
{
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif
