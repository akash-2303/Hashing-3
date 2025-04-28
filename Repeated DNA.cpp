// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code run on Leetcode: Yes

//Approach: 
// 1. Create a set to store the DNA sequences of length 10.
// 2. Create a set to store the result sequences that are repeated.
// 3. Iterate through the string and check if the sequence of length 10 is already in the set.
// 4. If it is not in the set, add it to the set. If it is in the set, add it to the result set.
// 5. Finally, convert the result set to a vector and return it.

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            if(s.size() <= 10){return {};}
            unordered_set<string> dna;
            unordered_set<string> result_set;
            for(int i = 0; i < s.size() - 9; i++){
                string word = s.substr(i, 10);
                if(dna.find(word) == dna.end()){
                    dna.insert(word);               
                }else{
                    result_set.insert(word);
                }
                
            }
            vector<string> res(result_set.begin(), result_set.end());
            return res;
        }
    };