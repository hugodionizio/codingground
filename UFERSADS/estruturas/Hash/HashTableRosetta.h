/*
 * HashTableRosetta.h
 *
 *  Created on: 03/10/2016
 *      Authors:
 *      		Rosetta Code in
 *      		http://rohttp://rosettacode.org/wiki/Associative_arrays/Creation/Csettacode.org/wiki/Associative_arrays/Creation/C
 *				Hugo Dionizio Santos
 */
#ifndef ESTRUTURAS_HASH_HASHTABLEROSETTA_H_
#define ESTRUTURAS_HASH_HASHTABLEROSETTA_H_

typedef struct hash_t {
    int size;
    void **keys;
    void **values;
} hash_t;

hash_t *hash_new (int);
int hash_index (hash_t *, void *);
void hash_insert (hash_t *, void *, void *);
void *hash_lookup (hash_t *, void *);
int mainHashTableRosetta(int, char **);

#endif /* ESTRUTURAS_HASH_HASHTABLEROSETTA_H_ */
