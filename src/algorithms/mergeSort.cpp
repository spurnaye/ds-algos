#include <iostream>
#include <vector>

using it = std::vector<int>::iterator;

void merge(){

}

void mergeSort(it start, it end){
	it mid = start;
	while(start < end){
		std::advance(mid,std::distance(start, end)/2);
		mergeSort(start, mid);
		mergeSort(mid, end);
		merge(start, mid, end);
	}
}

int main(){
	std::vector<int> v{1,5,2,6,3,7,4,8,10,9};
    mergeSort(start, end);
}