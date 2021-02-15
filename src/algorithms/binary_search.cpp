#include <iostream>
#include <vector>

using it = std::vector<int>::iterator;

int binary_search(it start, it end, int search){
	int idx = -1; 
	it orig_start = start;
	while(start <= end){
		auto distance = std::distance(start,end)/2;
		it mid = start;
		std::advance(mid,distance);
		if(*mid == search){
			idx = static_cast<int>(std::distance(orig_start, mid));
			break;
		}else if(search < *mid){
			end = std::next(mid);
		}else if (search > *mid){
			start = std::prev(mid);
		}else{
			std::cout << " not found! \n";
			break;
		}
	}
	return idx;
}

int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int searchNum = 6;
    int idx = binary_search(v.begin(), v.end(), searchNum);
    if(idx > -1	){
   		std::cout << searchNum << " Number found at index: "<<idx ;
   	}else{
   		std::cout << searchNum << " Number not found ";
   	}


}