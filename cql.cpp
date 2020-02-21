/****************************
 * This program is a command line sql-like utility
 * The purpose of this is to be an exercise for learning
 * binary search trees and file io.
 * The name "CQL" comes from Charlie's (Structured) Query Language
 * Changing "SQL" to "CQL"
 * 
 * My goal with CQL is not to exactly mimic SQL.  I have a somewhat limited understanding
 * of how true SQL engines actually work under the hood, and there is frustratingly limited
 * information that can be found on this.  Furthermore, SQL is so mature that full blown SQL engines are far
 * too highly engineered to use as starting points for understanding rudiments.  It would be like
 * trying to understand the most basic elements of an OS by starting with Windows 10.
 * Therefore, I am using what I know about SQL as an end-user paired with what I am learning
 * about Trees and sorting algorithms to implement how I imagine a basic SQL could work (but probably doesn't)
 * I have believed for some time that I can't truly understand something until I can build it
 * from scratch, so that is what I am doing here.
 * This is purely a fun learning exercise for me to learn CS fundamentals (trees, traversal, etc) and C/C++.
 * 
 * Eventually I want to turn this into a full command line utility
 * Right now, if using the Makefile, the "make build" command will compile
 * the program, move the binary to the ~/bin folder, chmod it, and add the binary to the PATH
 * so you can use it at the command line.
 * What I need to add is string parsing inside my "while (true)" loop so that I can 
 * input commands to be executed.
 *****************************/

#include <iostream>
#include <string>

template <int num_col>
struct Data {
    string column_names[num_col];
    string column_types[num_col];
};

//Calling it a row, but really a node in a b-tree
//For prototyping purposes, my data is just int
//but eventually I want it to be a pointer to a templated struct that
//holds all the data for that row.
//Also, initializing the pointers with nullptr works, but causes
//a compiler warning.  Honestly not sure how I would do this without using nullptr
struct Row {
    int index;
    int data;
    //Data<3>* data;
    Row* left = nullptr;
    Row* right = nullptr;
    Row* parent = nullptr;
};

//Not sure what I'm going to do with this yet
//Feels kinda weird referring to a table by the first row
//Therefore, would love to incorporate a Table struct
//Also, in the future, there will be more data associated
//with a table than just the b-tree holding the index
struct Table {
    Row root;
};

void insert_row(Row* root, int index, int data);
void select_row(Row* root, int index);
Row* generate_table(int num_rows);

int main() {
    std::cout << "Welcome to CQL" << std::endl;
    /*
    //I will eventually turn this into a command line program 
    //where you can just enter CQL statements.
    std::string statement;
    while(true) {
        std::cout << ">>";
        std::cin >> statement;
        std::istringstream iss(statement);
        std::vector<std::string> results(
            (std::istream_iterator<std::string>(iss)),
            std::istream_iterator<std::string>()
        );
    }
    */
   //For now though, I keep it simple
   int num_rows;
   std::cout << "How many rows: ";
   std::cin >> num_rows;
   Row* ptable = generate_table(num_rows);
   std::cout << "\nSelect an index: ";
   int requested_index;
   std::cin >> requested_index;
   std::cout << std::endl;
   select_row(ptable, requested_index);
    
    return 0;
}

//Recursively searches through the b-tree based on the index
void select_row(Row* root, int index) {
    if (index == root->index) {
        std::cout << "Index: " << root->index << "\tData: " << root->data << std::endl;
    }
    else if (index < root->index) {
        if (root->left == nullptr) {
            std::cout << "Index does not exist" << std::endl;
        }
        else {
            select_row(root->left, index);
        }
    }
    else if (index > root->index) {
        if (root->right == nullptr) {
            std::cout << "Index does not exist\n" << std::endl;
        }
        else {
            select_row(root->right, index);
        }
    }
}

//Adds the appropriate node to the b-tree
void insert_row(Row* root, int index, int data) {
    if (root->index == index) {
        std::cout << "This index already exists" << std::endl;
    }
    else if (index < root->index) {
        if (root->left == nullptr) {
            root->left = new Row;
            root->left->index = index;
            root->left->data = data;
            root->left->parent = root;
        }
        else {
            insert_row(root->left, index, data);
        }
    }
    else if (index > root->index) {
        if (root->right == nullptr) {
            root->right = new Row;
            root->right->index = index;
            root->right->data = data;
            root->right->parent = root;
        }
        else {
            insert_row(root->right, index, data);
        }
    }
}

Row* generate_table(int num_rows) {
    Row* ptable = new Row;

    for (int i=0; i<num_rows; i++) {
        //I realize that overflow of the int data will happen
        //I'm just trying to generate dummy data so overflow is fine
        insert_row(ptable, i, i*i);
    }
    return ptable;
}