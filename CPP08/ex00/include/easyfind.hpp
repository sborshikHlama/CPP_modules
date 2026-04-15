/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:25:40 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/15 18:26:30 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>


class ValueNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

template <typename T>
typename T::const_iterator easyfind(const T &container, int value);

#include "easyfind.tpp"

#endif