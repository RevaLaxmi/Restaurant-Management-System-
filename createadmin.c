struct node* theadministrators(struct node *head,int entry, char itemname[30], float costprice){
    n_node = (struct node*)malloc(sizeof(struct node));
    //have the newnode point to the entry or costprice etc as the user will make new entries 
    n_node->entry = entry;
    n_node->costprice = costprice;
    //set amount to 0 
    n_node-> amount = 0;
    //The strcpy() function copies the string pointed by source (including the null character) to the destination.
    //strcpy() function copies string2 this will also be including the ending null character, to the location that is specified by string1.
    //here we have it for itemname
    strcpy(n_node->itemname,itemname); 
    //implementing left and right pointers in this case
    n_node->right = NULL;
    n_node->left = NULL;
    struct node *temp = head;
    if(temp==NULL)
        head_1 = tail_1 = n_node;
    else{
        while(temp->right!=NULL)
            temp=temp->right;
            //while that is the case we have...
            //redirecting node 
        temp->right=n_node;
        n_node->left = tail_1;
        tail_1 = n_node;
    }
    return head_1;
}

// Allocates a new node with the given key and NULL left and right pointers.
/*
struct node *TreeNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
*/
