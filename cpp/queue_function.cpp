/* C++
 *
 * Queue storing functions
 * 
 */

#include <iostream>
#include <queue>
#include <functional>

template<typename T>
void display(std::queue <T> q) {
	while (!q.empty()) {
		T elem = q.front();
		q.pop();
		std::cout << elem << std::endl;
	}
}
template <typename T>
void caller (std::function<void(T)> f, T arg2) {
	f(arg2);
}
template <typename T>
void caller (std::function<void(T)> f, T arg2, T arg3) {
	f(arg2);
}


int testFunction(int i) {
	std::cout << "callback from testFunction " << i << std::endl;
	return 5;
}
int testFunction2(int i, std::string s) {
	std::cout << "testFunction2 " << i << s<<std::endl;

}

int main() {
	
	std:: queue <std::function<void ()>>  q;

	// direct function access 
	std::function<void(int)> f_var = testFunction;
	f_var(-9);


	// storing a pointer reference
	std::function<void(int)> ptr_var = &testFunction;
	ptr_var(1);
	
	int(* fcnPtr)(int ) = testFunction;

	std::function<void(int, std::string)> ptr2 = &testFunction2;
	caller(ptr2,1,"arg2");

	return 0;
}