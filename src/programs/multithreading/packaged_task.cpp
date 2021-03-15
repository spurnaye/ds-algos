#include <iostream>
#include <thread>
#include <future>

int add(int a, int b){
	return a+b;
}
int main(){
	std::packaged_task<int(int, int)> task(add);
	std::future<int> fut = task.get_future();
	task(1,2);
	std::cout << "future " << fut.get() << "\n";
}