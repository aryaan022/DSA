class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int> chosen;
        int last1 = -1, last2 = -1;

        for (auto &it : intervals) {
            int start = it[0], end = it[1];

            bool hasLast1 = (last1 >= start && last1 <= end);
            bool hasLast2 = (last2 >= start && last2 <= end);

            // Case 1: No point inside → add 2 new points
            if (!hasLast1 && !hasLast2) {
                last2 = end - 1;
                last1 = end;
                chosen.push_back(last2);
                chosen.push_back(last1);
            }
            // Case 2: Only last1 is inside → add 1 more
            else if (!hasLast1 || !hasLast2) {
                int newPoint = end;
                if (last1 == last2) newPoint = end;
                else if (hasLast1) newPoint = end;
                else newPoint = end;

                last2 = last1;
                last1 = newPoint;

                chosen.push_back(newPoint);
            }
        }

        return chosen.size();
    }
};
