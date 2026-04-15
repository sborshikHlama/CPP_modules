/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:26:11 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/15 18:26:45 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Span.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "--- Basic Test ---" << std::endl;
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (Expected: 14)" << std::endl;
        
        std::cout << "Attempting to add one more number..." << std::endl;
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << "Caught expected capacity exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Edge Case: 1 Element ---" << std::endl;
    Span sp1 = Span(1);
    sp1.addNumber(1);
    try {
        sp1.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "Caught expected exception for 1 element (shortest): " << e.what() << std::endl;
    }

    std::cout << "\n--- Large Test (10,000 numbers) ---" << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i * 2);
    }
    sp2.addNumber(v.begin(), v.end());
    std::cout << "Shortest span (10k): " << sp2.shortestSpan() << " (Expected: 2)" << std::endl;
    std::cout << "Longest span (10k): " << sp2.longestSpan() << " (Expected: 19998)" << std::endl;

    return 0;
}
