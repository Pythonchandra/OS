#include<stdio.h>
#include<stdlib.h>
struct process
{
    int ID,AT,BT,CT,TAT,WT,IsCOMP;
};
void main()
{
    int n,i,j;
    float total_tt=0,total_wt=0;
    struct process P[10],temp;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time\n");
    for(int i=0;i<n;i++)
    {
        P[i].ID=i+1;
        printf("Enter the arrival time for process %d: ",P[i].ID);
        scanf("%d",&P[i].AT);
        printf("Enter the burst time for process %d: ",P[i].ID);
        scanf("%d",&P[i].BT);
        P[i].IsCOMP=0;
    }
        printf("Gantt chart\n");
        int min_bt,min_ind,ct,c;
        while(c!=n){
            min_ind=-1;
            min_bt=999;
            //printf("%d\n",ct);
            for(i=0;i<n;i++)
            {
                if(P[i].AT<=ct && P[i].IsCOMP==0)
                {
                    if(P[i].BT<min_bt || (P[i].BT==min_bt && P[i].AT<P[min_ind].AT)){
                        min_bt=P[i].BT;
                        min_ind=i;
                    }
                }
            
            }
            if(min_ind==-1){
                ct++;
                printf("| IDLE(1) %d",ct);

            }
            
            else{
                ct+=P[min_ind].BT;
                P[min_ind].CT=ct;
                P[min_ind].TAT=P[min_ind].CT-P[min_ind].AT;
                P[min_ind].WT=P[min_ind].TAT-P[min_ind].BT;
                total_wt+=P[i].WT;
                total_tt+=P[i].TAT;
                P[min_ind].IsCOMP=1;
                c++;
                printf("|P%d(%d) %d",P[min_ind].ID,P[min_ind].BT,ct);
            }
        }
        printf("\n\nId\tAT\tBT\tCT\tTAT\tWT\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
        }
        printf("Total TAT and WT is: %.3f\t %.3f\n",(total_tt/n),(total_wt/n));
    
}
