class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build connected components
        for (auto& swapPair : allowedSwaps)
            unite(swapPair[0], swapPair[1]);

        // Group indices by component
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        int answer = 0;

        for (auto& [root, indices] : groups) {
            unordered_map<int, int> freq;

            // Count source values in this component
            for (int idx : indices)
                freq[source[idx]]++;

            // Match target values
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    answer++;
                }
            }
        }

        return answer;
    }
};
