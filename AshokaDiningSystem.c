/*
If the code is wrong it just in general splits off, so youll have to restart by deleting whatever is there. 
*/

/*
Splay trees are the self-balancing or self-adjusted binary search trees. In other words, we can say that the splay trees are the variants of the binary search trees. The prerequisite for the splay trees that we should know about the binary search trees.

As we already know, the time complexity of a binary search tree in every case. 
The time complexity of a binary search tree in the average case is O(logn) and the time complexity in the worst case is O(n). 
In a binary search tree, the value of the left subtree is smaller than the root node, and the value of the right subtree is greater than the root node; in such case, the time complexity would be O(logn). 
If the binary tree is left-skewed or right-skewed, then the time complexity would be O(n). To limit the skewness, the AVL and Red-Black tree came into the picture, having O(logn) time complexity for all the operations in all the cases. 
We can also improve this time complexity by doing more practical implementations, so the new Tree data structure was designed, known as a Splay tree.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char itemname[50];
    int amount;
    float costprice;
    int entry;
    struct node *left;
    struct node *right;
};

//struct node *head_3 = NULL;
//struct node *n_node = NULL;
//struct node *tail_3 = NULL;

//struct node *head_1 = NULL;
//struct node *tail_1 = NULL;

struct node *head_3 = NULL,*n_node,*tail_3 = NULL;
struct node *head_1 = NULL, *tail_1 = NULL;
struct node *head_s;

//the int values for everything and the char values and so on can stay the same - char of [50] for a limit
/*
// Tree Node
struct node
{
    int key;
    struct node *left, *right;
};
*/
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

/*

Here we have
ADMIN SECTION :On clicking admin we're going to the adminmenu
CUSTOMER SECTION: On clicking customer we're going to the customermenu
EXIT

*/

void administratorsection()
{
    printf("1. TOTAL SALES\n");
    printf("2. ADD A NEW FOOD ITEM\n");
    printf("3. DELETE ANY FOOD ITEM\n");
    printf("4. DISPLAY THE MENU\n");
    printf("5. GO BCAK TO THE ORIGINAL MAIN MENU \n\n");
    printf("ENTER YOUR CHOICE ->");
}

/*

Now here the thing is that we have
TOTAL SALES
ADD NEW ITEMS TO ORDER MENU
DELETE ITEMS FROM ORDER MENU
DISPLAY THE ORDER MENU
BACK TO THE MAIN MENU

*/

void customersection()
{
    printf("1. WHAT FOOD ITEM DO YOU WANT\n");
    printf("2. VIEW THE ORDERED ITEMS\n");
    printf("3. DELETE AN ITEM FROM YOUR ORDER\n");
    printf("4. FINAL BILL FOR FOOD\n");
    printf("5. GO BCAK TO THE ORIGINAL MAIN MENU \n\n");
    printf("ENTER YOUR CHOICE ->");
}

/*

So here in the customer menu we have 
PLACE ORDER
VIEW ORDER
DELETE SOMETHING FROM ORDER
DISPLAY BILL
MAIN MENU

*/

struct node* theadministrators(struct node *head,int entry, char itemname[25], float costprice)
{
    n_node = (struct node*)malloc(sizeof(struct node));
    //have the newnode point to the entry or costprice etc as the user will make new entries 

    n_node->entry = entry;
    n_node->costprice = costprice;
    n_node-> amount = 0;
        //set amount to 0 
    strcpy(n_node->itemname,itemname);
    n_node->right = NULL;
    n_node->left = NULL;
    //The strcpy() function copies the string pointed by source (including the null character) to the destination.
    //strcpy() function copies string2 this will also be including the ending null character, to the location that is specified by string1.
    //here we have it for itemname
    struct node *temp = head;
    //implementing left and right pointers in this case
    if(temp==NULL)
        head_1 = tail_1 = n_node;
    else
    {
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

struct node* thecustomer(struct node *head,int entry,int amount)
{
    n_node = (struct node*)malloc(sizeof(struct node));

    struct node *temp1 = head_1;
    int basecount = 0;
    while(temp1!=NULL)
    {
        if(temp1->entry==entry)
        {
            basecount = 1;
            break;
        }
        temp1 = temp1->right;
    }

    if(basecount==1)
    {
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
        else
        {
            while(temp->right!=NULL)
                temp=temp->right;

            temp->right=n_node;
            n_node->left = tail_3;
            tail_3 = n_node;
        }


    }
    else
    {
        printf("EMPTY: FOOD ITEM IS NOT PRESENT IN THE DATABASE MENU\n");
    }
    return head_3;
}

/*
for an example that I reffered to 

Zig-Zig (Left Left Case):
       G                        P                           X       
      / \                     /   \                        / \      
     P  T4   rightRotate(G)  X     G     rightRotate(P)  T1   P     
    / \      ============>  / \   / \    ============>       / \    
   X  T3                   T1 T2 T3 T4                      T2  G
  / \                                                          / \ 
 T1 T2                                                        T3  T4 

Zag-Zag (Right Right Case):
  G                          P                           X       
 /  \                      /   \                        / \      
T1   P     leftRotate(G)  G     X     leftRotate(P)    P   T4
    / \    ============> / \   / \    ============>   / \   
   T2   X               T1 T2 T3 T4                  G   T3
       / \                                          / \ 
      T3 T4                                        T1  T2

*/

void displayList(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\nEMPTY\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->amount==0)
            //same as below but for the amount in this case
                printf("%d\t%s\t%0.2f\n",temp1->entry,temp1->itemname,temp1->costprice);
            else
            {
                //we have the data entered here - and we're re"routing" that for the amount and so on because we either have that entered
                //or we're using the old one
                printf("%d\t%s\t%d\t%0.2f\n",temp1->entry,temp1->itemname,temp1->amount,temp1->costprice);
            }

            temp1 = temp1->right;
        }
        printf("\n");
    }

}

struct node* sales(int entry,int amount)
{
    n_node = (struct node*)malloc(sizeof(struct node));
    int basecount = 0;

    struct node *temp1 = head_1;
    while(temp1->entry!=entry)
    {
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
    else
    {
        while(temp->right!=NULL)
        {
            if(temp->entry==entry)
            {
                basecount = 1;
                break;
            }
            temp=temp->right;
        }

        if(basecount==1)
        {
            temp->amount += n_node-> amount;
            temp->costprice += n_node->costprice;
        }
        else
        {
            temp->right=n_node;
        }
    }

    return head_s;
}

//for taking like the right and left functins for splay trees as we've done above.. although yeah we can take the basic structure and work w that.

/*

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

*/

void calculatetotsales()
{
    struct node *temp = head_3;
    while(temp!=NULL)
    {
        //this is just to sum up the total "sales"
        head_s = sales(temp->entry, temp->amount);
        temp=temp->right;
    }
}

/*

struct node *rightRotate(struct node *x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

*/

struct node* delete(int entry,struct node *head, struct node* tail)
{
    //If Root is NULL: We simply return the root. In this case we have the head, root to be null - so we simple print "EMPTY" 
    if(head==NULL)
    {
        printf("\nEMPTY\n");
    }
    else
    {
        //Else Splay the given key (acc to name). If (acc to name) is present, then it becomes the new root. If not present, then last accessed leaf node becomes the new root.

        struct node* temp;
        if(entry==head->entry)
        {
            temp = head;
            head = head->right;
            if (head != NULL)
                head->left = NULL;
            free(temp);
        }
        //last accessed leaf node becomes the new root.

/*
DELETE(T, n)
  left_subtree = new splay_tree
  right_subtree = new splay_tree
  left_subtree.root = T.root.left
  right_subtree = T.root.right
  if left_subtree.root != NULL
    left_subtree.root.parent = NULL
  if right_subtree.root != NULL
    right_subtree.root.parent = NULL
*/
        else if(entry==tail->entry)
        {
            temp = tail;
            tail = tail->left;
            tail->right = NULL;
            free(temp);
        }
        //last accessed leaf node becomes the new root.
        else
        {
            temp = head;
            while(entry!=temp->entry)
            {
                temp = temp->right;
            }
            (temp->left)->right = temp->right;
            (temp->right)->left = temp->left;
            free(temp);
        }
    }
    return head;
}

/*

// The delete function for Splay tree. Note that this
// function returns the new root of Splay Tree after
// removing the key
struct node* delete_key(struct node* root, int key)
{
    struct node* temp;
    if (!root) here the difference would be that for the roots we're working with the heads and tail values
        return NULL;
  
    // Splay the given key
    root = splay(root, key);
  
    // If key is not present, then
    // return root
    if (key != root->key)
        return root;
  
    // If key is present
    // If left child of root does not exist
    // make root->right as root
    if (!root->left) {
        temp = root;
        root = root->right;
    }  

}
// A utility function to print preorder traversal of the
// tree. The function also prints height of every node
void preOrder(struct node* root){
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

*/

int deleteadmin()
{
    printf("NUMBER OF FOOD ITEM THAT IS TO BE DELETED: ");
    int num;
    scanf("%d",&num);

    struct node* temp=head_1;
    while(temp!=NULL)
    {
        if (temp->entry == num)
        {
            head_1 = delete(num, head_1, tail_1);
            return 1;
        }
        temp=temp->right;
    }

    return 0;
}

/*

// Else if left child exits
    else {
        temp = root;
  
        // New root
        root = splay(root->left, key);
  
        // Make right child of previous root as
        // new root's right child
        root->right = temp->right;
    }
    // free the previous root node, that is,
    // the node containing the key
    free(temp);
  
    // return root of the new Splay Tree
    return root;

*/

int deletecustomer()
{
    printf("\nNUMBER OF FOOD ITEM THAT IS TO BE DELETED: ");
    int num;
    scanf("%d",&num);

    struct node* temp=head_3;
    while(temp!=NULL)
    {
        if (temp->entry == num)
        {
            head_3 = delete(num, head_3, tail_3);
            return 1;
        }
        temp=temp->right;
    }

    return 0;
}

/*

and we're following a similar like structure for when we have
the admin code
the customer code
and deleting things such as
FOOD ITEMS
from ordered menu etc...

*/

void displaybill()
{
    displayList(head_3);
    struct node *temp = head_3;
    float fullprice = 0;
    while (temp!=NULL)
    {
        fullprice +=temp->costprice;
        temp = temp->right;
    }

    printf("Total price: %0.02f\n",fullprice);

}

struct node* deleteList(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp->right!=0)
        {
            temp = temp->right;
            free(temp->left);
        }
        free(temp);
        head = NULL;
    }

    return head;
}

/*
Then we will find the maximum of the left subtree and splay it to the root.

  if left_subtree.root != NULL
    m = MAXIMUM(left_subtree, left_subtree.root)
    SPLAY(left_subtree, m)
After that, we will make the right subtree the right child of the new root of the left subtree.

  if left_subtree.root != NULL
    ...
    left_subtree.root.right = right_subtree.root
    T.root = left_subtree.root

If there is no left subtree, we will make right subtree the new tree.

  if left_subtree.root != NULL
    ...
  else
    T.root = right_subtree.root
*/

void admin()
{
    printf("THE ADMINISTRATORS SECTION\n");
    while(1)
    {
        administratorsection();

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
            case 1:
                displayList(head_s);
                break;
            case 2:
//now if the food item serial number already exists, we havent written any splay tree that can replace it
                        //so we cannot replace the food item
                        //we can only add or delete
                        //so in this case we just go over it, do not write over anything
                        //just mention the options again and the user can re-choose an item
                printf("NUMBER OF FOOD ITEM:");
                int num,basecount = 0;
                char name[50];
                float costprice;
                scanf("%d",&num);

                struct node *temp = head_1;

                while(temp!=NULL)
                {
                    if(temp->entry==num)
                    {
                        printf("EMPTY: THIS ALREADY EXISTS, PICK ANOTHER NUMBER\n\n");
                        basecount = 1;
                        break;
                        //allow them to name the food
                    //..we need name and pricing ofcourse - keep a limit on the int.. so like for now yo ucan give campus pricings?
                    //or actually this is dependent on the user so error message will be needed if it goes over..
                    //for some reason the code is also just stopping there so that's messed up
                    }
                    temp = temp->right;
                }

                if(basecount==1)
                    break;

                printf("NAME OF FOOD ITEM:\n");
                scanf("%s",name);
                printf("PRICE (AMOUNT) OF FOOD ITEM\n");
                scanf("%f",&costprice);
                head_1 = theadministrators(head_1, num, name, costprice);
                printf("\nNEW FOOD ITEM ADDED TO THE MENU\n\n");
                break;
                //why does the code stop here.. should we just remove the admin/ customer option completely and keep it only to be customer? 
                //see the difference for like admin and user needs a login
                //but that's to difficult to implement..
                //like right now the user is just chosing between admin control vs user control..nothing else. 
                //ok we'll look into the whole user admin thing later - maybe we can have a csv file with stored user info and cross check through that???
            case 3:
                if(deleteadmin())
                {
                    printf("\nNEW FOOD ITEMS ON THE MENU\n");
                    displayList(head_1);
                }
                else
                    printf("\nTHIS FOOD ITEM DOES NOT EXIST\n\n");

                break;
            case 4:
                printf("\nTHE MENU\n");
                displayList(head_1);
                break;

            default:
                printf("\nPLEASE ENTER ANOTHER VALUE, THIS INPUT DOES NOT WORK\n");
                break;
        }
    }
}

void customer()
{
    int basecount=0,j=1;
    char ch;
    printf("FOR CUSTOMERS\n");
    while(1)
    {
        customersection();
        //we're creating this to be the customer option menu part

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;
        //now ofcourse if the user clicks 5 that goes back to the main menu, so it breaks

        switch (opt)
        {
            case 1:
                displayList(head_1);
                printf("\nNUMBER OF THE FOOD ITEM TO BE ORDERED");
                int n;
                //ok the user will order
                //what if they want numerous of the same thing <- feedback given
                scanf("%d",&n);
                printf("NUMBER OF THE AMOUNT OF THOSE FOOD ITEMS YOU WANT");
                int amount;
                scanf("%d",&amount);
                head_3 = thecustomer(head_3, n, amount);
                break;
            case 2:
                printf("\nTHE LIST OF THESE ORDERED ITEMS\n");
                displayList(head_3);
                break;
                //ok so like.. if we're ordering but ofcourse want more than just one.. like 3 chais? or 3 maggis.. 2 eggrolls and so on

            case 3:
            //for when the customer wants to know what theyve ordered - it's like you have them read it back to you in an actual restraunt 
            //here we'll just print it back
                if(deletecustomer())
                {
                    printf("\nNEW LIST OF THE ORDERED FOOD ITEMS\n");
                    displayList(head_3);
                }
                else
                    printf("\nTHIS FOOD ITEM DOES NOT EXIST\n");
                break;
            case 4:
                calculatetotsales();
                //is it the total bill so far or final.. cnanot tell too late
                printf("\nTHE TOTAL BILL, SO FAR\n");
                displaybill();
                head_3 = deleteList(head_3);
                                //I think it'll just be neater here to specify where to go back for the main menu.. but what we can do is use
                //fflush(stdin) should discard any unused input
//and we had a character: char=ch so here
                // fgetc() function reads a single unsigned character from the input stream at the current position and increases the associated file pointer
                //so then it equates the basecount to be 1
                printf("\nPRESS 'B' TO RETURN TO THE MAIN MENU\n");
                fflush(stdin);
                ch=fgetc(stdin);
                basecount=1;
                break;

            default:
                printf("\nTHIS INPUT IS WRONG, PLEASE ENTER ANOTHER\n");
                break;
        }
        if(basecount==1)
            break;
    }
}

/*
ACTIVE LIST OF THINGS TO CORRECT
SOME ERRORS SHOWING WITH THE POINTERS
PROGRAM STILL RUNNING FILE
THE VALUES ARE OF TYPE CONST HAR BUT WE'RE ENDING UP USING TYPE INT, BUT ON RUNNING ITS OK, SO PROBLEM IS OCCURING WITH SOME TAIL ENDS
*/

void originalmenu()
{
    printf("ASHOKA UNIVERSITY DINING SYSTEM FOR CUSTOMERS (STUDENTS) AND ADMINISTRATORS \n");
    printf("1. ADMINISTRATORS SECTION-> \n");
    printf("2. CUSTOMERS SECTION-> \n");
    printf("3. EXIT -> \n\n");
    printf("ENTER A VALID INPUT FOR YOUR CHOICE ->");
}

// --------------referred code .. what went wrong?

/*
// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root.  This function modifies the tree and returns the new root
struct node *splay(struct node *root, int key)
{
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->key == key)
        return root;
  
    // Key lies in left subtree
    if (root->key > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
  
        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
  
            // Do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
  
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
  
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
  
        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
  
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
  
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}
*/

int main()
{
    //this is the make-be menu we have for 5 items fort he user/admin to start off with in itself with cp values present on the RHS
    head_1 = theadministrators(head_1,1,"EGGROLL",60);
    head_1 = theadministrators(head_1,2,"MAGGI",30);
    head_1 = theadministrators(head_1,3,"HOT CHOCOLATE",80);
    head_1 = theadministrators(head_1,4,"CHICKEN SANDWHICH",70);
    head_1 = theadministrators(head_1,5,"LEMON SODA",50);
    //using switch and case here.. because itll just be easier than doing like 50 if else commands or calling function form main .. that kept resulting in some error

    while(1)
    {
        originalmenu();
        int choice;
        scanf("%d",&choice);

        if(choice==3)
        {
            printf("\n\n-END-\n");
            break;
        }
//this is just easier use of switch case for when we're working with admin vs with customers vs when we exit the program and simply break 
        //usually this is between option 3 and 5.. so remember to put break values for then 
        switch (choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
                break;

            default:
                printf("\nINPUT IS NOT VALID, PLEASE INPUT ANOTHER\n");
                break;
        }
    }
}