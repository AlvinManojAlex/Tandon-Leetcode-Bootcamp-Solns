class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        // Storing the words without spaces
        for (int i = 0 ; i < s.length() ; i++){
            if (s[i] == ' ' && temp == ""){
                continue;
            }

            else if (s[i] == ' '){
                words.push_back(temp);
                temp = "";
            }

            else {
                temp += s[i];
            }
        }

        // last word if it exists
        if (temp != ""){
            words.push_back(temp);
        }

        string ans = "";

        // Generating the answer from the words array
        for (int i = words.size() - 1; i >= 0 ; i--){
            if (i == 0){
                ans += words[i];
            }
            else {
                ans += words[i] + " ";
            }
        }

        return ans;
    }
};