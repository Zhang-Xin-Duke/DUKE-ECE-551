#include "HashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define DEFAULT_CAPACITY 8
#define MAX_PREALLOC  4096
#define LOAD_FACTOR 0.75    // ����ƽ�����ȵ����ֵ (�ÿռ任ʱ��)

// �����յĹ�ϣ��
HashMap* hashmap_create(void) {
	HashMap* map = malloc(sizeof(HashMap));
	map->elements = calloc(DEFAULT_CAPACITY, sizeof(Node*));
	map->capacity = DEFAULT_CAPACITY;
	map->size = 0;
    map->hashseed = time(NULL);

	return map;
}


void hashmap_destroy(HashMap* map) {
	// 1. ���ͷ�һ��һ����� ����ϣ��ı�����
	for (int i = 0; i < map->capacity; i++) {
		Node* curr = map->elements[i];
		while (curr) {
			Node* next = curr->next;
			free(curr);
			curr = next;
		} // curr == NULL
	}
	// 2. �ͷŶ�̬����
	free(map->elements);
	// 3. �ͷ�HashMap�ṹ��
	free(map);
}

/* murmurhash2 */
// 1. ���Զ��������͵�key���ϣֵ
// 2. ���ع�ϣֵ��seed��أ������˲�ȷ���ԣ���߰�ȫ (����DDOS����)��

// ���⣺DDOS����
uint32_t hash(const void* key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

void rehash(Node* node, Node** table, int length, uint32_t seed) {
    // ���¼����ϣֵ
    int idx = hash(node->key, strlen(node->key), seed) % length;
    // ͷ�巨
    node->next = table[idx];
    table[idx] = node;
}

void grow_capacity(HashMap* map) {
    // ���ݲ���
    int new_capacity = (map->capacity <= MAX_PREALLOC) ?
        (map->capacity << 1) : (map->capacity + MAX_PREALLOC);

    Node** new_table = calloc(new_capacity, sizeof(Node*));
    // rehash
    uint32_t seed = time(NULL);
    for (int i = 0; i < map->capacity; i++) {
        Node* curr = map->elements[i];
        while (curr) {
            Node* next = curr->next;
            rehash(curr, new_table, new_capacity, seed);
            curr = next;
        } // curr == NULL
    }

    free(map->elements);
    map->elements = new_table;
    map->capacity = new_capacity;
    map->hashseed = seed;
}

/*
1. ���key���ڣ�����key������ֵ������ԭ����ֵ���� (��֤�˼���Ψһ��)
2. ���key�����ڣ�����Ӽ�ֵ�ԣ�����������ֵ(NULL)
*/
V hashmap_put(HashMap* map, K key, V val) {
	// 1. ����key�Ĺ�ϣֵ, �ҵ����������
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // 2. ���������ж�key�Ƿ����
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // ����ֵ�������ؾɵ�ֵ
            V oldval = curr->val;
            curr->val = val;
            return oldval;
        }
        curr = curr->next;
    } // curr == NULL;

    // 3. �ж��Ƿ���Ҫ����
    if (map->size >= map->capacity * LOAD_FACTOR) {
        grow_capacity(map);
        // ���¼�������λ��
        idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    }
    
    // 4. ������㣬��������� (ͷ�巨)
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->val = val;
    new_node->next = map->elements[idx];
    map->elements[idx] = new_node;
    map->size++;

    return NULL;
}

// ����keyɾ����ֵ��
void hashmap_delete(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // �����������ҽ��
    Node* prev = NULL;
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // ɾ��curr���
            if (!prev) {
                map->elements[idx] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            map->size--;
            return ;
        }
        prev = curr;
        curr = curr->next;
    } // curr == NULL;
}

V hashmap_get(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // �����������ҽ��
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->val;
        }
        curr = curr->next;
    } // curr == NULL;
    return NULL;
}