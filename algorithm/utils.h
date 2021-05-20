#ifndef __UTILS_H_
#define __UTILS_H_
#include <stdlib.h>
#include <stdio.h>

/**
 * 乱序数组中的元素
 * @param list 数组
 * @param count 长度
 */
void randomList (int * list, int count);

/**
 * 检查数组是否正确排序
 * @param list 数组
 * @param count 长度
 * @return 0:success 1:faile
 */
int checkList (int * list, int count);

/**
 * 打印数组中的元素
 * @param list 数组
 * @param count 长度
 */
void showList (int * list, int count);

/**
 * 冒泡排序
 * @param list 数组
 * @param count 长度
 */
void bubbleSort (int * list, int count);

/**
 * 选择排序
 * @param list 数组
 * @param count 长度
 */
void selectionSort (int * list, int count);

/**
 * 插入排序
 * @param list 数组
 * @param count 长度
 */
void insertSort (int * list, int count);

#endif
