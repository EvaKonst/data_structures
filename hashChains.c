#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct hash *hashTable = NULL;
int eleCount = 0;

struct Node 
{
  float grade;
  char AM[100];
  char first_name[100];
  char last_name[100];
  struct Node *next;
};

struct hash 
{
struct Node *head;
int count;
};

struct Node * createNode(char *AM, char *first_name, char *last_name, float grade) 
{
  struct Node *newNode;

  newNode = (struct Node *) malloc(sizeof(struct Node));
  strcpy(newNode->AM, AM);
  strcpy(newNode->last_name, last_name);
  strcpy(newNode->first_name, first_name);
  newNode->grade = grade;
  newNode->next = NULL;
  return newNode;
}

int Hash(char *AM, int n)
{    
  int i;
  int hashIndex = 0;

  for (i=0; (i< 8) && (AM[i] != 0); i++)
  {
    hashIndex += AM[i];
  }

  return hashIndex % n;
}

void insertToHash() 
{
  struct Node node;

  FILE *fp;
  fp = fopen ("Foitites-Vathmologio-DS.txt","rb");

  if (fp == NULL) 
  { 
    fprintf(stderr,"Could not open file");  
    return;
  } 

  char line[4096];

  while (fgets(line, sizeof line,fp)) {
    size_t len = strlen(line);
    if (len && (line[len - 1] == '\n')) {
      /* complete line */
      if (sscanf(line,"%99s %99s %99s %f",node.AM, node.first_name, node.last_name, &node.grade) != 4) {
    puts("invalid file");
    return;
      }

      int hashIndex = Hash(node.AM, 19);

      struct Node *newNode = createNode(node.AM, node.first_name, node.last_name, node.grade);
      /* head of list for the bucket with index "hashIndex" */

      if (!hashTable[hashIndex].head) 
      {
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count = 1;
      }
      else {
        /* adding new Node to the list */
        newNode->next = (hashTable[hashIndex].head);
        /*
           * update the head of the list and no of
           * Nodes in the current bucket
        */
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
      }
    }
  }
  fclose(fp);
  printf("Done! \n");
}

void deleteFromHash(char *AM) 
{
  /* find the bucket using hash index */
  int hashIndex = Hash(AM, 19);
  int flag = 0;

  struct Node *temp, *myNode;
  /* get the list head from current bucket */

  myNode = hashTable[hashIndex].head;

  if (!myNode) {
    printf("Given data is not present in hash Table!!\n");

    return;
  }

  temp = myNode;
  while (myNode != NULL) {
    /* delete the Node with given AM */
    if (!strcmp(myNode->AM, AM)) {
      flag = 1;
      if (myNode == hashTable[hashIndex].head)
        hashTable[hashIndex].head = myNode->next;
      else
        temp->next = myNode->next;

      hashTable[hashIndex].count--;
      free(myNode);
      break;
    }

    temp = myNode;
    myNode = myNode->next;
  }
  if (flag)
    printf("Data deleted successfully from Hash Table\n");
  else
    printf("Given data is not present in hash Table!!!!\n");
}

void searchInHash(char *AM) {
  int hashIndex = Hash(AM, 19);
  int flag = 0;
  struct Node *myNode;        
  myNode = hashTable[hashIndex].head;
  if (!myNode) {
    printf("Search element unavailable in hash table\n");
    return;
  }
  while (myNode != NULL) {
    if (!strcmp(myNode->AM, AM)) {
      printf("Student ID  : %s\n", myNode->AM);
      printf("First Name     : %s\n", myNode->first_name);
      printf("Last Name     : %s\n", myNode->last_name);
      printf("grade      : %lg\n", myNode->grade);
      flag = 1;
      break;
    }
    myNode = myNode->next;
  }
  if (!flag)
    printf("Search element unavailable in hash table\n");
}

void display() {
  struct Node *myNode;
  int i;
  for (i = 0; i < eleCount; i++) {
    if (hashTable[i].count == 0)
      continue;
    myNode = hashTable[i].head;
    if (!myNode)
      continue;
    printf("\nData at index %d in Hash Table:\n", i);
    printf("Student ID    First Name    Last Name      Grade   \n");
    printf("--------------------------------\n");
    while (myNode != NULL) {
      printf("%-12s", myNode->AM);
      printf("%-15s", myNode->first_name);
      printf("%-15s", myNode->last_name);
      printf("%lg\n", myNode->grade);
      myNode = myNode->next;
    }
  }
  
  void overwrite(struct Node* A,struct  Node* B){
    strcpy(A->AM,B->AM);
    strcpy(A->first_name, B->first_name);
    strcpy(A->last_name, B->last_name);
    A->grade = B->grade;
}
}

int main() 
{
  int n=19, ch;
  char AM[100];
  int insertDone = 0;

  eleCount = n;
  /* create hash table with "n" no of buckets */
  hashTable = (struct hash *) calloc(n, sizeof(struct hash));
  while (1) {
    printf("\n1. Insertion\t2. Deletion\n");
    printf("3. Searching\t4. Display\n5. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &ch);


    switch (ch) {
    case 1: 
      if (insertDone)
        puts("Inserton was already done");
      else {
    /*inserting new Node to hash table */
        insertToHash();
        insertDone = 1;
      }
      break;

    case 2: 
      printf("Enter the AM to perform deletion:");
      scanf("%99s", AM);
      /* delete Node with "AM" from hash table */
      deleteFromHash(AM);
      break;

    case 3: 
      printf("Enter the AM to search:");
      scanf("%99s", AM);
      searchInHash(AM);
      break;
    case 4: 
      display();
      break;
    case 5: 
      exit(0);
    case 6:
       overwrite(struct, struct);
       break;
    default: 
      printf("U have entered wrong option!!\n");
      break;
    }
  }
  return 0;
}

