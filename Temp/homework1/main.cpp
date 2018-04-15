#include <iostream>
#include "Shop.h"
#include<stdio.h>

int Find(Shop *arr,int lenght,char *str)
{
    for(int i=0; i<lenght; i++)
    {
        if(strcmp(arr[i].get_name(),str)==0)
            return i;
    }
    return -1;
}

void Find(Shop *arr,int lenght,int number)
{
    for(int i=0;i<lenght;i++){
            if(arr[i].get_number()<number)
                arr[i].show();
        }
}


using namespace std;

int main()
{
    //setlocale(0,"");



    Shop a("Narodnii",1,75,90);
    Shop b("Globus",2,250,300.5);
    Shop c("Frunze",3,230,255);
    Shop e("Neman",4,150,180.54);
    a.show();
    b.show();
    c.show();
    e.show();

    Shop shop[4]= {Shop("Narodnii",1,75,90),Shop ("Globus",2,250,300.5),Shop("Frunze",3,230,255),Shop("Neman",4,150,180.54)};
    int a1=0;
    int b1=0;

    for (int i=0; i<4; i++)
    {
        if (shop[i].get_sales()>shop[a1].get_sales())
            a1=i;
        if (shop[i].get_sales()<shop[b1].get_sales())
            b1=i;
    }

    cout<<"������� �������� �������";
    shop[a1].show();
    cout<<"��������� �������� �������:";
    shop[b1].show();

    char ptr[20];
    cout<<"������� �������� ��������, ������� �����:"<<endl;
    cin>>ptr;
    int k=Find(shop,4,ptr);
    if(k<0)
        cout<<"����� ������� ���"<<endl;
    else shop[k].show();


    cout<<"����� �������� ���� 3-�:"<<endl;
        Find(shop,4,3);
    return 0;
}
