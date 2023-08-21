#include <stdio.h>

int parent(int index) {
	return ((index - 1) / 2);
}

int lchild(int index) {
	return (2 * index + 1);
}

int rchild(int index) {
	return (2 * index + 2);
}

void swap(int heap[], int index, int index2) {
	int temp = heap[index];
	heap[index] = heap[index2];
	heap[index2] = temp;
}	

void bubbleUp(int index, int heap[]) {
	while(parent(index) >= 0 && heap[parent(index)] < heap[index]) {
		swap(heap, index, parent(index));
		index = parent(index);
	}
}


//############ workt noch nicht ############//
void bubbleDown(int index, int heap[]) {
	while(lchild(index) < sizeof(heap) && heap[lchild(index)] > heap[index]) {
		if(rchild(index) < sizeof(heap) && rchild(index) < lchild(index)) {
			swap(heap, index, rchild(index));
			index = rchild(index);
		} else {
			swap(heap, index, lchild(index));
			index = lchild(index);
		}
	}
}

void printHeap(int heap[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}

/*
 * int getHeapSize(int heap[]) {
 * 	return (sizeof(heap) / sizeof(heap[0]));
 * }
 *
 */


void test() {
	int heap[] = {60, 100, 70, 30, 20, 60, 500};
	printHeap(heap, 7);
	bubbleUp(1, heap);
	printHeap(heap, 7);
	bubbleUp(6, heap);
	printHeap(heap, 7);

	int heap2[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
	printf("%ld \n", heap2[20]);
	printHeap(heap2, 20);
	bubbleDown(0, heap2);
	printHeap(heap2, 20);
}

int main() {
	test();
	return 0;
}

