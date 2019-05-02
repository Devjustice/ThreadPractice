#include"init.h"
void *thread_ffunction(void *data);
int main()
{pthread_t t_id;
int up=0,ipt=0,down=0,jumcol; //점프
void * t_return=NULL;
pthread_create(&t_id, NULL, thread_ffunction, (void *)&ipt);
pthread_join(t_id, &t_return);
printf("\n");
pthread_create(&t_id, NULL, thread_function, (void *)&ipt);
pthread_join(t_id, &t_return);
}

void *thread_ffunction(void *data)
{srand(time(NULL));
pthread_t t_id;
void * t_return=NULL;
int intervalcon=0;//장해물 간격 조절
int up=0,ipt=0,down=0,jumcol; //점프
int i,j,rnd,rndrw,x,y,z,des=0; //변수
double interval;//장해물 생성 간격
system("clear");
char maps[25][100000];//맵 가장자리 0번 21번 #포함 총 22줄 0번 21번줄 # 제외 20줄
for(i=0;i<22;i++){//맵 초기화
for(j=0;j<100000;j++){if(i==21||i==0)maps[i][j]='#';
else maps[i][j]=' ';
}
}
/*맵생성 과 장애물 */
for(interval=1;interval<999;){//object
rnd=(rand()%100)+100*interval;
intervalcon+=1;
if(intervalcon%2==1){rnd-=10;}else{rnd+=10;}
rndrw=rnd+3;
if(rnd>=100000)//컴파일용 a가 10만을 넘어가면 장해물이 시작부분에 생김 방지
{printf("%d\n",rnd);continue;}
for(i=18;i<21;i++){j=rnd;
for(;j<rndrw;j++){maps[i][j]='%';}}
if(interval<5){interval+=0.7;}
else if(interval>300){interval+=0.5;}else if(interval>120){interval+=0.6;}
else if(interval>60){interval+=0.5;}else if(interval>30){interval+=0.5;}
else if(interval>15){interval+=0.5;}else{interval+=0.5;}}
for(i=0;i<22;i++){//맵 생성
for(j=0;j<100;j++){
printf("%c",maps[i][j]);}printf("\n");}
for(j=100;j<100000;j++){//맵스크롤
system("clear");rnd=j+1;for(i=0;i<22;i++){
rndrw=j-99;for(;rndrw<rnd;rndrw++){
printf("%c",maps[i][rndrw]);}printf("\n");}
//점프키스레드
if(pthread_create(&t_id, NULL, thread_function, (void *)&ipt)){
pthread_join(t_id, &t_return);
}
//점프키스레드
if(ipt==1){up=10;ipt=0;free(t_return);}
if(up==0&&down==0){//1
for(x=18;x<21;x++){//2
y=11+des;//로우값변화
z=y+3;
for(;y<z;y++){//4
if(maps[x][y]=='%'||maps[x][y]=='#'){//1
printf("충돌1\n");int pthread_cancel(pthread_t thread);}//1break;int pthread_cancel(pthread_t thread);return 1;free(t_return);
else{//3
if(maps[x][y-3]=='a')
maps[x][y-3]=' ';	//그려진 캐릭터 제거
maps[x][y]='a';}}}}
/***************************************/
else if(up==0&&down>0){
down-=1;x=21-down;jumcol=x-3;if(jumcol>=18)jumcol=17;
for(;jumcol<x;jumcol++){
y=11+des;
z=y+3;
for(;y<z;y++){if(maps[x][y]=='%'||maps[x][y]=='-'){//	캐릭터가 그려질 공간에 %가 오면 충돌
printf("충돌2\n");int pthread_cancel(pthread_t thread);}
if(maps[jumcol][y-3]=='a')//뒤 제거
maps[jumcol][y-3]=' ';
if(maps[jumcol-3][y-3]=='a')//대각선 제거
maps[jumcol-3][y-3]=' ';
if(maps[jumcol-3][y]=='a')//위 제거
maps[jumcol-3][y]=' ';	//그려진 캐릭터 제거
maps[jumcol][y]='a';}}
}else{up--;down+=1;x=21-down;jumcol=x-3;
for(;x>jumcol;x--)
{y=11+des;
z=y+3;
for(;y<z;y++){if(maps[x][y]=='%'||maps[x][y]=='#')//	캐릭터가 그려질 공간에 %가 오면 충돌
{printf("충돌3\n");int pthread_cancel(pthread_t thread);}
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
des++;
printf("%d\n",des);//거리
if(j<500)	{// 거리에 따라 속도 증가
usleep(30000);}
else if(j<1000){
usleep(20000);
printf("\x1b[32m");}
else if(j<1500){
usleep(10000);printf("\x1b[33m");}else if(j<2000){
usleep(9000);printf("\x1b[36m");}else if(j<3500){
usleep(8000);printf("\x1b[34m");}else if(j<4000){
usleep(7000);printf("\x1b[35m");}else{usleep(6000);
printf("\x1b[31m");}
}

}//main

















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





