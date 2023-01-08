class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long hp = 1, aHp = 0;
        for (int x : damage) {
            if (aHp == armor || aHp >= x) hp += x;
            else if (x <= armor) hp += aHp, aHp = x;
            else hp += aHp + x - armor, aHp = armor;
        }
        return hp;
    }
};
