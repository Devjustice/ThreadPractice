#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<termios.h>
void *thread_function(void *);
int getch();
int main(){
pthread_t t_id;
int ipt=0;
void * t_return=NULL;
while(1){


pthread_create(&t_id, NULL, thread_function, (void *)&ipt); //방향키 쓰레드
pthread_join(t_id, &t_return);
//printf("%d",ipt); 
if(ipt==1){
puts("dd"); 
ipt=0;
}
}
return 0;}
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




void *thread_function(void *data)
{
               //방향키를 받는 변수
        int *ipt=(int *)malloc(sizeof(int));
        
        ipt=((int *)data);
       
        if (getch() == '\033') 
        {
               getch();
                switch(getch())
				{case 'A'://puts("up");
				*ipt=1;
				break;
                	
		 



		}
        



}
        return ipt;
}



//if(getch()==119){*ipt=7;puts("w");}











