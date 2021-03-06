// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *prv;
	struct node *next;
};

class linked_list
{
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	
	void add_node(int n) {
		node *temp = new node;
		temp->data = n;
		temp->prv;
		temp->next;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp->next;
			tail = temp;
		}
	}

private:

};



//
//struct node {
//	int data;
//	struct node *next;
//};
//
//class linked_list {
//	node *head, *tail;
//public:
//	linked_list() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	void front(int n) {
//		node *temp = new node;
//		temp->data = n;
//		temp->next = head;
//		head = temp;
//	}
//
//	void after(node *a, int n) {
//		node *temp = new node;
//		temp->data = n;
//		temp->next = a->next;
//		a->next = temp;
//	}
//
//	void add_node(int n) {
//		node *temp = new node;
//		temp->data = n;
//		temp->next = NULL;
//
//		if (head == NULL) {
//			head = temp;
//			tail = temp;
//		}
//		else {
//			tail->next = temp;
//			tail = tail->next;
//		}
//	}
//
//	void del(node *before_del) {
//		node *temp = before_del->next;
//		before_del->next = temp->next;
//		delete temp;
//	}
//
//   void display_using_While(){
//		node *temp;
//		temp = head;
//
//		while (temp != NULL)
//		{
//			cout << temp->data<<endl;
//			temp = temp->next;
//		}
//	}
//
//	node* gethead() {
//		return head;
//	}
//
//  static void display_using_recursion(node *head) {
//
//		if (head == NULL) {
//			cout << "NULL\n";
//		}
//		else
//		{
//			cout << head->data<<"\n";
//			display_using_recursion(head->next);
//		}
//
//	}
//
//  static void concatenate(struct node *a, struct node *b) {
//	  if (a != NULL && b != NULL) {
//		  if (a->next == NULL) {
//			  a->next = b;
//		  }
//		  else {
//			  concatenate(a->next, b);
//		  }
//	  }
//	  else {
//		  cout << "both node pointing to NULL\n";
//	  }
//  }
//
//};
//
//int main()
//{
//	linked_list a, b;
//
//	a.add_node(1);
//	a.add_node(2);
//
//	b.add_node(10);
//	b.add_node(9);
//	b.add_node(8);
//	a.front(99);
//	linked_list::concatenate(a.gethead(), b.gethead());
//	a.after(a.gethead()->next->next->next->next, 77);
//	a.del(a.gethead());
//
//	
//	linked_list::display_using_recursion(a.gethead());
//
//    return 0;
//}

