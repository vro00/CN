#include<bits/stdc++.h>
using namespace std;
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
        cout << "\n 1. Selective Repeat ARQ\n 2. Go BackN ARQ\n 3. Exit";
        cout << "\n Enter your choice: ";
        cin >> c;
        switch(c)
        {
            case 1: selective();
            break;
            case 2: goback();
            break;
            case 3: exit(0);
            break;
        }
    }while(c>=4);
}
void goback()
{
    sender();
    recack();
    resend();
    cout << "\n All packets sent successfully\n";
}
void selective()
{
    sender();
    recack();
    resend();
    cout << "\n All packets sent successfully\n";
}
int sender()
{
    int i;
    cout << "\n Enter no. of packets: ";
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cout << "\n Enter data for packets " << i << ": ";
        cin >> frm[i].data;
        frm[i].ack = 'y';
    }return 0;
}
void recack()
{
    int i;
    rand();
    r = rand()%n;
    frm[r].ack = 'n';
    for(i=1; i<=n; i++)
    {
        if(frm[i].ack == 'n')
        cout << "\n The packet no. "<< r << " is not received";
    }
}
// Selective Repeat
void resend()
{
    cout << "\n Resending Packet " << r;
    int sleep(2);
    frm[r].ack = 'y';
    cout << "\n The received packet is " << frm[r].data;
}
// Go Back N
void resend1()
{
    int i;
    cout << "\n Resending from packet " << r;
    for(i=r; i<=n; i++)
    {
        int sleep(2);
        frm[i].ack = 'y';
        cout << "\n Received data of packet " << i << " is " << frm[i].data;
    }
} 