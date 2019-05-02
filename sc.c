#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<termios.h>

void *thread_function(void *data);

int getch();

int main(){
        int state;
        pthread_t t_id;
        void * t_return=NULL;
        int center=15;     //이동하는 막대기를 나타내는 변수
        char tarr[32][32]={0};
        tarr[30][15]='1';
        tarr[29][15]='4';
	 
        system("clear");
         
        while(1)
        {  

                for(int i=0; i<=31; i++)
                {       
                        for(int j=0; j<=31; j++)
                        {
                                if(tarr[i][j]!='1' && tarr[i][j]!='4')
                                {
                                if(i==0 || i==31)tarr[i][j]='=';
                                else if((i>0 && i<31) && (j==0 || j==31))tarr[i][j]='5';
                                else tarr[i][j]=' ';
                                }
                        }
                }
                        tarr[30][center]='1';
                        tarr[30][center-1]='2';
                        tarr[30][center-2]='3';
                        tarr[30][center+1]='2';
                        tarr[30][center+2]='3';
                


                for(int i=0; i<=31; i++)
                {       
                        for(int j=0; j<=31; j++)
                        {
                                if(tarr[i][j]=='1' || tarr[i][j]=='2' || tarr[i][j]=='3')printf("■");
				                                
					else if(tarr[i][j]=='4')printf("○");
                                else if(tarr[i][j]=='5')printf("│");
                                else printf("%c",tarr[i][j]);
                        }
                        printf("\n");
                }

           	   pthread_create(&t_id, NULL, thread_function, (void *)&center); //방향키 쓰레드
                pthread_join(t_id, &t_return);
                	
                printf("%d\n",center);
                
                system("clear");
        }
        
                free(t_return);
        return 0;       
}


















void *thread_function(void *data)
{
        int key=0;        //방향키를 받는 변수
        int *center=(int *)malloc(sizeof(int));
        
        center=((int *)data);
        key=getch();
        if (getch() == '\033') 
        {
                getch();
                switch(getch())
                {
                        case 'C':
		                if(*center<=27)
		                *center+=1;
                                break;
                        case 'D':
                                if(*center>=3)
		                *center-=1;
                                break;
                }
        }
        return center;
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

