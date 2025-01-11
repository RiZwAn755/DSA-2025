class StockSpanner {
public:
    stack<pair<int, int>> st; // pair of {price, index}
    int idx;

    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) 
    {
        idx++; // Increment the index for the current price
        int ans;

        // Pop elements from the stack while they are less than or equal to the current price (preious greater element)
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Calculate the span
        ans = idx - (st.empty() ? -1 : st.top().second);

        // Push the current price and its index onto the stack
        st.push({price, idx});
        
        return ans;
    }
};
