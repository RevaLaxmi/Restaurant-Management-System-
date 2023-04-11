void displayList(struct node *head){
    struct node *temp1 = head;
    if(temp1==NULL){
        printf("EMPTY\n");
    }
    else{
        printf("\n");
        while(temp1!=NULL){
            if(temp1->amount==0)
                printf(temp1->entry,temp1->itemname,temp1->costprice);
            else{
                printf(temp1->entry,temp1->itemname,temp1->amount,temp1->costprice);
            }
            temp1 = temp1->right;
        }
        printf("\n");
    }
}