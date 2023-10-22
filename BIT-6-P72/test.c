#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
//文本行输入函数    fgets    所有输入流
//文本行输出函数	fputs	 所有输出流
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
//	//写文件
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
//*/
//
///*
//	//读文件
//	fgets(buf,1024,pf);
//	//printf("%s", buf);	//bit
//	puts(buf);//bit---自带换行
//
//	fgets(buf, 1024, pf);
//	//printf("%s", buf);	//hello
//	puts(buf);//hello---自带换行
//*/
//
///*
//	////从键盘读取一行文本信息
//	////从标准输入流读取
//	//fgets(buf, 1024, stdin);
//	////输出到标准输出流
//	//fputs(buf, stdout);
//	//
//	//等价于
//	gets(buf);
//	puts(buf);
//*/
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//格式化输出函数 fprintf 所有输出流
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
//	//格式化的形式写文件
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//格式化输入函数 fscanf 所有输入流
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
//	//格式化的形式写文件
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf("%d %f %s", s.n, s.score, s.arr);	//100 3.140000 hello
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//从标准输入流读取
//
//输出到标准输出流
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


//4.2 对比一组函数
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
// 
//scanf		printf 
//针对标准输入输出流
//fscanf	fprintf
//针对所有输入输出流

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
////sscanf	是从字符串中读取格式化的数据
////sprintf	是把格式化的数据输出成（储存到）字符串



//二进制输出 fwrite 文件
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "张三",20,55.6 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//以二进制的形式写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
// 
//二进制输入 fread 文件
struct S
{
	char name[20];
	int age;
	double score;
};

int main()
{
	//struct S s = { "张三",20,55.6 };
	struct S tmp = { 0 };

	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//以二进制的形式写文件
	//fwrite(&s, sizeof(struct S), 1, pf);
	//以二进制的形式读文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);//张三 20 55.600000

	fclose(pf);
	pf = NULL;
	return 0;
}