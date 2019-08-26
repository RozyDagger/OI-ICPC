#include <cstdio>
void readint(int &num){
  bool ng=0;
  register int c;
  num=0;
  c=getchar();
  if(c=='-'){
    ng=1;
    c=getchar();
  }
  for(;c>47&&c<58;c=getchar()) num=num*10+c-48;
  if(ng) num=(~(num)+1);
}
void readstr(string &str){
  register int c, vi[64]={0}, len=0;
  c=getchar();
  for(;(c>47&&c<58)||(c>64&&c<91)||(c>96&&c<123);c=getchar()) vi[len++]=c;
  //c=getchar();
  str.resize(len);
  for(int i=0;i<len;++i) str[i]=vi[i];
}
