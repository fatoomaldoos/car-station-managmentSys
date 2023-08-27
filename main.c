#include<stdio.h>
FILE *pointer1,*pointer2,*pointer3,*pointer4,*temp1,*temp2;

struct information
{
    int car_number;
    char car_type[10];
    char car_color[10];
    char person_name[10];
    int telephone;
} x;

struct date
{
    int day,month,year;
};


struct pieces
{
    int number_II;
    char name_II[10];
    int price_II;
} P;

struct fix
{
    int operation_number;
    int car_number;
    struct date fix;
    int piecestype_amount;
    int pieces_used[100][2];
    int price_fix;
    int total_price;

} D;

typedef struct
{
    struct fix f;
    struct node*next;
} node;
typedef node* ptr;

/**ØáÈ Çæá**/
/**ÇäÔÇÁ ãáÝ ÇáÓíÇÑÇÊ æ ÇáãÇáßíä**/

/*void creart_pieces_file( )
{
    if(!(pointer4=fopen("D:\\963.bin","wb")))
    {
        printf("error");
        exit(-1);
    }
    int i;
    for(i=0; i<8; i++)
    {
        scanf("%s",&P.name_II);
        scanf("%d",&P.number_II);
        scanf("%d",&P.price_II);
        fwrite(&P,sizeof(P),1,pointer4);

    }
    fclose(pointer4);
}*/

void display_pieces_file ( )
{
    if(!(pointer4=fopen("D:\\963.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    while(fread(&P,sizeof(P),1,pointer4)!=NULL)
    {
        printf("%s\t",P.name_II);
        printf("%d\t",P.number_II);
        printf("%d\n",P.price_II);
    }
    fclose(pointer4);
}
void random_add( )
{
    struct information y;
    printf("enter the information of car you want to add\n");
    printf("enter the car number\n");
    scanf("%d",&y.car_number);
    printf("enter the car type\n");
    scanf("%s",&y.car_type);
    printf("enter the car color\n");
    scanf("%s",&y.car_color);
    printf("enter the person name\n");
    scanf("%s",&y.person_name);
    printf("enter the telephone number\n");
    scanf("%d",&y.telephone);
    pointer1=fopen("D:\\011.bin","rb");
    if(pointer1==NULL)
    {
        fclose(pointer1);
        if(!(pointer1=fopen("D:\\011.bin","ab")))
        {
            printf("error");
            exit(-1);
        }
        fwrite(&y,sizeof(y),1,pointer1);
        fclose(pointer1);
    }
    else
    {

        if(!(pointer3=fopen("D:\\088.bin","wb")))
        {
            printf("error");
            exit(-1);
        }
        int check=0;
        while(fread(&x,sizeof(x),1,pointer1)!=NULL)
        {
            if(x.car_number==y.car_number)
            {
                printf("car is previous found");
                exit(1);
            }
            if(x.car_number>y.car_number&&check==0)
            {
                fwrite(&y,sizeof(y),1,pointer3);
                fwrite(&x,sizeof(x),1,pointer3);
                check++;
            }
            else
                fwrite(&x,sizeof(x),1,pointer3);
        }
        if(check==0)
            fwrite(&y,sizeof(y),1,pointer3);
        fclose(pointer1);
        fclose(pointer3);
        if(!(pointer3=fopen("D:\\088.bin","rb")))
        {
            printf("error");
            exit(-1);
        }
        if(!(pointer1=fopen("D:\\011.bin","wb")))
        {
            printf("error");
            exit(-1);
        }
        while(fread(&y,sizeof(y),1,pointer3)!=NULL)
            fwrite(&y,sizeof(y),1,pointer1);
        fclose(pointer1);
        fclose(pointer3);
    }
}
void display_car_file(void)
{
    if(!(pointer1=fopen("D:\\011.bin","rb")))
    {
        printf("error1");
        exit(-1);
    }
    while(fread(&x,sizeof(x),1,pointer1)!=NULL)
    {
        printf("car number: %d\tcar color:%s\tcar type:%s\tperson name:%s\ttelephone:%d\n",x.car_number,x.car_color,x.car_type,x.person_name,x.telephone);

    }
    fclose(pointer1);
}
void add_operation()
{

    int j,sum=0;
    struct fix D1;
    printf("enter the car number\n");
    scanf("%d",&D.car_number);
    printf("enter the fix year\n");
    scanf("%d",&D.fix.year);
    printf("enter the fix month\n");
    scanf("%d",&D.fix.month);
    printf("enter the fix day\n");
    scanf("%d",&D.fix.day);
    printf("enter the piecestype amount\n");
    scanf("%d",&D.piecestype_amount);
    printf("enter the ID of piece the the number of this piece\n");
    for(j=0; j<D.piecestype_amount; j++)
    {
        scanf("%d",&D.pieces_used[j][0]);/*ID piece*/
        scanf("%d",&D.pieces_used[j][1]); /*number piece*/
    }
    if(!(pointer4=fopen("D:\\963.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    while(fread(&P,sizeof(P),1,pointer4)!=NULL)
    {
        if(P.number_II==D.pieces_used[j][0])
            sum=sum+P.price_II*D.pieces_used[j][1];
    }
    fclose(pointer4);
    printf("enter price fix");
    scanf("%d",&D.price_fix);
    D.total_price=sum+D.price_fix;
    pointer2=fopen("D:\\022.bin","rb");
    if(pointer2==NULL)
    {
        fclose(pointer2);
        if(!(pointer2=fopen("D:\\022.bin","ab")))
        {
            printf("error");
            exit(-1);
        }
        D.operation_number=1;
        fwrite(&D,sizeof(D),1,pointer2);
        fclose(pointer2);
    }
    else
    {
        while(fread(&D1,sizeof(D1),1,pointer2)!=NULL);
        fclose(pointer2);
        if(!(pointer2=fopen("D:\\022.bin","ab")))
        {
            printf("error");
            exit(-1);
        }
        D.operation_number=D1.operation_number+1;
        fwrite(&D,sizeof(D),1,pointer2);
        fclose(pointer2);
    }

}
void display_add_operation( )
{
    int j;
    if(!(pointer2=fopen("D:\\022.bin","rb")))
    {
        printf("error");
        exit(-1);
    }

    while(fread(&D,sizeof(D),1,pointer2)!=NULL)
    {
        printf("%d\t%d\t",D.operation_number,D.car_number);
        printf("%d\t",D.fix.year);
        printf("%d\t",D.fix.month);
        printf("%d\t",D.fix.day);
        printf("%d\t",D.piecestype_amount);
        //****************************************************************************
   /*     for(j=0; j<D.piecestype_amount; j++)
        {
            printf("%d\t",D.pieces_used[j][0]);
            printf("%d\t",D.pieces_used[j][1]);
        }*/
        //*************************************************************************
        printf("%d\t",D.price_fix);
        printf("%d\n",D.total_price);
    }
    fclose(pointer2);


}
void Delete_car_and_fix ( )
{
    int i=1;
    if(!(pointer1=fopen("D:\\011.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    if(!(pointer2=fopen("D:\\022.bin","rb")))
    {
        printf("error");
        exit(-1);
    }

    if(!(temp1=fopen("D://055.bin","wb")))
    {
        printf("error");
        exit(-1);
    }
    if(!(temp2=fopen("D:\\066","wb")))
    {
        printf("error");
        exit(-1);
    }
    int delet_number;
    printf("enter the number car you want to delete it");
    scanf("%d",&delet_number);
    while((fread(&x,sizeof(x),1,pointer1)!=NULL))
    {
        if(delet_number!=x.car_number)
            fwrite(&x,sizeof(x),1,temp1);
    }
    while((fread(&D,sizeof(D),1,pointer2)!=NULL))
    {
        if(delet_number!=D.car_number)
        {
            D.operation_number=i;
            i++;
            fwrite(&D,sizeof(D),1,temp2);
        }
    }//////////////////
    fclose(temp2);
    fclose(temp1);
    fclose(pointer1);
    fclose(pointer2);
    if(!(pointer1=fopen("D:\\011.bin","wb")))
    {
        printf("error");
        exit(-1);
    }
    if(!(pointer2=fopen("D:\\022.bin","wb")))
    {
        printf("error");
        exit(-1);
    }

    if(!(temp1=fopen("D://055.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    if(!(temp2=fopen("D:\\066","rb")))
    {
        printf("error");
        exit(-1);
    }
    while((fread(&x,sizeof(x),1,temp1)!=NULL))
        fwrite(&x,sizeof(x),1,pointer1);
    while((fread(&D,sizeof(D),1,temp2)!=NULL))
        fwrite(&D,sizeof(D),1,pointer2);
    fclose(pointer2);
    fclose(pointer1);
    fclose(pointer1);
    fclose(pointer2);
}
void search ( )
{
    char search_name[10];
    scanf("%s",&search_name);
    int counter=0;
    if(!(pointer1=fopen("D:\\011.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    while(fread(&x,sizeof(x),1,pointer1)!=NULL)
    {
        if(strcmp(search_name,x.person_name)==0)
        {
            printf("%d\t",x.car_number);
            counter++;
        }
    }
    if(counter==0)
        printf("name not found\n");
    else
        printf("\n");
}

void display_after_date( )
{
    int enter_day,enter_month,enter_year,v,id[100],n=0,i;
mm:
    printf("enter year\n");
    scanf("%d",&enter_year);
    if(enter_year<=0)
    {
        printf("error");
        goto mm;
    }
hh:
    printf("enter month\n");
    scanf("%d",&enter_month);
    if(enter_month<=0 || enter_month>12 )
    {
        printf("error");
        goto hh;
    }
dd:
    printf("enter day\n");
    scanf("%d",&enter_day);
    for(enter_month=1; enter_month<=11; enter_month+=2)
        if(enter_day<1 || enter_day>31)
        {
            printf("error");
            goto dd;
        }
    for(enter_month=4; enter_month<=12; enter_month+=2)
        if(enter_day <1 || enter_day >30)
        {
            printf("error");
            goto dd;
        }
    if (enter_month==2)
    {
        if(enter_day<1 || enter_day>28)
        {
            printf("error");
            goto dd;
        }
    }
    if(!(pointer2=fopen("D:\\022.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    while(fread(&D,sizeof(D),1,pointer2)!=NULL)
    {
        v=0;
        if (enter_year<D.fix.year)
        {
            v=1;
        }
        else if (enter_year==D.fix.year&&enter_month<D.fix.month)
        {
            v=1;
        }
        else if(enter_month==D.fix.month&&enter_day<D.fix.day)
        {
            v=1;
        }
        if(v==1)
        {
            for(i=0; i<n; i++)
                if(id[i]==D.car_number)
                    break;
            if(i==n)
            {
                id[n]=D.car_number;
                n++;
            }
        }
    }
    if(n==0)
        printf("car not found\n");
    else
    {
        for(i=0; i<n; i++)
        {
            // printf("%d\n",i);
            if(!(pointer1=fopen("D:\\011.bin","rb")))
            {
                printf("error");
                exit(-1);
            }
            while(fread(&x,sizeof(x),1,pointer1)!=NULL)
            {
                if(x.car_number==id[i])
                    printf("%s\t",x.car_type);
            }
            fclose(pointer1);
        }
        printf("\n");
    }
}
void frequent_file( )
{
    int j;
    if(!(pointer2=fopen("D:\\022.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    int frequent[8]= {0};

    while(fread(&D,sizeof(D),1,pointer2)!=NULL)
    {
        for(j=0; j<D.piecestype_amount; j++)
        {
            if(D.pieces_used[j][0]==1)
                frequent[0]++;
            if(D.pieces_used[j][0]==2)
                frequent[1]++;
            if(D.pieces_used[j][0]==3)
                frequent[2]++;
            if(D.pieces_used[j][0]==4)
                frequent[3]++;
            if(D.pieces_used[j][0]==5)
                frequent[4]++;
            if(D.pieces_used[j][0]==6)
                frequent[5]++;
            if(D.pieces_used[j][0]==7)
                frequent[6]++;
            if(D.pieces_used[j][0]==8)
                frequent[7]++;
        }
    }
    int max=0,i;
    for(i=0; i<8; i++)
    {
        if(frequent[i]>max)
            max=frequent[i];
    }
    for(i=0; i<8; i++)
    {
        if(frequent[i]==max)
            printf("%d\t|",i+1);

    }
    printf("\n");
}
void insert(ptr*phead,struct fix op)
{
    ptr temp,curr,prev;
    temp=malloc(sizeof(node));
    temp->f=op;
    temp->next=NULL;

    if(*phead==NULL)
        *phead=temp;
    else if(temp->f.car_number<(*phead)->f.car_number)
    {
        temp->next=*phead;
        *phead=temp;
    }
    else
    {
        curr=*phead;
        prev=NULL;
        while(curr!=NULL && temp->f.car_number >= curr->f.car_number)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=temp;
        temp->next=curr;
    }
}
void display_list_fix(ptr head)
{
    int i;
    if(head!=NULL)
    {
        while(head!=NULL)
        {
            printf("number of car=%d\n",head->f.car_number);
            printf("number of fix=%d\n",head->f.operation_number);
            printf("date=%d/",head->f.fix.day);
            printf("%d/",head->f.fix.month);
            printf("%d\n",head->f.fix.year);
            printf("cost of fix=%d\n",head->f.price_fix);
            printf("total fix=%d\n",head->f.total_price);
            printf("number of tool=%d\n",head->f.piecestype_amount);
            for(i=0; i<head->f.piecestype_amount; i++)
            {
                printf("id of tool (%d)=%d\t",i+1,head->f.pieces_used[i][0]);
                printf("count of tool (%d)=%d\n",i+1,head->f.pieces_used[i][1]);
            }
            printf("---------------------------------------------\n");
            head=head->next;
        }
        printf("\n");
    }
    else
        printf("the list is empty\n");
}
void display_type_car()
{
    int id[100],n_id=0,j,i;

    if(!(pointer2=fopen("D:\\022.bin","rb")))
    {
        printf("error");
        exit(-1);
    }
    while(fread(&D,sizeof(D),1,pointer2)!=NULL)
        for(j=0; j<D.piecestype_amount; j++)
            if(D.pieces_used[j][0]==1)
            {
                for(i=0; i<n_id; i++)
                    if(id[i]==D.car_number)
                        break;
                if(i==n_id)
                {
                    id[i]=D.car_number;
                    n_id++;
                }


            }
    fclose(pointer2);
    if(n_id!=0)
    {
        printf("type of car  that change wheel:\n");
        for(i=0; i<n_id; i++)
        {
            if(!(pointer1=fopen("D:\\011.bin","rb")))
            {
                printf("error");
                exit(-1);
            }
            while(fread(&x,sizeof(x),1,pointer1)!=NULL)
                if(id[i]==x.car_number)
                    printf("%s\t",x.car_type);
            fclose(pointer1);
        }
        printf("\n");
    }
    else
        printf("no car change wheel/n");
}
int main()
{
    int choice;

    ptr*list_star=NULL;
    struct fix f;
    while(!0)
    {
        printf("enter\n 1 :to add car\n 2 :to display car file\n 3 :to delete file\n 4 :to creat pices file\n 5 :to display pieces file\n ");
        printf("6:to add new operation\n 7:to display this new operation\n 8: to delete car information\n");
        printf("9:to delete operation file\n10:to search car's owner\n");
        printf("11:to display car fixed after date\n12:to display tools more used\n");
        printf("13:type of car change wheel\n14:tidy by linked list\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            random_add( );
            break;
        case 2 :
            display_car_file( );
            break;
        case 3:
            remove("D:\\011.bin");
            break;
        /*case 4:
            creart_pieces_file();
            break;*/

        case 5 :
            display_pieces_file ( );
            break;
        case 6 :
            add_operation();
            break;
        case 7 :
            display_add_operation();
            break;
        case 8 :
            Delete_car_and_fix ();
            break;
        case 9:
            remove("D:\\022.bin");
            break;
        case 10 :
            search();
            break;
        case 11 :
            display_after_date( );
            break;
        case 12 :
            frequent_file( );
            break;
        case 13:
            display_type_car();
            break;
        case 14:

            if(!(pointer2=fopen("D:\\022.bin","rb")))
            {
                printf("error");
                exit(-1);
            }

            while(fread(&f,sizeof(D),1,pointer2)!=NULL)
            {
                insert(&list_star,f);
            }
            fclose(pointer2);
            break;
            case 15:
            display_list_fix(list_star);
            break;
        default:
            return 0;
        }
    }
}
