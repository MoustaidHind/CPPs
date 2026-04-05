#!/bin/bash

# Define the array of test cases
TESTS=(
    "c" "*" " " 
    "0" "42" "-42" "2147483647" "-2147483648"
    "0.0f" "4.2f" "-4.2f" "42.0f" "0.0" "4.2" "-4.2" "42.0"
    "nan" "nanf" "+inf" "+inff" "-inf" "-inff"
    "2147483649" "-2147483649" "-5" "130"
    "42abc" "abc" "42.42.42" "f" "." ""
)

# Check if the convert executable exists
if [ ! -f "./convert" ]; then
    echo "Error: ./convert not found. Please run 'make' first."
    exit 1
fi

# Loop through and run each test
for t in "${TESTS[@]}"; do
    echo -e "\n========================================"
    echo "TESTING: ./convert \"$t\""
    echo "========================================"
    ./convert "$t"
done