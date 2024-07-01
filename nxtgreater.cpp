class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          int n1 = nums1.size();
          int n2 = nums2.size();
          vector<int> ans;
          unordered_map<int,int> mpp;
          stack<int> s;
          for(int i = n2-1;i>=0;i--) {
                   while(!s.empty() && s.top() <= nums2[i]){
                    s.pop();
                   }
                   if(s.empty()){
                    mpp[nums2[i]] = -1;
                    s.push(nums2[i]);
                   }
                   else {
                      mpp[nums2[i]] = s.top();
                      s.push(nums2[i]);
                   }
          }
          for(int i = 0;i<n1;i++) {
            ans.push_back(mpp[nums1[i]]);
          }
          return ans;
    }
};
