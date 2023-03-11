//
// Created by Vik on 18/04/2022.
//

#include "Repository.h"

using namespace repository;

PharmaRepository::PharmaRepository() {
    this->products={};
}

vector<domain::Pharma> PharmaRepository::getallProducts() {
    return this->products;
}

void PharmaRepository::add_product(string name, string origin, domain::date expiry, int quantity, float price) {
    if(quantity<=0)
        throw exception();

    bool found = false;
    for(domain::Pharma &product: this->products){
        if(product.get_name()==name && product.get_origin()==origin) {
            product.set_quantity(product.get_quantity() + quantity);   //falls produkt existiert wird die Menge aktualisiert
            found = true;
            break;
        }
    }
    if(!found)
        this->products.emplace_back(domain::Pharma(name,origin,expiry,quantity,price));  //falls produkt noch nicht existiert
}

void PharmaRepository::remove_product(string name, string origin) {
    remove_if(this->products.begin(), this->products.end(),[name,origin](domain::Pharma product){return product.get_name()==name && product.get_origin()==origin;});
}