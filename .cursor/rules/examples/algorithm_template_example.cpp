/**
 * Algorithm: Binary Search
 * Category: Searching
 *
 * Description:
 * An efficient search algorithm that finds the position of a target value
 * within a sorted array. Binary search compares the target value to the middle
 * element of the array. If they are not equal, the half in which the target cannot
 * lie is eliminated and the search continues on the remaining half, again taking
 * the middle element to compare to the target value, and repeating until the target
 * value is found or the array is exhausted.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * Parameters:
 * - arr: A sorted array of elements
 * - target: The value to search for in the array
 * - left: The starting index of the search range (optional)
 * - right: The ending index of the search range (optional)
 *
 * Returns:
 * - The index of the target if found, otherwise -1
 *
 * Example Usage:
 * vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 * int target = 7;
 * int result = binarySearch(nums, target);  // Returns 6
 *
 * Variants:
 * - Lower bound: Find the first element >= target
 * - Upper bound: Find the first element > target
 * - Closest element: Find the element closest to target
 *
 * References:
 * - Introduction to Algorithms (CLRS), Chapter 2.3
 * - https://en.wikipedia.org/wiki/Binary_search_algorithm
 *
 * Related Problems:
 * - LeetCode 704: Binary Search
 * - LeetCode 35: Search Insert Position
 * - LeetCode 33: Search in Rotated Sorted Array
 */

#include <vector>

template <typename T>
int binarySearch(const std::vector<T> &arr, const T &target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        // Calculate middle index (avoiding potential overflow)
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
        {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else
        {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

// Lower bound variant: finds the first element >= target
template <typename T>
int lowerBound(const std::vector<T> &arr, const T &target)
{
    int left = 0;
    int right = arr.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // If left == arr.size(), target is greater than all elements
    return (left < arr.size()) ? left : -1;
}

// Upper bound variant: finds the first element > target
template <typename T>
int upperBound(const std::vector<T> &arr, const T &target)
{
    int left = 0;
    int right = arr.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // If left == arr.size(), all elements are <= target
    return (left < arr.size()) ? left : -1;
}

// Usage example
void usage_example()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Basic binary search
    int target = 7;
    int result = binarySearch(nums, target); // Returns 6

    // Lower bound example
    int lb = lowerBound(nums, 7); // Returns 6

    // Upper bound example
    int ub = upperBound(nums, 7); // Returns 7
}

// Test cases
void test_cases()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Test binary search
    assert(binarySearch(nums, 1) == 0);   // First element
    assert(binarySearch(nums, 10) == 9);  // Last element
    assert(binarySearch(nums, 5) == 4);   // Middle element
    assert(binarySearch(nums, 11) == -1); // Not found, greater than all
    assert(binarySearch(nums, 0) == -1);  // Not found, smaller than all

    // Test lower bound
    assert(lowerBound(nums, 0) == 0);   // Smaller than all
    assert(lowerBound(nums, 5) == 4);   // Existing element
    assert(lowerBound(nums, 6.5) == 6); // Between elements

    // Test upper bound
    assert(upperBound(nums, 5) == 5);   // Existing element
    assert(upperBound(nums, 10) == -1); // Larger than all
    assert(upperBound(nums, 6.5) == 6); // Between elements
}