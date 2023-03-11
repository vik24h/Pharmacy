//
// Created by Vik on 18/04/2022.
//

#include "UI.h"
#include <iostream>

using namespace std;
using namespace ui;

PharmaUI::PharmaUI(controller::PharmaController &control) : control(control) {}

controller::PharmaController PharmaUI::get_control() {
    return this->control;
}

void PharmaUI::menu() {
    cout << endl;
    cout << "     ***___ Apotheken App ___***" << endl;
    cout << "               *Menu*" << endl;
    cout << "      1.Add product" << endl;
    cout << "      2.Delete product" << endl;
    cout << "      3.List specific products" << endl;
    cout << "      4.List meager quantity" << endl;
    cout << "      5.List expiry date growing" << endl;
    cout << "      0 -> Exit" << endl;
    cout << endl;
    cout << "      Option: " << endl;

    int input;
    cin >> input;

    vector<domain::Pharma> filtered_products;
    string name, origin;
    domain::date expiry;
    int quantity;
    float price;

    switch (input) {

        case 1:
            cout << "Give input name: " << endl;
            cin >> name;
            cout << "Give input origin: " << endl;
            cin >> origin;
            cout << "Give input expiry (format: day/month/year): " << endl;
            cin >> expiry.day;
            cin >> expiry.month;
            cin >> expiry.year;
            cout << "Give input quantity: " << endl;
            cin >> quantity;
            cout << "Give input price: " << endl;
            cin >> price;
            this->control.add_product(name, origin, expiry, quantity, price);
            menu();

        case 2:
            cout << "Give input name: " << endl;
            cin >> name;
            cout << "Give input origin: " << endl;
            cin >> origin;
            this->control.remove_product(name, origin);
            menu();

        case 3:
            cout << "Give specific string (type *all* if there is no specific string): " << endl;
            cin >> name;
            if (name == "all" || name == "*all*")
                name = "";
            filtered_products = this->control.list_specific_products(name);
            for (domain::Pharma product: filtered_products)
                product.print_product();
            cout << endl;
            menu();

        case 4:
            cout << "Give input quantity: " << endl;
            cin >> quantity;
            filtered_products = this->control.list_meager_quantity(quantity);
            for (domain::Pharma product: filtered_products)
                product.print_product();
            cout << endl;
            menu();

        case 5:
            filtered_products = this->control.list_sorted();
            for (domain::Pharma product: filtered_products)
                product.print_product();
            cout << endl;
            menu();

        default:
            exit(0);

    }
}

