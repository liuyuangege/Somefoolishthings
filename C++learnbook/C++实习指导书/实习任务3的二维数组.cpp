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
//	data = new int* [n];  //��̬����ָ������ 
//	for (int i = 0; i < n; ++i)
//		data[i] = new int[n];   //ÿ��ָ������ָ��̬������ 1 ά���� 
//	for (int i = 0; i < n; ++i) {    //��ʼ������Ԫ��   
//		for (int j = 0; j < n; ++j)
//			data[i][j] = i + j;
//	}
//	int* diagonal = getDiagonal(data, n);
//	for (int i = 0; i < n; ++i)
//		cout << diagonal[i] << endl;
//	delete[] diagonal;    //�ͷŶ�̬�����ĶԽ���Ԫ������  	
//	for (int i = 0; i < n; ++i)  //�ͷŶ�ά����  	 	
//		delete[] data[i];
//	delete[] data;
//	return 0;
//}
