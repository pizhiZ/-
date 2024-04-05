#include<stdio.h>
char pprint(char a[]){
    for (int  i = 0; i < 9; i++)
    {
        printf("%c",a[i]);
        if (i==2||i==5||i==9)
        {
            printf("\n");
        }
        
    }
}
void xiaqi(char q,int h,int l,char *p){
    *(p+(h-1)*3+l-1)=q;
}
int judge(char *p){
   for (int  i = 0; i < 7; i+=3)
    {
        if (*p==*(p+1+i)&&*(p+1+i)==*(p+2+i))
        {
            if (*p!='N')
            {
                return 1;
            }
            
        }
    }
     for (int  i = 0; i < 3; i++)
    {
        if (*(p+i)==*(p+3+i)&&*(p+3+i)==*(p+6+i))
        {
            if (*(p+i)!='N')
            {
                return 1;
            }
            
        }
    }
     for (int  i = 0; i < 3; i+=2)
    {
        if (*p==*(p+4)&&*(p+4)==*(p+8))
        {
            if (*p!='N')
            {
                return 1;
            }
            
        }
        if (*(p+i)==*(p+2+i)&&*(p+2+i)==*(p+6+i))
        {
            if (*(p+i)!='N')
            {
                return 1;
            }
            
        }
    }
}
int main(){
    int hang,lie,hang0,lie0;
    int count=0;
	char chessboard[9]={'N','N','N',
                        'N','N','N',
                        'N','N','N',},qi,qi0;
    printf("以上展示的是棋盘,规格为9X9\n\n\n",pprint(chessboard));
    printf("▢ 请输入要下的棋子(分别有X,O)\n[例:X 3 1(其中，前一个数字为行,后一个为列)]\n");
    scanf("%c %d %d",&qi,&hang,&lie);
    qi0=qi;
    for (int i = 0; i < 9; i++)
    {
        xiaqi(qi,hang,lie,chessboard);
        count++;
        pprint(chessboard);
        if (judge(chessboard)==1)
        {
            printf("\n\n游戏结束,%c棋玩家胜利!",qi);
            break;
        }
        printf("\n\n请下一位玩家下棋:");
        getchar();
        scanf("%c %d %d",&qi,&hang,&lie);
        if (qi0==qi)
        {
            printf("%c玩家不可连续下棋!请另一位玩家下棋");
            printf("\n\n请下一位玩家下棋:");
            getchar();
            scanf("%c %d %d",&qi,&hang,&lie);
        }
        if (hang==hang0&&lie==lie0)
        {
            printf("不可在重复位置下棋，请重下");
            getchar();
            scanf("%c %d %d",&qi,&hang,&lie);
        }
        
        qi0=qi;
        hang0=hang;
        lie0=lie;
    } 
    return 0;
}