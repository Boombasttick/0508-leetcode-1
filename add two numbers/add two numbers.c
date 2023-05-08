/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));//用一个哑节点(dummy node)提供迭代的初始参数；
	res->val = 0;
	res->next = NULL;
	struct ListNode* pre = res;
	int carry = 0;
	while (l1 || l2 || carry)//只要有一个存在迭代就可以继续；
	{
		struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		int	n1 = l1 ? l1->val : 0;
		int	n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;

		temp->val = sum % 10;
		temp->next = NULL;
		pre->next = temp;
		//以上三行代码为新节点各域(数据域和指针域)赋值，并放置于前驱节点之后；
		
		pre = pre->next;
		carry = sum / 10;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
		//以上四行代码更新四个迭代参数；
	}
	return res->next;
}

void addcontact(struct ListNode* pb,int* arr)
{
    int i=0;
    pb->val=arr[0];
    for (i=1;i<3;i++){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        pb->next =  temp;
        pb = pb->next;
    }
}

int main(){
    int arr1[] = {2,4,3};
    int arr2[] = {5,6,4};
    struct ListNode l1;
	struct ListNode l2;
    addcontact(&l1,arr1);
    addcontact(&l2,arr2);
    struct ListNode* l3 = addTwoNumbers(&l1, &l2);
    return 0;
}