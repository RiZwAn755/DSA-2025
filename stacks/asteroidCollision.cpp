

// In this problemwe are given an array of asteroids where asteroid[i] = direction of asteroid + magnitude of asteroid
// positive sign means asteroid is moving in right direction and negative sign means asterois is moving in left direction
// when two asteroids collids the asteroid with samller magnitude gets destroyed and bigger one remains same in both magnitude and direction
// All the asteroids are moving with same speed so the asteroid moving in same direction never collides

// ex: asteroids = [-2,-1,1,2] 
// first two have negative sign so they are moving towards left so they dont collide 
// next two are moving towards right they also dont collids so no collision occurs


// ----------------------------------------Approach-------------------------------------

 


#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < n; i++) 
        {
            int current = asteroids[i];

            if (!st.empty() && current < 0) 
            {
                bool destroyed = false;
                while (!st.empty() && st.top() > 0)
                 {
                    if (abs(st.top()) == abs(current)) 
                    {
                        
                        st.pop();
                        destroyed = true;
                        break;
                    } else if (abs(st.top()) > abs(current)) {
                        
                        destroyed = true;
                        break;
                    } 
                    else {
                      
                        st.pop();
                    }
                }

                if (!destroyed) {
                    st.push(current);
                }
            } 

            else 
            {
              
                st.push(current);
            }
        }


        while (!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }

        return ans;
    }
};
