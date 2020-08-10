class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int a : asteroids) {
            if (a > 0) {
                // a is going to the right
                s.push(a);
            } else {
                // a is going to the left
                if (s.empty() || s.top() < 0) {
                    // either empty stack for everything going left
                    s.push(a);
                    continue;
                }

                bool explode = false;
                //s is not empty and there is collision
                while (!s.empty() && s.top() <= abs(a) && s.top() > 0) {
                    if (s.top() < abs(a)) {
                        s.pop();
                    } else {
                        //equal
                        s.pop();
                        explode = true;
                        break;
                    }
                }
                if (!s.empty() && s.top() < 0 && !explode) {
                    s.push(a);
                } else if (s.empty() && !explode) {
                    s.push(a);
                }
            }
        }
        //Now stack->vector
        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

};