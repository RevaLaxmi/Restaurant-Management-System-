void calculatetotsales(){
    struct node *temp = head_3;
    while(temp!=NULL){
        head_s = sales(temp->entry, temp->amount);
        temp=temp->right;
    }
}