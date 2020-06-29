#pragma once



typedef struct DataItem {
	int item1;
	int item2;
	int item3;
} DATAITEM;




typedef struct UserCall {
	int user_floor; //�û�����¥��
	int user_target; //�û�Ŀ��¥��
	int call_time; //�û�����ʱ��
	char call_type; //�û��������ͣ���U���ʾ����ָ���D���ʾ����ָ��
}USERCALL;



typedef struct ServeListNode {
	char serve_state; //���ݷ���״̬
	USERCALL *user_call;//���ݵ�ǰ��Ӧ�û�ָ��ʱ��ָ��ָ�������ĳһ��Ԫ��
	struct ServeListNode *next_node;//�洢��һ�����ĵ�ַ
}SERVELISTNODE;

typedef struct elevatorstate {
	int current_floor; //���ݵ�ǰ����¥��
	char run_state; //��������״̬
	SERVELISTNODE *serve_list;//���ݵ�ǰ����ָ�����ָ��
}ELEVATORSTATE;

typedef struct ResponseListNode {
	USERCALL *user_call; //�û�ָ����ָ�������ж�Ӧ�����
	struct ResponseListNode *next_node;//�洢��һ�����ĵ�ַ
}RESPONSELISTNODE;

typedef struct ResponseListHeadNode {
	int list_num; //����Ӧ�û�ָ�����������ݽ��ĸ���
	RESPONSELISTNODE *head;//�����е�һ�����ݽ���ָ��
	RESPONSELISTNODE *tail;//���������һ�����ݽ���ָ��
}RESPONSELISTHEADNODE;

typedef struct conf {
	char *filename;//���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
	int leng;//�������ݸ��� 
	int time;//���ڴ��ʱ�� 
	ELEVATORSTATE *elevator;//���ڴ�ŵ���״̬
	RESPONSELISTHEADNODE readynode;//���ڴ�Ŵ���Ӧ����
	DATAITEM *dataitem;//�ṹ������
	int ii;//�ṹ���λ�� 
}CONF;
