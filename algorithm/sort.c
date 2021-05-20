/**
 * 冒泡排序
 */
#include "utils.h"

int main (void) {
    int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int len = sizeof(list)/sizeof(int);
    int loop = 10;
    int error;

    while (loop--) {
	printf("随机的列表:\t");
	randomList(list, len);
	showList(list, len);
	printf("排序后的列表:\t");
	/* bubbleSort(list, len); */
	/* selectionSort(list, len); */
	insertSort(list, len);
	showList(list, len);
	printf((checkList(list, len) == 0)? "排序成功\n":"排序失败\n");
	printf("\n");
    }
}
