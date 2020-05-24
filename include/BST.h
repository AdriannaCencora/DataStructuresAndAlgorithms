

#include "GenericStructure.h"

#include <memory>

class BST : public GenericStructure {
    public:
        BST() = default;
        BST(int size) : size(size) {}
        virtual ~BST() = default;

        virtual void insert(int position, int value);
        virtual void remove(int value);
        virtual bool search(int value);
        virtual int getSize() const;
        virtual void print();
        virtual void fillWithRandomData(int givenSize, int givenUpperRange);
		virtual void readFromFile(FileHandler& fileHandler);
		virtual void clearStructure();

		void fixBalance();

		struct Node {
			Node(int nodeData) : data(nodeData) {}

			int data{};
			Node* parent{nullptr};
			Node* leftChild{nullptr};
			Node* rightChild{nullptr};
		};


    private:
		Node* insert(Node* currentParent, int value);
		Node* search(Node* node, int value);
		void remove(Node* nodeToDelete);
		Node* findNodeByValue(int value);
		bool isEmpty();
		void rotateLeft(Node* axis);
		void rotateRight(Node* axis);
		void makeLinear();
		void makeBalanced();
		Node* getMin(Node* node);
	    Node* getMax(Node* node);
		Node* getPredecessor(Node* node);
		Node* getSuccessor(Node* node);
		void printNode(const std::string &sMiddle, const std::string &sBefore, Node* currNode);
		void clearStructure(Node *node);


		Node* root{nullptr};
		size_t size{};


};
