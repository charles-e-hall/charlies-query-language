/********************
 * This program is to make sure that I am 
 * using pointers to my structs appropriately
 */

#include <iostream>

struct Test {
    int index;
    Test* child = nullptr;
};

void test_append(Test* root, int index);
void print_last(Test* root);
Test* generate_list(int length);
void print_all(Test* root);

int main() {
    Test my_test;
    my_test.index = 0;
    my_test.child = new Test;

    std::cout << "Index: " << my_test.index << std::endl;
    std::cout << "Child: " << my_test.child << std::endl;

    //dereference
    Test deref = *(my_test.child);
    std::cout << "Index of the child by deref: " << deref.index << std::endl;
    std::cout << "Child of the child by deref: " << deref.child << std::endl;

    if (deref.child == nullptr) {
        std::cout << "Initialized pointer is nullptr" << std::endl;
    }

    //test_append(&my_test, 10);
    //Test deref2 = *(deref.child);

    //std::cout << "Deref Index: " << deref2.index << std::endl;

    Test* pmy_test = &my_test;

    std::cout << "Index of the child by ptr: " << pmy_test->child->index << std::endl;
    std::cout << "Child of the child by ptr: " << pmy_test->child->child << std::endl;

    //pmy_test->child->child = new Test;
    test_append(pmy_test, 10);
    std::cout << "\nExecuted append function\n\n";

    std::cout << "Index of the child by ptr: " << pmy_test->child->index << std::endl;
    std::cout << "Child of the child by ptr: " << pmy_test->child->child << std::endl;
    std::cout << "Index of the child of the child by ptr: " << pmy_test->child->child->index << std::endl;
    print_last(pmy_test);

    std::cout << "Generating list ..." << std::endl;
    Test* pmylist = generate_list(12);
    std::cout << "Printing list ..." << std::endl;

    print_all(pmylist);

    return 0;
}

void test_append(Test* root, int index) {
    if (root->child == nullptr) {
        root->child = new Test;
        root->child->index = index;
    }
    else {
        test_append(root->child, index);
    }
}

void print_last(Test* root) {
    if (root->child == nullptr) {
        std::cout << "Last element is: " << root->index << std::endl;
    }
    else {
        print_last(root->child);
    }
}

Test* generate_list(int length) {
    Test* plist = new Test;

    for (int i=0; i<length; i++) {
        test_append(plist, i);
    }

    return plist;
}

void print_all(Test* root) {
    std::cout << root->index << std::endl;

    if (root->child != nullptr) {
        print_all(root->child);
    }
}