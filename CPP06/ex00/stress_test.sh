#!/bin/bash

EXECUTABLE="./converter"

if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable $EXECUTABLE not found. Compiling..."
    c++ -Wall -Wextra -Werror -std=c++98 main.cpp ScalarConverter.cpp -o converter
fi

TEST_CASES=(
    "42"
    "42.0f"
    "42.42"
    "a"
    "*"
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "inff"
    "-inff"
    ""
    "   "
    "42abc"
    "abc42"
    "42.42.42"
    "2147483647"
    "2147483648"
    "-2147483648"
    "-2147483649"
    "1.79769e+308"
    "99999999999999999999999999999999999999"
    "0.0000000000000000000000000000000000001"
)

for test in "${TEST_CASES[@]}"; do
    echo "---------------------------------------"
    echo "TESTING: '$test'"
    $EXECUTABLE "$test"
done
