#include<stdio.h>
#include<stdlib.h>
struct process
{
    int AT,ID,BT,CT,TAT,WT,isCOMP,PRI;
};
void main()
{
    int n,i,j;
    struct process P[10];
    float tot_tt=0.0,tot_wt=0.0;
    printf("Enter the no of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        P[i].ID=i+1;
        printf("Enter the arrival time, burst time,priority\n");
        scanf("%d %d %d",&P[i].AT,&P[i].BT,&P[i].PRI);
        P[i].isCOMP=0;
    }
    int MIN_PRI,MIN_IND,ct=0,c=0;
    printf("Gantt chart\n");
    while(c!=n)
    {
        MIN_PRI=999;
        MIN_IND=-1;
        for(i=0;i<n;i++)
        {
            if(P[i].AT<=ct && P[i].isCOMP==0)
            {
                if(P[i].PRI<MIN_PRI || (P[i].PRI==MIN_PRI && P[i].AT<P[MIN_IND].AT))
                {
                    MIN_PRI=P[i].PRI;
                    MIN_IND=i;
                }
            }
        }
        if(MIN_IND==-1)
        {
            printf("| IDLE %d",ct);
            ct++;
        }
        else{
                ct+=P[MIN_IND].BT;
                P[MIN_IND].CT=ct;
                P[MIN_IND].TAT=P[MIN_IND].CT-P[MIN_IND].AT;
                P[MIN_IND].WT=P[MIN_IND].TAT-P[MIN_IND].BT;
                printf("| P%d(%d) %d",P[MIN_IND].ID,P[MIN_IND].BT,ct);
                tot_tt+=P[MIN_IND].TAT;
                tot_wt+=P[MIN_IND].WT;
                c++;
                P[MIN_IND].isCOMP=1;
            }
        }
    printf("\nID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].PRI,P[i].CT,P[i].TAT,P[i].WT);
    }
    printf("AVerage wt and tat is %.3f %.3f\n",tot_wt/n,tot_tt/n);
}
