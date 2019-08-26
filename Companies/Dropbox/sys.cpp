#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 256
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define LEFT(a) ((a)*2+1)
#define RIGHT(a) ((a)*2+2)
#define PARENT(a) (((a)-1)/2)

class Allocator{
public:
    class que{
    public:
        queue<int> q;
        unordered_set<int> st;
        int sz;
        que(int a):sz(a){
            for(int i=1;i<=a;q.push(i++));
            st.clear();
        }
        int get(){
            if(q.empty()) return -1;
            int rst=q.front();
            q.pop();
            st.insert(rst);
            return rst;
        }
        bool del(int a){
            if(a<0||a>=sz||st.find(a)==st.end()) return 0;
            st.erase(a);
            q.push(a);
            return 1;
        }
    };
    class bs{
    public:
        bitset<MAXN> v;
        int sz, cur;
        bs(int a):sz(a){
            v.reset();
            cur=0;
        }
        int get(){
            if(cur>=sz) return -1;
            int rst=cur;
            v.set(cur);
            for(;v.test(cur);++cur);
            return rst;
        }
        bool del(int a){
            if(a<0||a>=sz||!v.test(a)) return 0;
            v.reset(a);
            cur=cur<a?cur:a;
            return 1;
        }
    };
    class st{
    public:
        bitset<MAXN> T;
        int sz;
        st(int a):sz(2*a-1){
            T.reset();
        }
        void update(int id){
            while(id>0){
                int p=PARENT(id);
                if(T.test(LEFT(p))&&T.test(RIGHT(p))) T.set(p);
                else T.reset(p);
                id=p;
            }
        }
        int get(){
            int ind=0;
            while(ind<sz-1)
                if(!T.test(LEFT(ind))) ind=LEFT(ind);
                else if(!T.test(RIGHT(ind))) ind=RIGHT(ind);
                else return -1;
            T.set(ind);
            update(ind);
            return ind-sz+1;
        }
        bool del(int id){
            if(id<0||id>=sz||!T.test(id+sz-1)) return 0;
            T.reset(id+sz-1);
            update(id+sz-1);
            return 1;
        }
    };
};

class download{
public:
    class down_bs{
    private:
        bitset<100> bs;
    public:
        down_bs(){
            bs.reset();
        }
        bool update(int a){
            bs.set(a);
            return 1;
        }
        bool update(int a, int b){
            for(int i=a;i<=b;bs.set(i++));
            return 1;
        }
        bool done(){
            for(int i=0;i<100;++i) if(!bs.test(i)) return 0;
            return 1;
        }
    };

    class down_mi_q{
        struct Node{
            int a, b;
            Node(int i, int j):a(i), b(j){}
        };
        struct cmp{ 
            bool operator()(Node a, Node b) const{
                return a.a<b.a;
            }
        };
    private:
        priority_queue<Node, vector<Node>, cmp> q;
        int sz;
    public:
        down_mi_q(int a){
            sz=a;
        }
        void add(Node a){
            q.push(a);
            if(q.size()>1){
                Node t=q.top();
                q.pop();
                while(!q.empty()&&q.top().a<t.b){
                    Node tt=q.top();
                    q.pop();
                    t.b=MAX(t.b, tt.b);
                }
                q.push(t);
            }
        }
        bool check(){
            return q.size()==1&&q.top().a==0&&q.top().b==sz;
        }
    };
}

class logger{
public:
    class que{
    public:
        queue<int> Q;
        int T;
        que(int t):T(t){}
        int get(int t){
            for(;!Q.empty()&&Q.front()+T<t;Q.pop());
            return Q.size();
        }
        void req(int t){
            Q.push(t);
        }
    };
    class arr{
    public:
        vector<int> V, R;
        int T;
        arr(int t):T(t){
            V.resize(t, 0);
            R.resize(t, 0);
        }
        int get(int t){
            int rst=0;
            for(int i=0;i<T;++i) if(R[i]+T>=t) rst+=V[i];
            return rst;
        }
        void req(int t){
            int ind=t%T;
            if(R[ind]!=t){
                R[ind]=t;
                V[ind]=1;
            }else ++V[ind];
        }
    };
};

int main() {
    /*
    //bitset test
    bitset<8> b(43);
    cout << "Bitset is         " << b << '\n';
    b.reset(0);
    cout << "After b.reset(0): " << b << '\n';
    b.reset();
    cout << "After b.reset():  " << b << '\n';
    
    //allocate id: queue
    cout<<"========Allocate id-Queue========"<<endl;
    alloc_q T(10);
    for(int i=0;i<10;++i) cout<<T.get()<<endl;
    for(int i=0;i<10;i+=2) cout<<T.del(i)<<endl;
    for(int i=0;i<10;++i) cout<<T.get()<<endl;
    
    //allocate id: bitset
    cout<<"========Allocate id-Bitset========"<<endl;
    alloc_bs T1(10);
    for(int i=0;i<12;++i) cout<<T1.get()<<endl;
    for(int i=0;i<10;i+=2) cout<<T1.del(i)<<endl;
    for(int i=0;i<10;++i) cout<<T1.get()<<endl;
    
    //allocate id: segment tree
    cout<<"========Allocate id-Segment tree========"<<endl;
    alloc_st T2(10);
    for(int i=0;i<12;++i) cout<<T2.get()<<endl;
    for(int i=0;i<10;i+=2) cout<<T2.del(i)<<endl;
    for(int i=0;i<10;++i) cout<<T2.get()<<endl;
    */
    
    //Allocator
    Allocator::que *q=new Allocator::que(10);
    for(int i=0;i<12;cout<<q->get()<<endl, ++i);
    for(int i=0;i<10;cout<<q->del(i)<<endl, i+=2);
    for(int i=0;i<10;cout<<q->get()<<endl, ++i);
}
