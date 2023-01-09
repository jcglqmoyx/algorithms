class DataStream {
    int cnt;
    int _value, _k;
public:
    DataStream(int value, int k) {
        cnt = 0, _value = value, _k = k;
    }

    bool consec(int num) {
        if (num == _value) cnt++;
        else cnt = 0;
        return cnt >= _k;
    }
};