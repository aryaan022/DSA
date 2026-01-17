class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long bestSide = 0;

        for (int a = 0; a < n; a++) {
            int leftA = bottomLeft[a][0];
            int bottomA = bottomLeft[a][1];
            int rightA = topRight[a][0];
            int topA = topRight[a][1];

            if (rightA - leftA <= bestSide || topA - bottomA <= bestSide)
                continue;

            for (int b = a + 1; b < n; b++) {
                int leftB = bottomLeft[b][0];
                int bottomB = bottomLeft[b][1];
                int rightB = topRight[b][0];
                int topB = topRight[b][1];

                int overlapLeft = max(leftA, leftB);
                int overlapBottom = max(bottomA, bottomB);
                int overlapRight = min(rightA, rightB);
                int overlapTop = min(topA, topB);

                if (overlapLeft < overlapRight && overlapBottom < overlapTop) {
                    long long width = overlapRight - overlapLeft;
                    long long height = overlapTop - overlapBottom;
                    long long side = min(width, height);
                    bestSide = max(bestSide, side);
                }
            }
        }
        return bestSide * bestSide;
    }
};