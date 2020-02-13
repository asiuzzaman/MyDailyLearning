#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define HASHMAX 20

typedef struct nodeStruct{
	char name[11];
	struct nodeStruct *next;
}NODE;

NODE *createNode(char S[])
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	int i;
	for (i = 0; S[i]; i++)
		newNode->name[i] = S[i];
	newNode->name[i] = S[i];
	newNode->next = NULL;
	return newNode;
}

int hashFunc(char S[])
{
	int hash = 0;
	for (int i = 0; S[i]; i++) {
		hash += S[i];
	}
	return hash%HASHMAX;
}

void insert(NODE *hashTable[], char S[])
{
	int index = hashFunc(S);
	NODE *newNode = createNode(S);
	newNode->next = hashTable[index];
	hashTable[index] = newNode;
}

void search(NODE *hashTable[], char S[])
{
	int index = hashFunc(S);
	int flag = 0;
	NODE *curNode = hashTable[index];
	while (curNode != NULL) {
		flag = 1;
		for (int i = 0; S[i]; i++) if (S[i] != curNode->name[i]) {
			flag = 0;
			break;
		}
		if (flag)
			break;
		curNode = curNode->next;
	}
	if (flag)
		printf("%s found\n", S);
	else
		printf("%s not found\n", S);
}

int main()
{
	NODE *hashTable[HASHMAX];
	for (int i = 0; i < HASHMAX; i++)
		hashTable[i] = NULL;
	insert(hashTable, "asiu");
	insert(hashTable, "vs");
	search(hashTable, "vs");
	search(hashTable, "hell");
	return 0;
}
