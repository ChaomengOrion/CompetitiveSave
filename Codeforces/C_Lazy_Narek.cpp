#include <bits/stdc++.h>
using namespace std;

// Function to process a string starting from state 's'
pair<int, int> process_string(int s, const string &S, const string &target) {
    int k = 0;
    for(char c : S){
        if(c == target[s]){
            s++;
            if(s == 5){
                k++;
                s = 0;
            }
        }
    }
    return {k, s};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string target = "narek";
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> strings(n);
        // Read all strings and precompute C_S and transitions
        struct StringInfo {
            int C_S;
            pair<int, int> transitions[5]; // transitions[s] = {added_k, new_s}
        };
        vector<StringInfo> info(n);
        for(int i=0; i<n; i++){
            cin >> strings[i];
            // Count C_S
            int count_CS =0;
            for(char c : strings[i]){
                if(c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') count_CS++;
            }
            info[i].C_S = count_CS;
            // Compute transitions for each starting state
            for(int s=0; s<5; s++){
                info[i].transitions[s] = process_string(s, strings[i], target);
            }
        }
        // Initialize DP
        // dp[s][k] = minimal C_S to reach state s with k "narek" sequences
        // Since k can be up to (n * m)/5 <= 2000
        const int MAX_K = 2000;
        // Initialize with INF
        const int INF = 1e9;
        vector<vector<int>> dp_prev(5, vector<int>(1, 0)); // Initially only dp[0][0] =0
        // To handle variable k, we'll use dynamic sizing
        // We'll use separate vectors for each state
        // Initialize DP for first string
        // Start with dp_prev[s][k]
        // We'll use a vector of 5 vectors
        // Initialize all to INF
        // Set dp_prev[0][0] =0
        // For other states and k, set to INF
        // For each string, update dp_prev to dp_new
        // To save space and time, use vectors that grow as needed
        // Initialize dp_prev
        vector< vector<int> > dp(5, vector<int>());
        dp[0].push_back(0); // dp[0][0] =0
        // To keep track of k for each state
        // We will store for each state, a vector where index represents k and value represents C_S
        for(int i=0; i<n; i++){
            // Create a new DP for this step
            vector< vector<int> > dp_new(5, vector<int>());
            // Initialize all entries to INF
            // But we'll build them incrementally
            for(int s=0; s<5; s++){
                for(int idx=0; idx<dp[s].size(); idx++){
                    int k = idx;
                    int C_S = dp[s][idx];
                    // Option1: skip the string
                    // Update dp_new[s][k] with min C_S
                    if(k < dp_new[s].size()){
                        dp_new[s][k] = min(dp_new[s][k], C_S);
                    }
                    else{
                        // Fill with INF up to k
                        while(dp_new[s].size() < k){
                            dp_new[s].push_back(INF);
                        }
                        dp_new[s].push_back(C_S);
                    }
                    // Option2: include the string
                    pair<int, int> trans = info[i].transitions[s];
                    int added_k = trans.first;
                    int new_s = trans.second;
                    int new_k = k + added_k;
                    int new_C_S = C_S + info[i].C_S;
                    // Update dp_new[new_s][new_k]
                    if(new_k < dp_new[new_s].size()){
                        dp_new[new_s][new_k] = min(dp_new[new_s][new_k], new_C_S);
                    }
                    else{
                        // Fill with INF up to new_k
                        while(dp_new[new_s].size() < new_k){
                            dp_new[new_s].push_back(INF);
                        }
                        dp_new[new_s].push_back(new_C_S);
                    }
                }
            }
            // After processing the string, set dp = dp_new
            dp = move(dp_new);
        }
        // Now, iterate through all possible states and k to find the maximum 10*k -C_S
        int max_val = 0;
        for(int s=0; s<5; s++){
            for(int k=0; k<dp[s].size(); k++){
                int C_S = dp[s][k];
                // scoren - scorec =10*k - C_S
                int val = 10 * k - C_S;
                if(val > max_val){
                    max_val = val;
                }
            }
        }
        cout << max_val << "\n";
    }
}