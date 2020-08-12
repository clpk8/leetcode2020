//
// Created by Chunbin lin on 8/10/20.
//

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> es;
        //build graph
        for (auto e : employees)
            es.emplace(e->id, e);

        return dfs(id, es);
    }

private:
    int dfs(int id, const unordered_map<int, Employee*>& es) {
        const auto e = es.at(id);
        int sum = e->importance;
        for (int rid : e->subordinates)
            sum += dfs(rid, es);
        return sum;
    }
};