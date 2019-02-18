#include "bits/stdc++.h"
using namespace std;

namespace Tree {

	template < class T>
	class Node{
	public:
		Node* left;
		Node* right;
		T data;
		Node(){};
		Node(T data): 
		data(data),left(NULL),right(NULL) {}
	};

	template < class T >
	class Bst{

	private:

		int size;
		Node < T >* root;

		bool find(Node < T > *root, T key) {
			if(root == NULL)
				return false;
			if(key == root->data)
				return true;
			if(key < root->data)
				return find(root->left,key);
			else
				return find(root->right,key);
		}

		void insert(Node < T > *root, T key) {
			if(root == NULL) {
				root = new Node < T > (key);
				return;
			}

			if(root->data > key)
				if(! root->left)
					root->left = new Node < T > (key);
				else
					insert(root->left,key);
			else
				if(! root->right)
					root->right = new Node < T > (key);
				else
					insert(root->right,key);
		}

		void inorder(Node < T >* root, vector < T > &nodes) {
			if(root == NULL)
				return;
			inorder(root->left,nodes);
			nodes.push_back(root->data);
			inorder(root->right,nodes);
		} 

		Node < T > * leftMostNode(Node < T > *root) {
			if(root->left == NULL)
				return root;
			else
				return leftMostNode(root->left);
		}

		// deletes the node and return the new root node
		// for current bst
		Node < T >* deleteNode(Node < T > *root, T key) {
			if(root == NULL)
				return NULL;
			if(key > root->data) {
				root->right = deleteNode(root->right,key);
			}
			else if(key < root->data) {
				root->left = deleteNode(root->left,key);
			}
			else {
				// 1) no child, one child
				if(root->left == NULL) {
					Node < T > * tmp = root->right;
					delete(root);
					return tmp;
				}
				else if(root->right == NULL) {
					Node < T > * tmp = root->left;
					delete(root);
					return tmp;
				}
				// 2) two child
				Node < T > *tmp = leftMostNode(root->right);
				root->data = tmp->data;
				root->right = deleteNode(root->right,root->data);
			}
			return root;
		}

	public:

		Bst();
		Bst(T data);
		int getSize();
		void insert(T key);
		bool find(T key);
		vector < T > inorderTraversal();
		void deleteNode(T key);
	};

	template < class T >
	Bst < T > :: Bst() {
		this->root = new Node<T>();
		this->size = 0;
	}

	template < class T >
	Bst < T > :: Bst(T key) {
		this->root = new Node < T >(key);
		this->size = 1;
	}

	template < class T >
	int Bst < T > :: getSize() {
		return this->size;
	}

	template < class T >
	void Bst < T > :: insert(T key) {
		if(!(*this).getSize()) {
			this->root->data = key;
			return;
		}
		this->size++;
		insert(root,key);
	}

	template < class T >
	vector < T > Bst<T> :: inorderTraversal() {
		vector < T > inorderNodes;
		inorder(this->root,inorderNodes);
		return inorderNodes;
	}

	template < class T >
	bool Bst < T > :: find(T key) {
		return find(this->root,key);
	}

	template < class T >
	void Bst < T > :: deleteNode(T key) {
		this->root = deleteNode(this->root,key);
	}
}

int main(int argc, char const *argv[])
{
	Tree :: Bst < int > b(10);
	cout << b.getSize() << endl;
	b.insert(23);
	b.insert(3);
	b.insert(12);
	vector < int > v = b.inorderTraversal();
	for(auto val : v)
			cout << val << " ";
	cout << endl;
	cout << b.find(12) << endl;
	cout << b.find(50) << endl;

	b.deleteNode(12);

	v = b.inorderTraversal();
	for(auto val : v)
			cout << val << " ";
	cout << endl;

	return 0;
}