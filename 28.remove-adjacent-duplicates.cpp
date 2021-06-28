class Solution {
public:
    string removeDuplicates(string s) {
    int len = s.length();
        string res="";
        if(len==1 or len==0) return s;
    stack<char> st;
    for(const char& c : s){
        if(st.empty() or st.top()!=c) st.push(c);
        else st.pop();
    }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
