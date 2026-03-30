#!/bin/bash
set -e

echo "========================================="
echo "C++ Compile Check"
echo "========================================="

# Find all C++ files
CPP_FILES=$(find . -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" \) \
    -not -path "./.git/*" \
    -not -path "./.github/*" \
    -not -path "./bits/*" \
    -not -path "./.cursor/*" \
    -not -path "./.cache/*" | head -100)

if [ -z "$CPP_FILES" ]; then
    echo "No C++ files found to check."
    exit 0
fi

echo "Found $(echo "$CPP_FILES" | wc -l) C++ files (checking first 100)"
echo ""

FAILED=0
PASSED=0

for FILE in $CPP_FILES; do
    echo -n "Checking $FILE ... "

    # Try to compile with syntax check only
    if g++ -std=gnu++20 -fsyntax-only -Wall -Wextra -I. "$FILE" 2>/dev/null; then
        echo "PASS"
        PASSED=$((PASSED + 1))
    else
        echo "FAIL"
        echo "  Compile error details:"
        g++ -std=gnu++20 -fsyntax-only -Wall -Wextra -I. "$FILE" 2>&1 | sed 's/^/  /'
        FAILED=$((FAILED + 1))
    fi
done

echo ""
echo "========================================="
echo "Results: $PASSED passed, $FAILED failed"
echo "========================================="

if [ $FAILED -gt 0 ]; then
    exit 1
else
    exit 0
fi
