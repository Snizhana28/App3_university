#pragma once

namespace ASD {

	template <class T>
	class List
	{
		class Node {
		public:
			T data;
			Node *next, *prev;
			Node(T  &d, Node *n = 0, Node *p = 0) { data = d; next = n; prev = p; }
		};
		Node *head, *tail;
		int count;
	public:
		List() { head = tail = 0; count = 0; }
		~List() { RemoveAll(); }

		typedef void * POSITION;
		int GetCount() { return count; }
		POSITION GetHead() { return (POSITION)head; }
		POSITION GetTail() { return (POSITION)tail; }

		T GetNext(POSITION & pos) {
			T data = ((Node *)pos)->data;
			pos = (POSITION)(((Node *)pos)->next);
			return data;
		}
		T GetPrev(POSITION & pos) {
			T data = ((Node *)pos)->data;
			pos = (POSITION)(((Node *)pos)->prev);
			return data;
		}
		List & AddHead(T data) {
			Node * newNode = new Node(data, head, 0);
			if (head) { head->prev = newNode; }
			head = newNode;
			if (!tail) { tail = newNode; }
			count++;
			return *this;
		}
		
		List & AddTail(T data) {
			Node * newNode = new Node(data, 0, tail);
			if (tail) { tail->next = newNode; }
			tail = newNode;
			if (!head) { head = newNode; }
			count++;
			return *this;
		}

		List & RemoveAll() {
			Node * p, *t = head;
			while (t) {
				p = t->next;
				delete t;
				t = p;
			}
			head = tail = 0; count = 0;
			return *this;
		}

		
		POSITION Find(T data) {			
			Node *t = head;
			while (t) {
				if (t->data == data) {
					return (POSITION)t;
				}
				t = t->next;
			}			
			return (POSITION)0;
		}

		
		T Remove(POSITION pos) {
			Node *t = (Node *)pos;
			if (t->prev) { t->prev->next = t->next;}
			if (t->next) { t->next->prev = t->prev; }
			if (head == pos) { head = t->next; }
			if (tail == pos) { tail = t->prev; }
			T d = t->data;
			delete t;
			count--;
			return d;
		}

		List & Insert(POSITION pos, T data) {
			Node * t = (Node *)pos;
			Node * n = new Node(data, t->next, t);
			if (t->next) { t->next->prev = n; }
			t->next = n;
			return *this;
		}
		
	};
}

