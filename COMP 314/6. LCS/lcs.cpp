/*
Date: Feb 28, 2019
Duration: ~20 minutes
*/


#include <iostream>
#include <string>

using namespace std;

int max(int x, int y) { return (x > y) ? x : y; }

int lcs(string a, string b, int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (a[i - 1] == b[j - 1]) return lcs (a, b, i - 1, j - 1) + 1;
  return max(lcs(a, b, i , j - 1), lcs(a, b, i - 1, j));
}

int main() {
  const string s1 = "adityathebe";
  const string s2 = "arsenalfootballclub";
  int lengthLCS = lcs(s1, s2, s1.size(), s2.size());
  cout << lengthLCS << endl;
}