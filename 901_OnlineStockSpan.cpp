//
// Created by Chunbin lin on 5/20/20.
//

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int w = 1;
        while (!prices.empty() && prices.top() <= price) {
            prices.pop();
            w += weights.top();
            weights.pop();
        }

        prices.push(price);
        weights.push(w);
        return w;
    }
private:
    stack<int> prices, weights;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */