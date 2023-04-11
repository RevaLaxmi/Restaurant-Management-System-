struct node* delete(int entry,struct node *head, struct node* tail){
    //If Root is NULL: We simply return the root. In this case we have the head, root to be null - so we simple print "EMPTY" 
    if(head==NULL){
        printf("EMPTY");
    }
    else{
            //Else Splay the given key (acc to name). If (acc to name) is present, then it becomes the new root. If not present, then last accessed leaf node becomes the new root.
        struct node* temp;
        if(entry==head->entry){
            temp = head;
            head = head->right;
            if (head != NULL)
                head->left = NULL;
            free(temp);
        }
        //last accessed leaf node becomes the new root.
        else if(entry==tail->entry){
            temp = tail;
            tail = tail->left;
            tail->right = NULL;
            free(temp);
        }
        //last accessed leaf node becomes the new root.
        else{
            temp = head;
            while(entry!=temp->entry){
                temp = temp->right;
            }
            (temp->left)->right = temp->right;
            (temp->right)->left = temp->left;
            free(temp);
        }
    }
    return head;
}


//delete in splay trees are as follows