/*Problem pascals triangle
 * Difficulty medium
 *
 * Given an integer numRows , return the first numRows of a Pascal's Triangle
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it Input:  numRows = 5 Output: [[1] , [1,1] , [1,2,1] , [1,3,3,1] ,
 * [1,4,6,4,1]]*/

#include <iostream>
#include <vector>

std::ostream operator<<(std::ostream &COUT,
                        std::vector<std::vector<int>> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[0].size(); i++) {
      COUT << nums[i][j] << " ";
    }
    COUT << "\n";
  }
  return COUT;
}

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {}
};

int main() {
  int numRows = 5;
  std::vector<std::vector<int>> pascalTriangle = generate(numRows);
  std::cout << pascalTriangle;
  return 0;
}
