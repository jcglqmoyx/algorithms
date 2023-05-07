class FrequencyTracker {
    int cnt_num[100010]{}, cnt_freq[200010]{};
public:
    FrequencyTracker() {
    }

    void add(int x) {
        cnt_num[x]++;
        cnt_freq[cnt_num[x]]++;
        cnt_freq[cnt_num[x] - 1]--;
    }

    void deleteOne(int x) {
        if (cnt_num[x]) {
            cnt_num[x]--;
            cnt_freq[cnt_num[x] + 1]--;
            cnt_freq[cnt_num[x]]++;
        }
    }

    bool hasFrequency(int f) {
        return cnt_freq[f];
    }
};