// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


struct node {
	int data;
	node* next;
};

class LinkList {
	node *head,*tail;

public:
	LinkList() {
		head = NULL;
		tail = NULL;
	}
	void addNode(int data) {
		
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;// old next poter to 
			tail = temp;
		}
		
	}

	void addNodeSart(int data) {
		node *temp = new node;
		temp->data = data;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}

	}

	void addNodeAfter(node *nth, int data) {
		node *temp = new node;
		temp->data = data;
		temp->next = nth->next;
		nth->next = temp;
	}

	void rmNode(node *nth) {
		node *temp = new node;
		temp = nth->next;
		nth->next = temp->next;
		delete temp;
	}

	void joinNode(node *a, node *b) {
		if (a != NULL && b != NULL) {
			if (a->next == NULL)
				a->next = b;
			else
				joinNode(a->next, b);
		}
		
	}



	void display(node* head) {
		if (head != NULL) {
			std::cout << head->data << std::endl;
			display(head->next);
		}
	}

	node* getNode(){
		return head;
	}

};

int main()
{
    std::cout << "Hello World!\n"; 
	LinkList A,B;
	
	A.addNodeSart(10);
	A.addNodeSart(30);
	A.addNodeSart(50);
	A.addNodeSart(70);

	B.addNode(20);
	B.addNode(40);
	B.addNode(60);
	B.addNode(80);

	B.addNodeAfter(B.getNode()->next->next, 1000);
	B.rmNode(B.getNode());

//	A.joinNode(A.getNode(), B.getNode());
	A.display(A.getNode());
	std::cout << "@@@" <<std::endl;
	B.display(B.getNode());


}

