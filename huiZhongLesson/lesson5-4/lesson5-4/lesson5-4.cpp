#include "stdio.h"

//运算符优先级非与或

void main(){
	bool b = !true && false || true;
	printf("%d",b);

	//繁杂版猜数字
	int math = 20;
	int guess = 0;
	printf("请输入一个数字");
	scanf_s("%d",&guess);
	if (guess == math)
		printf("猜对了\n");
	else{
		if (math < guess){
			printf("输大了\n");
			printf("请输入一个数字");
			scanf_s("%d", &guess);
			if (guess == math)
				printf("猜对了\n");
			else{
				if (math < guess){
					printf("输大了\n");
					printf("请输入一个数字");
					scanf_s("%d", &guess);
					if (guess == math)
						printf("猜对了\n");
					else{
						if (math < guess){
							printf("输大了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
						else{
							printf("输小了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
					}
				}
				else{
					printf("输小了\n");
					printf("请输入一个数字");
					scanf_s("%d", &guess);
					if (guess == math)
						printf("猜对了\n");
					else{
						if (math < guess){
							printf("输大了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
						else{
							printf("输小了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else{
			printf("输小了\n");
			printf("请输入一个数字");
			scanf_s("%d", &guess);
			if (guess == math)
				printf("猜对了\n");
			else{
				if (math < guess){
					printf("输大了\n");
					printf("请输入一个数字");
					scanf_s("%d", &guess);
					if (guess == math)
						printf("猜对了\n");
					else{
						if (math < guess){
							printf("输大了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
						else{
							printf("输小了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
					}
				}
				else{
					printf("输小了\n");
					printf("请输入一个数字");
					scanf_s("%d", &guess);
					if (guess == math)
						printf("猜对了\n");
					else{
						if (math < guess){
							printf("输大了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
						else{
							printf("输小了\n");
							printf("请输入一个数字");
							scanf_s("%d", &guess);
							if (guess == math)
								printf("猜对了\n");
							else{
								if (math < guess){
									printf("输大了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
								else{
									printf("输小了\n");
									printf("请输入一个数字");
									scanf_s("%d", &guess);
									if (guess == math)
										printf("猜对了\n");
									else{
										if (math < guess){
											printf("输大了\n");
										}
										else{
											printf("输小了\n");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}