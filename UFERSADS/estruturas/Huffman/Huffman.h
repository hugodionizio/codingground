#include <stdio.h>
#include <stdlib.h>
#include "../Cadeias/Vector.h"

#define MAX_TREE_HT 100

typedef struct RootNodes {

} RootNodes;

typedef struct MH_Node {
    char character;
    unsigned frequency;
    struct MH_Node *l, *r;
} MH_Node;
MH_Node fila_vazia_prioridades_ascendentes;


struct M_Heap {
    unsigned size;
    unsigned space;
    MH_Node **array;
};
typedef struct M_Heap M_Heap;

// Interface do código de Huffman
int maketree(int);
int numItens(MH_Node);
int pqmindelete(MH_Node);
int info(int);
int father(int);
bool isleft(int);
void pqinsert(MH_Node, int);
char sequencia(int, char);
void setleft(int, int);
void setright(int, int);

MH_Node* newNode (char character, unsigned frequency) {
    MH_Node* temp = (MH_Node *) malloc(sizeof(MH_Node));
    temp->l = temp->r = NULL;
    temp->character = character;
    temp->frequency = frequency;
    
    return temp;
}

M_Heap* createM_Heap(unsigned space) {
    M_Heap* M_Heap = malloc(sizeof(M_Heap));
    M_Heap->size = 0;
    M_Heap->space = space;
    M_Heap->array = (MH_Node**)malloc(M_Heap->space * sizeof(MH_Node*));
    
    return M_Heap;
}

void swapMH_Node(MH_Node** a, MH_Node** b) {
    MH_Node* t = *a;
    *a = *b;
    *b = t;
}

void M_Heapify(M_Heap* M_Heap, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    
    if (l < M_Heap->size && M_Heap->array[l]->frequency < M_Heap->array[smallest]->frequency)
    smallest = l;
    
    if (r < M_Heap->size && M_Heap->array[r]->frequency < M_Heap->array[smallest]->frequency)
    smallest = r;
    
    if (smallest != idx) {
        swapMH_Node(&M_Heap->array[smallest], &M_Heap->array[idx]);
        M_Heapify(M_Heap, smallest);
        }
    }
    
    int isSizeOne(struct M_Heap* M_Heap) {
        return (M_Heap->size == 1);
    }

MH_Node* extractMin(M_Heap* M_Heap) {
    MH_Node* temp = M_Heap->array[0];

    M_Heap->array[0] = M_Heap->array[M_Heap->size - 1];
    --M_Heap->size;
    M_Heapify(M_Heap, 0);

    return temp;
}

void insertM_Heap(M_Heap* M_Heap, MH_Node* MH_Node) {
    int i = M_Heap->size - 1;

    ++M_Heap->size;
    while (i && MH_Node->frequency < M_Heap->array[(i - 1)/2]->frequency) {
        M_Heap->array[i] = M_Heap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    M_Heap->array[i] = MH_Node;
}

void buildM_Heap(M_Heap* M_Heap) {
    int n = M_Heap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        M_Heapify(M_Heap, i);
}

void printArr(int arr[], int n) {
    int i;
    
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(MH_Node* root) {
    return !(root->l) && !(root->r) ;
}

M_Heap* createAndBuildM_Heap(char character[], int frequency[], int size) {
    int i;
    struct M_Heap* M_Heap = createM_Heap(size);
    
    for (i = 0; i < size; ++i)
        M_Heap->array[i] = newNode(character[i], frequency[i]);
        M_Heap->size = size;
        buildM_Heap(M_Heap);

    return M_Heap;
}

MH_Node* buildHuffmanTree(char *character, int *frequency, int size) {
    MH_Node *l, *r, *top;
    M_Heap* M_Heap = createAndBuildM_Heap(character, frequency, size);
    
    while (!isSizeOne(M_Heap)) {
        l = extractMin(M_Heap);
        r = extractMin(M_Heap);
        top = newNode('$', l->frequency + r->frequency);
        top->l = l;
        top->r = r;
        insertM_Heap(M_Heap, top);
    }

    return extractMin(M_Heap);
}

void printCodes(struct MH_Node* root, int arr[], int top) {
    if (root->l) {
        arr[top] = 0;
        printCodes(root->l, arr, top + 1);
    }
    
    if (root->r) {
        arr[top] = 1;
        printCodes(root->r, arr, top + 1);
    }
    
    if (isLeaf(root)) {
        printf("%c: ", root->character);
            printArr(arr, top);
    }
}

void HuffmanCodes(char *character, int *frequency, int size) {
    MH_Node* root = buildHuffmanTree(character, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    
    printCodes(root, arr, top);
}

void Huffman() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size;
    
    size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, frequency, size);
    getchar();
}

int mainHuffman(int argc, char **argv) {
	Huffman();
    return (0);
}
