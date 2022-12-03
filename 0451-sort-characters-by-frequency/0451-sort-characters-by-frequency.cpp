class Solution {
public:
    string frequencySort(string& s) {
        int counter[128] = {};
        for (char c : s) ++counter[c];

        string output = "";
        while (output.size() < s.size()) {
            char c = max_element(counter, counter + 128) - counter;
            while (counter[c]--) output += c;
        }
        return output;
    }
};
