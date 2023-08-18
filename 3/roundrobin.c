#include<stdio.h>
struct pro{
    int id,at,bt,ct,wt,tt,rt,isCmp,qfg;
};
int q[20],f=0,r=-1;
void insert(struct pro p[10],int k){
    r+=1;
    q[r]=k;
    p[k].qfg=1;
}
void main(){
    struct pro p[10];
    int n,i,j,avgtt=0,avgwt=0,sumbt=0,tq=0;
    printf("Enter no of process: ");
    scanf("%d",&n);
    printf("Enter AT and BT for\n");
    for(i=0;i<n;i++){
        printf("Process %d: ",(i+1));
        scanf("%d%d",&p[i].at,&p[i].bt);
        sumbt+=p[i].bt;
        p[i].rt=p[i].bt;
        p[i].id=i+1;
        p[i].isCmp=0;
        p[i].qfg=0;
    }
    printf("Enter Time Quantum\n");
    scanf("%d",&tq);
    insert(p,0);
    if(p[0].at>0) 
    {
        printf("| Idle for %d sec",p[0].at);
        sumbt+=p[0].at;
    }
    for(int tim=p[0].at;tim<sumbt;){
        i=q[f];
        f+=1;
        p[i].qfg=0;
        if(p[i].rt<=tq){
            tim+=p[i].rt;
            printf("|P%d(%d) %d",p[i].id,p[i].rt,tim);
            p[i].rt=0;
            p[i].isCmp=1;
            p[i].ct=tim;
            p[i].wt=p[i].ct-p[i].at-p[i].bt;
            p[i].tt=p[i].ct-p[i].at;
            avgwt+=p[i].wt;
            avgtt+=p[i].tt;
            for(j=0;j<n;j++){
                 if(p[j].at>tim && p[j-1].isCmp==1){
                     printf("| IDLE for %d sec",p[j].at-p[j-1].ct);
                     sumbt+=p[j].at-tim;
                     tim=p[j].at;
                     insert(p,j);
                 }
                else if(p[j].at<=tim && p[j].isCmp!=1 && p[j].qfg==0){
                    insert(p,j);
                }
            }
        }
        else{
            tim+=tq;
            p[i].rt-=tq;
            printf("|P%d(%d) %d",p[i].id,tq,tim);
            for(j=0;j<n;j++){
                if(p[j].at<=tim && p[j].isCmp!=1 && i!=j && p[j].qfg==0){
                    insert(p,j);
                }
            }
            insert(p,i);
        }
    }
    printf("\nID\tAT\tBT\tCT\tWT\tTT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tt);
    }
    printf("AvgTT; %.3f\n",((float)avgtt)/n);
    printf("AvgWT; %.3f\n",((float)avgwt)/n);
}
