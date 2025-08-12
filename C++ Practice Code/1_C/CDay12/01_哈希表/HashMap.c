#include "HashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define DEFAULT_CAPACITY 8
#define MAX_PREALLOC  4096
#define LOAD_FACTOR 0.75    // 链表平均长度的最大值 (用空间换时间)

// 创建空的哈希表
HashMap* hashmap_create(void) {
	HashMap* map = malloc(sizeof(HashMap));
	map->elements = calloc(DEFAULT_CAPACITY, sizeof(Node*));
	map->capacity = DEFAULT_CAPACITY;
	map->size = 0;
    map->hashseed = time(NULL);

	return map;
}


void hashmap_destroy(HashMap* map) {
	// 1. 先释放一个一个结点 （哈希表的遍历）
	for (int i = 0; i < map->capacity; i++) {
		Node* curr = map->elements[i];
		while (curr) {
			Node* next = curr->next;
			free(curr);
			curr = next;
		} // curr == NULL
	}
	// 2. 释放动态数组
	free(map->elements);
	// 3. 释放HashMap结构体
	free(map);
}

/* murmurhash2 */
// 1. 可以对任意类型的key求哈希值
// 2. 返回哈希值和seed相关，引入了不确定性，提高安全 (避免DDOS攻击)。

// 问题：DDOS攻击
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
    // 重新计算哈希值
    int idx = hash(node->key, strlen(node->key), seed) % length;
    // 头插法
    node->next = table[idx];
    table[idx] = node;
}

void grow_capacity(HashMap* map) {
    // 扩容策略
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
1. 如果key存在，更新key关联的值，并把原来的值返回 (保证了键的唯一性)
2. 如果key不存在，则添加键值对，并返回特殊值(NULL)
*/
V hashmap_put(HashMap* map, K key, V val) {
	// 1. 计算key的哈希值, 找到数组的索引
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // 2. 遍历链表，判断key是否存在
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // 更新值，并返回旧的值
            V oldval = curr->val;
            curr->val = val;
            return oldval;
        }
        curr = curr->next;
    } // curr == NULL;

    // 3. 判断是否需要扩容
    if (map->size >= map->capacity * LOAD_FACTOR) {
        grow_capacity(map);
        // 重新计算索引位置
        idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    }
    
    // 4. 创建结点，并添加链表 (头插法)
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->val = val;
    new_node->next = map->elements[idx];
    map->elements[idx] = new_node;
    map->size++;

    return NULL;
}

// 根据key删除键值对
void hashmap_delete(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // 遍历链表，查找结点
    Node* prev = NULL;
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // 删除curr结点
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
    // 遍历链表，查找结点
    Node* curr = map->elements[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->val;
        }
        curr = curr->next;
    } // curr == NULL;
    return NULL;
}