#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
//�ı������뺯��    fgets    ����������
//�ı����������	fputs	 ���������
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r+");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
///*
//	//д�ļ�
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
//*/
//
///*
//	//���ļ�
//	fgets(buf,1024,pf);
//	//printf("%s", buf);	//bit
//	puts(buf);//bit---�Դ�����
//
//	fgets(buf, 1024, pf);
//	//printf("%s", buf);	//hello
//	puts(buf);//hello---�Դ�����
//*/
//
///*
//	////�Ӽ��̶�ȡһ���ı���Ϣ
//	////�ӱ�׼��������ȡ
//	//fgets(buf, 1024, stdin);
//	////�������׼�����
//	//fputs(buf, stdout);
//	//
//	//�ȼ���
//	gets(buf);
//	puts(buf);
//*/
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//��ʽ��������� fprintf ���������
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"hello" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//��ʽ������ʽд�ļ�
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��ʽ�����뺯�� fscanf ����������
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//��ʽ������ʽд�ļ�
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);	//100 3.140000 hello
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�ӱ�׼��������ȡ
//
//�������׼�����
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));//11 2.22  hello
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);	//11 2.220000 hello
//
//	return 0;
//}


//4.2 �Ա�һ�麯��
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
// 
//scanf		printf 
//��Ա�׼���������
//fscanf	fprintf
//����������������

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"hello" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//
//	
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);	//11 2.220000 hello
//	printf("%s\n", buf);	//100 3.140000 hello
//
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));//11 2.22  hello
//	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);////100 3.140000 hello
//	return 0;
//}
////sscanf	�Ǵ��ַ����ж�ȡ��ʽ��������
////sprintf	�ǰѸ�ʽ������������ɣ����浽���ַ���



//��������� fwrite �ļ�
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "����",20,55.6 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//�Զ����Ƶ���ʽд�ļ�
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
// 
//���������� fread �ļ�
struct S
{
	char name[20];
	int age;
	double score;
};

int main()
{
	//struct S s = { "����",20,55.6 };
	struct S tmp = { 0 };

	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//�Զ����Ƶ���ʽд�ļ�
	//fwrite(&s, sizeof(struct S), 1, pf);
	//�Զ����Ƶ���ʽ���ļ�
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);//���� 20 55.600000

	fclose(pf);
	pf = NULL;
	return 0;
}