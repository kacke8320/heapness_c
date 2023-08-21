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

int bubbleDown(int index, int heap[]) {
}

void printHeap(int heap[]) {
	for(int i = 0; i < sizeof(heap) -1; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}




void test() {
	int heap[] = {60, 100, 70, 30, 20, 60, 500};
	printHeap(heap);
	bubbleUp(1, heap);
	printHeap(heap);
	bubbleUp(6, heap);
	printHeap(heap);
}

int main() {
	test();
	return 0;
}

