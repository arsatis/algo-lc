typedef unsigned long long ULL;

const int N=1010, P=131;

class Solution {
    ULL h1[N], h2[N], p[N];
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        p[0]=1;
        for(int i=1; i<=n1; i++){
            h1[i]=h1[i-1]*P+nums1[i-1];
            p[i]=p[i-1]*P;
        }
        for(int i=1; i<=n2; i++){
            h2[i]=h2[i-1]*P+nums2[i-1];
            p[i]=p[i-1]*P;
        }
            
        int l=0, r=min(n1,n2);
        while(l<r){
            int mid=l+r+1>>1;
            if(check(nums1,nums2,mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
    
    bool check(vector<int> nums1, vector<int> nums2, int len){
        int n1=nums1.size(), n2=nums2.size();
        unordered_set<ULL> S;
        for(int i=0; i<=n1-len; i++){
            ULL x=h1[i+len]-h1[i]*p[len];
            S.insert(x);
        }
        for(int j=0; j<=n2-len; j++){
            ULL y=h2[j+len]-h2[j]*p[len];
            if(S.count(y)) return true;
        }
        return false;
    }
};