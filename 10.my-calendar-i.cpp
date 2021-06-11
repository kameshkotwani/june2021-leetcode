class MyCalendar {
    private:
        vector<pair<int, int>> cal;
    public:
        MyCalendar() {}

        bool book(int start, int end) {
            for (auto a : cal) {
                if (max(a.first, start) < min(a.second, end)) return false;
            }
            cal.push_back({start, end});
            return true;
        }


};
