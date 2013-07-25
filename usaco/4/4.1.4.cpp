/*
ID: lisendo1
PROG: cryptcow
LANG: C++
*/
#include<fstream> //by adventop
#include<cstring>
#define BIG 1500000
#define LEN 77
using namespace std;
const char End[] = "Begin the Escape execution at the Break of Dawn";
ofstream fout ("cryptcow.out",ios::out);
ifstream fin ("cryptcow.in",ios::in);
bool Hash[BIG];
long END=0,HASH;
char start[LEN],fir[LEN],STR[LEN];
inline unsigned long BKDRhash(const char *str){ //BKDRhash
    unsigned long seed=131313,hash=0;
    while(*str) hash=hash*seed+(*str++);
    return (hash & 0x7FFFFFFF) % 1000003;
}
inline void change(char *str,int c,int o,int w){
    int len=-1;
    memset(STR,0,sizeof(STR));
    for(int i=0;i<c;i++) STR[++len]=str[i];
    for(int i=o+1;i<w;i++) STR[++len]=str[i];
    for(int i=c+1;i<o;i++) STR[++len]=str[i];
    for(int i=w+1;i<strlen(str);i++) STR[++len]=str[i];
    strcpy(str,STR);
}
inline bool dfscut(const char *str){
    int len=-1,Len,i,flag,Flag,lens=strlen(str);
    while(++len<lens && str[len]!='C') if(End[len]!=str[len]) return true;
    i=47;Len=len+1;len=lens;
    while(len>0 && str[len-1]!='W') if(End[--i]!=str[--len]) return true;
    lens=len;len=Len;Len=-1;
    while(len<lens){
        while(++len<lens && str[len]!='C' && str[len]!='O' && str[len]!='W')
            fir[++Len]=str[len];
        Flag=0;
        if(len<=lens)
            for(int i=0;i<strlen(End)-Len;i++){
                flag=1;
                for(int j=i;j<=i+Len;j++)
                    if(fir[j-i]!=End[j]) {flag=0;break;}
                if(flag) {Flag=1;break;}
            }
        if(!Flag) return true;
        Len=-1;
    }
    return false;
}
bool dfs(char *str,int step){
    char DFS[LEN];
    HASH=BKDRhash(str);
    if(Hash[HASH]) return false;
    else if(HASH==END) {fout<<"1 "<<step<<endl;return true;}
    Hash[HASH]=true;
    if(dfscut(str)) return false;
    for(int o=0;o<strlen(str);o++)
        if(str[o]=='O')
            for(int c=0;c<o;c++)
                if(str[c]=='C')
                    for(int w=strlen(str)-1;w>o;w--)
                        if(str[w]=='W'){
                            strcpy(DFS,str); //avoid to use dynamic point
                            change(DFS,c,o,w);
                            if(dfs(DFS,step+1)) return true;
                        }
    return false;
}
int main(){
    memset(Hash,0,sizeof(Hash));
    END=BKDRhash(End);
    fin.getline(start,LEN+2,'\n');
    if(!((strlen(start)-47)%3) && !dfs(start,0)) fout<<"0 0"<<endl;
    return 0;
}
