#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//my struct defination
struct node{
    int key;
    struct node *rightChild;
    struct node *leftChild;
};
//Global variables 
int sequenceSize = 0;
int numOfSequences = 0;
struct node *temp;
//Methods
void swap(int* x, int* y); 
void insert(struct node **root, int key);
void printTree(struct node *root);
int createArray(struct node *root, int arr[], int i);
void tryCompination(int* arr, int harry, int potter, struct node* root);
int compare(struct node* root, struct node* t);
void execute(struct node* root);
//main method
int main(int argc, char const *argv[]){
    struct node *root = NULL;
    int num;
    char temp;
    printf("enter a sequence of number\n");
    do {
        scanf("%d%c", &num, &temp);
        insert(&root, num);
        sequenceSize++;
    } while(temp != '\n');   
    int arr[sequenceSize];
    createArray(root, arr, 0);
    printTree(root);
    tryCompination(arr, 1, sequenceSize - 1, root);
}
//insertion method
void insert(struct node **root, int key){
    if(!(*root)){
        struct node *newNode = malloc(sizeof(struct node));
        newNode->key = key;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        *root = newNode;
    }
    else if((*root)->key > key){
        insert(&((*root)->leftChild), key);
    }
    else if((*root)->key < key){
        insert(&((*root)->rightChild), key);
    }
    return;  
}
void printTree(struct node *root){
    if(root){
        printTree(root->leftChild);
        printf("%d\n", root->key);
        printTree(root->rightChild);
    }
    return;
}
int createArray(struct node *root, int arr[], int i)
{
    if(root == NULL){
        return i;
    }
    arr[i] = root->key;
    i++;
    if(root->leftChild != NULL){
        i = createArray(root->leftChild, arr, i);
    }    
    if(root->rightChild != NULL){
        i = createArray(root->rightChild, arr, i);
    }
    return i;
}
void tryCompination(int* arr, int harry, int potter,struct node* root){ 
    if (harry == potter){
    	temp = NULL;
        for(int b = 0; b < sequenceSize; b++){
        	if(temp == NULL){
	            insert(&temp,arr[b]);
            }
	        else{
	            insert(&temp,arr[b]);
            }
	    }
        if(compare(root, temp)){
            printf("\n");
            numOfSequences++;
            for(int j = 0; j < sequenceSize; j++){
	            printf("%d ", arr[j]); 	
		    }
		    printf("%d",numOfSequences); 
	    }
	    execute(temp);
		temp = NULL; 			
	}
    else { 
        for (int i = harry; i <= potter; i++) { 
            swap((arr + harry), (arr + i)); 
            tryCompination(arr, harry + 1, potter,root); 
            swap((arr + harry), (arr + i)); 
        } 
    }
} 
void swap(int* x, int* y){ 
    int temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
int compare(struct node* root, struct node* t){ 
    if (root == NULL && t == NULL){
        return 1; 
    } 
    if (root != NULL && t != NULL){ 
        return
        (
            root->key == t->key && 
            compare(root->leftChild, t->leftChild) && 
            compare(root->rightChild, t->rightChild) 
        ); 
    } 
    return 0; 
}
void execute(struct node* root){ 
    if (root == NULL){
        return; 
    } 
    execute(root->leftChild); 
    execute(root->rightChild); 
    free(root); 
} 