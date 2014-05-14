int record_average(Node* n){
    int count = 0;
    int number = 0;
    
    if (n = null){
        return 0;
    }
    
    count += n-> value;
    number += 1;
    record_average(n -> left);
    record_average(n ->right);
    
    return count/number;
}
