void displaybill(){
    displayList(head_3);
    struct node *temp = head_3;
    float fullprice = 0;
    while (temp!=NULL){
        fullprice +=temp->costprice;
        temp = temp->right;
    }
    printf("BILL AMOUNT IS ",fullprice);
}