/*
 * HashTable.h
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ESTRUTURAS_HASH_HASHTABLESPARKNOTES_H_
#define ESTRUTURAS_HASH_HASHTABLESPARKNOTES_H_

#include <string.h>

/* http://www.sparknotes.com/cs/searching/hashtables/section3.rhtml */
// 1.1 We begin with our linked lists (for separate chaining):
typedef struct _list_t_ {
	char *str;
	struct _list_t_ *next;
} list_t;

// 1.2. Now we need a hashSparkNotes table structure.
typedef struct _hash_table_t_ {
	int size; /* the size of the table */
	list_t **table; /* the table elements */
} hash_table_t;

/* Why did we declare the table as list_t **table?
 * We don't know up front how big we want the table to be.
 * Therefore, we need to make the table a dynamic array.
 * Remember that an array is just a big block of memory and is
 * basically synonymous with a pointer
 * (see the SparkNotes on arrays and pointers).
 * What we have is a pointer to a pointer to a linked list;
 * thus list_t **table.

 * Functions
 * What basic operations do we need to be able to perform with our hashSparkNotes tables?:
 * 1) We need to be able to create a table.
 * 2) We need to be able to hashSparkNotes; thus we need a hashSparkNotes function.
 * 3) We need to be able to free a table.
 * 4) We need to be able to insert into them.
 * 5) We need to be able to lookup an element in them.
 * That should do it for a basic implementation.
 */

hash_table_t *create_hash_table(int); //2.1. Creation: create a hashSparkNotes table
unsigned int hashSparkNotes(hash_table_t *, char *); // 2.2. Our hashSparkNotes function.
list_t *lookup_string(hash_table_t *, char *); // 2.3. String lookup.
int add_string(hash_table_t *, char *); // 2.4. Inserting a string.
void free_table(hash_table_t *); // 2.5. Deleting a table.


#endif /* ESTRUTURAS_HASH_HASHTABLESPARKNOTES_H_ */
