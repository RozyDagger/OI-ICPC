//Source code of <get/put>char_unlocked() {return __getc_unlocked_body(stdin);}
#define __getc_unlocked_body(_fp)                                        \
  (__glibc_unlikely ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end)        \
   ? __uflow (_fp) : *(unsigned char *) (_fp)->_IO_read_ptr++)

#define __putc_unlocked_body(_ch, _fp)                                        \
  (__glibc_unlikely ((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end)        \
   ? __overflow (_fp, (unsigned char) (_ch))                                \
   : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))

#include <stdio.h>
#define M10(a) (((a)<<3)+((a)<<1))
inline void readint(int &x){
    int c=getchar_unlocked();
    x=0;
    bool ng=0;
    for(;(c<48||c>57)&&c!='-';c=getchar_unlocked());
    if(c=='-'){
        ng=1;
        c=getchar_unlocked();
    }
    for(;c>47&&c<58;c=getchar_unlocked()) x=M10(x)+c-48;
    if(ng) x=-x;
}
inline void readstr(char *x){   //only lowercase here
    char c=getchar_unlocked();
    int i=0;
    for(;c<97||c>122;c=getchar_unlocked());
    for(;c>96&&c<123;c=getchar_unlocked()) x[i++]=c;
}
inline void writeint(int x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    if(x<0){
        putchar_unlocked('-');
        x=~x+1;
    }
    int n=x, t=n, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
