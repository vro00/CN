#include<stdio.h>
#include<conio.h>
void main()
{
    int data[7], rec[7], i, c1, c2, c3, c;
    printf("enter 4-bit message: ");
    scanf("%d%d%d%d", &data[2], &data[4], &data[5], &data[6]);
    data[0] = data[2]^data[4]^data[6];
    data[1] = data[2]^data[5]^data[6];
    data[3] = data[4]^data[5]^data[6];
    printf("\nencoded bits are: \n");
    for(i=0; i<7; i++){
        printf("%d", data[i]);
    }
    printf("\nenter received data bits: \n");
    for(i=0; i<7; i++){
        scanf("%d", &rec[i]);
    }
    c1 = rec[0]^rec[2]^rec[4]^rec[6];
    c2 = rec[1]^rec[2]^rec[5]^rec[6];
    c3 = rec[3]^rec[4]^rec[5]^rec[6];
    c = c3*4 + c2*2 + c1;

    if(c==0){
        printf("\n no error: ");
    }
    else{
        printf("\n error on the position: %d \n correct message is \n", c);
        if(rec[c-1] == 0){
            rec[c-1] = 1;
        }
        else{
            rec[c-1] = 0;
        }
        for(i=0; i<7; i++){
            printf("%d", rec[i]);
        }
    }getch();      
}