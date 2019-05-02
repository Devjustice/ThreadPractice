#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>
int getch();

int main(){
int x;
int ipt;
char tarr[20][30];
while(1){
        system("clear");
        for(int i=1;i<=11;i++){
                for(int k=1;k<30;k++){
                        if(i==11)tarr[i][k]='@';
                        else
                        tarr[i][k]=' ';
                        
                        if(i==10&&k==1){tarr[i][k]='#';}//i=19땅 i=10공중 기둥높이 7이라서 
                        
                        printf("%c ",tarr[i][k]);
                }
                printf("\n");
        }

        ipt=getch();
        if(ipt==27)
        {
                int j=10;
                
                for(x=0;x<10;x++)
                {       
                        system("clear");
                        for(int i=1;i<=11;i++)
                        {
                                for(int k=1;k<30;k++)
                                {
                                        if(i==11)tarr[i][k]='@';
                                        else if(tarr[i][k]='@')
                                        {tarr[i][k]=' ';}
                                        tarr[j][1]='#';
                                        printf("%c ",tarr[i][k]);
                                        
                                }
                                printf("\n");
                        }
                        j--;
                        if(j==1){break;}
                        usleep(x*10000);
                                                
                        
                }
               
                for(x=10;x>0;x--)
                {
                        system("clear");
                        for(int i=1;i<=11;i++)
                        {
                                for(int k=1;k<30;k++)
                                {
                                        if(i==11)tarr[i][k]='@';
                                        else if(tarr[i][k]='#')
                                        {tarr[i][k]=' ';}
                                        tarr[j][1]='#';
                                        printf("%c ",tarr[i][k]);
                                        
                                }
                                printf("\n");
                        }
                        j++;
                        if(j==11){break;}
                        usleep(x*10000);                        
                        
                }
                

        }

        for(int i=1;i<20;i++){
                for(int k=1;k<30;k++){
                        tarr[i][k]=' ';
                        if(i==19&&k==1){tarr[i][k]='#';}//i=19땅 i=10공중 기둥높이 7이라서 
                        printf("%c ",tarr[i][k]);
                }
        printf("\n");
        }
}
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




/*


*/


