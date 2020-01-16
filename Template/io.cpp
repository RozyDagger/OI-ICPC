#include <cstdio>
int readint(){
  bool ng=0;
  int c=getchar(), num=0;
  c=getchar();
  ng=c=='-';
  for(c=getchar();c>47&&c<58;c=getchar()) num=num*10+c-48;
  return ng?(~(num)+1):num;
}
void readstr(string &str){
  int c, vi[64]={0}, len=0;
  c=getchar();
  for(;(c>47&&c<58)||(c>64&&c<91)||(c>96&&c<123);c=getchar()) vi[len++]=c;
  //c=getchar();
  str.resize(len);
  for(int i=0;i<len;++i) str[i]=vi[i];
}
