#include<stdio.h>
#include<stdlib.h>
struct process
{
    int ID,AT,BT,CT,TAT,WT;
};
void main()
{
    int n,i,j,ct;
    float totat_tt=0,total_wt=0;
    struct process P[10],temp;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    //printf("Enter the arrival time and burst time\n");
    for(int i=0;i<n;i++)
    {
        P[i].ID=i+1;
        printf("Enter the arrival time for process %d: ",P[i].ID);
        scanf("%d",&P[i].AT);
        printf("Enter the burst time for process %d: ",P[i].ID);
        scanf("%d",&P[i].BT);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(P[j].AT>P[j+1].AT)
            {
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
        printf("Gantt chart\n");
        P[0].CT=P[0].AT+P[0].BT;
        ct=P[0].CT;
        printf("|P(%d)%d %d\n",P[0].ID,P[i].BT,ct);
        for(i=1;i<n;i++)
        {
            if(P[i].AT>P[i-1].CT)
            {
                printf("Idle(%d) %d\n",P[i].AT-P[i-1].CT,P[i].AT);
                ct=P[i].AT+P[i].BT;
            }
            else
                ct+=P[i].BT;
            P[i].CT=ct;
            printf("P(%d)%d %d\n",P[i].ID,P[i].BT,ct);
            
        }
        for(i=0;i<n;i++)
        {
            P[i].TAT=P[i].CT-P[i].AT;
            P[i].WT=P[i].TAT-P[i].BT;
            total_wt+=P[i].WT;
            totat_tt+=P[i].TAT;
        }
        printf("\n\nId\tAT\tBT\tCT\tTAT\tWT\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
        }
        printf("Total TAT and WT is: 3%f\t .3%f\n",totat_tt/n,total_wt/n);
    }

