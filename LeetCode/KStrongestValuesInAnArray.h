class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int median = arr[(arr.size()-1)/2];
        sort(arr.begin(), arr.end(), [median](int a, int b) 
             {  if (abs(a - median) == abs(b - median))
                    return a > b;
                else
                    return abs(a - median) > abs(b - median);
             });
        vector<int> result;

        while(k > 0) {
            result.push_back(arr[k-1]);
            k--;
        }
        
        return result;
            
    }
};
