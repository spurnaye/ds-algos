#include <thread>
#include <future>
#include <iostream>

int retVal(int a, int b){
	return a+b;
}

int main(){
	std::future<int> ans = std::async(retVal,1,2);
	std::cout << "addition is "<< ans.get() << '\n';
}
