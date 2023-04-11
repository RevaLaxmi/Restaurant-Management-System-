struct node* thecustomer(struct node *head,int entry,int amount){
    n_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp1 = head_1;
    int basecount = 0;
    while(temp1!=NULL){
        if(temp1->entry==entry){
            basecount = 1;
            break;
        }
        temp1 = temp1->right;
    }
    if(basecount==1){
        n_node->entry = entry;
        n_node->costprice = amount*(temp1->costprice);
        n_node-> amount = amount;
        //The strcpy() function copies the string pointed by source (including the null character) to the destination.
        //strcpy() function copies string2 this will also be including the ending null character, to the location that is specified by string1.
        //here we have it for itemname for the newnode and the temp1
        strcpy(n_node->itemname,temp1->itemname);
        n_node->right = NULL;
        n_node->left = NULL;

        struct node *temp = head;

        if(temp==NULL)
            head_3 = tail_3 = n_node;
        else{
            while(temp->right!=NULL)
                temp=temp->right;
            temp->right=n_node;
            n_node->left = tail_3;
            tail_3 = n_node;
        }
    }
    else{
        printf("EMPTY: THIS ITEM DOES NOT EXIST\n");
    }
    return head_3;
}