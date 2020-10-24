#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/add-strings/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int maxPower(string &s) {
    int arr[123] = {0};
    int mx = 1;
    arr[s[0]]++;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1]) {
        arr[s[i]]++;
        mx = max(mx, arr[s[i]]);
      } else {
        arr[s[i - 1]] = 0;
        arr[s[i]] = 1;
      }
    }
    return mx;
  }
};

void test1() { // test
  string s = "leetcode";
  cout << "2 ? " << Solution().maxPower(s) << endl;
  s = "abbcccddddeeeeedcba";
  cout << "5 ? " << Solution().maxPower(s) << endl;
  s = "triplepillooooow";
  cout << "5 ? " << Solution().maxPower(s) << endl;
  s = "hooraaaaaaaaaaay";
  cout << "11 ? " << Solution().maxPower(s) << endl;
  s = "tourist";
  cout << "1 ? " << Solution().maxPower(s) << endl;
}

void test2() {}

void test3() {}