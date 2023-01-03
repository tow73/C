#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, &m7 };
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;//p290 Quiz 02
int get_nonleaf_count(TreeNode* t)
{
	int count = 0;
	if (t == NULL)
		return 0;
	else if (t->left == NULL && t->right == NULL)
		return 0;
	else
		count += 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
	return count;
}
//p319 #16
int get_oneleaf_count(TreeNode* node)
{
	if (node != NULL)
	{
		if ((node->left != NULL) && (node->right == NULL))
			return 1 + get_oneleaf_count(node->left);  // + get_oneleaf_count(node->right)
		else if ((node->left == NULL) && (node->right != NULL))
			return 1 + get_oneleaf_count(node->right);  // + get_oneleaf_count(node->left)
		else
			return  get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}
	return 0;
}
int get_twoleaf_count(TreeNode* node)
{
	if (node != NULL)
	{
		if (node->left != NULL && node->right != NULL)
			return 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
		else
			return  get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}
	return 0;
}
//p319 #17
int get_max(TreeNode* node) //�� min���� �ٸ���..
{
	TreeNode* temp = node;
	while (temp->right != NULL)
		temp = temp->right;
	return temp->data;

	/*
	int max = INT_MIN;
	int temp, left, right;
	if (node != NULL) {
		temp = node->data;
		left = get_max(node->left);
		right = get_max(node->right);
		if (left > right)
			max = left;
		else
			max = right;
	}
	return max;
	*/
}
int get_min(TreeNode* node)
{
	TreeNode* temp = node;
	while (1) {
		if (temp->data >= temp->left->data)
			temp = temp->left;
		else
			break;
	}
	return temp->data;
}
//p290 Quiz 03
int equal(TreeNode* t1, TreeNode* t2)
{
	if (t1 != NULL)
	{
		equal(t1->left, t2->left);
		if (t1->data != t2->data)
			return FALSE;
		equal(t1->right, t2->right);
	}
	return TRUE;

	/*
	if (t1 == NULL && t2 == NULL)
		return TRUE;
	if ((t1 != NULL && t2 == NULL) || (t1 == NULL && t2 != NULL))
		return FALSE;
	return equal(t1->left, t2->left) && equal(t1->right, t2->right);
	*/
}
TreeNode* copy(TreeNode* node)
{
	TreeNode* temp = node;
	return temp;

	/*
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	if (node != NULL) {
		temp->data = node->data;
		temp->left = copy(node->left);
		temp->right = copy(node->right);
		return temp;
	}
	return NULL;
	*/
}
//p319 #20 ��� ��� 1�� ����
void node_increase(TreeNode* node)
{
	if(node != NULL) {
		node->data += 1;
		if (node->left != NULL) node_increase(node->left);  //�׳� �ϱ�
		if (node->right != NULL) node_increase(node->right);  //�׳� �ϱ�
	}
	return root;
}
void preorder(TreeNode* root) // p274 �ڵ� ����
{
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;

	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));
	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));
	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));

	printf("\n ��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����" : "�ٸ���");

	printf("\n ��)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}