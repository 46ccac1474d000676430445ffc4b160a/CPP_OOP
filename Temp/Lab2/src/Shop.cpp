#include "Shop.h"

Shop::Shop()
{
}
Shop::~Shop()
{
    printf("I'm destructr");
}

Shop::Shop(const char*name, int number,double sales, double storage) :
    this->number(number)
{
    strcpy(this->name, name);
    this->number=number;
    this->sales=sales;
    this->storage=storage;
}

const char* Shop::get_name()
{
    return name;
}

int Shop::get_number()
{
    return number;
}

double Shop::get_sales()
{
    return sales;
}

double Shop::get_storage()
{
    return storage;
}

void Shop::set_name(const char* name)
{
    strcpy(this->name, name);
}

void Shop::set_number(int number)
{
    this->number=number;
}

void Shop::set_sales(double sales)
{
    this->sales=sales;
}

void Shop::set_storage(double storage)
{
    this->storage=storage;
}

void Shop::show()
{
    printf ("name %s,\nmunber %d\nsales %f\n,storage %f",name,number,sales,storage);
}

