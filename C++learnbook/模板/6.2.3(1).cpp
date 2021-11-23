//#include<iostream>
//using namespace std;
//template <typename T>
//class Array1D {
//public:
//	Array1D(int newSize); //指定数组大小
//	Array1D(T* p, int newSize); //指定数组大小并传递初始值
//	Array1D(const Array1D <T>& a); //拷贝构造函数
//	~Array1D();
//	int getSize()const; //获取数组的大小
//	T max()const; //获取数组的最大值
//	void reverse(); //逆转数组元素
//	const T& operator[](int index)const;
//	T& operator[](int index);
//	Array1D& operator=(const Array1D<T>& a); //赋值运算符
//	template <typename X>
//	friend ostream& operator<<(ostream& out, const Array1D <X>& t);
//private:
//	T* pData; //指向堆中数组的指针
//	int size; //数组元素个数
//};
//template <typename T>
//Array1D<T>::Array1D(int newSize)
//{
//	pData = new T[newSize];
//	size = newSize;
//	for (int i = 0; i < size; i++)
//	{
//		pData[i] = 0;
//	}
//}
//template <typename T>
//Array1D<T>::Array1D(T* p, int newSize)
//{
//	pData = new T[newSize];
//	size = newSize;
//	for (int i = 0; i < size; i++)
//	{
//		pData[i] = p[i];
//	}
//}
//template <typename T>
//Array1D<T>::Array1D(const Array1D <T>& a)
//{
//	size = a.getSize();
//	pData = new T[size];
//	for (int i = 0; i < size; i++)
//	{
//		pData[i] = a[i];
//	}
//}
//template <typename T>
//Array1D<T>::~Array1D()
//{
//	delete pData;
//}
//template <typename T>
//int Array1D<T>::getSize()const
//{
//	return size;
//}
//template <typename T>
//void Array1D<T>::reverse()
//{
//	T* newpData = new T[size];
//	for (int i = 0; i < size; i++)
//	{
//		newpData[i] = pData[size - i - 1];
//	}
//	delete pData;
//	pData = newpData;
//}
//template <typename T>
//T Array1D<T>::max()const
//{
//	T mas = pData[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (pData[i] > mas)mas = pData[i];
//	}
//	return mas;
//}
//template <typename T>
//const T& Array1D<T>::operator[](int index)const
//{
//	if (index >= 0 && index < size)
//		return pData[index];
//	else
//		exit(0);
//}
//template <typename T>
//T& Array1D<T>::operator[](int index)
//{
//	if (index >= 0 && index < size)
//		return pData[index];
//	else
//		exit(0);
//}
//template <typename T>
//Array1D<T> & Array1D<T>::  operator=(const Array1D<T>& a)
//{
//	if (this == &a)
//		return *this;
//	delete pData;
//	size = a.getSize();
//	pData = new T[size];
//	for (int i = 0; i < size; i++)
//	{
//		pData[i] = a[i];
//	}
//}
//template <typename X>
//ostream& operator<<(ostream& out, const Array1D <X>& t)
//{
//	for (int i = 0; i < t.getSize(); i++)
//	{
//		out << t.pData[i];
//	}
//	return out;
//}
///*说明：类的模板类型参数为 T，但友元函数 operator<<不是类的成员，所以
//不能使用类型参数 T，在声明时必须指定自己的模板参数。
//测试主程序如下：*/
//int main() {
//	Array1D <int> array(5);
//	for (int i = 0; i < array.getSize(); ++i)
//		array[i] = i + 1;
//	cout << "Max: " << array.max() << endl;
//	for (int i = 0; i < array.getSize(); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//	cout << array;
//	return 0;
//	
//}