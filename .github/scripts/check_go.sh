#!/bin/bash
# set -e  # Don't exit on error - this is informational only

echo "========================================="
echo "Go Build Check"
echo "========================================="

# Find all Go files
GO_FILES=$(find . -type f -name "*.go" \
    -not -path "./.git/*" \
    -not -path "./.github/*" \
    -not -path "./.cursor/*" \
    -not -path "./.cache/*")

if [ -z "$GO_FILES" ]; then
    echo "No Go files found to check."
    exit 0
fi

echo "Found $(echo "$GO_FILES" | wc -l) Go files"
echo ""

# Check each Go file individually
FAILED=0
PASSED=0

for FILE in $GO_FILES; do
    echo -n "Checking $FILE ... "

    # Create a temp directory for building
    TEMP_DIR=$(mktemp -d)
    cp "$FILE" "$TEMP_DIR/"
    BASENAME=$(basename "$FILE")

    # Try to build
    if (cd "$TEMP_DIR" && go build -o /dev/null "$BASENAME" 2>/dev/null); then
        echo "PASS"
        PASSED=$((PASSED + 1))
    else
        echo "FAIL"
        echo "  Build error details:"
        (cd "$TEMP_DIR" && go build -o /dev/null "$BASENAME" 2>&1) | sed 's/^/  /'
        FAILED=$((FAILED + 1))
    fi

    rm -rf "$TEMP_DIR"
done

echo ""
echo "========================================="
echo "Results: $PASSED passed, $FAILED failed"
echo "========================================="
echo ""
echo "Note: This check is informational only."
echo "Even if some files fail, the workflow will continue."

# Always exit successfully - this is just an informational check
exit 0
