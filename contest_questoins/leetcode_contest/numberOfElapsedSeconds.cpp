#include <bits/stdc++.h>
using namespace std;

class Solution {
  int convert(vector<string> time) {
    int hour = stoi(time[0]) * 3600;
    int min = stoi(time[1]) * 60;
    int seconds = stoi(time[2]);
    return hour + min + seconds;
  }
  vector<string> split(string time) {
    string temp = "";
    vector<string> res;
    for (int i = 0; i < time.size(); i++) {
      if (time[i] == ':') {
        res.push_back(temp);
        temp = "";
      } else {
        temp += time[i];
      }
    }
    res.push_back(temp);
    return res;
  }

public:
  int secondsBetweenTimes(string startTime, string endTime) {
    int start = convert(split(startTime));
    int end = convert(split(endTime));
    return end - start;
  }
};
