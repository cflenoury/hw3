#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct isNeg{
	bool operator()(int x){	return x <0 ;}
};

struct isEven{
	bool operator()(int x){	return x%2 == 0 ;}
};

struct greaterThanXX{
	bool operator()(int x){	return x > 20 ;}
};

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

		//Testing Llpivot
    // Node* smaller = nullptr;
    // Node* larger = nullptr;

    // llpivot(head, smaller, larger, 20);

    // print(head);
    // print(smaller);
    // print(larger);

		isEven c1;
		isNeg c2;
		greaterThanXX c3;

		//Node* fin1 = llfilter(head, c1);
		//Node* fin2 = llfilter(head, c2);
		Node* fin3 = llfilter(head, c3);

		///print(fin1);
		//print(fin2);
		print(fin3);
    
    return 0;
}
