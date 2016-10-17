
class Node {
public:
	int value;
	Node *next;
	Node(int data) {
		this->value = data;
	}
};

Node *reverseList(Node *head) {
	Node *pre = nullptr, *next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

