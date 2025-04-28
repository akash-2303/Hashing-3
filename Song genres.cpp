// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code run on Leetcode platform: Yes

// Approach:
// 1. Create a map to store the song and its genre.
// 2. Create a map to store the user and their favorite genres.
// 3. Iterate through the user map and for each song, check its genre in the song map.
// 4. Count the number of songs in each genre for each user.
// 5. Find the maximum count of songs in a genre for each user and store the genres with that count in the result map.
// 6. Return the result map.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Function to implement
unordered_map<string, vector<string>> favoritegenre(unordered_map<string, vector<string>>& userMap, unordered_map<string, vector<string>>& genreMap) {
    unordered_map<string, string> songMap;
    for(auto &entry : genreMap){
        string genre = entry.first;
        for(string &song : entry.second){
            songMap[song] = genre;
        }
    }
    unordered_map<string, vector<string>> result;
    for(auto &user : userMap){
        unordered_map<string, int> genreCount;
        int maxCount = 0;
        for(string& song : user.second){
            if(songMap.count(song)){
                string genre = songMap[song];
                genreCount[genre]++;
                maxCount = max(maxCount, genreCount[genre]);
            }
        }
        for (auto& entry : genreCount) {
            if(entry.second == maxCount){
                result[user.first].push_back(entry.first);
            }
        }
    }
    return result;
}

int main() {
    unordered_map<string, vector<string>> userSongs;
    userSongs["David"] = {"song1", "song2", "song3", "song4", "song8"};
    userSongs["Emma"] = {"song5", "song6", "song7"};

    unordered_map<string, vector<string>> songGenres;
    songGenres["Rock"] = {"song1", "song3"};
    songGenres["Dubstep"] = {"song7"};
    songGenres["Techno"] = {"song2", "song4"};
    songGenres["Pop"] = {"song5", "song6"};
    songGenres["Jazz"] = {"song8", "song9"};

    unordered_map<string, vector<string>> res = favoritegenre(userSongs, songGenres);

    // Printing result
    for (auto& [user, genres] : res) {
        cout << user << ": ";
        for (string& genre : genres) {
            cout << genre << " ";
        }
        cout << endl;
    }

    return 0;
}
