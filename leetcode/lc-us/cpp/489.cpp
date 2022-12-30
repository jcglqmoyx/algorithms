#include <cstring>

using namespace std;

class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();

    void turnRight();

    // Clean the current cell.
    void clean();
};

class Solution {
    bool visited[405][205]{};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(Robot &robot, int x, int y, int d) {
        visited[x][y] = true;
        robot.clean();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[(i + d) % 4];
            int ny = y + dy[(i + d) % 4];
            if (!visited[nx][ny] && robot.move()) {
                dfs(robot, nx, ny, (i + d) % 4);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
        }
    }

public:
    void cleanRoom(Robot &robot) {
        memset(visited, false, sizeof visited);
        dfs(robot, 201, 101, 0);
    }
};