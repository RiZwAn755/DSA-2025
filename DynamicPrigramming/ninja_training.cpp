// question :
//            ninja is planning a n days long training program.
//            each day he can either do a pushup or a situp or a pullup.
//            each day he can do only one activity.
//            he can not do the same activity on consecutive days.
        //    he can not do more than one activity on the same day.

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
// Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

// N days , 3 tasks , choose one each day that was not selected in prev day


int f(int day , int last , vector<vector<int>>& points , vector<vector<int>>& dp)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0; 
    for(int i = 0; i < 3; i++)
    {
        if(i != last)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n , vector<int>(4 , -1) );
    return f(n - 1, 3, points , dp); 
}

