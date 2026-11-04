class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        stack<int>st;
        for(string s:operations){
            if(s=="C") {
            int x=st.top();
            st.pop();
            ans-=x;
            }
            else if(s=="D"){
                int first=2*st.top();
                st.push(first);
                ans+=first;
            }
            else if(s=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int third=first+second;
                st.push(second);
                st.push(first);
                st.push(third);
                ans+=third;
            }
            else{
                int x=stoi(s);
                st.push(x);
                ans+=x;
            }
        }
        return ans;
    }
};