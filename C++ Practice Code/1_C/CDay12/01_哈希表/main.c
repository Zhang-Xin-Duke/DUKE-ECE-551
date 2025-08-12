#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HashMap.h"

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	HashMap* map = hashmap_create();

	//hashmap_put(map, "liuqiangdong", "zhangzetian");
	//hashmap_put(map, "wangbaoqiang", "marong");
	//hashmap_put(map, "wenzhang", "mayili");
	//hashmap_put(map, "jianailiang", "lixiaolu");

	//hashmap_put(map, "wangbaoqiang", "");
	//hashmap_put(map, "wenzhang", "");
	//hashmap_put(map, "jianailiang", "");

	//// hashmap_get
	//V value1 = hashmap_get(map, "liuqiangdong");
	//V value2 = hashmap_get(map, "peanut");

	//// hashmap_delete
	//hashmap_delete(map, "liuqiangdong");
	//hashmap_delete(map, "peanut");

	hashmap_put(map, "wd1", "");
	hashmap_put(map, "wd2", "marong");
	hashmap_put(map, "wd3", "mayili");
	hashmap_put(map, "wd4", "lixiaolu");
	hashmap_put(map, "wd5", "lixiaolu");
	hashmap_put(map, "wd6", "lixiaolu");
	hashmap_put(map, "wd7", "lixiaolu");
	hashmap_put(map, "wd8", "lixiaolu");
	hashmap_put(map, "wd9", "lixiaolu");

	return 0;
}