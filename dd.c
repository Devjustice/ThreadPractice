//thread
#include <pthread.h> //pthread_create(), pthread_join(), pthread_self()
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//쓰레드에서 사용할 함수
void *t_function(void *data)
{
        int id;
        int ii = 0;
	int ipt,i,j,rc;
        id = *((int *)data);
pthread_mutex_t a_mutex=PTHREAD_MUTEX_INITIALIZER;
rc=pthread_mutex_lock(&a_mutex);
        while(1)
        {
             srand(time(NULL));
int userhp=250;//수강생 기본hp
char names[20][30]={"","복이","땅복이","킹복이"};
char inv[20][30]={"","소드","엘보","키보드","콜라"};
int monhpa [4]={0,500,700,1500};

int monpp=0;
int monhp=500;
int ipt=0;
int ipt1=0;
int monlesthp=500;
int uselesthp=250;
int userpp=0;//파워 포인트
int monar=1;
EXIT:
while(1){pthread_mutex_lock(&a_mutex);
printf("[%s]와의 전투를 준비하세요\n",names[monar]);
printf("-----------1pIoT수강생의 하루----------------\n");
printf("||||1번 소드 ||||2번 엘보|||| 3번 키보드 \n||||4번 콜라||||\n");
scanf("%d",&ipt);

switch(ipt){

case 1: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 2: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 3: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 4: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);int tmp=rand()&500;
uselesthp =uselesthp+tmp;printf("%d만큼 회복됨\n",tmp);
   goto EXIT;break;}

default : break;
}
printf("1p수강생은 [%s]를 만났습니다.\n",names[monar]);
while(1){
userpp=rand()%500;
if(monar==1){monpp=rand()%100;
if(monpp<10){monpp+10;}}
if(monar==2){monpp=rand()%300;
if(monpp<30){monpp+30;}}
if(monar==3){monpp=rand()%500;
if(monpp<50){monpp+50;}}
printf("1p수강생 채력 [%d]\n",uselesthp);
printf("1p수강생 공격력 = [%d]\n",userpp);
printf("[%s] 채력 = [%d]\n",names[monar],monlesthp);
printf("[%s] 공격력= [%d]\n",names[monar],monpp);
system("clear");
printf("\n");
printf("공격하려면 1을 입력하세요\n");
printf("인벤토리로 가려면 2을 입력하세요\n");
scanf("%d",&ipt1);


if(ipt1==2){printf("인벤토리");break;}
if(ipt1==1)
{
printf("[%s]의 맛을 보아라\n",inv[ipt]);
monlesthp = monlesthp-userpp;

if(monlesthp<=0){monar++;monlesthp=monhpa[monar];

if(monar==4){
printf("모두물리침");
monlesthp=0;break;}
printf("[%s]를 물리쳤다\n",names[monar-1]);
printf("다음상대는 [%s]이다\n",names[monar]);
break;}
}
if(monlesthp!=0){
printf("[%s]공격차례\n",names[monar]);

uselesthp=uselesthp-monpp;
if(uselesthp<=0){printf("[%s]에게 사망함\n",names[monar]);break;}
printf("\n");

printf("[%s]로부터 공격받음\n",names[monar]);
sleep(1);
printf("\n");


} 

}

if(uselesthp<=0){printf("1p수강생은 [%s]에게 사망함",names[monar]);break;}
 if(monlesthp<=0){;break;;}

}
if(monlesthp<=0){printf("물리침");exit(1);}
}

		
		               
		if(ii==9)
                return (void *)ii;
        }


void *t_ffunction(void *data)
{
        int id;
        int i = 0;

        id = *((int *)data);

        while(1)
        {
                //thread 식별자 출력,
               srand(time(NULL));
int userhp=250;//수강생 기본hp
char names[20][30]={"","복이","땅복이","킹복이"};
char inv[20][30]={"","소드","엘보","키보드","콜라"};
int monhpa [4]={0,500,700,1500};

int monpp=0;
int monhp=500;
int ipt=0;
int ipt1=0;
int monlesthp=500;
int uselesthp=250;
int userpp=0;//파워 포인트
int monar=1;
int rc=0;
pthread_mutex_t a_mutex=PTHREAD_MUTEX_INITIALIZER;
rc=pthread_mutex_lock(&a_mutex);
EXIT:
while(1){
printf("[%s]와의 전투를 준비하세요\n",names[monar]);
printf("-----------2pIoT수강생의 하루----------------\n");
printf("||||1번 소드 ||||2번 엘보|||| 3번 키보드 \n||||4번 콜라||||\n");


pthread_mutex_lock(&a_mutex);
scanf("%d",&ipt);
switch(ipt){

case 1: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 2: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 3: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);break;}
case 4: {printf("당신은 [%s]을 들었습니다.\n",inv[ipt]);int tmp=rand()&500;
uselesthp =uselesthp+tmp;printf("%d만큼 회복됨\n",tmp);
   goto EXIT;break;}

default : break;
}
printf("IOT수강생은 [%s]를 만났습니다.\n",names[monar]);
while(1){
userpp=rand()%500;
if(monar==1){monpp=rand()%100;
if(monpp<10){monpp+10;}}
if(monar==2){monpp=rand()%300;
if(monpp<30){monpp+30;}}
if(monar==3){monpp=rand()%500;
if(monpp<50){monpp+50;}}
printf("IOT수강생 채력 [%d]\n",uselesthp);
printf("IOT수강생 공격력 = [%d]\n",userpp);
printf("[%s] 채력 = [%d]\n",names[monar],monlesthp);
printf("[%s] 공격력= [%d]\n",names[monar],monpp);
system("clear");
printf("\n");
printf("공격하려면 1을 입력하세요\n");
printf("인벤토리로 가려면 2을 입력하세요\n");
scanf("%d",&ipt1);


if(ipt1==2){printf("인벤토리");break;}
if(ipt1==1)
{
printf("[%s]의 맛을 보아라\n",inv[ipt]);
monlesthp = monlesthp-userpp;

if(monlesthp<=0){monar++;monlesthp=monhpa[monar];

if(monar==4){
printf("모두물리침");
monlesthp=0;break;}
printf("[%s]를 물리쳤다\n",names[monar-1]);
printf("다음상대는 [%s]이다\n",names[monar]);
break;}
}
if(monlesthp!=0){
printf("[%s]공격차례\n",names[monar]);

uselesthp=uselesthp-monpp;
if(uselesthp<=0){printf("[%s]에게 사망함\n",names[monar]);break;}
printf("\n");

printf("[%s]로부터 공격받음\n",names[monar]);
sleep(1);
printf("\n");


} 

}

if(uselesthp<=0){printf("IoT수강생은 [%s]에게 사망함",names[monar]);break;}
 if(monlesthp<=0){;break;;}

}
if(monlesthp<=0){printf("물리침");exit(1);}

}  
		if(i==99)
                return (void *)i;
        }


int main(void)
{
        pthread_t p_thread[2]; //thread ID 저장할 변수 2개
        int thr_id; //thread generation error check
        int status; //thread 종료시 반환하는 값 저장 변수
        int a = 1; //쓰레드 함수 인자
        int b = 2; //쓰레드 함수 인자

        //thread1 generation
        thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
        if(thr_id < 0)
        {
                perror("thread create error : ");
                exit(0);
        }

        //thread2 generation
        thr_id = pthread_create(&p_thread[1], NULL, t_ffunction, (void *)&b);
        if(thr_id < 0)
        {
                perror("thread create error : ");
                exit(0);
        }

        //thread1이 종료될 때까지 main함수 종료를 기다린다. thread1이 종료시 반환하는 값 받는다.
        pthread_join(p_thread[0], (void **)&status);
        printf("return thread 0 %d\n", status);
        //thread2가 종료될  때까지 mian함수 종료를 기다린다. thread2가 종료시 반환하는 값 받는다.

        pthread_join(p_thread[1], (void **)&status);
        printf("return thread 1 %d\n", status);

        return 0;
}


