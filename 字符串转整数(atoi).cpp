﻿//请你来实现一个 atoi 函数，使其能将字符串转换成整数。首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。当我们寻找到的第一个
//非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起
//来，形成整数。该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
//注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。在任何情况下，若函数不能进行有
//效的转换时，请返回 0。
//链接：https ://leetcode-cn.com/problems/string-to-integer-atoi
class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int bol = 1;
		long long res = 0;
		while (i < str.size() && str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			bol = -1;
			i++;
		}
		else if (str[i] == '+')
		{
			bol = 1;
			i++;
		}
		if (i == str.size())
			return 0;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i++] - '0');
			if (res >= 2147483648)
			{
				if (bol == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}
		}
		return res * bol;
	}
};