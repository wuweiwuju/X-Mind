//大小端
/*#include<stdio.h>
union un
{
	char a;
	int b;
};
int main()
{
	un x;
	x.b = 1;
	if (x.a == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}*/

//字符串函数的模拟实现
//1.strcpy
/*#include<stdio.h>
#include<assert.h>
char* Strcpy(char* des, const char* src)
{
	char* ret = des;
	assert(des);
	assert(src);
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	return ret;
}
int main()
{
	const char* src = "hello";
	char des[20] = { 0 };
	char* ret = Strcpy(des, src);
	printf("%s\n", des);
	return 0;
}*/
//2.strlen
/*#include<stdio.h>
#include<assert.h>
int Strlen1(const char* des)
{
	int count = 0;
	assert(des);
	while (*des++ != '\0')
		++count;

	return count;
}
int Strlen2(const char* des)
{
	const char* temp = des;
	assert(des);
	while (*des != '\0')
		++des;

	return (des - temp);
}
int main()
{
	const char* des = "hello";
	int ret = Strlen2(des);
	printf("%d\n", ret);
	return 0;
}*/
//3.strstr
/*#include<stdio.h>
#include<assert.h>
const char* Strstr(const char* src1, const char* src2)
{
	assert(src1);
	assert(src2);
	const char* p2 = src2;
	const char* t = nullptr;
	while (*src1 != '\0') {
		if(*src1 == *src2) {
			t = src1;
			while (*src1 == *src2) {
				++src1;
				++src2;
				if (*src2 == '\0')
					return t;
			}
		}
		else {
			++src1;
			src2 = p2;
		}
	}
	return nullptr;
}
int main()
{
	const char* src1 = "hellorwr";
	const char* src2 = "llo";
	const char* ret = Strstr(src1, src2);
	printf("%s\n", ret);
	return 0;
}*/
//4.strcat
/*#include<stdio.h>
#include<assert.h>
char* Strcat(char* des, const char* src)
{
	char* p = des;
	assert(src);
	assert(des);
	while (*des != '\0')
		++des;
	while (*src != '\0')
	{
		*des = *src;
		++des;
		++src;
	}
	*des = '\0';
	return p;
}
int main()
{
	char des[20] = "hello ";
	const char* src = "world";
	char* ret = Strcat(des, src);
	printf("%s\n", ret);
	return 0;
}*/
//5.strcmp
/*#include<stdio.h>
#include<string.h>
#include<assert.h>
int Strcmp(const char* s1, const char* s2)
{
	assert(s1 != nullptr && s2 != nullptr);
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 > *s2)
			return 1;
		else if (*s1 < *s2)
			return -1;
		else
			++s1, ++s2;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return 0;

	if (*s1 == '\0')
		return -1;

	return 1;
}
int main()
{
	const char* str1 = "hfllo";
	const char* str2 = "helpi";
	int ret = strcmp(str1, str2);
	int ret1 = Strcmp(str1, str2);
	printf("%d %d\n", ret, ret1);
	return 0;
}*/
//6.memcpy
/*#include<stdio.h>
#include<assert.h>
#include<string.h>
void* Memcpy(void* memto, const void* memfro, size_t count)
{
	assert(memto != nullptr && memfro != nullptr);
	int* tmp1 = (int *)memto;
	int* tmp2 = (int *)memfro;
	int sum = count / sizeof(int);
	while ((sum--) && *tmp2 != '\0') {
		*tmp1 = *tmp2;
		++tmp1;
		++tmp2;
	}
	return memto;
}
int main()
{
	int memto[10] = { 0 };
	int memfro[] = { 1,2,3,4,5,6,7,8,9 };
	//memcpy(memto, memfro, 16);
	Memcpy(memto, memfro, 16);
	for(int i = 0; i < 10; ++i)
		printf("%d ", memto[i]);

	printf("\n");
	return 0;
} */
//7.memmove
/*#include<stdio.h>
#include<assert.h>
#include<string.h>
void* Memmove(void* des, const void* src, size_t count)
{
	assert(des && src);
	int* p1 = (int*)des;
	int* p2 = (int*)src;
	count = count / sizeof(int);
	while (count--)
	{
		if (des < src) {
			*(p1++) = *(p2++);
		}
		else {
			*(p1 + count) = *(p2 + count);
		}
	}
	return des;
}
int main()
{
	int mem[] = { 1,2,3,4,5,6,7,8,9 };
	//memcpy(memto, memfro, 16);
	Memmove(mem+2, mem, 16);
	for (int i = 0; i < 9; ++i)
		printf("%d ", mem[i]);

	printf("\n");
	return 0;
}*/
//8.atoi
//9.itoa