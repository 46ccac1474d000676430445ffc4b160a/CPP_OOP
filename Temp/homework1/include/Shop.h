#ifndef SHOP_H
#define SHOP_H
#include <cstring>
#include <cstdio>


class Shop
{
    private:
        char name[128];
        int number;
        double sales;
        double storage;

    public:
        Shop();
        Shop(const char*name, int number,double sales, double storage);
        ~Shop();

        const char* get_name();
        int get_number();
        double get_sales();
        double get_storage();

        void set_name(const char*name);
        void set_number(int number);
        void set_sales(double sales);
        void set_storage(double storage);

        void show();
   };

#endif // SHOP_H
