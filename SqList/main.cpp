#include "SqList.h"


int main()
{
	//  �ṹ�����  elem  length  listsize
	SqList list;  
	InitSqList(&list);			//��ʼ��
	InsertSqList(&list, 0, 10);	// ��˳����ָ��λ��pos��������val
	InsertSqList(&list, 1, 11);
	InsertSqList(&list, 2, 12);
	InsertSqList(&list, 3, 13);
	InsertSqList(&list, 4, 14);
	InsertSqList(&list, 5, 15);
	InsertSqList(&list, 9, 15);
	Printf(&list);
	InsertHead(&list,9);		// ��˳���ĵ�һ��λ�ò�������
	Printf(&list);				//��ӡ˳���
	InsertTail(&list,16);		// ��˳�������һ��λ�ò�������
	Printf(&list);
	DeleteSqList(&list,3);		// ɾ��ָ��λ�õ�����
	Printf(&list);
	DeleteHead(&list);			// ɾ����һ������Ԫ��
	DeleteTail(&list);			// ɾ�����һ������Ԫ��
	Printf(&list);
	FindVal(&list,12);			// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)
	FindVal(&list,10);
	
	
	DestroySqList(&list);		//ɾ��˳���
	return 0;
}