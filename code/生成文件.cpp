#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

using namespace std;
typedef struct
{
	int x, y, z;
}random;//��¼ÿһ�е�3��Ԫ��

int main(int argc, char *argv[]) {

	int sum, i;
	FILE* fp;
	FILE* fp1;
	random *p;
	char function[1];
 	int function_int;

	
		
		srand((unsigned int)time(NULL));
		sum =rand() % 10 ;//����������������
		p = (random*)malloc((sizeof(random))*sum);
		if (!p) exit(0);
		for (i = 0; i<sum; i++)
		{while(1){
		
			srand((unsigned int)time(NULL) + i);
			p[i].x = rand() % 15+1;
			p[i].y = rand() % 15+1;
			p[i].z = rand() % 50;
			if(i!=0){
				if(p[i].x!=p[i].y&&p[i].z!=p[i-1].z) break;
			}
			else {
			if (p[i].x!=p[i].y) break;
			}
			
			}
				
		}

	
	
	
	if ((fp = fopen("�ı��ļ�.txt", "w")) == NULL)//���ı��ļ����ļ�·��Ϊ����·�����ļ���Ϊ123 
	{
		printf("wrong"); exit(1);
	}
	fprintf(fp, "%d\n", sum);
	for (i = 0; i<sum; i++)
	{
		fprintf(fp, "%d,", p[i].x);
		fprintf(fp, "%d,", p[i].y);
		fprintf(fp, "%d", p[i].z);
		fprintf(fp,"\n");
	}

	
	
	
	fclose(fp);//�ر��ļ�
	free(p);
	return 0;
}


