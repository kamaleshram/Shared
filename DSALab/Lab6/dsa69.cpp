#include <iostream>
#include <stack>
#include <string>

using namespace std;

string simplifyPath(string path) {
  stack<string> st;
  int n = path.length();
  int i = 0;
  while (i < n) {
    // Ignore any leading slashes
    while (i < n && path[i] == '/')
      i++;
    // Extract the directory name
    string dir = "";
    while (i < n && path[i] != '/')
      dir += path[i++];
    // Process the directory name
    if (dir == "..") {
      if (!st.empty())
        st.pop();
    } else if (dir != "." && dir != "") {
      st.push(dir);
    }
  }
  // Construct the simplified path
  string res = "";
  while (!st.empty()) {
    res = "/" + st.top() + res;
    st.pop();
  }
  // Check if path is empty and return "/"
  if (res == "")
    res = "/";
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << simplifyPath(s) << endl; // Output: /c
  return 0;
}
