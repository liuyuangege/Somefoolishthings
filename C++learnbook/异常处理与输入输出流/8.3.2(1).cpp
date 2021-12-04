//#include<iostream>
//using namespace std;
//class ExceptionBase { //�쳣����
//public:
//	virtual void showReason() {
//		cout << "Base Exception!\n";
//	}
//};
//class PushOnFull :ExceptionBase
//{
//public:
//	void showReason()
//	{
//		cout << "��ջ����" << endl;
//	}
//};
//class PopOnEmpty :ExceptionBase
//{
//public:
//	void showReason()
//	{
//		cout << "��ջ�ѿ�" << endl;
//	}
//};
//template<typename T>
//class Stack
//{
//private:
//	T *pData;
//	int top,size;
//public:
//	Stack(int size);
//	void push(T data);
//	T pop();
//	bool isEmpty();
//	bool isFull();
//};
//template<typename T>
//Stack<T>::Stack(int Size)
//{
//	pData = new T[Size];
//	size = Size;
//	top = -1;
//}
//template<typename T>
//void Stack<T>::push(T data)
//{
//	if (isFull())
//	{
//		cout << "Stack is full!\n";
//		throw PushOnFull();
//	}
//	top++;
//	pData[top] = data;
//}
//template<typename T>
//T Stack<T>::pop()
//{
//	if (isEmpty())
//	{
//		cout << "Stack is empty!\n";
//		throw PopOnEmpty();
//	}
//	T temp = pData[top];
//	top--;
//	return temp;
//}
//template <typename T>
//bool Stack<T>::isEmpty()
//{
//	if (top == -1)return 1;
//	return 0;
//}
//template <typename T>
//bool Stack<T>::isFull()
//{
//	if (top == size-1)return 1;
//	return 0;
//}
//int main() {
//	int array[10] = { 1, 3, 2, 4 };
//	Stack<int> s(4); //������ջ s�����ó�ʼ��СΪ 4
//	cout << endl;
//	try {
//		for (int i = 0; i < 3; ++i)
//			s.push(array[i]);
//		while (!s.isEmpty())
//			cout << s.pop() << ' ';
//		for (int i = 0; i < 10; ++i)
//			s.push(array[i]);
//	}
//	catch (ExceptionBase& e) {
//		e.showReason();
//	}
//	return 0;
//}
