#include "common/include_header.h"


void acc(intsIt begin, intsIt end, int& output){
	output = std::accumulate(begin, end, output);
}

int main(){
	ints inputVec;
	threadVec threads;
	size_t numThreads = 4;
	ints output(4, 0);

	for(int i = 1; i <= 100; ++i){
		inputVec.push_back(i);
	}

	intsIt start = inputVec.begin();
	size_t increments = inputVec.size()/numThreads;

	for(size_t i = 0; i < numThreads; ++i){
		
		std::thread t(acc, start, start+increments, std::ref(output[i]));
		threads.push_back(std::move(t));
		start += increments;
	}

	for(auto& t: threads){
		if(t.joinable()) t.join();
	}

	for(auto& i: output) std::cout << i << '\n';
	int final = 0;
	final = std::accumulate(output.begin(), output.end(), final);
	std::cout << "final "<< final << '\n';
}