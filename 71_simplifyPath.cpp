class Solution {
public:
  string simplifyPath(string path) {
    std::stack<std::string> parts;
    int pos = 0;
    while (pos < path.size()) {
      std::string p = part(path, pos);
      if (p == "." || p == "")
        continue;
      if ((p == "..")) {
        if (!parts.empty())
          parts.pop();
      } else
        parts.push(p);
    }
    // parts {a,b,c}
    std::string simplified;
    bool first = true;
    while (!parts.empty()) {
      if (first) {
        simplified = parts.top();
        first = false;
      } else {
        simplified = parts.top() + "/" + simplified;
      }
      parts.pop();
    }

    simplified = "/" + simplified;

    return simplified;
  }

  string part(string &path, int &pos) {
    string p;
    while (pos < path.size() && path[pos] == '/')
      pos++;
    while (pos < path.size() && path[pos] != '/') {
      p += path[pos++];
    }
    return p;
  }
};
