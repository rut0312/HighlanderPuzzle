#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long,long long>
#define rep(i, n) for(int i = 0; i < n; ++i)

int dx[6]={0,1,1,0,-1,-1};
int dy[6]={1,1,0,-1,-1,0};

int h,w;
int a[20][20];
int b[20][20];
int tp,tq,tr;
int nchp;

int x,y,pd;
int p,q,r;
int xchp;
bool ok;
stack<int>st;

void dfs(void);

void gonext(int d){
	if(ok)return;
	int c1,c2;
	bool can=true;
	if((0<b[x][y])&&(b[x][y]<77)){
		c1=b[x][y]/10,c2=b[x][y]%10;
		if((d!=c1)&&(d!=c2))can=false;
	}
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(a[nx][ny]<0)can=false;
	if((0<a[nx][ny])&&(a[nx][ny]<77)){
		c1=a[nx][ny]/10,c2=a[nx][ny]%10;
		if(((d+3)%6!=c1)&&((d+3)%6!=c2))can=false;
	}
	//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" "<<d<<endl;
	if(!can)return;
	int sx=x,sy=y,spd=pd;
	int sp=p,sq=q,sr=r;
	int sxchp=xchp;
	if((pd>=0)&&(b[x][y]==0)){
		if(abs(pd-d)==0)p++;
		if((abs(pd-d)==1)||(abs(pd-d)==5))q++;
		if((abs(pd-d)==2)||(abs(pd-d)==4))r++;
	}
	if((0<b[x][y])&&(b[x][y]<77))xchp++;
	//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" "<<d<<" ok"<<endl;
	x=nx,y=ny,pd=d;
	dfs();
	x=sx,y=sy,pd=spd;
	p=sp,q=sq,r=sr;
	xchp=sxchp;
	return;
}

void wrt_sol(void){
  st.push(100*x+y);
	int n=st.size();
	int c[20][20]={};
	rep(i,n){
		int z=st.top();
		c[z/100][z%100]=i+1;
		st.pop();
	}
	rep(i,h){
		rep(j,w){
			cout << std::setfill('0') << std::right << std::setw(2) << c[i][j];
			if(j<(w-1))cout<<" ";
			else cout<<endl;
		}
	}
	ok=true;
	return;
}

void dfs(void){
  //cout<<((int)(st.size()))<<" "<<x<<" "<<y<<endl;
	if(a[x][y]==88){
		if((tp>=p)&&(tq>=q)&&(tr>=r)&&(xchp>=nchp))wrt_sol();
		return;
	}
	a[x][y]=-1;
	st.push(100*x+y);
	rep(i,6)if(!ok)gonext(i);
	st.pop();
	a[x][y]=b[x][y];
	return;
}

int main(void){
	cin>>h>>w;
	cin>>tp>>tq>>tr;
	nchp=0;
	rep(i,h){
		rep(j,w){
			cin>>a[i][j];
			b[i][j]=a[i][j];
			if((0<a[i][j])&&(a[i][j]<77))nchp++;
		}
	}
	rep(i,h)rep(j,w)if(a[i][j]==77){
		x=i,y=j,pd=-1;
		p=0,q=0,r=0;
		ok=false;
		dfs();
	}
	if(!ok)cout<<"Impossible"<<endl;
	
	return 0;
}