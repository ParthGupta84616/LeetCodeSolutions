class Router {
    int memoryLimit;
    using PacketKey = uint64_t;
    queue<PacketKey> q;
    unordered_set<PacketKey> set;
    map<int, vector<int>> destTimes;

    PacketKey encode(int source, int destination, int timestamp) {
        return (static_cast<PacketKey>(source) << 44) | (static_cast<PacketKey>(destination) << 24) | static_cast<PacketKey>(timestamp);
    }

    void insertTimestamp(int destination, int timestamp) {
        auto& v = destTimes[destination];
        auto it = lower_bound(v.begin(), v.end(), timestamp);
        v.insert(it, timestamp);
    }

    void removeTimestamp(int destination, int timestamp) {
        auto& v = destTimes[destination];
        auto it = lower_bound(v.begin(), v.end(), timestamp);
        if (it != v.end() && *it == timestamp) v.erase(it);
        if (v.empty()) destTimes.erase(destination);
    }

    void decode(PacketKey key, int &source, int &destination, int &timestamp) {
        source = int(key >> 44);
        destination = int((key >> 24) & ((1 << 20) - 1));
        timestamp = int(key & ((1 << 24) - 1));
    }

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        PacketKey key = encode(source, destination, timestamp);
        if (set.count(key)) return false;
        if ((int)q.size() == memoryLimit) {
            PacketKey oldKey = q.front();
            q.pop();
            set.erase(oldKey);
            int oldSrc, oldDst, oldTs;
            decode(oldKey, oldSrc, oldDst, oldTs);
            removeTimestamp(oldDst, oldTs);
        }
        q.push(key);
        set.insert(key);
        insertTimestamp(destination, timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        PacketKey key = q.front();
        q.pop();
        set.erase(key);
        int source, destination, timestamp;
        decode(key, source, destination, timestamp);
        removeTimestamp(destination, timestamp);
        return {source, destination, timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;
        const auto& v = it->second;
        auto lb = lower_bound(v.begin(), v.end(), startTime);
        auto ub = upper_bound(v.begin(), v.end(), endTime);
        return int(ub - lb);
    }
};
