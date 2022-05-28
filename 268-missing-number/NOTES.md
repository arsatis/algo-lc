### Attempt 1:
* Idea: add numbers from 0 to n to hashset, iterate through nums and remove corresponding element from set, and return last element remaining in set.
* Time: O(n), two passes (initializing hashset and iterating through nums).
* Space: O(n), size of hashset.

### Attempt 2:
* Idea: compute sum of 0 to n and minus away each element in nums within the same loop.
* Time: O(n), single pass.
* Space: O(1).
