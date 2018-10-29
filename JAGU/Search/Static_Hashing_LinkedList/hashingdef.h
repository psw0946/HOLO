#ifndef STATIC_HASHING_LIST_HASHINGDEF_H
#define STATIC_HASHING_LIST_HASHINGDEF_H

#define HASH_KEY_SIZE 10

class HashElement {
public:
	char key[HASH_KEY_SIZE + 1];
	int value;
};

#endif