//
// Created by Chunbin lin on 5/29/20.
//

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map; // content : vector of file path

        for (const string &path : paths) {
            //we parse path
            vector<string> files;
            istringstream ss(path);
            do {
                string word;
                ss >> word;
                files.push_back(word);
            } while (ss);
            //we know files[0] contain root info
            for (int i = 1; i < files.size(); i++) {
                string file = files[i];
                string fileName = "";
                string content = "";
                bool contentFound = false;
                for (const char &c : file) {
                    if (contentFound) {
                        if (c != ')') {
                            content.push_back(c);
                        }
                    } else {
                        if (c == '(') {
                            contentFound = true;
                        } else {
                            fileName.push_back(c);

                        }
                    }
                }

                fileName = files[0] + '/' + fileName;
                if (content != "") {
                    map[content].push_back(fileName);
                }
            }
        }
        vector<vector<string>> result;

        for (auto it : map) {
            cout << it.first << endl;
            if (it.second.size() > 1) {
                result.push_back(it.second);
            }
        }
        return result;

    }
};