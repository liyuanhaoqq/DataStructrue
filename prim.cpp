#include<stdio.h>
#include<string>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
const int MAXN=1000+10;
const int MAXINT=32767 ;
struct Graph{
    string vexs[MAXN];
    int arcs[MAXN][MAXN];
    int vexnum,arcnum;
}G;
struct low{
    string adjvex;
    int lowcost;
}closedge[MAXN];
int LocateVex(string s)
{
    return (int)(s[1]-'0');
}
void PrintUDN()
{

    for(int i=1;i<=G.vexnum;++i)
     {
        for(int j=1;j<=G.vexnum;++j)
        {
            printf("%10d",G.arcs[i][j]);

        }
        printf("\n");
     }
}
void CreateUDN()
{
    int vexnum,arcnum;
    cin>>vexnum>>arcnum;// ‰»Î
    G.vexnum=vexnum;
    G.arcnum=arcnum;
    for(int i=1;i<=vexnum;++i){
        cin>>G.vexs[i];// ‰»Î
    }
    for(int i=1;i<=G.vexnum;++i)
         for(int j=1;j<=G.vexnum;++j)
            G.arcs[i][j]=MAXINT;
    for(int k=1;k<=arcnum;++k)
    {

        string v1,v2;
        int w;
        cin>>v1>>v2>>w;
        int i=LocateVex(v1);
        int j=LocateVex(v2);
        G.arcs[i][j]=G.arcs[j][i]=w;

    }
    PrintUDN();
}
int MIN(struct low closedge[])
{
    int k;
    struct low minTemp;
    minTemp.lowcost=MAXINT;
    for(int i=1;i<=G.vexnum;++i)
    {
        if(closedge[i].lowcost!=0&&(minTemp.lowcost>closedge[i].lowcost))
            {
                minTemp.lowcost=closedge[i].lowcost;
                k=i;
            }
    }

    return k;
}
void shortestSpanTree_prim()
{
    int k=LocateVex(G.vexs[1]);
    for(int j=1;j<=G.vexnum;++j)
    {
        if(j!=k){
                closedge[j]={G.vexs[k],G.arcs[k][j]};
               // cout<<j<<":"<<closedge[j].adjvex<<" "<<closedge[j].lowcost<<endl;
        }
    }
    closedge[k].lowcost=0;
    for(int i=2;i<=G.vexnum;++i)
    {
        k=MIN(closedge);

        string u0,v0;
        u0=closedge[k].adjvex;
        v0=G.vexs[k];
        //cout<<"K="<< G.vexs[4]<<endl;
        cout<<"("<<u0<<","<<v0<<")"<<" ";
        closedge[k].lowcost=0;
        //cout<<"K="<< closedge[k].lowcost<<endl;
        for(int j=1;j<=G.vexnum;++j)
        {
            if(G.arcs[k][j]<closedge[j].lowcost)
                {
                    closedge[j].adjvex=G.vexs[k];
                    closedge[j].lowcost=G.arcs[k][j];
                }
        }

    }

}
int main()
{
    CreateUDN();
    shortestSpanTree_prim();
    return 0;
}
/*6 10
v1 v2 v3 v4 v5 v6
v1 v3 1
v1 v4 5
v1 v2 6
v2 v3 5
v2 v5 3
v4 v3 5
v4 v6 2
v5 v3 6
v5 v6 6
v6 v3 4*/
