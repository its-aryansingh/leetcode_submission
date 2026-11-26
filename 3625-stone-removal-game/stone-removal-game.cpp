class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool aliceWins = false;

        while (n >= stonesToRemove && stonesToRemove > 0) {
            n -= stonesToRemove;
            stonesToRemove--;
            aliceWins = !aliceWins;
        }

        return aliceWins;
    }
};
