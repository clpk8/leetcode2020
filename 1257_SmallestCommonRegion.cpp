//
// Created by Chunbin lin on 6/14/20.
//

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_set<string> seen;
        unordered_map<string, string> parent;

        for (int i = 0; i < regions.size(); i++) {
            for (int j = 1; j < regions[i].size(); j++) {
                //map children to parent
                parent[regions[i][j]] = regions[i][0];
            }
        }

        //now traverse region1, put all parents to the map
        while (parent.find(region1) != parent.end()) {
            seen.insert(region1);
            region1 = parent[region1];
        }


        while (seen.find(region2) == seen.end() && region1 != region2) {
            region2 = parent[region2];
        }

        return region2;


    }
};