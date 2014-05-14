int leaves(Node* root){
    Node* temp = root;
    if(root-> left == NULL && root -> right ==NULL)
        return 1;
        
    if (root -> left != NULL && root -> right == NULL)
        return leaves(temp->left);
    
    if (root -> left == NULL && root -> right != NULL)
        return leaves(temp-> right);
        
    return leaves(temp -> left) + leaves(temp -> right);
}
