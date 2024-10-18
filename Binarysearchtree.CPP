#include <iostream.h>
#include <conio.h>
struct bt_node {
    bt_node *left, *right;
    int data;
};
class bst {
    bt_node *root;
    bt_node* minValueNode(bt_node *node) {
	while (node && node->left != NULL)
	    node = node->left;
	return node;
    }
    bt_node* deleteNode(bt_node *root, int item) {
	if (root == NULL)
	    return root;
	if (item < root->data)
	    root->left = deleteNode(root->left, item);
	else if (item > root->data)
	    root->right = deleteNode(root->right, item);
	else {
	    if (root->left == NULL) {
		bt_node *temp = root->right;
		delete root;
		return temp;
	    } else if (root->right == NULL) {
		bt_node *temp = root->left;
		delete root;
		return temp;
	    }
	    bt_node *temp = minValueNode(root->right);
	    root->data = temp->data;
	    root->right = deleteNode(root->right, temp->data);
	}
	return root;
    }
public:
    bst() : root(NULL) {}
    void insert(int item) {
	bt_node *p = new bt_node;
	p->data = item;
	p->left = NULL;
	p->right = NULL;

	if (root == NULL) {
	    root = p;
	} else {
	    bt_node *parent = NULL, *ptr = root;
	    while (ptr != NULL) {
		parent = ptr;
		if (item > ptr->data)
		    ptr = ptr->right;
		else
		    ptr = ptr->left;
	    }
	    if (item < parent->data)
		parent->left = p;
	    else
		parent->right = p;
	}
    }
    void printBinTree(bt_node *ptr) {
	if (ptr != NULL) {
	    printBinTree(ptr->left);
	    cout << " " << ptr->data << " ";
	    printBinTree(ptr->right);
	}
    }
    void displayBinTree() {
	printBinTree(root);
	cout << endl;
    }
    int search(int item) {
	bt_node *ptr = root;
	while (ptr != NULL) {
	    if (item == ptr->data)
		return 1;
	    else if (item < ptr->data)
		ptr = ptr->left;
	    else
		ptr = ptr->right;
	}
	return 0;
    }
    void deleteNode(int item) {
	root = deleteNode(root, item);
    }
};
void push(bst& b, int i) { b.insert(i); }
void remove(bst& b) {
    int del;
    cout << "Enter the element to delete: ";
    cin >> del;
    b.deleteNode(del);
    cout << "Deleted successfully" << endl;
}
void find(bst& b) {
    int ser;
    cout << "Enter the element to search: ";
    cin >> ser;
    cout << "Searching for " << ser << ": " << (b.search(ser) ? "Found" : "Not Found") << endl;
}
void show(bst& b) {
    cout << "Binary tree: ";
    b.displayBinTree();
}
int main() {
    clrscr();
    bst b;
    int ch;
    while (1) {
	cout << "1: Insert\n2: Delete\n3: Search\n4: Display\n5: Exit\nEnter your choice: ";
	cin >> ch;
	switch (ch) {
	    case 1: {
		int j;
		cout << "Enter the value to push: ";
		cin >> j;
		push(b, j);
		break;
	    }
	    case 2: remove(b); break;
	    case 3: find(b); break;
	    case 4: show(b); break;
	    case 5: return 0;
	    default: cout << "Enter a valid choice" << endl;
	}
    }
}