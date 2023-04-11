void customer(){
    int basecount=0,j=1;
    char ch;
    printf("CUSTOMER SECTION");
    while(1){
        customersection();
        //we're creating this to be the customer option menu part
        int opt;
        scanf("%d",&opt);
        if(opt==5)
        //now ofcourse if the user clicks 5 that goes back to the main menu, so it breaks
            break;
        switch (opt){
            case 1:
                displayList(head_1);
                printf("ENTER THE NUMBER OF THE ITEM YOU WANT TO ORDER\n");
                //ok the user will order
                //what if they want numerous of the same thing <- feedback given
                int n;
                scanf("%d",&n);
                //ok so like.. if we're ordering but ofcourse want more than just one.. like 3 chais? or 3 maggis.. 2 eggrolls and so on
                printf("HOW MANY OF THIS ITEM DO YOU WANT?\n");
                int amount;
                scanf("%d",&amount);
                head_3 = thecustomer(head_3, n, amount);
                break;
            case 2:
                printf("THIS IS WHAT YOU HAVE ORDERED SO FAR\n");
                displayList(head_3);
                break;
            case 3:
            //for when the customer wants to know what theyve ordered - it's like you have them read it back to you in an actual restraunt 
            //here we'll just print it back
                if(deletecustomer()){
                    printf("THIS IS A NEW LIST OF WHAT YOU HAVE ORDERED\n");
                    displayList(head_3);
                }
                else
                    printf("THIS FOOD ITEM DOES NOT EXISTS\n");
                break;
            case 4:
                calculatetotsales();
                printf("THE BILL\n");
                displaybill();
                head_3 = deleteList(head_3);
                //I think it'll just be neater here to specify where to go back for the main menu.. but what we can do is use
                printf("PRESS 'B' TO GO BACK TO THE MAIN MENU");
                //fflush(stdin) should discard any unused input
                fflush(stdin);
                //and we had a character: char=ch so here
                // fgetc() function reads a single unsigned character from the input stream at the current position and increases the associated file pointer
                ch=fgetc(stdin);
                //so then it equates the basecount to be 1
                basecount=1;
                break;
            default:
                printf("INPUT IS WRONG, ENTER AN OPTION NUMBER\n");
                break;
        }
        if(basecount==1)
            break;
    }
}