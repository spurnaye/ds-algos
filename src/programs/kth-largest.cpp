#include <vector>
#include <iostream>

using it = std::vector<int>::iterator;

it partition(it start, it end, int index){
	it pivot = start;
	for(it i = start; i < end; ++i){
		if(*i <= *end){
			std::iter_swap(i, pivot);
			pivot++;
		}
	}
	std::iter_swap(pivot, end);
	return pivot;
}
int kthLargest(int k, std::vector<int>& v){
	if(k > 0 && k < )
	int interestedIndex = v.size() - k;
	it idx = partition(v.begin(),v.end(), interestedIndex);
	return *(idx);
}

int main(){
	std::vector<int> v {3,2,1,5,6,4};
    int k = kthLargest(2, v);
    std::cout << "found index "<< k << '\n';
}