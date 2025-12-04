class Solution:
    def countCollisions(self, directions: str) -> int:
        directions = directions.lstrip("L").rstrip("R") # 左侧的L和右侧的R不会发生碰撞
        ans = len(directions) - directions.count("S")
        return ans
