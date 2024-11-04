class Solution {
public:
    long long newPeople(int day, vector<long long> &N){
        if (day < 0){
            return 0;
        }
        else{
            return N[day];
        }
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        
        // H -> Number of people who know secret
        // N -> Number of new people at day 'i'
        // S -> Number of people who can share secret
        vector<long long> H(5e5, 0);
        vector<long long> N(5e5, 0);
        vector<long long> S(5e5, 0);

        H[1] = 1;
        N[1] = 1;

        for (int i = 2; i <= n ; i++){
            S[i] = (S[i - 1] - newPeople(i - forget, N) + mod) % (mod) + newPeople(i - delay, N);
            S[i] %= (mod);

            H[i] = (H[i - 1] - newPeople(i - forget, N) + mod) % (mod) + S[i];
            H[i] %= (mod);

            N[i] = S[i];
            N[i] %= (mod);
        }

        return H[n];
    }
};