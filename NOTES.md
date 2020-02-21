# Notes

 * recommend compiling with warnings enabled and potentially with warnings treated as errors
   * g++ -std=c++11 -Wall -Werror cql.cpp -o cql
 * add -std=c++11 to gcc line in Makefile to enable C++11 features (for example, in-class initialization of non-static members)
 * string (and other types from the STL) need to start with std:: -> this kept me from being able to compile this using g++
 * always null check when a raw pointer is the input
   * it's a bit tedious, but will keep unexpected crashes down
 * in `select_row`, start with a null check and report your "does not exist" message there
   * instead of the nested `if/else` just send the `left` and `right` node directly to `select_row` and let the initial null check handle it
   * this should help reduce redundant checks and make the implementation more concise while having the same effect
   * see proposed implementation below (my go-to formatting is a bit different from what you have, but your original code should still be clearly visible)
 * you might find it useful when doing node-based data models like this to have a way to print the nodes starting at a provided node `print_nodes(const Node* pRoot)` where `pRoot` does not necessarily have to be the true root of the tree, but the root from which you want to start printing
   * just walk the tree and print the value at each node; you can decide how fancy you want formatting to be

``` cpp
// Proposed update of select_row
//Recursively searches through the b-tree based on the index
void select_row(Row* root, int index)
{
    if(root == nullptr)
    {
        std::cout << "Index does not exist" << std::endl;
        return;
    }
    if(index == root->index)
    {
        std::cout << "Index: " << root->index << "\tData: " << root->data << std::endl;
    }
    else if(index < root->index)
    {
        select_row(root->left, index);
    }
    else if(index > root->index)
    {
        select_row(root->left, index);
    }
}
```
