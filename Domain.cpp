//
// Created by Vik on 18/04/2022.
//

#include "Domain.h"
#include <iostream>

using namespace std;
using namespace domain;

Pharma::Pharma(string name, string origin, date expiry, int quantity, float price) {
    this->name = name;
    this->origin = origin;
    this->expiry = expiry;
    this->quantity = quantity;
    this->price = price;
}

//getters und setters
string Pharma::get_name() {
    return this->name;
}

void Pharma::set_name(string name) {
    this->name = name;
}

string Pharma::get_origin() {
    return this->origin;
}

void Pharma::set_origin(string origin) {
    this->origin = origin;
}

date Pharma::get_date() {
    return this->expiry;
}

void Pharma::set_date(date expiry) {
    this->expiry.day = expiry.day;
    this->expiry.month = expiry.month;
    this->expiry.year = expiry.year;
}

int Pharma::get_quantity() {
    return this->quantity;
}

void Pharma::set_quantity(int quantity) {
    this->quantity = quantity;
}

float Pharma::get_price() {
    return this->price;
}

void Pharma::set_price(float price) {
    this->price = price;
}

void Pharma::print_product() {
    cout << this->get_name() << " " << this->get_origin() << " " << this->get_date().day << "/"
         << this->get_date().month << "/" << this->get_date().year << " " << this->get_quantity() << " "
         << this->get_price() << endl;
}
