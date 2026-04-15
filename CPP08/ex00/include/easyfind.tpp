/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:25:43 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/15 18:26:25 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T &container, int value) 
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) 
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}
