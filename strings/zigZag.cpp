class Solution {
    public:
        string convert(string s, int x)
         {
            string ans = "";
            int n = s.size();
    
            if(x == 1)
            return s ; 
    
            for(int i =0 ; i < x ; i++)
            {
                int idx = i; // idx = index of string that we are accessing

                int delDown = 2*(x - i - 1) ;  // we will get next element of the row on going down

                int delUp = 2*i; // next element of row on going up
    
                bool gd = true; // for changing the direction of movement
    
                while(idx < n)
                {
                     ans += s[idx];                     
    
                    if(i == 0)  // for first row we move down only
                    {
                       idx += delDown;
                    }
    
                    else if(i == x-1) // for last row we only move up
                    {
                      idx += delUp;
                    }
    
                    else
                    {
                        if(gd)
                        {
                            idx += delDown;
                        }
                        else 
                        {
                            idx += delUp;
                        }
    
                         if(gd) gd = false; // changing the movement direction
                         else gd = true;
                    }
                   
                }
    
    
                
            }
    
            return ans;
           
         }
    };