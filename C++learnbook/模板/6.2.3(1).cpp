//#include<iostream>
//using namespace std;
//template <typename T>
//class Array1D {
//public:
//	Array1D(int newSize); //ָ�������С
//	Array1D(T* p, int newSize); //ָ�������С�����ݳ�ʼֵ
//	Array1D(const Array1D <T>& a); //�������캯��
//	~Array1D();
//	int getSize()const; //��ȡ����Ĵ�С
//	T max()const; //��ȡ��������ֵ
//	void reverse(); //��ת����Ԫ��
//	const T& operator[](int index)const;
//	T& operator[](int index);
//	Array1D& operator=(const Array1D<T>& a); //��ֵ�����
//	template <typename X>
//	friend ostream& operator<<(ostream& out, const Array1D <X>& t);
//private:
//	T* pData; //ָ����������ָ��
//	int size; //����Ԫ�ظ���
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
///*˵�������ģ�����Ͳ���Ϊ T������Ԫ���� operator<<������ĳ�Ա������
//����ʹ�����Ͳ��� T��������ʱ����ָ���Լ���ģ�������
//�������������£�*/
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