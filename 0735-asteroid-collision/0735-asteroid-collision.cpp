class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> astStack;
        astStack.reserve(asteroids.size());
        for (int a : asteroids) {
            if (a > 0) astStack.emplace_back(a);
            else {
                bool isDestroyed = false;
                while (!astStack.empty() && !isDestroyed && astStack.back() > 0) {
                    int tmp = astStack.back();
                    if (tmp <= -a) astStack.pop_back();
                    if (tmp >= -a) isDestroyed = true;
                }
                if (!isDestroyed) astStack.emplace_back(a);
            }
        }
        return move(astStack);
    }
};