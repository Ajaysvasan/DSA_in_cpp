#include <iostream>
#include <string>
#include <vector>
using namespace std;

// given string = "1123"
// 1 - > a , 11 -> k , 2 -> b , 3 - > c , 23 -> w
//
// a - > 1 , b - > 2 , c -> 3 , .... , z -> 26
// str[0] != 0 if 0 invalid
// size is less than or equals 2 for a alphabet
// 1 ,  2 start , 6 end
//
// f(str , idx){
//      if(str[0] == 0){
//      return 0;
//      }
//      if(idx == str.size()){
//      return 1;
//      }
//      count = 0;
//      count += f(str , idx + 1)
//          if(i + 1 < str.size() && str[i] == '1' || str[i] == '2' && str[i] <=
//          '6'){
//              count += f(str , i + 2);
//          }
//      }
// }
//
//    5
//    /\
//    4 3
//    /\ /\ 
//    3 2 2 1
//    /\ /\ /\
//    2 1 1 0 1 0
//    /\
//    1 0
// 2 ^ n
int helper(string &str, int idx, vector<int> &dp) {
  if (idx == str.size())
    return 1;
  if (str[idx] == '0')
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int count = helper(str, idx + 1, dp);
  if (idx + 1 < str.size() && str[idx] == '1' ||
      (str[idx] == '2' && str[idx + 1] <= '6')) {
    count += helper(str, idx + 2, dp);
  }
  return dp[idx] = count;
}

int main(int argc, char *argv[]) {
  string str;
  cin >> str;
  vector<int> dp(str.size() + 1, -1);
  cout << helper(str, 0, dp);
  return 0;
}
