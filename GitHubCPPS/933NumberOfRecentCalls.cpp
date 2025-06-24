class RecentCounter {
private:
    std::queue<int> tq{};
public:
    RecentCounter() {

    }

    int ping(int t) {
        int cnt = 0;
        tq.push(t);
        while (t - tq.front() > 3000) tq.pop();
        return(tq.size());
    }
};
