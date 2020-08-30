//
// Created by Chunbin lin on 8/29/20.
//

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {

private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(Robot &robot, int x, int y, int dir, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(to_string(x) + "-" + to_string(y));
        //search
        for (int i = 0; i < dirs.size(); i++) {
            int cur = (i + dir) % 4, dx = x + dirs[cur][0], dy = y + dirs[cur][1];
            if (!visited.count(to_string(dx) + "-" + to_string(dy)) && robot.move()) {
                //continue
                dfs(robot, dx, dy, cur, visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight(); //change direction
        }
    }
public:
    void cleanRoom(Robot& robot) {

        unordered_set<string> visited;
        dfs(robot, 0, 0, 0, visited);


    }
};




