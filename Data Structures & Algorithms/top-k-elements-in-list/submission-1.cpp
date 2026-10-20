class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //solution bucket_sort, chia cno vao tung bucket co so luong frequency khac nhau, moi frequency la index cho cno

        int n = nums.size(); 
        //dem so luong fre
        unordered_map<int, int> countMap;
        for(int n : nums){
            countMap[n]++;
        }
        // Chỉ số của bucket chính là tần suất (từ 0 đến n)
        // Mỗi bucket sẽ chứa danh sách các số có chung tần suất đó
        vector<vector<int>> buckets(n + 1);
        for (auto& pair : countMap) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            // Nếu bucket khong tro^'ng
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    // Nếu đã đủ k phần tử thì dừng lại luôn
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }
        return result;
    }
};
