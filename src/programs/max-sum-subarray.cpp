#include <iostream>
#include <vector>
#include <climits>

int brute_force(const std::vector<int>& v){
	int max_sum = INT_MIN;
	int local_max = 0;
	int local_max1 = 0;
	for(int j=0; j < v.size(); ++j){
		for(int i = 0; i <=j; ++i){
			local_max = 0;
			for(int k = i; k <= j; ++k){
				local_max += v[k];
			}
			local_max1 = std::max(local_max1, local_max);
		}
		max_sum = std::max(local_max1, max_sum);
    }
    return max_sum;
}

int kadane(const std::vector<int>& v){
	int max_sum = INT_MIN;
	int local_max = 0;
	for(int i: v){
		local_max = std::max(i, i+local_max);
		max_sum = std::max(local_max, max_sum);
	}
	return max_sum;
}


int main(){
	std::vector<int> v{1,2,-5,-6,9,0,-1,4,6,0};
	int max_sum = brute_force(v);
	std::cout << "Max sum brute force "<< max_sum << '\n';
	max_sum = kadane(v);
	std::cout << "Max sum kadane "<< max_sum << '\n';
}