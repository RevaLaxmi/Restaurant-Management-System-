int deletecustomer(){
    printf("ENTER THE NUMBER OF THE FOOD ITEM THAT IS TO BE DELETED\n");
    int num;
    scanf("%d",&num);
    struct node* temp=head_3;
    while(temp!=NULL){
        if (temp->entry == num){
            head_3 = delete(num, head_3, tail_3);
            return 1;
        }
        temp=temp->right;
    }
    return 0;
}