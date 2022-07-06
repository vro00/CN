#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r;
struct frame
{
    char ack;
    int data;
}frm[10];
int sender(void);
void recack(void);
void resend(void);
void resend1(void);
void goback(void);
void selective(void);
int main()
{
    int c;
    do{
        printf("\n 1.Selective repeat ARQ \n 2.Go back N ARQ \n 3.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:selective();
            break;
            case 2:goback();
            break;
            case 3:exit(0);
            break;
        }
    }while(c>=4);
}
void selective()
{
    sender();
    recack();
    resend();
    printf("\n All packets sent successfully");
}
void goback()
{
    sender();
    recack();
    resend1();
    printf("\n All packets snet successfully");
}
int sender()
{
    int i;
    printf("\n Enter no. of packets: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("\n Enter data for packet %d : ", i);
        scanf("%d", &frm[i].data);
        frm[i].ack = 'y';
    }return 0;
}
void recack()
{
    int i;
    rand();
    r = rand()%n;
    frm[r].ack = 'n';
    for(i=1; i<=n; i++){
        if(frm[i].ack == 'n')
        printf("\n The packet no. %d is not received ", r);
    }
}
//SELECTIVE REPEAT
void resend()
{
    printf("\n resending packet %d", r);
    sleep(2);
    frm[r].ack = 'y';
    printf("\n The received packet is %d", frm[r].data);
}
//GO BACK N
void resend1()
{
    int i;
    printf("\n resending from packet %d", r);
    for(i=r; i<=n; i++){
        sleep(2);
        frm[i].ack = 'y';
        printf("\n Received data of packet %d is %d ", i, frm[i].data);
    }
}