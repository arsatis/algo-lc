### Attempt 1:
* Idea: sliding window, use hashset to store characters in string.
* Time: O(n), two passes (left and right pointers).
* Space: O(1), size of hashset will not exceed 256.

### Attempt 2:
* Idea: sliding window, initialize array of 256 whose values indicate position where character was last seen.
* Time: O(n), single pass.
* Space: O(1), size of array is constant at 256.
