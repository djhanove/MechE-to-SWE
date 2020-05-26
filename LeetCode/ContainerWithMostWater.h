class Solution {
public:
    int maxAreaBruteForce(vector<int>& height) {
        int area = 0;
        int xdist = 0;
        
        // area = min(height[i], prevMax) * xdist
        for(size_t i = 0; i < height.size()-1; i++){
            for(size_t j = height.size()-1; j > i ; j--) {
                int tempmin = min(height[i],height[j]) * (j-i);
                area = std::max(area,  tempmin);
            }
        }
        return area;
    }
    
    int maxArea(vector<int>& height) {
        int area = 0;
        int i = 0;
        int j = height.size() - 1;
        // start with widest bowl, then skip all entries that arent <= height at the max side of the bowl
        while(i < j) {
            int h = min(height[i], height[j]);
            area = max(area, h*(j-i));
            
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return area;
    }
    
};
