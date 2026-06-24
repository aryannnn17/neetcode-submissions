class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                if (s == "+")
                    st.push(to_string(y + x));
                else if (s == "-")
                    st.push(to_string(y - x));
                else if (s == "*")
                    st.push(to_string(y * x));
                else if (s == "/")
                    st.push(to_string(y / x));
            } else
                st.push(s);
        }
        return stoi(st.top());
    }
};
