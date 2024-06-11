class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to, price});
        }

        vector<int> price(n, 1e9);
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;

        price[src] = 0;

        pq.push({0, {src, 0}}); //{price,{src,stops}}

        while (!pq.empty()) {
            auto port = pq.top();
            pq.pop();

            int stops = port.first;
            int node = port.second.first;
            int currentPrice = port.second.second;

            if(stops>k){
                continue;
            }

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int requiredPrice = it.second;

                if (currentPrice + requiredPrice < price[nextNode]) {
                    price[nextNode] = currentPrice + requiredPrice;
                    pq.push({stops+1, {nextNode, currentPrice + requiredPrice}});
                }
            }
        }

        return price[dst] == 1e9 ? -1 : price[dst];
    }
};