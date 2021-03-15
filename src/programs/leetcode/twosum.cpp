#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> numSet;
        std::vector<int> ret;
        
        for(int i = 0; i < nums.size(); ++i){
           numSet.insert({nums.at(i), i});
        }
        
        for(int i = 0; i < nums.size(); ++i){
            int curr = nums.at(i);
            int remaining = target - curr;
            auto rem = numSet.find(remaining);
            if( rem != numSet.end() && rem->second != i){
                ret.push_back(i);
                ret.push_back(rem->second);
                break;
            }
        }
        return ret;
    }
};

int main(){
   Solution s;
   std::vector<int> v{3,2,4};
   std::vector<int> ans = s.twoSum(v, 6);
   for(auto& i: ans){std::cout << i <<  ' ';}
   	std::cout << '\n';
}