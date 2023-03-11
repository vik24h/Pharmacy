//
// Created by Vik on 19/04/2022.
//

#ifndef OOP_LAB4_CONTROLLER_H
#define OOP_LAB4_CONTROLLER_H

#include "Repository.h"

namespace controller{
    class PharmaController{
    private:
        repository::PharmaRepository& reposit;

    public:   //controller beschaftigt sich mit dem Anzeigen der Liste mit bestimmten Bedingungen

        PharmaController(repository::PharmaRepository& reposit);

        //repository::PharmaRepository get_reposit();

        vector<domain::Pharma> list_specific_products(string name);

        vector<domain::Pharma> list_meager_quantity(int quantity);

        static bool compare_expiry(domain::Pharma prod1, domain::Pharma prod2);

        vector<domain::Pharma> list_sorted();

        void remove_product(string prodName, string origin);

        void add_product(string prodName, string origin, domain::date date1, int qty, float price);
    };
}

#endif //OOP_LAB4_CONTROLLER_H
