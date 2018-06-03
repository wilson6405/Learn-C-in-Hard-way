## ex11
### How To Break It
1. 忘記初始化int i，使循環發生錯誤
```shell
$ valgring ./ex11
Conditional jump or move depends on uninitialised value(s)
at 0x4005EB: main (in /home/wilson/Documents/c/LCTHW/ex11/ex11)
state 0: California
state 1: Oregon
state 2: Washington
state 3: texas
```
2. 忘記初始化第二個循環的i，於是i還保留著第一個循環結束時的值。你的第二個循環可能執行也可能不會執行
```shell
$ ./ex11 test
arg 0: ./ex11
arg 1: test
state 2: Washington
state 3: texas
$ ./ex11 test it
arg 0: ./ex11
arg 1: test
arg 2: it
state 3: texas
```
3. 忘記在最後執行i ++自增，你會得到一個“死循環”，它是在你開始編程的第一個或前兩個十年中，最可怕的問題之一
```shell
state 0: California
state 0: California
state 0: California
state 0: California
...
```
### Extra Credit
1. 讓這些循環倒序執行,通過使用 i-- 從 argc 開始遞減直到0。你可能需要做一些算數操作讓數組的下標正常工作

   ```c
   #include <stdio.h>

   int
   main(int argc, char *argv[])
   {
   	int i = argc - 1;
   	while(i >= 0){
   		printf("arg %d: %s\n", i, argv[i]);
   		i--;
   	}

   	char *states[] = {
   		"California", "Oregon",
   		"Washington", "texas"
   	};

   	int num_states = 4;
   	i = num_states - 1;
   	while(i >= 0) {
   		//states[i] = argv[i];
   		printf("state %d: %s\n", i, states[i]);
   		i--;
   	}
   	/*
   	while (i < num_states) {
           printf("state %d: %s\n", i, states[i]);
           i++;
       }
   	*/
   	return 0;
   }
   ```

   ```shell
   ./ex11 a b c d
   arg 4: d
   arg 3: c
   arg 2: b
   arg 1: a
   arg 0: ./ex11
   state 3: texas
   state 2: Washington
   state 1: Oregon
   state 0: California
   ```

2. 使用 while 循環將 argv 中的值複製到 states 。
```c
#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i = 0;
	while(i < argc){
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	char *states[] = {
		"California", "Oregon",
		"Washington", "texas"
	};

	int num_states = 4;
	i = 0;
	while(i < argc) {
		states[i] = argv[i];
		printf("state %d: %s\n", i, states[i]);
		i++;
	}
	return 0;
}
```
```shell
./ex11 a b c d
arg 0: ./ex11
arg 1: a
arg 2: b
arg 3: c
arg 4: d
state 0: ./ex11
state 1: a
state 2: b
state 3: c
state 4: d
```
4. 讓這個複制循環不會執行失敗,即使 argv 之中有很多元素也不會全部放進 states 

   ```c
   #include <stdio.h>

   int
   main(int argc, char *argv[])
   {
   	int i = 0;
   	while(i < argc){
   		printf("arg %d: %s\n", i, argv[i]);
   		i++;
   	}

   	char *states[] = {
   		"California", "Oregon",
   		"Washington", "texas"
   	};

   	int num_states = 4;
   	i = 0;

   	int count = 0;
   	if (num_states > argc) 
   		count = argc;
   	else
   		count = num_states;

   	while(i < count) {
   		states[i] = argv[i];
   		printf("state %d: %s\n", i, states[i]);
   		i++;
   	}
   	return 0;
   }
   ```

5. 研究你是否真正複製了這些字符串。答案可能會讓你感到意外和困惑。

```c
#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i = 0;
	while(i < argc){
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	char *states[] = {
		"California", "Oregon",
		"Washington", "texas"
	};

	int num_states = 4;
	i = 0;

	int count = 0;
	if (num_states > argc) 
		count = argc;
	else
		count = num_states;

	while(i < count) {
		states[i] = argv[i];
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	printf("%p\n", *states);
	printf("%p\n", argv[0]);
	return 0;
}
```

```shell
$ ./ex11 
arg 0: ./ex11
state 0: ./ex11
0x7ffc5ed0c064
0x7ffc5ed0c064
```

states[i]重新指向argv[i]，並不是複製字串過去