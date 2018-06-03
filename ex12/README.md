# ex12
## How To Break It

1. 移除 else 部分,使它不能處理邊界情況

   除了只有一個參數會滿足其他都沒有顯示結果

2. 將 && 改為 || ,於是你會把“與”操作變成“或”操作,並且看看會發生什麼。

   || 因為滿足了前面 argc > 1 的條件，故後面的不執行

## Extra Credit

1. 我已經向你簡短地介紹了 && ,它執行“與”操作。上網搜索與之不同的“布爾運算符”。
   - && 為 logic AND，當左邊的條件為真實才判斷右邊條件是否為真，都為真則回傳真，其他則為否
   - || 為 logic OR，當左邊條件為否才繼續判斷右邊的直到有條件為真才回傳真，如果都沒有就回傳否


2. 為這個程序編寫更多的測試用例,看看你會寫出什麼。

   ```c
   #include <stdio.h>

   int
   main(int argc, char *argv[])
   {
   	int i = 0;

   	if(argc == 1) {
   		printf("You only have one argument. You suck.\n");
   	} else if(argc > 1 && argc < 4) {
   		printf("Here's your argument:\n");

   		for (i = 0; i < argc; i++)
   		{
   			printf("%s ", argv[i]);
   		}
   		printf("\n");
   	} else if(argc == 4){
   		printf("Perfect!\n");
   	} else {
   		printf("You have too many arguments. You suck.\n");
   	}

   	return 0;
   }
   ```

   ​

3. 回到練習10和11,使用 if 語句使循環提前退出。你需要 break 語句來實現它,搜索它的有關資料。

   ex10:

   ```c
   for(i =	1;	i <	argc; i++){
   		printf("arg %d: %s\n", i, argv[i]);
   		if(i == 2) break;
   	}
   ```

   ​

   ex11:

   ```c
   int i = 0;
   	while(argc){
   		printf("arg %d: %s\n", i, argv[i]);
   		i++;
   		if(i >= argc) break;
   	}
   ```

4. 第一個判斷所輸出的話真的正確嗎?由於你的“第一個參數”不是用戶輸入的第一個參數,把它改正。

   ```c
   if(argc == 1) {
   		printf("Please enter arguments.\n");
   	} else if(argc > 1 && argc < 4) {
   		printf("Here's your argument:\n");

   		for (i = 1; i < argc; i++)
   		{
   			printf("%s ", argv[i]);
   		}
   		printf("\n");
   	} else if(argc == 4){
   		printf("Perfect!\n");
   	} else {
   		printf("You have too many arguments. You suck.\n");
   	}
   ```

   i = 0會顯示程式本身，i = 1才是參數的開始