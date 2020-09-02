//
// Created by Chunbin lin on 9/1/20.
//

//DFS

class Solution {
private:
    unordered_map<string, unordered_set<string>> graph_; // node, neighbors
    unordered_map<string, string> name_; // email, usernames
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //build graph
        for (vector<string>& account : accounts) {
            string userName = account.front();
            for (int i = 1; i < account.size(); i++) {
                name_[account[i]] = userName;
                if (i == 1) continue;
                // build graph
                graph_[account[i]].insert(account[i-1]);
                graph_[account[i-1]].insert(account[i]);
            }

        }

        unordered_set<string> visited;
        vector<vector<string>> ans;

        //dfs
        for (auto s : name_) {
            deque<string> currList;
            if (!visited.count(s.first)) {
                visited.insert(s.first);
                dfs(s.first, visited, currList);
                sort(currList.begin(), currList.end());
                currList.push_front(s.second);
                ans.push_back(vector<string>(currList.begin(), currList.end()));
            }
        }
        return ans;
    }
private:
    void dfs(string email, unordered_set<string>& visited, deque<string>& currList) {

        currList.push_back(email);
        for (string neighbor : graph_[email]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                dfs(neighbor, visited, currList);
            }
        }
    }
};