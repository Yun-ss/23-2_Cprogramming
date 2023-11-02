#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
	int id;
	int level;
}item;

item* MakeItem(int id, int level) {
	item* newItem = (item*)malloc(sizeof(item));
	newItem->id = id;
	newItem->level = level;
	return newItem;
}

int isGoodItem(item* pitem) {
	if (pitem->level >= 2) {
		return 1;
	}
	else return 0;
}

int isLowIdItem(item* pitem) {
	if (pitem->id <= 2) {
		return 1;
	}
	else return 0;
}

void FindItemByPredicate(item* items[], int length, int(*Predicate)(item*)) {
	for (int i = 0; i < length; i++) {
		if (Predicate(items[i])) {
			printf("find item! id: %d, level: %d\n",items[i]->id,items[i]->level);
		}
	}

}

int main() {
	item* items[4];
	items[0] = MakeItem(1, 0);
	items[1] = MakeItem(3, 1);
	items[2] = MakeItem(2, 2);
	items[3] = MakeItem(4, 3);

	FindItemByPredicate(items, 4, *isGoodItem);
	FindItemByPredicate(items, 4, *isLowIdItem);

	for (int i = 0; i < 4; i++) {
		free(&items[i]);
	}
	return 0;
}