//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Predicate {
//public:
//	bool operator()(int data)
//	{
//		if (data % 3 == 0 && data <= 20)return true;
//		return false;
//	}
//	
//};
//int main() {
//	vector<int> vec{ 2,4,5,6,10,15,3,21,36,72,9,13 };
//	vector<int> result;
//	result.resize(vec.size());
//	auto end = copy_if(vec.begin(), vec.end(), result.begin(), Predicate());
//	result.erase(end, result.end());
//	for (auto e : result) cout << e << endl;
//	return 0;
//}