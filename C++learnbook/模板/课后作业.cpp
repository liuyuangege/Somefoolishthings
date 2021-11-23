#include <iostream>
#include <vector>
using namespace std;
template<typename T>
bool greaterFun(T a, T b) { return a >= b; }
template<typename T>
bool lessFun(T a, T b) { return a < b; }
template<typename T, typename T2, typename C>
T search(T begin, T end, T2 value, C con) {
	while (begin != end) {
		if (con(*begin, value)) return begin;
		
			begin++;
	}
	return end;
}
int main() {
	int a[] = { 90,87,56,100,82 };
	auto it = search(begin(a), end(a), 100, greaterFun<int>);
	if (it != end(a))
		cout << "First:" << *it << endl;
	it = search(begin(a), end(a), 60, lessFun<int>);
	if (it != end(a))
		cout << "Second:" << *it << endl;
	return 0;
}
