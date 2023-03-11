//
// Created by Vik on 19/04/2022.
//

#include "Controller.h"

using namespace controller;

PharmaController::PharmaController(repository::PharmaRepository &reposit) : reposit(reposit) {}

/*
repository::PharmaRepository controller::PharmaController::get_reposit() {
    return this->reposit;
}
*/

vector<domain::Pharma> PharmaController::list_specific_products(string name) {
    vector<domain::Pharma> filtered_prod = {};
    if (name.empty()) {
        for (domain::Pharma product: this->reposit.getallProducts())   //wenn kein Name eingegeben wird
            filtered_prod.emplace_back(product);
    } else {
        for (domain::Pharma product: this->reposit.getallProducts()) {
            if (product.get_name().find(name) != std::string::npos)
                filtered_prod.emplace_back(product);
        }

    }
    std::sort(filtered_prod.begin(), filtered_prod.end(),
              [](domain::Pharma &prod1, domain::Pharma &prod2) { return prod1.get_name() < prod2.get_name(); });
    return filtered_prod;
}

vector<domain::Pharma> PharmaController::list_meager_quantity(int quantity) {
    vector<domain::Pharma> filtered_prod = {};

    for (domain::Pharma product: this->reposit.getallProducts()) {  //nach der Menge sortiert
        if (product.get_quantity() < quantity) {
            filtered_prod.emplace_back(product);
        }
    }
    return filtered_prod;
}

bool PharmaController::compare_expiry(domain::Pharma prod1, domain::Pharma prod2) {
    if (prod1.get_date().year < prod2.get_date().year)
        return true;
    else if (prod1.get_date().year == prod2.get_date().year && prod1.get_date().month < prod2.get_date().month)
        return true;
    else if (prod1.get_date().year == prod2.get_date().year && prod1.get_date().month == prod2.get_date().month &&
             prod1.get_date().day <= prod2.get_date().day)
        return true;
    return false;
}

vector<domain::Pharma> PharmaController::list_sorted() {
    vector<domain::Pharma> filtered_prod = {};
    for (domain::Pharma product: this->reposit.getallProducts())  //sortiert nach Datum
        filtered_prod.emplace_back(product);

    std::sort(filtered_prod.begin(), filtered_prod.end(), controller::PharmaController::compare_expiry);
    return filtered_prod;
}

void PharmaController::remove_product(string prodName, string origin) {
    reposit.remove_product(prodName, origin);
}

void PharmaController::add_product(string prodName, string origin, domain::date date1, int qty, float price) {
    reposit.add_product(prodName, origin, date1, qty, price);

}

