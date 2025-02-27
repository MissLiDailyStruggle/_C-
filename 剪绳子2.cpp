//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0], k[1]...k[m - 1] 。请问 k[0] * k[1] * 
//...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。答案需要取模 1e9 + 7（10
//00000007），如计算初始结果为：1000000008，请返回 1。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
class Solution {
public:
	int cuttingRope(int n) {
		if (n < 2)
			return 0;
		if (n < 4)
			return n - 1;
		if (n == 4)
			return 4;
		long ans = 1;
		while (n > 4) //5 6 7 //2 3 4
		{
			n -= 3;
			ans = (ans * 3) % 1000000007;
		}
		return ans * n % 1000000007;
	}
};