//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//bool predicate(int data) {
//	if (data % 3 == 0 && data <= 20)return true;
//	return false;
//}
//int main() {
//	vector<int> vec{ 2,4,5,6,10,15,3,21,36,72,9,13 };
//	vector<int> result;
//	result.resize(vec.size());
//	auto end = copy_if(vec.begin(), vec.end(), result.begin(), predicate);
//	result.erase(end, result.end());
//	for_each(result.begin(), result.end(), [](int e) {cout << e << endl; });
//	return 0;
//}