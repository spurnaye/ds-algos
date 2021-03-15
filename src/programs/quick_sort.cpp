#include <iostream>
#include <vector>
#include <algorithm>
using it = std::vector<int>::iterator;

it partition(it start, it end){
	it partition = start;
	for(it i = start; i != end; ++i){
		if(*i < *end){
			std::iter_swap(i, partition);
			++partition;
		}
	}
	std::iter_swap(partition, end);
	return partition;
}
void quick_sort(it start, it end){
	int i = std::distance(start, end);
	if(i <= 1) return;
	it part_index = partition(start, end);
	quick_sort(start, part_index-1);  
	quick_sort(part_index, end);
}
int main(){
	std::vector<int> a{10,8,1,4,2,6,3,0,9};
	quick_sort(a.begin(), a.end()-1);
	for(int i: a){std::cout << i << ' ';}
		std::cout <<  '\n';
	
}