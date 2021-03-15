#include "common/include_header.h"

void chooseK(ints input, intVecSize start, intVecSize k, vectIntsRef final, ints partial){
	if(partial.size() == k){
    	final.push_back(partial);
    	return;
    }
    if(start == input.size()) return;

    partial.push_back(input.at(start));
    chooseK(input, start+1, k, final, partial);
    partial.pop_back();
    chooseK(input, start+1, k, final, partial);
}

int main(){
	ints input{1,2,3,4,5};
	int k = 3;
	ints partial;
	vectInts final;
	chooseK(input, 0, k, final, partial);

	for(intsRef comb: final){
		print(comb);
	}

	std::cout << "Total combinations "<< final.size() << '\n';
}