#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
	int id;
	int level;
}item;

item* MakeItem(int id, int level) {
	item* newItem = (item *)malloc(sizeof(item));
	newItem->id = id;
	newItem->level = level;
	return newItem;
}

int main() {
	item* items[4];
	items[0] = MakeItem(1, 0);
	items[1] = MakeItem(3, 1);
	items[2] = MakeItem(2, 2);
	items[3] = MakeItem(4, 3);

	for (int i = 0; i < 4; i++) {
		printf("item, id: %d, level: %d\n", items[i]->id, items[i]->level);
	}

	for (int i = 0; i < 4; i++) {
		free(&items[i]);
	}
	return 0;
}