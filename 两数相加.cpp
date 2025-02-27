﻿//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相
//加起来，则会返回一个新的链表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//链接：https ://leetcode-cn.com/problems/add-two-numbers
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode root(0);
		ListNode*p = &root;
		int carry = 0;
		int sum = 0;
		while (l1 || l2 || carry)
		{
			int x = (l1 != nullptr) ? l1->val : 0;
			int y = (l2 != nullptr) ? l2->val : 0;
			sum = (x + y + carry) % 10;
			carry = (x + y + carry) / 10;
			ListNode *sumnode = new ListNode(sum);
			sumnode->val = sum;
			p->next = sumnode;
			p = p->next;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		return root.next;
	}
};