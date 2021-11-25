#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct student node_student;
typedef struct bin_tree bin_tree;

//student of a Binary Tree Node
struct student{
    char id[20];
    char name[100];
    char last_name[100];
    float grade;
};

//Binary Tree Node
struct node{
    node_student *student;
    node *parent;
    node *left;
    node *right;
};


//Binary Tree
struct bin_tree{
    node *root;
};

bin_tree* initialize();
node *findMax(node* root);
node* bt_search(char *query, node *root);
node* create_btree();
void print_node(node* n);
void add(node* leaf, node* root);
void inorder(node* bt);
void overwrite(node* A, node* B);
void add_node(char *id, char *name, char *last_name,
float grade, bin_tree* bt);
void read_db_to_tree(bin_tree *);
void print_preorder(node* bt);

float main(){
    bin_tree *tree = initialize();
    read_db_to_tree(tree);
    node* tmp;
    char buffer[256];
    int cmd,ibuff;
    float fbuff;

    while(1){
        printf("########################\n");
        printf("# 1. Print In-Order    #\n");
        printf("# 2. Search            #\n");
        printf("# 3. Modify            #\n");
        printf("# 4. Delete            #\n");
        printf("# 5. Exit              #\n");
        printf("########################\n");
        printf("Enter your choice: ");
        scanf("%d",&cmd);
        switch (cmd){
            case 1:
                inorder(tree->root);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%s",&buffer);
                tmp = bt_search(buffer, tree->root);
                if (tmp != NULL) {
                    printf("\nResult: ");
                    print_node(tmp);
                    printf("\n");
                }
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%s", &buffer);
                tmp = bt_search(buffer, tree->root);
                if (tmp != NULL){
                    printf("Enter Name: ");
                    scanf("%s",&buffer);
                    strcpy(tmp->student->name, buffer);
                     printf("Enter Last Name: ");
                    scanf("%s",&buffer);
                    strcpy(tmp->student->last_name, buffer);
                    printf("Enter Grade: ");
                    scanf("%d",&fbuff);
                    tmp->student->grade = fbuff;
                }
                fflush(stdin);
                break;
            case 4:
                printf("Enter ID: ");
                scanf("%s",&buffer);
                delete_element(buffer, tree->root);
                break;

            case 5:
                exit(0);
            default:
                printf("Bad Command\n");
                break;
        }
    }

}

//Binary Tree Initialization
bin_tree* initialize(){
    bin_tree* bt = (bin_tree*)malloc(sizeof(bin_tree));
    bt->root = NULL;
    return bt;
}

//Binary Tree Print Method
void inorder(node* bt){
    if (bt != NULL){
        inorder(bt->left);
        print_node(bt);
        inorder(bt->right);
    }
}

//add node to bin_tree
void add_node(char *id, char *name, char *last_name,
    float grade, bin_tree* bt){

    //initialization
    node* leaf = (node*)malloc(sizeof(node));
    leaf->left = NULL;
    leaf->right= NULL;

    leaf->student = (node_student*)malloc(sizeof(node_student));
    strcpy(leaf->student->id, id);
    strcpy(leaf->student->name, name);
    strcpy(leaf->student->last_name, last_name);
	leaf->student->grade;

    if (bt->root == NULL){
        bt->root = leaf;
    }
    else add(leaf, bt->root);
}
 
void add(node* leaf, node* root){

    if ( strcmp(leaf->student->id, root->student->id) == -1 ){
        if (root->left == NULL){
            root->left = leaf;
            leaf->parent = root;
        }
        else{
            add(leaf, root->left);
        }
    }
    else{
        if (root->right == NULL){
            root->right = leaf;
            leaf->parent = root;
        }
        else{
            add(leaf, root->right);
        }
    }

}

//search for student in the binary tree
node* bt_search(char *query, node *root){
    if (root == NULL){
        printf("\nRecord not found\n\n");
        return NULL;
    }
    if (strcmp(root->student->id, query) == 0){
        return root;
    }
    else{
        if ( strcmp(query, root->student->id) == -1 ){
            bt_search(query, root->left);
        }
        else{
            bt_search(query, root->right);
        }
    }
}

//function that deletes the element
void delete_element(char *query, node *root){
    if (root == NULL){
        printf("Empty Tree\n");
        return;
    }

    node* del = bt_search(query, root);
    node* tmp;

    if (del == NULL) return;

    if (del->left!=NULL && del->right!=NULL){
        tmp = findMax(del->left);
        overwrite(del, tmp);

        //checking if it's the left or right child of the parent node
        if (tmp->parent->left == tmp) tmp->parent->left=NULL;
        else tmp->parent->right = NULL;
        free(tmp->student);
        free(tmp);
    }
    
    else if (del->left==NULL && del->right==NULL){

        ///checking if it's the left or right child of the parent node
        if (del->parent->left == del) del->parent->left=NULL;
        else del->parent->right = NULL;
        free(del->student);
        free(del);
    }
    //only one child
    else{
        if (del->left == NULL){
            tmp = del->right;
            del->right = NULL;
        }
        else if (del->right == NULL){
            tmp = del->left;
            del->left = NULL;
        }
        overwrite(del, tmp);
        del->left = tmp->left;
        del->right = tmp->right;
        free(tmp->student);
        free(tmp);
    }
}

//finds max value (this function helps other functions)
node *findMax(node* root){
    if (root == NULL){
        return NULL;
    }
    if (root->right == NULL){
        return root;
    }
}

//change node A with node B
void overwrite(node* A, node* B){
    strcpy(A->student->id,B->student->id);
    strcpy(A->student->name, B->student->name);
    strcpy(A->student->last_name, B->student->last_name);
    A->student->grade = B->student->grade;
}

//displaying each node
void print_node(node* n){
    printf("%s -- %s -- %s -- %f\n",
        n->student->id, n->student->name, 
        n->student->last_name,
        n->student->grade);
}
//reading the txt file that will give us the information of the students
void read_db_to_tree(bin_tree* tree){
    FILE *fh;
    fh = fopen("Foitites-Vathmologio-DS.txt","r");

    if (fh == NULL){
        printf("NULL");
    }

    size_t line_size = 4096;
    char buffer[4096];
    char *id = malloc(20*sizeof(char));
    char *name = malloc(100*sizeof(char));
    char *last_name = malloc(100*sizeof(char));
    float grade;
    int i;
    while(fgets(buffer, line_size, fh)!=NULL){
        id = strtok(buffer," ");
        name = strtok(NULL," ");
        last_name = strtok(NULL," ");
        grade = atof(strtok(NULL," "));
        add_node(id, name, last_name, grade, tree);
    }
}

