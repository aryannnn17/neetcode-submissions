class Solution {
public:
    int sqr(int n){
        int res =0;
        while(n){
            res += pow(n%10, 2); 
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int temp = n;
        unordered_set<int> s;
        while(temp!=1){
            s.insert(temp);
            temp = sqr(temp);
            if(s.contains(temp))
                return false;
        }
        return true;
    }
};
