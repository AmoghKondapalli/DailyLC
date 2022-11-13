class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int start = 0;
        int end = 0;
        while((start = s.find_first_not_of(' ',end))!=string::npos){
            end = s.find_first_of(' ',start);
            st.push(s.substr(start,end-start));
        }
        string ans;
        while(!empty(st)){
            if(!empty(ans))ans.push_back(' ');
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};