//#include<iostream>
//using namespace std;
//template <typename T>
//class Stack {
//public:
//	Stack(int size = 100);
//	~Stack();
//	void push(T data);
//	T pop();
//	bool isEmpty()const;
//	bool isFull()const;
//private:
//	T* pData;
//	int stackSize;
//	int top;
//};
//template <typename T>
//Stack<T>::Stack(int size) {
//	pData = new T[size];
//	stackSize = size;
//	top = -1;
//}
//template <typename T>
//Stack<T>::~Stack() {
//	delete[] pData;
//}
//template <typename T>
//void Stack<T>::push(T data) {
//	if (isFull()) {
//		cout << "Stack is full!\n";
//		exit(0);
//	}
//	top++;
//	pData[top] = data;
//}
//template <typename T>
//T Stack<T>::pop() {
//	if (isEmpty()) {
//		cout << "Stack is empty!\n";
//		exit(0);
//	}
//	int temp = pData[top];
//	top--;
//	return temp;
//}
//template <typename T>
//bool Stack<T>::isEmpty()const {
//	return top == -1;
//}
//template <typename T>
//bool Stack<T>::isFull()const {
//	return top == stackSize - 1;
//}
//
//
//
//
//
//
//
//
//
//int main() {
//	int array[10] = { 1, 3, 2, 4 };
//	Stack<int> s(4); //创建堆栈 s，设置初始大小为 4
//	int i;
//	for (i = 0; i < 3; ++i)
//		s.push(array[i]);
//	while (!s.isEmpty())
//		cout << s.pop() << ' ';
//	for (i = 0; i < 10; ++i)
//		s.push(array[i]);
//	cout << endl;
//	return 0;
//}
//
