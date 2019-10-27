#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

// quick and dirty test cases for trie

void main(int argc, char* argv[])
{

	int *a, *b, *c, *d;
	a = malloc(sizeof(int));
	*a = 1;
	c = malloc(sizeof(int));
	*c = 3;

	struct trie* test_trie = trie_create();	
	trie_insert(test_trie, "aa", a);
	int *trie_value = find(test_trie, "aa");
	printf("lookup got %d\n", *trie_value);
	trie_insert(test_trie, "ccz", c);	
	trie_value = find(test_trie, "ccz");
	printf("lookup got %d\n", *trie_value);
	leaf_remove(test_trie, "ccz");
	printf("lookup got %d\n", find(test_trie,"ccz"));
	
	
	
}
