class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if (colors.length() == 1) {
            return 0;
        }

        int cost = 0;
        int n = neededTime.size();

        char currentColor = colors[0];
        int currentIndex = 0;
        int currentTime = neededTime[0];

        for (int i = 1; i < n; i++) {
            if (colors[i] == currentColor) {
                if (neededTime[i] > currentTime) {
                    cost += currentTime;
                    currentColor = colors[i];
                    currentIndex = i;
                    currentTime = neededTime[i];
                }
                else{
                    cost += neededTime[i];
                }
            } else {   
                currentColor = colors[i];
                currentIndex = i;
                currentTime = neededTime[i];
            }
        }

        return cost;
    }
};