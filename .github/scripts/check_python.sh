#!/bin/bash
# set -e  # Don't exit on error - this is informational only

echo "========================================="
echo "Python Syntax Check"
echo "========================================="

# Find all Python files
PY_FILES=$(find . -type f -name "*.py" \
    -not -path "./.git/*" \
    -not -path "./.github/*" \
    -not -path "./.cursor/*" \
    -not -path "./.cache/*" | head -100)

if [ -z "$PY_FILES" ]; then
    echo "No Python files found to check."
    exit 0
fi

echo "Found $(echo "$PY_FILES" | wc -l) Python files (checking first 100)"
echo ""

FAILED=0
PASSED=0

for FILE in $PY_FILES; do
    echo -n "Checking $FILE ... "

    # Check syntax without executing
    if python3 -m py_compile "$FILE" 2>/dev/null; then
        echo "PASS"
        PASSED=$((PASSED + 1))
    else
        echo "FAIL"
        echo "  Syntax error details:"
        python3 -m py_compile "$FILE" 2>&1 | sed 's/^/  /'
        FAILED=$((FAILED + 1))
    fi
done

# Clean up pycache
find . -name "__pycache__" -type d -prune -exec rm -rf {} + 2>/dev/null || true
find . -name "*.pyc" -delete 2>/dev/null || true

echo ""
echo "========================================="
echo "Results: $PASSED passed, $FAILED failed"
echo "========================================="
echo ""
echo "Note: This check is informational only."
echo "Even if some files fail, the workflow will continue."

# Always exit successfully - this is just an informational check
exit 0
