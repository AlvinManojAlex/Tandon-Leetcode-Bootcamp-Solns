class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        pair<int, int> temp;

        for (int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    temp.first = i;
                    temp.second = j;
                    zeroes.push_back(temp);
                }
            }
        }

        for (auto x : zeroes){
            for(int i = 0 ; i < matrix.size() ; i++){
                matrix[i][x.second] = 0;
            }

            for(int j = 0 ; j < matrix[0].size(); j++){
                matrix[x.first][j] = 0;
            }
        }
        
        
    }
};