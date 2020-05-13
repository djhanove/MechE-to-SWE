class Solution {
public:
    void mergeExtraDataStructure(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;

        if(nums1.empty() && !nums2.empty())
            nums1 = nums2;
    
        vector<int> result;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                result.push_back(nums1[i++]);
            }
            else {
                result.push_back(nums2[j++]);
            }
        }
        while(i<m)
            result.push_back(nums1[i++]);
        
        while(j<n)
            result.push_back(nums2[j++]);
        
        nums1 = result;
        
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1;
        int b=n-1;
        int i = n + m - 1;

        while(a>=0 && b>=0) {
            if(nums1[a] > nums2[b])
                nums1[i--] = nums1[a--];
            else
                nums1[i--] = nums2[b--];
        }
        
        while(b>=0)
            nums1[i--] = nums2[b--]; // protect for the event that n > m 
    
    }
    
};
