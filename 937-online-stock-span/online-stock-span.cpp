class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {

    }

    int next(int price) {
        int days = 1;

        while (!st.empty() && st.top().first <= price) {      
            days+=st.top().second;
            st.pop();
        }
        st.push(make_pair(price,days));

        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */