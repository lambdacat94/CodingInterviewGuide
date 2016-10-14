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

int testarr1[] = { 1, 3, 4, 5, 7, 9, 11 };
int testarr2[] = { 2, 3, 5, 6, 7, 8, 11 };

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

	Node *p = createLinkList(testarr1, 7);
	Node *q = createLinkList(testarr2, 7);

	printLinkList(p);
	printLinkList(q);

	printCommonPart(p, q);

	return 0;
}