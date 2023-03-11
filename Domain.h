//
// Created by Vik on 18/04/2022.
//

#ifndef OOP_LAB4_DOMAIN_H
#define OOP_LAB4_DOMAIN_H

#include <string>

using namespace std;

namespace domain {

    struct date {
        int day;
        int month;
        int year;
    };

    class Pharma {
    private:
        string name;
        string origin;
        date expiry;
        int quantity;
        float price;

    public:

        Pharma(string name, string origin, date expiry, int quantity, float price);

        string get_name();

        void set_name(string name);

        string get_origin();

        void set_origin(string origin);

        date get_date();

        void set_date(date expiry);

        int get_quantity();

        void set_quantity(int quantity);

        float get_price();

        void set_price(float price);

        void print_product();
    };
}
#endif //OOP_LAB4_DOMAIN_H
