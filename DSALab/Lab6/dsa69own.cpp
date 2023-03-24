#include <iostream>
#include <stack>
#include <string>

using namespace std;

string simplifyPath(string path) {
  stack <string> st;
  int n = path.length(), i = 0;
  string spath = "";
  while (i < n) {
    while (i < n && path[i] == '/')
      i++;

    string dir = "";
    while (i < n && path[i] != '/')
      dir += path[i++];
    
    if (dir == "..") {
      if(!(st.empty()))
        st.pop();
    } else if (dir != "." && dir != "")
      st.push(dir);
  }
  
  while(!(st.empty())) {
    spath = "/" + st.top() + spath;
    st.pop();
  }

  if (spath == "")
    spath += "/";

  return spath;
}


int main() {
  string s, path;
  cin >> s;

  path = simplifyPath(s);
  cout << path;
}