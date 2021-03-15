#include "common/include_header.h"

void targetSum(ints input, vectIntsRef output, int target, intSet set, intVecSize start){
	int total = 0;
	//sum(set, total);
	if(total == target){

		return;
	}

	for(intVecSize i = start; i < input.size(); ++i){
		int c = input[i];
		if(total + c > target){
			continue;
		}

	}

	return;
}

int main(){
	ints v{10,2,1,5,7,6,1};
	vectInts output;
	int target = 15;
	std::sort(v.begin(), v.end());
	//targetSum(v, output, target);
}