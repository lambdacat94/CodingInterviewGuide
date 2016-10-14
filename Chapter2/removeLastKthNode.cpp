// #define LOCAL

#include <fstream>
#include <iostream>


using namespace std;

struct Node {
	int value;
	Node *next;
	Node(int data) {
		value = data;
	}
};

void printCommonPart(Node *head1, Node *head2) {
	cout << "Print the common part of two link list" << endl;
	while (head1 != nullptr && head2 != nullptr) {
		if (head1->value < head2->value) head1 = head1->next;
		else if (head2->value < head1->value) head2 = head2->next;
		else cout << head1->value << " ", head1 = head1->next, head2 = head2->next;
	}
	cout << endl;
}

Node *removeLastKthNode(Node *head, int lastKth) {
	Node *p = head;
	while (lastKth--) p = p->next;
	p = p->next;
	Node *q = head;
	while (p != nullptr) p = p->next, q = q->next;
	Node *r = q->next;
	q->next = r->next;
	delete r;
	return head;
}

DoubleNode *removeLastKthDNode(DoubleNode *head, int lastKth) {
	DoubleNode *p = head;
	while (lastKth--) p = p->next;
	p = p->next;
	DoubleNode *q = head;
	while (p != nullptr) p = p->next, q = q->next;
	DoubleNode *r = q->next;
	q->next = r->next;
	r->next->last = q;
	delete r;
	return head;
}



int testarr1[] = { 1, 3, 4, 5, 7, 9, 11 };
int testarr2[] = { 2, 3, 5, 6, 7, 8, 11 };

// 创建一个内容为 arr 的单链表，长度为 size
Node *createLinkList(int *arr, int size) {
	Node *p = new Node(arr[0]);
	Node *head = p;
	for (int i = 1; i < size; ++i) {
		p->next = new Node(arr[i]);
		p = p->next;
	}
	p->next = nullptr;
	return head;
}

struct DoubleNode {
	int value;
	DoubleNode *last;
	DoubleNode *next;
	DoubleNode(int data) {
		value = data;
	}
};


// 创建一个内容为 arr 的双链表，长度为 size
DoubleNode *createDLinkList(int *arr, int size) {
	DoubleNode *p = new DoubleNode(arr[0]);
	DoubleNode *q = p, *head = p;
	p->last = p->next = nullptr;
	if (size >= 2) {
		p->next = new DoubleNode(arr[1]);
		q = p; p = p->next;
		p->last = q;
	}
	else
		return head;
	for (int i = 2; i < size; ++i) {
		p->next = new DoubleNode(arr[i]);
		q = p;
		p = p->next;
		p->last = q;
	}
	p->next = nullptr;
	return head;
}

// 输出一个双链表的所有节点
void printDLinkList(DoubleNode *head) {
	cout << "print DLinkList " << endl;
	DoubleNode *p = head, *q = head;
	while (p != nullptr) {
		q = p;
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
	cout << "print reverse DLinkList " << endl;
	while (q != nullptr) {
		cout << q->value << " ";
		q = q->last;
	}
	cout << endl;
}


// 输出一个单链表的所有节点
void printLinkList(Node *head) {
	Node *p = head;
	while (p != nullptr) {
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char **argv) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	DoubleNode *dp = createDLinkList(testarr1, 7);
	printDLinkList(dp);

	return 0;
}