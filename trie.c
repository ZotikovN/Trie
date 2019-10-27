#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

struct trie* trie_create()
{
	
    return malloc(sizeof(struct trie));
}

int trie_insert(struct trie* data, char* key, void* val)
{
    struct trie* current_node = data;
    while (*key != 0)
    {
        struct trie* child = current_node->children[*key];
        if (!child) 
        {
            current_node->children[*key] = trie_create();
            child = current_node->children[*key];
			child->charKey = *key;
			child->skip = 0;
            *current_node->children = child;
        }
        current_node = child;
        key++;
    }
    current_node->val = val;
}


void* find(struct trie* data, char* key)
{   
    struct trie* current_node = data;
    while (*key != 0)
    {
        struct trie* next_node = current_node->children[*key];
        if (!next_node) 
        {
            return NULL;
        }
        current_node = next_node;
        key++;
    }
    if (!current_node)
    {
        return NULL;
    }
	if (current_node->skip==0) {
		return current_node->val;
	}
	else return NULL;
    
}


 
int leaf_remove(struct trie* data, char* key)
{
    struct trie* current_node = data;
    while (*key != 0)
    {
        struct trie* next_node = current_node->children[*key];
        if (!next_node) 
        {
            return 0;
        }
        current_node = next_node;
        key++;
    }
	current_node->skip = 1;
    free(current_node->val);
    return 1;
}



void trie_print (struct trie *data, int level) {
	for (int a = 1; a < 256; a++)
    {
        if (data->skip == 0) {
			printf (" %d ", data->charKey);
			printf ("(");
			trie_print(&(data->children[a]), level+1);
            printf (")");
        }
    if (level == 0)
        printf ("\n");
    }
	
}

