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

#include<pthread.h>

void *thread_function(void *);
void *thread_ffunction(void *);
int getch();
int map();

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
	pthread_t t_id;
	void * t_return=NULL;
	int jum=0,ipt=0,pe=0,q; //점프
	int i,j,a,b,x,y,z,k=0; //변수
	double c;//장해물 생성 간격
	system("clear");
	char maps[25][100000];//맵 가장자리 0번 21번 #포함 총 22줄 0번 21번줄 # 제외 20줄
		pthread_create(&t_id, NULL, thread_ffunction, (void *)&ipt); //방향키 쓰레드
		pthread_join(t_id, &t_return);
		
		pthread_create(&t_id, NULL, thread_function, (void *)&ipt); //방향키 쓰레드
		pthread_join(t_id, &t_return);
		
		if(jum==0&&pe==0&&ipt==1)
		{
			jum=10;
		}
		
		
		if(ipt==1)
		{
			if(jum==0&&pe>0)//내려감
			{
			
				pe-=1;
				x=21-pe;
				q=x-3;
				if(q>=18)
				q=17;
				for(;q<x;q++)
				{
					y=11+k;
					z=y+3;
					for(;y<z;y++)
					{
						if(maps[q][y]=='%')//	캐릭터가 그려질 공간에 %가 오면 충돌
						{
							printf("충돌\n");
							return 1;
						}
						else//	캐릭터 그리기
						{
							if(maps[q][y-3]=='a')//뒤 제거
							maps[q][y-3]=' ';
							if(maps[q-3][y-3]=='a')//대각선 제거
							maps[q-3][y-3]=' ';
							if(maps[q-3][y]=='a')//위 제거
							maps[q-3][y]=' ';	//그려진 캐릭터 제거
							maps[q][y]='a';		//캐릭터 그리기
						}	
					}
				}
				
				//pthread_exit(NULL);
			}
			else //올라감
			{
				jum--;
				pe+=1;
				x=21-pe;
				q=x-3;
				for(;x>q;x--)
				{
					y=11+k;
					z=y+3;
					for(;y<z;y++)
					{
						if(maps[x][y]=='%')//	캐릭터가 그려질 공간에 %가 오면 충돌
						{
							printf("충돌\n");
							return 1;
						}
						else//	캐릭터 그리기
						{
							if(maps[x+3][y]=='a')//아래 제거
							maps[x+3][y]=' ';
							if(maps[x+3][y-3]=='a')//대각선 제거
							maps[x+3][y-3]=' ';
							if(maps[x][y-3]=='a')//뒤 제거
							maps[x][y-3]=' ';	//그려진 캐릭터 제거
							maps[x][y]='a';		//캐릭터 그리기
						}		
					}
				}
			}
		
		
			ipt=0;
		
		
		
		}
		for(x=18;x<21;x++)
		{
			y=11+k;
			z=y+3;
			for(;y<z;y++)
			{
				if(maps[x][y]=='%')//	캐릭터가 그려질 공간에 %가 오면 충돌
				{
					printf("충돌\n");
					return 1;
				}
				else//	캐릭터 그리기
				{
			
					/*if(maps[x+3][y]=='a')//아래 제거
					maps[x+3][y]=' ';
					if(maps[x+3][y-3]=='a')//대각선 제거
					maps[x+3][y-3]=' ';
					if(maps[x][y-3]=='a')//뒤 제거
					maps[x][y-3]=' ';	//그려진 캐릭터 제거
					maps[x][y]='a';		//캐릭터 그리기*/
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
	//printf("\x1b[0m");//색깔 원상복구


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
    return c;
}




void *thread_function(void *data)
{
               //방향키를 받는 변수
        int *ipt=(int *)malloc(sizeof(int));
        
        ipt=((int *)data);
       
        if (getch() == '\033') 
        {
               getch();
                switch(getch())
		{
		case 'A'://puts("up");
		*ipt=1;
		break;
		}
	}
        return ipt;
}








void *thread_ffunction(void *data)
{
int jum=0,ipt=0,pe=0,q; //점프
	int i,j,a,b,x,y,z,k=0; //변수
	double c;//장해물 생성 간격
	system("clear");
	char maps[25][100000];//맵 가장자리 0번 21번 #포함 총 22줄 0번 21번줄 # 제외 20줄
	
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
		for(i=16;i<21;i++)
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

}sleep(100000);
}
