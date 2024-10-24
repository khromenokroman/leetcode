/*
 1041. Robot Bounded In Circle
Medium
Topics
Companies
Hint
On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

The north direction is the positive direction of the y-axis.
The south direction is the negative direction of the y-axis.
The east direction is the positive direction of the x-axis.
The west direction is the negative direction of the x-axis.
The robot can receive one of three instructions:

"G": go straight 1 unit.
"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
"R": turn 90 degrees to the right (i.e., clockwise direction).
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.



Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
Based on that, we return false.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
"G": move one step. Position: (-1, 1). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
"G": move one step. Position: (-1, 0). Direction: South.
"L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
"G": move one step. Position: (0, 0). Direction: East.
"L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
Based on that, we return true.


Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

struct Point {
    int x = 0;
    int y = 0;
    bool operator==(Point const& other) const { return x == other.x && y == other.y; }
};
struct Robot {
    Point point{0, 0};
    int north = 1; // север
    int west = 0;  // запад
    int east = 0;  // восток
    int south = 0; // юг
    [[nodiscard]] bool is_changed_direction() const { return north != 1; }
    [[nodiscard]] bool is_start_point() const { return point == Point{0, 0}; }
    void step() {
        if (north) {
            point.y += 1;
        }
        if (west) {
            point.x -= 1;
        }
        if (east) {
            point.x += 1;
        }
        if (south) {
            point.y -= 1;
        }
    }
    void set_direction(char instruction) {
        if (instruction == 'L' && north) {
            north = 0;
            west = 1;
        } else if (instruction == 'L' && west) {
            west = 0;
            south = 1;
        } else if (instruction == 'L' && south) {
            south = 0;
            east = 1;
        } else if (instruction == 'L' && east) {
            east = 0;
            north = 1;
        }

        if (instruction == 'R' && north) {
            north = 0;
            east = 1;
        } else if (instruction == 'R' && east) {
            east = 0;
            south = 1;
        } else if (instruction == 'R' && south) {
            south = 0;
            west = 1;
        } else if (instruction == 'R' && west) {
            west = 0;
            north = 1;
        }
    }
    void move(char instruction) {
        switch (instruction) {
            case 'G':
                step();
                break;
            case 'L':
                set_direction(instruction);
                break;
            case 'R':
                set_direction(instruction);
                break;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot) {
        return os << "Robot at (" << robot.point.x << ", " << robot.point.y << ") " << "north: " << robot.north
                  << " south: " << robot.south << " west: " << robot.west << " east: " << robot.east;
    }
};

class Solution {
   public:
    bool isRobotBounded(std::string instructions) {
        Robot robot{};
        for (auto i = 0; i < instructions.size(); i++) {
            robot.move(instructions[i]);
            std::cout << "command: " << instructions[i] << std::endl;
            std::cout << robot << std::endl;
        }
        return robot.is_start_point() || robot.is_changed_direction();
    }
};

int main() {
    std::string data{"GGLLGG"};
    //        std::string data{"GG"};
    //        std::string data{"GL"};
    Solution sol;
    std::cout << sol.isRobotBounded(data) << std::endl;
    return 0;
}