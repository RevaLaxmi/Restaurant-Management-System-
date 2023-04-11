int main()
{
    head_1 = theadministrators(head_1,1,"Eggroll",60);
    head_1 = theadministrators(head_1,2,"Plain Maggi",30);
    head_1 = theadministrators(head_1,3,"Chicken Sandwhich",70);
    head_1 = theadministrators(head_1,4,"Hot Chocolate",50);
    head_1 = theadministrators(head_1,5,"Fried Momos",120);
//using switch and case here.. because itll just be easier than doing like 50 if else commands or calling function form main .. that kept resulting in some error
    while(1){
        originalmenu();
        int choice;
        scanf("%d",&choice);
        if(choice==3){
            printf("Complete\n");
            break;
        }
        switch (choice){
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
                break;

            default:
                printf("WRONG INPUT, PLEASE RE-ENTER OPTION NUMBER\n");
                break;
        }
    }
}