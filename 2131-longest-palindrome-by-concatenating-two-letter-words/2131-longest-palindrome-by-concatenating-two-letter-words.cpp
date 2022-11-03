class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int count = 0;
        for(auto x:words)mp[x]++;
        bool flag = false;
        for(auto x : words){
            string wrd = x;
            reverse(wrd.begin(),wrd.end());
            if(wrd!=x&&mp[wrd]>0&&mp[x]>0){
                mp[wrd]--;
                mp[x]--;
                count+=4;
            }
            else if(wrd==x&&mp[x]>1){
                count+=4;
                mp[x]-=2;
            }
            else if(wrd==x&&mp[x]>0&&!flag){
                mp[x]--;
                count+=2;
                flag = true;
            }
        }
            return count;
    }
};