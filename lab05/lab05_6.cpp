//Kevin Chan
//Lab #5, Problem #6

int my_func(struct node* node)
{
    if (node == NULL)
        return 1;
    
    if (node-> left != NULL && node->left->data > node->data)
        return 0;
    
    if (node->right != NULL && node->right->data <= node->data)
        return 0;
        
    if(!my_func(node->left) || !my_func(node->right))
        return 0;
        
    return 1;
}
// If the node is a leaf, then the value is 1;
// If the left node is not empty, and it is bigger than the data,
// it will return a 0;
// If the right node is not empty and it is smaller than the data,
// it will return a 0;
// Finally, if the nodes are ordered, then it will return a 0.
// This function will check if it is ordered or not.
