/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:26:08 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/15 18:26:43 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>

class Span {
private:
  unsigned int _size;
  std::vector<int> _storage;
  Span();

public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int n);
  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    typename std::iterator_traits<InputIterator>::difference_type count =
        std::distance(first, last);

    if (count < 0 ||
        _storage.size() + static_cast<std::size_t>(count) > _size) {
      throw std::exception();
    }
    _storage.insert(_storage.end(), first, last);
  }

  int shortestSpan() const;
  int longestSpan() const;
};

#endif
