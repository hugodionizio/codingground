// Huffman Coding
/* Huffman Coding in C . This program reads a text file named on the command line, then compresses it using Huffman coding. The file is read twice, once to determine the frequencies of the characters, and again to do the actual compression. 
http://cppgm.blogspot.com.br/search?q=huffman
*/

#include < stdio.h>
#include < stdlib.h>
#include < string.h>
#include < time.h>

/* there are 256 possible characters */

#define NUM_CHARS 256

/* tree node, heap node */

typedef struct _treenode treenode;
struct _treenode {
int freq; /* frequency; is the priority for heap */
unsigned char ch; /* character, if any */
treenode *left, /* left child of Huffman tree (not heap!) */
*right; /* right child of Huffman tree */
};

/* this is a priority queue implemented as a binary heap */
typedef struct _pq {
int heap_size;
treenode *A[NUM_CHARS];
} PQ;

/* create an empty queue */

void create_pq (PQ *p) {
p->heap_size = 0;
}

/* this heap node's parent */

int parent (int i) {
return (i-1) / 2;
}

/* this heap node's left kid */

int left (int i) {
return i * 2 + 1;
}

/* this heap node's right kid */

int right (int i) {
return i * 2 + 2;
}

/* makes the subheap with root i into a heap , assuming left(i) and
* right(i) are heaps
*/
void heapify (PQ *p, int i) {
int l, r, smallest;
treenode *t;

l = left (i);
r = right (i);

/* find the smallest of parent, left, and right */

if (l < p->heap_size && p->A[l]->freq < p->A[i]->freq)
smallest = l;
else
smallest = i;
if (r < p->heap_size && p->A[r]->freq < p->A[smallest]->freq)
smallest = r;

/* swap the parent with the smallest, if needed. */

if (smallest != i) {
t = p->A[i];
p->A[i] = p->A[smallest];
p->A[smallest] = t;
heapify (p, smallest);
}
}

/* insert an element into the priority queue. r->freq is the priority */
void insert_pq (PQ *p, treenode *r) {
int i;

p->heap_size++;
i = p->heap_size - 1;

/* we would like to place r at the end of the array,
* but this might violate the heap property. we'll start
* at the end and work our way up
*/
while ((i > 0) && (p->A[parent(i)]->freq > r->freq)) {
p->A[i] = p->A[parent(i)];
i = parent (i);
}
p->A[i] = r;
}

/* remove the element at head of the queue (i.e., with minimum frequency) */
treenode *extract_min_pq (PQ *p) {
treenode *r;

if (p->heap_size == 0) {
printf ("heap underflow!\n");
exit (1);
}

/* get return value out of the root */

r = p->A[0];

/* take the last and stick it in the root (just like heapsort) */

p->A[0] = p->A[p->heap_size-1];

/* one less thing in queue */

p->heap_size--;

/* left and right are a heap, make the root a heap */

heapify (p, 0);
return r;
}

/* read the file, computing the frequencies for each character
* and placing them in v[]
*/
unsigned int get_frequencies (FILE *f, unsigned int v[]) {
int r, n;

/* n will count characters */

for (n=0;;n++) {

/* fgetc() gets an unsigned char, converts to int */

r = fgetc (f);

/* no more? get out of loop */

if (feof (f)) break;

/* one more of this character */

v[r]++;
}
return n;
}

/* make the huffman tree from frequencies in freq[] (Huffman's Algorithm) */

treenode *build_huffman (unsigned int freqs[]) {
int i, n;
treenode *x, *y, *z;
PQ p;

/* make an empty queue */

create_pq (&p);

/* for each character, make a heap/tree node with its value
* and frequency
*/
for (i=0; i< NUM_CHARS; i++) {
x = malloc (sizeof (treenode));

/* its a leaf of the Huffman tree */

x->left = NULL;
x->right = NULL;
x->freq = freqs[i];
x->ch = (char) i;

/* put this node into the heap */

insert_pq (&p, x);
}

/* at this point, the heap is a "forest" of singleton trees */

n = p.heap_size-1; /* heap_size isn't loop invariant! */

/* if we insert two things and remove one each time,
* at the end of heap_size-1 iterations, there will be
* one tree left in the heap
*/
for (i=0; i< n; i++) {

/* make a new node z from the two least frequent
* nodes x and y
*/
z = malloc (sizeof (treenode));
x = extract_min_pq (&p);
y = extract_min_pq (&p);
z->left = x;
z->right = y;

/* z's frequency is the sum of x and y */

z->freq = x->freq + y->freq;

/* put this back in the queue */

insert_pq (&p, z);
}

/* return the only thing left in the queue, the whole Huffman tree */

return extract_min_pq (&p);
}

/* traverse the Huffman tree, building up the codes in codes[] */

void traverse (treenode *r, /* root of this (sub)tree */
int level, /* current level in Huffman tree */
char code_so_far[], /* code string up to this point in tree */
char *codes[]) {/* array of codes */

/* if we're at a leaf node, */

if ((r->left == NULL) && (r->right == NULL)) {

/* put in a null terminator */

code_so_far[level] = 0;

/* make a copy of the code and put it in the array */

codes[r->ch] = strdup (code_so_far);
} else {

/* not at a leaf node. go left with bit 0 */

code_so_far[level] = '0';
traverse (r->left, level+1, code_so_far, codes);

/* go right with bit 1 */

code_so_far[level] = '1';
traverse (r->right, level+1, code_so_far, codes);
}
}

/* global variables, a necessary evil */

int nbits, current_byte, nbytes;

/* output a single bit to an open file */

void bitout (FILE *f, char b) {

/* shift current byte left one */

current_byte < < = 1;

/* put a one on the end of this byte if b is '1' */

if (b == '1') current_byte |= 1;

/* one more bit */

nbits++;

/* enough bits? write out the byte */

if (nbits == 8) {
fputc (current_byte, f);
nbytes++;
nbits = 0;
current_byte = 0;
}
}

/* using the codes in codes[], encode the file in infile, writing
* the result on outfile
*/
void encode_file (FILE *infile, FILE *outfile, char *codes[]) {
unsigned char ch;
char *s;

/* initialize globals for bitout() */

current_byte = 0;
nbits = 0;
nbytes = 0;

/* continue until end of file */

for (;;) {

/* get a char */

ch = fgetc (infile);
if (feof (infile)) break;

/* put the corresponding bitstring on outfile */

for (s=codes[ch]; *s; s++) bitout (outfile, *s);
}

/* finish off the last byte */

while (nbits) bitout (outfile, '0');
}

/* main program */

int main (int argc, char *argv[]) {
FILE *f, *g;
treenode *r; /* root of Huffman tree */
unsigned int n, /* number of bytes in file */
freqs[NUM_CHARS]; /* frequency of each char */
char *codes[NUM_CHARS], /* array of codes, 1 per char */
code[NUM_CHARS], /* a place to hold one code */
fname[100]; /* what to call output file */

/* hassle user */

if (argc != 2) {
fprintf (stderr, "Usage: %s < filename>\n", argv[0]);
exit (1);
}

/* set all frequencies to zero */

memset (freqs, 0, sizeof (freqs));

/* open command line argument file */

f = fopen (argv[1], "r");
if (!f) {
perror (argv[1]);
exit (1);
}

/* compute frequencies from this file */

n = get_frequencies (f, freqs);
fclose (f);

/* make the huffman tree */

r = build_huffman (freqs);

/* traverse the tree, filling codes[] with the codes */

traverse (r, 0, code, codes);

/* name the output file something.huf */

sprintf (fname, "%s.huf", argv[1]);
g = fopen (fname, "w");
if (!g) {
perror (fname);
exit (1);
}

/* write frequencies to file so they can be reproduced */

fwrite (freqs, NUM_CHARS, sizeof (int), g);

/* write number of characters to file as binary int */

fwrite (&n, 1, sizeof (int), g);

/* open input file again */

f = fopen (argv[1], "r");
if (!f) {
perror (argv[1]);
exit (1);
}

/* encode f to g with codes[] */

encode_file (f, g, codes);
fclose (f);
fclose (g);
/* brag */
printf ("%s is %0.2f%% of %s\n",
fname, (float) nbytes / (float) n, argv[1]);
exit (0);
}
