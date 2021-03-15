#include "common/include_header.h"

void getPerm(intsRef input, intsRef partial, vectIntsRef final, usedRef usedIdxs){
	if(partial.size() == input.size()){
		final.push_back(partial);
		return;
	}
	for(intVecSize i = 0; i < input.size(); ++i){
		if(usedIdxs[i] == false){
			usedIdxs[i] = true;
			partial.push_back(input[i]);
			getPerm(input, partial, final, usedIdxs);
			partial.pop_back();
			usedIdxs[i] = false;
		}
	}

}

int main(){
	ints v{1,2,3,4,5};
	ints partial;
	vectInts final;
	used usedIdxs(v.size(), false);
	getPerm(v, partial, final, usedIdxs);

	for(intsRef comb: final){
		print(comb);
	}

	std::cout << "Total combinations "<< final.size() << '\n';
}