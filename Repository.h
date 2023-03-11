//
// Created by Vik on 18/04/2022.
//

#ifndef OOP_LAB4_REPOSITORY_H
#define OOP_LAB4_REPOSITORY_H

#include "Domain.h"
#include <vector>

namespace repository{
    class PharmaRepository{
    private:

        vector<domain::Pharma> products;

    public:    //repository beschaftigt sich mit der Speicherverwaltung

        PharmaRepository();

        vector<domain::Pharma> getallProducts();

        void add_product(string name, string origin, domain::date expiry, int quantity, float price);

        void remove_product(string name, string origin);

    };
}

#endif //OOP_LAB4_REPOSITORY_H
