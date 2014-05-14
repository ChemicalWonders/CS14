// Problem #3
int num (Node* n){
    if (n==NULL)
        return 0;
    
    return 1+num(n ->left) + num (n -> right);
}
