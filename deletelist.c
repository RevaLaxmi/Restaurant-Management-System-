struct node* deleteList(struct node* head){
    if(head==NULL){
        return NULL;
    }
    else{
        struct node* temp = head;
        while(temp->right!=0){
            temp = temp->right;
            free(temp->left);
        }
        free(temp);
        head = NULL;
    }
    return head;
}