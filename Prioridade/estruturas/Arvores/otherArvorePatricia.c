#include <stdio.h>
#include <string.h>
 
#define ALPHABET_SIZE 26
 
struct node {
    int data;
    struct node* link[ALPHABET_SIZE];
};
 
struct node* root = NULL;
 
struct node*  create_node() {
    struct node *q = (struct node*)malloc(sizeof(struct node));
    int x;
    for(x=0;x<ALPHABET_SIZE;x++)
        q->link[x] = NULL;
    q->data = -1;
    return q;
}
 
// Look at this function like this: (Comparing it with LinkedList traversal for adding a node at the end of the list)
// Keep traversing, (q = q->link[index] instead of q = q->link) until we get q->link[index] == NULL (instead of q->link == NULL)
// When we get NULL, then instead of adding just 1 node and making the previous node point to it, we create as many new nodes
// as the value of (length - level) at that time.
void insert_node(char key[]) {
    int length = strlen(key);
    int index;
    int level = 0;
    if(root == NULL)
        root = create_node();
    struct node *q = root;  // For insertion of each String key, we will start from the root
 
    for(;level < length;level++) {
        // At each level, find the index of the corresponding
        // character (a-z = 0-26)
        index = key[level] - 'a';
 
        if(q->link[index] == NULL) {
            // Put the value of this character inside q->link[index]
            // and create 1 more node to which this node will point
            q->link[index] = create_node();  // which is : struct node *p = create_node(); q->link[index] = p;
        }
 
        q = q->link[index];
    }
    // Now, the last character(node) of the String key will contain the value of this key
    q->data = level; // Assuming the value of this particular String key is 11     
}
 
int search(char key[]) {
    struct node *q = root;
    int length = strlen(key);
    int level = 0;
    for(;level < length;level++) {
        int index = key[level] - 'a';
        if(q->link[index] != NULL)
            q = q->link[index];
        else
            break;
    }
    if(key[level] == '\0' && q->data != -1)
        return q->data;
    return -1;
}
 
int mainOtherArvorePatricia(int argc, char **argv) {

    insert_node("by");
    insert_node("program");
    insert_node("programming");
    insert_node("data structure");
    insert_node("coding");
    insert_node("code");
    printf("Searched value: %d\n",search("code"));
    printf("Searched value: %d\n",search("geeks"));
    printf("Searched value: %d\n",search("coding"));
    printf("Searched value: %d\n",search("programming"));

    return (0);
}
