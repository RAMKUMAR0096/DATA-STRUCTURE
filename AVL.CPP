#include<iostream.h>
#include<conio.h>
struct Node {
    int key, height;
    Node* left;
    Node* right;
};
int height(Node* N) {
    return N ? N->height : 0;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
Node* rR(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node* lR(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* N) {
    return N ? height(N->left) - height(N->right) : 0;
}
Node* insert(Node* node, int key) {
    if (!node) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (key < node->key) 
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    else 
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rR(node);
    if (balance < -1 && key > node->right->key)
        return lR(node);
    if (balance > 1 && key > node->left->key) {
        node->left = lR(node->left);
        return rR(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rR(node->right);
        return lR(node);
    }
    return node;
}
Node* minNode(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key) 
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
	    return temp;
	}
	Node* temp = minNode(root->right);
	root->key = temp->key;
	root->right = deleteNode(root->right, temp->key);
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rR(root);
    if (balance < -1 && getBalance(root->right) <= 0) return lR(root);
    if (balance > 1 && getBalance(root->left) < 0) {
	root->left = lR(root->left);
	return rR(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
	root->right = rR(root->right);
	return lR(root);
    }
    return root;
}
void display(Node* root) {
    if (root) {
	cout << root->key << " ";
	display(root->left);
	display(root->right);
    }
}
void main() {
    clrscr();
    Node* root = NULL;
    int choice, key;
    do {
	cout << "\n1. Insert\n2. Delete\n3. Display (Pre-order)\n4. Exit\nChoose an operation: ";
	cin >> choice;
	switch (choice) {
	    case 1:
		cout << "Enter key to insert: ";
		cin >> key;
		root = insert(root, key);
		break;
	    case 2:
		cout << "Enter key to delete: ";
		cin >> key;
		root = deleteNode(root, key);
		break;
	    case 3:
		cout << "Tree elements (Pre-order): ";
		display(root);
		cout << endl;
		break;
	    case 4:
		cout << "Exiting.\n";
		break;
	    default:
		cout << "Invalid choice. Try again.\n";
	}
    } while (choice != 4);
    getch();
}
