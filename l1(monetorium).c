#include<stdio.h>
#include<math.h>
#include<windows.h>

int days1(int,int,int,int,int,int);
int days(int,int,int,int,int,int);

void main()
{
    float p,newp,r,n,f,f1,i,j,k,i1,p1,bacc=0,cacc,paid,outs;
    int m,d,dd,mm,yy,tdd,tmm,tyy,n1,d1,x=0;
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

    dd=1;
    mm=3;
    yy=2020;

    if(dd<tdd&&mm<tmm&&yy<tyy || dd<tdd&&mm<tmm&&yy==tyy || dd<tdd&&mm==tmm&&yy<tyy ||
            dd<tdd&&mm==tmm&&yy==tyy || dd<tdd&&mm>tmm&&yy<tyy || dd==tdd&&mm<tmm&&yy<tyy ||
            dd==tdd&&mm<tmm&&yy==tyy || dd==tdd&&mm==tmm&&yy<tyy || dd==tdd&&mm>tmm&&yy<tyy ||
            dd>tdd&&mm<tmm&&yy<tyy || dd>tdd&&mm<tmm&&yy==tyy || dd>tdd&&mm==tmm&&yy<tyy ||
            dd>tdd&&mm>tmm&&yy<tyy)
    {
        printf("NA");
    }
    else
    {
        tyy=tyy+n;
        //printf("Maturity Date is: %02d/%02d/%04d\n",tdd,tmm,tyy);
/*
        if(dd==tdd&&mm==tmm&&yy==tyy)
        {
            d=days (tdd,dd,tmm,mm,tyy,yy);

        }
        else if(dd<tdd&&mm<tmm&&yy>tyy || dd<tdd&&mm==tmm&&yy>tyy)
        {
            dd=dd+30;
            mm=mm+11;
            yy=yy-1;
            d=days (tdd,dd,tmm,mm,tyy,yy);

        }
        else if(dd<tdd&&mm>tmm&&yy==tyy || dd<tdd&&mm>tmm&&yy>tyy)
        {
            dd=dd+30;
            mm=mm-1;
            d=days (tdd,dd,tmm,mm,tyy,yy);

        }

        else if(dd==tdd&&mm<tmm&&yy>tyy || dd>tdd&&mm<tmm&&yy>tyy)
        {
            mm=mm+12;
            yy=yy-1;
            d=days (tdd,dd,tmm,mm,tyy,yy);

        }
        else if(dd==tdd&&mm==tmm&&yy>tyy || dd==tdd&&mm>tmm&&yy==tyy || dd>tdd&&mm==tmm&&yy==tyy||
                dd>tdd&&mm==tmm&&yy>tyy || dd>tdd&&mm>tmm&&yy==tyy || dd>tdd&&mm>tmm&&yy>tyy )
        {
            d=days (tdd,dd,tmm,mm,tyy,yy);

        }
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(dd<tdd&&mm<tmm&&yy<tyy || dd<tdd&&mm<tmm&&yy==tyy || dd<tdd&&mm==tmm&&yy<tyy||
                dd<tdd&&mm==tmm&&yy==tyy || dd==tdd&&mm<tmm&&yy<tyy || dd==tdd&&mm<tmm&&yy==tyy ||
                dd==tdd&&mm==tmm&&yy<tyy)
        {
            d=days1(tdd,dd,tmm,mm,tyy,yy);

        }
        else if(dd<tdd&&mm>tmm&&yy<tyy || dd==tdd&&mm>tmm&&yy<tyy)
        {
            tyy=tyy-1;
            tmm=tmm+12;
            d=days1(tdd,dd,tmm,mm,tyy,yy);

        }

        else if(dd>tdd&&mm<tmm&&yy<tyy || dd>tdd&&mm<tmm&&yy==tyy)
        {
            tdd=tdd+30;
            tmm=tmm-1;
            d=days1(tdd,dd,tmm,mm,tyy,yy);

        }

        else if(dd>tdd&&mm==tmm&&yy<tyy || dd>tdd&&mm>tmm&&yy<tyy)
        {
            tyy=tyy-1;
            tmm=tmm+11;
            tdd=tdd+30;
            d=days1(tdd,dd,tmm,mm,tyy,yy);

        }
    }

        d1=(n*12)-d;
        printf("\n");
        printf("%d",d1);
        paid=(d1*i);
        printf("\n");
        printf("%f",paid);
        outs=(p+i1)-paid;
        printf("\n");
        printf("%f",outs);
        newp=outs+(6*i);
        printf("\n");
        printf("%f",newp);
        m=(newp/i);
        printf("\n");
        printf("%d",m);
        printf("\n");
        printf("you are given 6 months monetorium and %d installments are increased for %f rupees",m,i);

        cacc=cacc+p;
        bacc=bacc-p;
        //printf("%f",i1);
        //printf("\nYour Account is credited with = %f",p1);
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


/*int days (int dd,int tdd, int mm,int tmm,int yy,int tyy)
{
    int daydiff,monthdiff,yeardiff,d;

    daydiff=dd-tdd;
    monthdiff=mm-tmm;
    yeardiff=yy-tyy;
    d=(yeardiff*365)+(monthdiff*30)+daydiff;
    printf("\nCustomer came after %d days of maturity date",d);
    printf("\n");
    printf("\n");
    return d;
}*/
int days1(int dd,int tdd, int mm,int tmm,int yy,int tyy)
{
    int daydiff,monthdiff,yeardiff,d;

    daydiff=dd-tdd;
    monthdiff=mm-tmm;
    yeardiff=yy-tyy;
    d=(yeardiff*12)+monthdiff+(daydiff/30);
    //printf("\n%d months",d);
    //printf("\n");
    return d;
}
