//单链表 头插法

#include <stdio.h>
#include <stdlib.h>

struct Book 
{
	char title[128];
	char author[64];
	struct Book *next;
};

void getInput(struct Book *book)
{
	printf("书名:");
	scanf("%s",book->title);
	printf("作者:");
	scanf("%s",book->author);
}

void addLibrary(struct Book **library)
{
	struct Book *book, *temp;
	
	book = (struct Book *)malloc(sizeof(struct Book));
	if(book == NULL)
	{
		printf("内存分配失败");
		exit(1);
	}

	printf("请输入录入信息：");
	getInput(book);
	
	if(*library !=  NULL)
	{
		temp = *library;
		*library = book;
		book->next = temp;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
}

void printLibrary(struct Book *library)
{
	struct Book *book;
	int count = 0;
	book = library;
	
	while(book != NULL)
	{
		printf("书名：%s \n",book->title);
		printf("作者：%s \n",book->author);
		book = book->next;
		count++;
		
	}

	printf("打印完毕，你一共打印了%d本书",count);

}

void releaseLibrary(struct Book *library)
{
	struct Book *temp;

	while(library != NULL)
	{
		temp = library;
		library = library->next;
		free(temp);

	}

}

int main(void)
{
	struct Book *library=NULL;

	int ch;

	while(1)
	{
		printf("请问是否要录入书籍(y/n)\n");
		
		do
		{	
		ch = getchar();
		}while(ch != 'y' && ch != 'n');

		if(ch == 'y')
		{
			addLibrary(&library);
		}
		if(ch == 'n')
		{
			break;
		}
	}

	printf("需要打印书籍吗？(y/n)\n");

	do
	{	
		ch = getchar();
	}while(ch != 'y' && ch != 'n');

	if(ch == 'y')
	{
		printLibrary(library);
	}

	releaseLibrary(library);

	return 0;
}

