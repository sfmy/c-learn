#include "utils.h"

void randomList (int * list, int count) {
    int i, j, tmp;
    for (i = 0; i < count; ++i) {
	j = count*1.0*rand()/RAND_MAX;
	tmp = list[i];
	list[i] = list[j];
	list[j] = tmp;
    }
}

int checkList (int * list, int count) {
    int success = 0, fail = 1;
    int i;

    for (i = 0; i < count-1; ++i) {
	if (list[i] > list[i+1]) {
	    return fail;
	}
    }
    return success;
}

void showList (int * list, int count) {
    int i;
    for (i = 0; i < count; ++i) {
	printf((i==count-1)? "%d\n":"%d,", list[i]);
    }
}

void bubbleSort (int * list, int count) {
    int i, j, tmp;
    for (i = 0; i < count-1; ++i) {
	for (j = 1; j < count-i; ++j) {
	    if (list[j] < list[j-1]) {
		tmp = list[j];
		list[j] = list[j-1];
		list[j-1] = tmp;
	    }
	}
    }
}

void selectionSort (int * list, int count) {
    int i, j, k, tmp;
    for (i = 0; i < count-1; ++i) {
	k = 0;
	for (j = 1; j < count-i; ++j) {
	    if (list[j] > list[k]) {
		k = j;
	    }
	}
	tmp = list[k];
	list[k] = list[count-i-1];
	list[count-i-1] = tmp;
    }
}

void insertSort (int * list, int count) {
    int i, j, tmp;
    for (i = 1; i < count; ++i) {
	tmp = list[i];
	for (j = i; j > 0; --j) {
	    if (list[j-1] > tmp) {
		list[j] = list[j-1];
	    }
	    else {
		break;
	    }
	}
	if (j != i) {
	    list[j] = tmp;
	}
    }
}
