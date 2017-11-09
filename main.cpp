#include <iostream>
#include <cstdlib>
#include <mem.h>

using namespace std;

class Node {
    string data;
    Node *left, *right = nullptr;

public:
    Node(string data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    static Node *root;

    //Methods
    static void insert(string value);

    static void preOrderTransversal(Node *tree);

    static void postOrderTransversal(Node *tree);

    static void inOrderTransversal(Node *tree);
};

Node *Node::root = nullptr;

void printMenu();

int main() {

    printMenu();
    while (true) {
        int option;
        cout << "Enter Option: ";
        cin >> option;
        string value;
        switch (option) {

            case 0:
                cout << "Exiting Program.." << endl;
                exit(0);
            case 1:
                cout << "Insert Value" << endl;
                cin >> value;
                Node::insert(value);
                break;
            case 2:
                cout << "Search value: " << endl;
                cin >> value;
//                Node::search(value);
                break;
            case 3:
                cout << "Transversal: " << endl;
                Node::inOrderTransversal(Node::root);
                break;
            case 4:
                printMenu();
                break;
            default:
                cout << "Enter A Valid Number" << endl;
        }
    }
}

void printMenu() {
    cout << "0. Exit" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Transversal" << endl;
    cout << "4. Print Menu" << endl;
}

void Node::insert(string value) {
    //Creating the node to be inserted
    Node *newNode = new Node(value);
    //Check if tree is empty, if yes insert at root
    if (root == nullptr) {

        root = newNode;
        cout << "Inserted at Root" << endl;
    } else {    //Tree is not empty
        //We will start with making current node as the root node
        Node *current = root;

        if (strcmpi(root->data.c_str(), value.c_str()) ==
            0) {//Check if is same at root, if yes then duplicate message,No node addded
            cout << "Duplicate Value..";
        } else {
            while (true) {
                //Looping till we dont find the place to insert the node or duplicate value

                if (strcmpi(current->data.c_str(), value.c_str()) >
                    0) {//Will be true, if value to be inserted is less than the current node

                    if (current->left == nullptr) {//we check if left is Empty, if yes - insert at left

                        current->left = newNode;
                        cout << "Inserted at left" << endl;
                        return;
                    } else {

                        current = current->left;    //if left is not empty, left node will become the current node and again we check bot left and right sides
                    }

                } else if (strcmpi(root->data.c_str(), value.c_str()) <
                           0) {//Will be true if value to be inserted is greater than the current node

                    if (current->right == nullptr) {//we check if right is Empty, if yes - insert at right

                        current->right = newNode;
                        cout << "Inserted at right" << endl;
                        return;
                    } else {

                        current = current->right;   //if right is not empty, right node will become the current node and again we check bot left and right sides
                    }
                } else {    //will be true if value to be inserted is same as current meaning duplication

                    cout << "Duplicate Value" << endl;
                    return;

                }
            }

        }

    }
}


void Node::preOrderTransversal(Node *tree) {

    if (tree == nullptr) {
//        cout << "Tree is NULL" << endl;
        return;
    }
    cout << tree->data << endl;
    preOrderTransversal(tree->left);
    preOrderTransversal(tree->right);
}


void Node::inOrderTransversal(Node *tree) {
    if (tree != nullptr) {
        inOrderTransversal(tree->left);
        cout << tree->data << endl;
        inOrderTransversal(tree->right);
    }
}

void Node::postOrderTransversal(Node *tree) {

    if (tree != nullptr) {
        postOrderTransversal(tree->left);
        postOrderTransversal(tree->right);
        cout << tree->data << endl;
    }
}
