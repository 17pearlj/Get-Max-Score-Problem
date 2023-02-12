class Solution {
public:
    long modV = 1e9 + 7;
       
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long score1 = 0;
        long score2 = 0;
        int i1 = 0;
        int i2 = 0;
        while (i1 < nums1.size() || i2 < nums2.size()) {
            if (i1 < nums1.size() && (i2 == nums2.size() || nums1[i1] < nums2[i2])) {
                score1 += nums1[i1++] % modV;
              //  score1 = fmod(score1, modV);
            } else if (i2 < nums2.size() && (i1 == nums1.size() || nums1[i1] > nums2[i2])) {
                score2 += nums2[i2++] % modV;
               // score2 = fmod(score2, modV);
            } else {
                score1 = (max(score1, score2) + nums1[i1]) % modV;
               // score1 = fmod(score1, modV);
                score2 = score1;
                i1++;
                i2++;
            }
        }
        return max(score1, score2) % modV;
    }
};
