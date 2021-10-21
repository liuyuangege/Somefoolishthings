//#include <iostream>
//using namespace std;
//int* getDiagonal(int** matrix, int n)
//{
//	int* sb = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		sb[i] = matrix[i][i];
//	}
//	return sb;
//}
//int main() {
//	int** data, n = 5;
//	data = new int* [n];  //动态创建指针数组 
//	for (int i = 0; i < n; ++i)
//		data[i] = new int[n];   //每个指针数组指向动态创建的 1 维数组 
//	for (int i = 0; i < n; ++i) {    //初始化数组元素   
//		for (int j = 0; j < n; ++j)
//			data[i][j] = i + j;
//	}
//	int* diagonal = getDiagonal(data, n);
//	for (int i = 0; i < n; ++i)
//		cout << diagonal[i] << endl;
//	delete[] diagonal;    //释放动态创建的对角线元素数组  	
//	for (int i = 0; i < n; ++i)  //释放二维数组  	 	
//		delete[] data[i];
//	delete[] data;
//	return 0;
//}
