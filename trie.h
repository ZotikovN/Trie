#include <stdbool.h>
#include <limits.h>
#include <stdio.h>


struct trie {
    void* val;
    struct trie* children[256]; 
	char charKey;
	int skip;
};


struct trie* trie_create();


int insert(struct trie* data, char* key, void* val);


void* find(struct trie* data, char* key);


int leaf_remove(struct trie* data, char* key);


void trie_print(struct trie* data, int level);
