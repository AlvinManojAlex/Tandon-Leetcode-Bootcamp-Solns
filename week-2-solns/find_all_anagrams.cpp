class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> mp1, mp2;
        
        // Storing mapping of characters in pattern
        for (int i = 0 ; i < p.size() ; i++){
            mp2[p[i]] += 1;
        }

        // Storing mapping of characters in string with length = pattern's length => First window
        for (int i = 0 ; i < p.size() ; i++){
            mp1[s[i]] += 1;
        }

        int i = 0;
        int j = p.size();

        // Checking for remaining windows, if the mapping is same
        while(j < s.size()){
            if (mp1 == mp2){
                ans.push_back(i);
            }

            mp1[s[i]]--;
            mp1[s[j]]++;

            if (mp1[s[i]] == 0){
                mp1.erase(s[i]);
            }

            i++;
            j++;
        }

        // last window
        if (mp1 == mp2){
            ans.push_back(i);
        }

        return ans;   
    }
};