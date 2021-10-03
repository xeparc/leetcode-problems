# #############################################################################
# 
# 1041. Robot Bounded In Circle
# https://leetcode.com/problems/robot-bounded-in-circle/
# 
# #############################################################################

# On an infinite plane, a robot initially stands at (0, 0) and faces north.
# The robot can receive one of three instructions:

# "G": go straight 1 unit;
# "L": turn 90 degrees to the left;
# "R": turn 90 degress to the right.
# The robot performs the instructions given in order, and repeats them forever.

# Return true if and only if there exists a circle in the
# plane such that the robot never leaves the circle.


# Example 1:
# Input: "GGLLGG"
# Output: true
# Explanation: 
# The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
# When repeating these instructions, the robot remains in the circle of radius
# 2 centered at the origin.


# Example 2:
# Input: "GG"
# Output: false
# Explanation: 
# The robot moves north indefinitely.


# Example 3:
# Input: "GL"
# Output: true
# Explanation: 
# The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

# Note:
# 1 <= instructions.length <= 100
# instructions[i] is in {'G', 'L', 'R'}



class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        position = [0, 0]
        rotation = 0
        for i in instructions:
            if i == 'G':
                moveRobot(position, rotation)
            elif i == 'L':
                rotation = (rotation + 90) % 360
            else:
                rotation = (rotation - 90) % 360
        return position == [0, 0] or rotation

                
def moveRobot(pos, rot):
    if rot == 0:
        pos[1] += 1
    elif rot == 90:
        pos[0] += 1
    elif rot == 270:
        pos[0] -= 1
    else:
        pos[1] -= 1
