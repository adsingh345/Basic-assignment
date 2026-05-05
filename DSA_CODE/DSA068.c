class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        // Initialize in-degree for all unique characters
        for (const string& word : words) {
            for (char c : word) {
                if (inDegree.find(c) == inDegree.end()) inDegree[c] = 0;
            }
        }

        // Build the graph
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, len) == w2) return "";

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break; 
                }
            }
        }

        // Kahn's Algorithm
        queue<char> q;
        for (auto const& [character, count] : inDegree) {
            if (count == 0) q.push(character);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return (result.length() == inDegree.size()) ? result : "";
    }
};
