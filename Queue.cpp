#include <iostream>;
using namespace std;
typedef int ELementtype;
typedef int position;
// Queue array based 
class Queue {
private:
	ELementtype* Data;
	int Capacity;
	position Front, Rear;
	int Counter;
public:
	// constructor is 
	Queue(int size) {
		MakeNull(size);
	}
	void MakeNull(int size) {
		Capacity = size;
		Data = new ELementtype[Capacity];
		Front = 0;
		Rear = -1;
		Counter = 0;
	}
	// make function to kwon the queue is enpty or not 
	bool IsEmpty() {
		return(Counter = 0);
	}
	// make function to kwon the queue iss fully or not
	bool IsFully() {
		return(Counter = Capacity);
	}
	// make function to return the first number 
	ELementtype first() {
		if (IsEmpty()) {
			cout << "the Queue is empty";
			return -1;
		}
		else {
			return Data[Front];
		}
	}
	// make enqueue function to add element to the queue
	void Enqueue(ELementtype x){
		if (IsFully()) {
			cout << "the queue is full element";
		}
		else {
			Rear = (Rear + 1) % Capacity;
			Data[Rear] = x;
			Counter++;
		}
	}
	// make function dequeue to remove element from the queue
	ELementtype Dequeue() {
		if (IsEmpty()) {
			cout << "the queue is empty";
			return -1;
		}
		else {
			ELementtype x = Data[Front];
			Front = (Front + 1) % Capacity;
			Counter--;
			return x;
		}
	}
	// make function to return the size of the Queue
	int Size() {
		return Counter;
	}
	// make function to print the element in the Queue
	void  Printlist() {
		if (IsEmpty()) {
			cout << "the queue is empty";
		}
		else {
			cout << "The front is ";
			cout << Data[Front];
			for (int i = 0; i < Capacity - 1; i++) {
				cout << "Element is ";
				cout << Data[i];
			}
			cout << "The Rear is";
			cout << Data[Rear];
		}
	}
	// make Queue but linked list based
	struct Node {
		ELementtype Data;
		Node* next;
	};
	typedef Node* Position;
	// we will use the Node to Make This 
	class LinkedQueue {
	private:
		Position Front;
		Position Rear;
		int Counter;
	public:
		LinkedQueue() {
			MakeNull();
		}
		void MakeNull() {
			Front = NULL;
			Rear = NULL;
			Counter = 0;
		}
		bool IsEmpty() {
			return (Counter = 0);
		}
		ELementtype Frist() {
			if (IsEmpty) {
				cout << "sorry the Queue is empty";
				return -1;
			}
			else {
				return Front->Data;
			}
		}
		void Enqueue(ELementtype x) {
			Position newnode = new Node;
			newnode->Data = x;
			newnode->next = NULL;
			if (IsEmpty()) {
				Rear = newnode;
				Front = newnode;
			}
			else {
				Rear->next = newnode;
				Rear = newnode;
			}
			Counter++;
		}
		ELementtype Dequeue() {
			if (IsEmpty) {
			cout << "Your queue is empty";
				return -1;
			}
			else {
				ELementtype x = Front->Data;
				Front = Front->next;
				Counter--;
				if (Counter == 0) {
					Rear = NULL;
				}
				return x;
			}
		}
		int Size() {
			return Counter;
		}
		void PrintQueue(){
			if (IsEmpty()) {
				cout << "the Queue is empty";
			}
			else {
				cout << "the front is ";
				Position q = Front;
				while ( q != Rear) {
					cout << "the data is ";
					cout << q->Data;
					q = q->next;
				}
				cout << "the rear is ";
				cout << Rear->Data;
			}
		}
		ELementtype sum(Queue k) {
			ELementtype s = 0 ;
			ELementtype q = k.first();
			while (q!=k.Rear) {
				s += q;
				Dequeue();
			}
			s += k.Rear;
			return s;
		}
		Queue evenQ(Queue o) {
			Queue e(o.Size());
			ELementtype curr = o.Front;
			while (curr!= o.Rear) {
				if (curr % 2 == 0) {
					e.Enqueue(curr);
				}
				o.Dequeue();
				return e;
			}
		}
		ELementtype MaxQueue(Queue m) {
			ELementtype max = m.Front;
			ELementtype q = m.Front;
			while (q!= m.Rear) {
				if (q > max) {
					max = q;
				}
				m.Dequeue();
			}
		}
	};
};
