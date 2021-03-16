#include "common/include_header.h"

void acc(intsIt start, intsIt end, std::promise<int> proms){
	int total = std::accumulate(start, end, 0);
	proms.set_value(total);
}

int main(){
	ints v;
	size_t s = 100;
	for(size_t i = 1; i <= s; ++i){
		v.push_back(i);
	}

	std::promise<int> acc_promise;
	std::future<int> fut = acc_promise.get_future();
	std::thread t(acc, v.begin(), v.end(), std::move(acc_promise));

	if(t.joinable()) t.join();
	fut.wait();
	std::cout << "sum is " << fut.get() << '\n';
}