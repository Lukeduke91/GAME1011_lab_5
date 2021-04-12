#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;
		QueueNode(T value1, QueueNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and Destructor
	DynTempQueue()
	{
		front = nullptr;
		rear = nullptr;
	}
	~DynTempQueue()
	{
		clear();
	}

	// Member functions
	void enqueue(T enq)
	{
		if (isEmpty())
		{
			front = new QueueNode(enq);
			rear = front;
		}
		else
		{
			rear->next = new QueueNode(enq);
			rear = rear->next;
		}
	}
	void dequeue(T& enq)
	{
		QueueNode* temp;
		if (isEmpty())
		{
			cout << "The queue is empty.\n";
			exit(1);
		}
		else
		{
			enq = front->value;
			temp = front;
			front = front->next;
			delete temp;
		}
	}
	bool isEmpty() const
	{
		if (front == nullptr)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	void clear()
	{
		T value;

		while (!isEmpty())
		{
			dequeue(value);
		}
	}
};

template <class T>
class DynTempStack
{
private:
	class StackNode
	{
		friend class DynTempStack;
		T value;
		StackNode* next;
		// Constructor
		StackNode(T value1, StackNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode* top;
public:
	DynTempStack() { top = NULL; }
	void push(T num)
	{
		top = new StackNode(num, top);
	}
	void pop(T& sta)
	{
		StackNode* temp;

		if (isEmpty())
		{
			cout << "The stack is empty.\n";
			exit(1);
		}
		else   // Pop value off top of stack
		{
			sta = top->value;
			temp = top;
			top = top->next;
			delete temp;
			temp = nullptr;
		}
	}
	bool isEmpty() const
	{
		if (!top)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
};

int main()
{
	
	DynTempQueue<int> tQueue;
	DynTempStack<int> tStack;
	int catchVar;

	// This is where the primitive data is being presented. 
	cout << "Enqueue 10 items...\n";
	for (int i = 1; i <= 10; i++)
	{
		tQueue.enqueue(i * i);
	}

	cout << "The values in the queue were:\n";

	while (!tQueue.isEmpty())
	{
		int value2;
		tQueue.dequeue(value2);
		cout << value2 << " ";
	}

	cout << endl;

	for (int i = 5; i <= 50; i = i + 5)
	{
		cout << "Push: " << i << endl;
		tStack.push(i);
	}
	cout << endl;

	for (int i = 1; i <= 10; i++)
	{
		cout << "Pop: ";
		tStack.pop(catchVar);
		cout << catchVar << endl;
	}

	cout << "\n Attempting to pop again..." << endl;

	//// this is the end of the Non-primative type.
	DynTempQueue<string> tSQueue;
	DynTempStack<string> tSStack;
	string array[10] = {"Lucas", "Nick", "james", "luke", "Michael", "amy", "Lucy", "elizabeth", "julia", "missy"};
	string names;

	cout << "\nEnqueue 5 more  items...\n";
	for (int i = 0; i < 10; i++)
	{
		tSQueue.enqueue(array[i]);
	}

	cout << "The values in the queue were:\n";

	while (!tSQueue.isEmpty())
	{
		string value2;
		tSQueue.dequeue(value2);
		cout << value2 << " ";
	}

	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Push: " << array[i] << endl;
		names = array[i];
		tSStack.push(array[i]);
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Pop: ";
		tSStack.pop(names);
		cout << names << endl;
	}

	cout << "\n Attempting to pop again..." << endl;

	return 0;
}