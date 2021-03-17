#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <condition_variable>
#include <future>
#include <atomic>
#include <shared_mutex>


using ints = std::vector<int>;
using used = std::vector<bool>;
using usedRef = std::vector<bool>;
using intsRef = ints&;
using vectInts = std::vector<ints>;
using vectIntsRef = vectInts&;
using intsIt = ints::iterator;
using intVecSize = ints::size_type;

// multithreading related
using threadVec = std::vector<std::thread>;
using threadVecIt = threadVec::iterator;
using futIntVec = std::vector<std::future<int>>;
using futVecIt = futIntVec::iterator;

using intSet = std::set<int>;
using vectIntSet = std::vector<intSet>;
using vectIntSetRef = vectIntSet&;

using sec = std::chrono::seconds;
using ms = std::chrono::milliseconds;

#define LOG_ERROR(msg) do{ std::cerr << __FILE__ << " :  "<< __PRETTY_FUNCTION__<< " (@" << __LINE__ << "): " << msg << '\n'; } while( false )
#define LOG_INFO(msg) do{ std::cout << "[" <<std::this_thread::get_id() << "]" << __FILE__ << " :  "<< __PRETTY_FUNCTION__<< "(@" << __LINE__ << "): " << msg << '\n'; } while( false )

template <typename T>
void sum(const T& input, T& output){
	//std::accumulate(input.begin(), input.end(), output, std::plus<T>);
}

void print(intsRef v){
	std::cout << '[';
	for(auto& i: v){
			std::cout << i << ' ';
		}
	std::cout << "]\n";
}

void print(vectIntsRef v){
	std::cout << "<<<<-----\n";
	for(auto& i: v) print(i);
	std::cout << "----->>>>>\n";
}

