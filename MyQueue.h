#ifndef MYQUEUE_H
#define MYQUEUE_H

template<class T>
class MyQueue
{
	struct Node
	{
		T data;
		Node *next = nullptr;
	};
	Node *front{ nullptr };
	Node *rear{ nullptr };
	size_t size = 0;
public:
	MyQueue(){}
	MyQueue(const MyQueue& q)
	{
		Node* temp = q.front;

		while (temp != nullptr)
		{
			Enqueue(temp->data);
			temp = temp->next;
		}
	}
	~MyQueue()
	{
		std::cout << Size() << "\n";
		while (front != nullptr)
		{
			Dequeue();
		}
		std::cout << "MyQueue Destroyed" << std::endl;
	}
	void Enqueue(T input)
	{
		Node *temp = new Node;
		temp->data = input;
		if(rear == nullptr)
			rear = temp;
		else
		{
			rear->next = temp;
			rear = temp;
		}
		if (front == nullptr)
			front = temp;
		size++;
	}
	void Dequeue()
	{
		if (front != nullptr)
		{
			Node *temp = new Node;
			temp = front;
			if (front == rear)
				rear = rear->next;
			front = front->next;
			delete temp;
			size--;
		}
		else
			std::cerr << "Error: No elements in Queue." << std::endl;
	}
	void operator= (const MyQueue& q)
	{
		MyQueue temp(q);
		std::swap(front, temp.front);
	}
	T Front()
	{
		if (front != nullptr)
			return front->data;
		else
		{
			std::cerr << "Error: No elements in Queue." << std::endl;
			return -1;
		}
	}
	T Back()
	{
		if (!Empty())
		{
			return rear->data;
		}
		else
		{
			std::cerr << "Error: No elements in Queue." << std::endl;
			return -1;
		}
	}
	size_t Size()
	{
		return size;
	}
	bool Empty()
	{
		if (front == nullptr)
			return true;
		else
			return false;
	}
};

#endif