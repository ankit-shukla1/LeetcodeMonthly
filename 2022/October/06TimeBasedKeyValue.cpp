// Problem Link : https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        store.clear();
    }
    
    void set(const string &key, const string &value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(const string &key, int timestamp) {
        int largestIndex=store[key].size();
        if(largestIndex==0) return "";
        int lo=0,hi=largestIndex-1;
        auto &arr = store[key];
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid].first>timestamp){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return arr[lo].first>timestamp?(lo>0?arr[lo-1].second:""):arr[lo].second;
    }
};
