#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<tuple<int, int, int>> sortedEvents;
        
        for(int i = 0; i < events.size(); ++i) {
            int ts = stoi(events[i][1]);
            int type = (events[i][0] == "OFFLINE") ? 0 : 1;
            sortedEvents.push_back({ts, type, i});
        }
        
        // Sort by timestamp asc, then by type asc
        sort(sortedEvents.begin(), sortedEvents.end());
        
        vector<int> mentions(numberOfUsers, 0);
        vector<int> onlineUntil(numberOfUsers, 0); // Stores the time user comes back online
        
        for(const auto& ev : sortedEvents) {
            int ts = get<0>(ev);
            int type = get<1>(ev);
            int idx = get<2>(ev);
            const string& content = events[idx][2];
            
            if(type == 0) { // OFFLINE event
                int userId = stoi(content);
                // User is offline for 60 units, back at ts + 60
                onlineUntil[userId] = ts + 60;
            } else { // MESSAGE event
                if(content == "ALL") {
                    for(int i = 0; i < numberOfUsers; ++i) {
                        mentions[i]++;
                    }
                } else if(content == "HERE") {
                    for(int i = 0; i < numberOfUsers; ++i) {
                        // User is online if current timestamp >= time they are back online
                        // or if they never went offline (onlineUntil is 0)
                        if(ts >= onlineUntil[i]) {
                            mentions[i]++;
                        }
                    }
                } else {
                    // Specific IDs string, e.g., "id0 id1 id0"
                    stringstream ss(content);
                    string token;
                    while(ss >> token) {
                        // token is like "id123", substr(2) skips "id" to get "123"
                        int userId = stoi(token.substr(2));
                        mentions[userId]++;
                    }
                }
            }
        }
        
        return mentions;
    }
};