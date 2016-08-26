#include<iostream>
using namespace std;





//
//分析：回溯算法
//这是一个可以用回朔法解决的典型题。首先，在矩阵中任选一个格子作为路径的起点。如果路径上的第i个字符不是ch，那么这个格子不可能处在路径上的
//第i个位置。如果路径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i + 1个字符。除在矩阵边界上的格子之外，其他格子都有4个相邻的格子。
//重复这个过程直到路径上的所有字符都在矩阵中找到相应的位置。
//由于回朔法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符的位置之后，在与第n个字符对应的格子的周围都没有找到第n + 1个
//字符，这个时候只要在路径上回到第n - 1个字符，重新定位第n个字符。
//由于路径不能重复进入矩阵的格子，还需要定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子。 当矩阵中坐标为（row, col）的
//格子和路径字符串中相应的字符一样时，从4个相邻的格子(row, col - 1), (row - 1, col), (row, col + 1)以及(row + 1, col)中去定位路径字符串中下一个字符
//如果4个相邻的格子都没有匹配字符串中下一个的字符，表明当前路径字符串中字符在矩阵中的定位不正确，我们需要回到前一个，然后重新定位。
//一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到合适的位置



//回溯法：体现在那个很长的if语句后面的，flag标记的恢复
class Solution 
{
	
	bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, int* flag)
	{
		int index = i * cols + j;
		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == 1)
			return false;
		if (k == strlen(str) - 1) return true;
		flag[index] = 1;
		if (helper(matrix, rows, cols, i - 1, j, str, k + 1, flag)
			|| helper(matrix, rows, cols, i + 1, j, str, k + 1, flag)
			|| helper(matrix, rows, cols, i, j - 1, str, k + 1, flag)
			|| helper(matrix, rows, cols, i, j + 1, str, k + 1, flag)) {
			return true;
		}
		flag[index] = 0;
		return false;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str) 
	{
		int* flag = new int[strlen(matrix)];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (helper(matrix, rows, cols, i, j, str, 0, flag))
					return true;
			}
		}
		return false;
	}
	
};
