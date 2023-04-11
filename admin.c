void admin(){
    printf("FOR THE ADMINISTRATORS");
    while(1){
        administratorsection();
        int opt;
        scanf("%d",&opt);
        if(opt==5)
            break;
        switch (opt){
            case 1:
                displayList(head_s);
                break;
            case 2:
                printf("ENTER THE NUMBER OF THE FOOD ITEM: \n");
                int num,basecount = 0;
                char name[50];
                float costprice;
                scanf("%d",&num);
                struct node *temp = head_1;
                while(temp!=NULL){
                    if(temp->entry==num){
                        //now if the food item serial number already exists, we havent written any splay tree that can replace it
                        //so we cannot replace the food item
                        //we can only add or delete
                        //so in this case we just go over it, do not write over anything
                        //just mention the options again and the user can re-choose an item
                        printf("THIS FOOD ITEM ALREADY EXISTS: WE WILL REPRINT YOUR OPTIONS BELOW");
                        basecount = 1;
                        break;
                    }
                    temp = temp->right;
                }
                if(basecount==1)
                    break;
                    //allow them to name the food
                    //..we need name and pricing ofcourse - keep a limit on the int.. so like for now yo ucan give campus pricings?
                    //or actually this is dependent on the user so error message will be needed if it goes over..
                    //for some reason the code is also just stopping there so that's messed up
                printf("Enter food item name: ");
                scanf("%s",name);
                printf("Enter price: ");
                scanf("%f",&costprice);
                head_1 = theadministrators(head_1, num, name, costprice);
                printf("New food item added to the list!!\n\n");
                break;
                //why does the code stop here.. should we just remove the admin/ customer option completely and keep it only to be customer? 
                //see the difference for like admin and user needs a login
                //but that's to difficult to implement..
                //like right now the user is just chosing between admin control vs user control..nothing else. 
                //ok we'll look into the whole user admin thing later - maybe we can have a csv file with stored user info and cross check through that???
            case 3:
                if(deleteadmin()){
                    printf("NEW MENU\n");
                    displayList(head_1);
                }
                else
                    printf("EMPTY: THIS FOOD ITEM DOES NOT EXIST\n");
                break;
            case 4:
                printf("THE MENU\n");
                displayList(head_1);
                break;
            default:
                printf("INPUT IS WRONG, PLEASE ENTER AN OPTION NUMBER\n");
                break;
        }
    }
}