class StockSpanner {
private:
    stack<pair<int, int>> pns;
public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (!pns.empty() && pns.top().first <= price) {
            span += pns.top().second;
            pns.pop();
        }
        pns.emplace(price, span);
        return span;
    }
};
