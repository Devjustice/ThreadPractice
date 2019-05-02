#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>

int map();
int user();int getch();
//int hitbox(char *maps,int k);

int main()
{	
	int a;
	
	a=map();
	
	system("clear");
	if(a==1)
	{
		printf("충돌!\n");
	}
	else
	printf("완-주!\n");
	return 0;
}

int map()
{
	srand(time(NULL));
	int ret;
	int i,j,a,b,x,y,z,k=0;
	double c;
	system("clear");
	char maps[50][100000];//맵 가장자리 0번 21번 #포함 총 22줄 0번 21번줄 # 제외 20줄
	for(i=0;i<22;i++)//맵 초기화
	{
		for(j=0;j<100000;j++)
		{
			if(i==21||i==0)
			maps[i][j]='#';
			else
			maps[i][j]=' ';
		}
		  

	}
	
	for(c=1;c<999;)//장해물 생성
	{
		
		a=(rand()%100)+100*c;
		b=a+3;
		
		if(a>=100000)//컴파일용 a가 10만을 넘어가면 장해물이 시작부분에 생김 방지
		{
			continue;
		}
		for(i=13;i<21;i++)
		{	
			j=a;
			for(;j<b;j++)
			{
				maps[i][j]='%';
			}
		}
		if(c<5)//거리에따라 장해물 빈도 증가
		{
			c+=0.9;
		}
		else if(c>300)
		{
			c+=0.3;
		}
		else if(c>120)
		{
			c+=0.4;
		}
		else if(c>60)
		{
			c+=0.5;
		}
		else if(c>30)
		{
			c+=0.6;
		}
		else if(c>15)
		{
			c+=0.7;
		}
		else
		{
			c+=0.8;
		}
	}
	for(i=0;i<22;i++)//맵 생성
	{
		for(j=0;j<100;j++)
		{
			printf("%c",maps[i][j]);
		}
		printf("\n");
	}
	sleep(1);
	
	
	for(j=100;j<100000;j++)//맵 스크롤
	{
		system("clear");
		a=j+1;
		for(i=0;i<22;i++)
		{
			b=j-99;
			for(;b<a;b++)
			{
				printf("%c",maps[i][b]);
			}
			printf("\n");
		}
		//충돌
		
		
		for(x=18;x<21;x++)
		{
			y=11+k;
			z=y+3;
			for(;y<z;y++)
			{
				maps[x][y-3]=' ';//	그려진 캐릭터 제거
				if(maps[x][y]=='%')//	캐릭터가 그려질 공간에 %가 오면 충돌
				{
					printf("충돌\n");
					return 1;
				}
				else//	캐릭터 그리기
				{
					maps[x][y]='a';
				}
				ipt=getch();
				if(ipt==27){//키입력시
				int x=0,j=10;
				for(x=0;x<10;x++){system("clear");
				for(int i=1;i<=30;i++)
				for





						}
				
			}
			
		}
		










		k++;
		printf("%d\n",k);//거리
		if(j<500)	// 거리에 따라 속도 증가
		{
			usleep(100000);
		}
		else if(j<1000)
		{
			usleep(80000);
			printf("\x1b[32m");//초록
		}
		else if(j<2000)
		{
			usleep(70000);
			printf("\x1b[33m");//노랑
		}
		else if(j<3000)
		{
			usleep(60000);
			printf("\x1b[36m");//하늘
		}
		else if(j<4000)
		{
			usleep(50000);
			printf("\x1b[34m");//파랑
		}
		else if(j<5000)
		{
			usleep(40000);
			printf("\x1b[35m");//분홍
		}
		else
		{
			usleep(30000);
			printf("\x1b[31m");//빨강
			
		}
	}
	printf("\x1b[0m");//색깔 원상복구
}
/*int hitbox(char *maps,int k)//충돌파트
{
	int i=14,j=11+K,a=j+3;
	
	
	for(;i<21;i++)
	{
		for(;j<a;j++)
		{
			if(strcmp(map[i][j],'%'))
			{
				printf("충돌\n");
				return 0;
			}
			else
			{
				map[i][j]='u';
			}
		}
	}
}*/
int user()
{

}




int getch()
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);           // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);         // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                      // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                     // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // 터미널에 설정 입력
    c = getchar();                               // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // 원래의 설정으로 복구
    return c;}


