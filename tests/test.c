#include<stdio.h>
#include<limits.h>
#include<stdint.h>
#include<stdarg.h>

typedef int (*printf_like)(const char *, ...);

int test_signed_integer(printf_like print, printf_like print2, int value)
{
	int just_printed;
	//%d
	print("[Testing %%d with d = %i]\n", value);
	just_printed = print("%d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	if (print2)
	{
		just_printed = print2("%d\n", value);
		print("[printed %i bytes]\n\n", just_printed - 1);
	}
	//%#d
	print("[Testing %%#d with d = %i]\n", value);
	just_printed = print("%#d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//% d
	print("[Testing %% d with d = %i]\n", value);
	just_printed = print("% d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%+d
	print("[Testing %%+d with d = %i]\n", value);
	just_printed = print("%+d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%10d
	print("[Testing %%10d with d = %i]\n", value);
	just_printed = print("%10d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%010d
	print("[Testing %%010d with d = %i]\n", value);
	just_printed = print("%010d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//% 010d
	print("[Testing %% 010d with d = %i]\n", value);
	just_printed = print("% 010d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%0 10d
	print("[Testing %%0 10d with d = %i]\n", value);
	just_printed = print("%0 10d\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%x
	print("[Testing %%x with d = %i]\n", value);
	just_printed = print("%x\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%X
	print("[Testing %%X with d = %i]\n", value);
	just_printed = print("%X\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%.16X
	print("[Testing %%.16X with d = %i]\n", value);
	just_printed = print("%.16X\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%#.16X
	print("[Testing %%#.16X with d = %i]\n", value);
	just_printed = print("%#.16X\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
	//%#X
	print("[Testing %%#X with d = %i]\n", value);
	just_printed = print("%#X\n", value);
	print("[printed %i bytes]\n\n", just_printed - 1);
}

int main(void)
{
	test_signed_integer(printf, NULL, INT_MIN);
	test_signed_integer(printf, NULL, INT_MAX);
	test_signed_integer(printf, NULL, 42);
	test_signed_integer(printf, NULL, -69420);
	test_signed_integer(printf, NULL, 0);
	test_signed_integer(printf, NULL, 1);
	test_signed_integer(printf, NULL, -1);
}
