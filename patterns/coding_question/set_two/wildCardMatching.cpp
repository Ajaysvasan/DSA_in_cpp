#include <iostream>
#include <string>

using namespace std;

bool matchFrom(const string &text, const string &pattern, int start,
               int &endPos) {

  int i = start;
  int j = 0;

  while (j < pattern.size()) {

    char ch = pattern[j];

    // Character followed by *
    if (j + 1 < pattern.size() && pattern[j + 1] == '*') {

      while (i < text.size() && text[i] == ch)
        i++;

      j += 2;
    }

    // Character followed by +
    else if (j + 1 < pattern.size() && pattern[j + 1] == '+') {

      if (i >= text.size() || text[i] != ch)
        return false;

      while (i < text.size() && text[i] == ch)
        i++;

      j += 2;
    }

    // Normal character
    else {

      if (i >= text.size() || text[i] != ch)
        return false;

      i++;
      j++;
    }
  }

  endPos = i;
  return true;
}

int main() {

  string text, pattern;

  cin >> text >> pattern;

  for (int start = 0; start < text.size(); start++) {

    int endPos;

    if (matchFrom(text, pattern, start, endPos)) {

      cout << text.substr(start, endPos - start);
      return 0;
    }
  }

  cout << "No Match";
}
