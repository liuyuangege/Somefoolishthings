//#include <iostream>
//using namespace std;
//class Stack {
//public:
//	Stack(int size = 100); //按指定的大小构建堆栈
//	~Stack();
//	void push(int data); //向栈顶添加元素
//	int pop(); //弹出并返回栈顶元素
//	bool isEmpty()const; //判断堆栈是否为空
//	bool isFull()const; //判断堆栈是否满
//private:
//	int* pData; //指向堆中为堆栈分配的数据
//	int stackSize; //堆栈当前容量
//	int top; //栈顶的下标位置
//};
//Stack::Stack(int size) {
//	pData = new int[size];
//	stackSize = size;
//	top = -1;
//}
//Stack::~Stack() {
//	delete[] pData;
//}
//void Stack::push(int data) {
//	if (isFull()) {
//		cout << "Stack is full!\n";
//		exit(0);
//	}
//	top++;
//	pData[top] = data;
//}
//int Stack::pop() {
//	if (isEmpty()) {
//		cout << "Stack is empty!\n";
//		exit(0);
//	}
//	int temp = pData[top];
//	top--;
//	return temp;
//}
//bool Stack::isEmpty()const {
//	return top == -1;
//}
//bool Stack::isFull()const {
//	return top == stackSize - 1;
//}
//int main() {
//	int array[10] = { 1, 3, 2, 4 };
//	Stack s(4); //创建堆栈 s，设置初始大小为 4
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