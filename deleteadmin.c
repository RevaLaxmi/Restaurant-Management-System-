int deleteadmin(){
    printf("ENTER THE NUMBER OF THE FOOD ITEM THAT IS TO BE DELETED\n");
    int num;
    scanf("%d",&num);
    struct node* temp=head_1;
    while(temp!=NULL){
        if (temp->entry == num){
            head_1 = delete(num, head_1, tail_1);
            return 1;
        }
        temp=temp->right;
    }
    return 0;
}