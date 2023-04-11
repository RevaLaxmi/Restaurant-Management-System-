struct node* sales(int entry,int amount){
    n_node = (struct node*)malloc(sizeof(struct node));
    int basecount = 0;
    struct node *temp1 = head_1;
    while(temp1->entry!=entry){
        temp1 = temp1->right;
    }
    n_node->entry = entry;
    n_node->costprice = amount*(temp1->costprice);
    n_node-> amount = amount;
    //The strcpy() function copies the string pointed by source (including the null character) to the destination.
    //strcpy() function copies string2 this will also be including the ending null character, to the location that is specified by string1.
    //here we have it for itemname for the newnode and the temp1
    strcpy(n_node->itemname,temp1->itemname);
    n_node->right = NULL;
    n_node->left = NULL;
    struct node *temp = head_s;
    if(temp==NULL)
        head_s = n_node;
    else{
        while(temp->right!=NULL){
            if(temp->entry==entry){
                basecount = 1;
                break;
            }
            temp=temp->right;
        }
        if(basecount==1){
            temp->amount += n_node-> amount;
            temp->costprice += n_node->costprice;
        }
        else{
            temp->right=n_node;
        }
    }
    return head_s;
}