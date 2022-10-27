#include<stdio.h>
#include<math.h>
#include<windows.h>

void main()
{
    float p,r,n,f,f1,i,j,k,i1,p1,bacc=0,cacc;
    int tdd,tmm,tyy,n1,x=0;
    char choice;

    printf("\nEnter date of loan disbursement (dd/mm/yy) format: ");
    scanf("%d/%d/%d",&tdd,&tmm,&tyy);

    printf("\nEnter Requirement of Money\n");
    scanf("%f",&p);
    p1=p;
    printf("Enter Rate of Interest\n");
    scanf("%f",&r);
    printf("Enter time Duration in years\n");
    scanf("%f",&n);
    printf("Enter A for EMI type \nEnter B for Reducing Type\n");
    printf("Enter Your Choice\n");
    scanf("\n%c",&choice);
    n1=n*12;


    switch(choice)
    {

    case 'A':

        r=r/(12*100);
        i=(p*r*pow(1+r,n1))/(pow(1+r,n1)-1);
        printf("\nNumber of installments = %d\n",n1);
        printf("Installment = %f\n",i);
        i1=(i*n1)-p;
        cacc=cacc+p;
        bacc=bacc-p;
        printf("\nYour Account is credited with = %f",p1);
        break;

    case 'B':

        f=p/n1;
        printf("\nNumber of installments = %d\n",n1);
        if(tdd>=1&&tdd<=15)
        {
            tdd=1;

        }
        else if(tdd>=15 && tdd<=31)
        {
            tdd=1;
            tmm=tmm+1;
        }


            for(j=0; j<n1; j++)
            {
                i=((p*r*n)/100)/n1;
                f1=f+i;
                tmm=tmm+1;
                x=x+1;
                if(tmm>12)
                {
                    tmm=tmm-12;
                    tyy=tyy+1;
                }

                if(tmm==2 && (tyy%4)==0 && tdd==29)
                {
                    tmm=tmm+1;
                    tdd=tdd-28;
                }
                else if(tmm==2 && tdd==29)
                {
                    tdd=tdd-1;
                }
                printf("%d Installment on => ",x);
                printf("Date %d/%d/%d =>",tdd,tmm,tyy);
                printf("%f\n",f1);
                p=p-f;
            }

        cacc=cacc+p;
        bacc=bacc-p;

        printf("\nYour Account is credited with = %f",p1);
        break;

    default :

        printf("Enter Valid Choice");
        break;
    }
}
