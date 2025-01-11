class Solution {
public:
    string removeKdigits(string s, int k) 
    {
        int n = s.size();
        stack<char>st;
        // string ans = "0";
        if(k == n)
        return "0";

        int ch = 0;
            for(int i=0 ; i < n; i++)
            {
                                     
                                while(!st.empty() && ch < k && (st.top()  > s[i] ))
                                {
                                   st.pop();
                                    ch++;                         
                                }  
                      
                    st.push(s[i]);              
            }
        

        while(ch < k && !st.empty()) // incase you have still not removed k elements
        {
            st.pop();
            ch++;
        }

         string ans;
        while (!st.empty()) 
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        int ck =0 ;
        for(int i =0 ; i < ans.size() ; i++) 
        {
            if(ans[i] > '0')
            {
                ck = i;
                break;
            }
        }

       ans = ans.substr(ck);
       string res = "";
       int p =0 ; 
       while(p < ans.size() && ans[p] == '0')
       {
        p++;
       }
       for(int i= p; i < ans.size() ; i++)
       {
        res += ans[i];
       }
      if(res == "")
      return "0";
     
       return res;
    }
};