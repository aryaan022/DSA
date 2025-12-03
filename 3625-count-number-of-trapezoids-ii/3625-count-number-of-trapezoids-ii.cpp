#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        struct Segment {
            long long lenSq;
        };

        map<pair<int, int>, map<long long, vector<Segment>>> slopeMap;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long dy = points[i][1] - points[j][1];
                long long dx = points[i][0] - points[j][0];
                long long lenSq = dx * dx + dy * dy;

                long long common = std::gcd(std::abs(dy), std::abs(dx));
                dy /= common;
                dx /= common;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                long long intercept = dy * points[i][0] - dx * points[i][1];
                slopeMap[{ (int)dy, (int)dx }][intercept].push_back({lenSq});
            }
        }

        long long totalTrapezoids = 0;
        long long parallelogramOvercounts = 0;

        for (auto& [slopeKey, linesMap] : slopeMap) {
            vector<vector<Segment>*> lines;
            lines.reserve(linesMap.size());
            for (auto& entry : linesMap) {
                lines.push_back(&entry.second);
            }

            for (int i = 0; i < lines.size(); ++i) {
                for (int j = i + 1; j < lines.size(); ++j) {
                    vector<Segment>& lineA = *lines[i];
                    vector<Segment>& lineB = *lines[j];

                    totalTrapezoids += (long long)lineA.size() * lineB.size();

                    vector<long long> lensA, lensB;
                    lensA.reserve(lineA.size());
                    lensB.reserve(lineB.size());
                    
                    for(const auto& s : lineA) lensA.push_back(s.lenSq);
                    for(const auto& s : lineB) lensB.push_back(s.lenSq);
                    
                    sort(lensA.begin(), lensA.end());
                    sort(lensB.begin(), lensB.end());

                    int p1 = 0, p2 = 0;
                    while (p1 < lensA.size() && p2 < lensB.size()) {
                        if (lensA[p1] < lensB[p2]) {
                            p1++;
                        } else if (lensA[p1] > lensB[p2]) {
                            p2++;
                        } else {
                            long long currentLen = lensA[p1];
                            long long c1 = 0, c2 = 0;
                            while (p1 < lensA.size() && lensA[p1] == currentLen) { c1++; p1++; }
                            while (p2 < lensB.size() && lensB[p2] == currentLen) { c2++; p2++; }
                            parallelogramOvercounts += c1 * c2;
                        }
                    }
                }
            }
        }

        return (int)(totalTrapezoids - (parallelogramOvercounts / 2));
    }
};