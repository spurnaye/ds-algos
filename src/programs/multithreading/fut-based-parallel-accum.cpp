#include "common/include_header.h"

template <typename Iterator, typename T>
T acc(Iterator begin, Iterator end, T& output){
	return std::accumulate(begin, end, output);
}

int main(){
	ints inputVec;
	futIntVec futures;
	size_t numThreads = 4;
	
	for(int i = 1; i <= 100; ++i){
		inputVec.push_back(i);
	}

	intsIt start = inputVec.begin();
	size_t increments = inputVec.size()/numThreads;
	int init_condition = 0;
	for(size_t i = 0; i < numThreads; ++i){
		std::future<int> fut = std::async(acc<intsIt,int>, start, start+increments, std::ref(init_condition));
		futures.push_back(std::move(fut));
		start += increments;
	}

	int final = 0;
	for(auto& i: futures) final += i.get();
	std::cout << "final "<< final << '\n';
}