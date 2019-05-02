#include"init.h"
int main(){
srand(time(NULL));
pthread_t t_id;//키입력쓰레드
void * t_return=NULL;//키입력쓰레드생성
int obd=0;
int rnd=0;
int tmp=0;
int up=0;
int ipt=0;//
int down=0;//내려갈때 변수
double intervalcon;//장애물간 간격조절
double interval;//장애물간 간격
char map[25][100000];//맵의 배열
/******************************/
for(int i=0;i<22;i++){//맵 생성
for(int j=0;j<100000;j++){
if(i==21||i==0)map[i][j]='-';
else map[i][j]=' ';
}}
while(1){//장애물 생성
rnd=(rand()%100)+100*interval;//장애물 랜덤
intervalcon++; 
if(intervalcon%2==1)
rnd-=10; else rnd+=10;
if(rnd>100000)//시작부분에 생성되는 것을 방지
printf("%d\n",rnd);continue;
for(int i=18;i<21;i++){//장애물의 높이
tmp=rnd;//임시값에 저장
for(tmp;tmp<rnd;tmp++){//장애물의 넓이
map[i][tmp]='X';}
}





}//장애물생성 종료













return 0;}
