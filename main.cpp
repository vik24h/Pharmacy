#include <cassert>
#include "UI.h"

void test_add_product() {
    repository::PharmaRepository repos = repository::PharmaRepository();
    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    assert(repos.getallProducts()[0].get_name() == "Parasinus");
    assert(repos.getallProducts()[0].get_origin() == "Italy");
    assert(repos.getallProducts()[0].get_quantity() == 50);
    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 10, 21);
    assert(repos.getallProducts()[0].get_quantity() == 60);

}

void test_remove_product() {
    repository::PharmaRepository repos = repository::PharmaRepository();
    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    repos.add_product("Xyzal", "Germany", {5, 5, 2035}, 20, 15);
    repos.remove_product("Parasinus", "Italy");
    assert(repos.getallProducts()[0].get_name() == "Xyzal");
    assert(repos.getallProducts()[0].get_origin() == "Germany");

}

void test_list_specific_products() {
    repository::PharmaRepository repos = repository::PharmaRepository();
    controller::PharmaController control = controller::PharmaController(repos);

    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    repos.add_product("Coldrex", "Romania", {7, 7, 2027}, 30, 30);
    repos.add_product("Strepsils", "Sweden", {19, 3, 2029}, 69, 33);

    vector<domain::Pharma> filtered_prod1 = {};
    filtered_prod1 = control.list_specific_products("");
    assert(filtered_prod1[0].get_name() == "Coldrex");
    assert(filtered_prod1[1].get_name() == "Parasinus");

    vector<domain::Pharma> filtered_prod2 = {};
    filtered_prod2 = control.list_specific_products("si");
    assert(filtered_prod2[0].get_name() == "Parasinus");
    assert(filtered_prod2[1].get_name() == "Strepsils");

}

void test_list_meager_quantity() {
    repository::PharmaRepository repos = repository::PharmaRepository();
    controller::PharmaController control = controller::PharmaController(repos);

    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    repos.add_product("Xyzal", "Germany", {5, 5, 2035}, 20, 15);
    repos.add_product("Zinnat", "Poland", {2, 2, 2025}, 10, 100);

    vector<domain::Pharma> filtered_prod = {};
    filtered_prod = control.list_meager_quantity(15);
    assert(filtered_prod[0].get_name() == "Zinnat");

}

void test_list_sorted() {
    repository::PharmaRepository repos = repository::PharmaRepository();
    controller::PharmaController control = controller::PharmaController(repos);

    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    repos.add_product("Xyzal", "Germany", {5, 5, 2035}, 20, 15);
    repos.add_product("Zinnat", "Poland", {2, 2, 2025}, 10, 100);

    vector<domain::Pharma> filtered_prod = {};
    filtered_prod = control.list_sorted();
    assert(filtered_prod[0].get_name() == "Zinnat");
    assert(filtered_prod[1].get_name() == "Parasinus");

}

int main() {

    test_add_product();
    test_remove_product();
    test_list_specific_products();    //Testfunktionen
    test_list_meager_quantity();
    test_list_sorted();

    repository::PharmaRepository repos = repository::PharmaRepository();
    controller::PharmaController control = controller::PharmaController(
            repos);  //Repository, Controller und UI generieren
    ui::PharmaUI UI = ui::PharmaUI(control);

    repos.add_product("Parasinus", "Italy", {10, 10, 2032}, 50, 21);
    repos.add_product("Xyzal", "Germany", {5, 5, 2035}, 20, 15);
    repos.add_product("Zinnat", "Poland", {2, 2, 2025}, 10, 100);
    repos.add_product("Coldrex", "Romania", {7, 7, 2027}, 30, 30);
    repos.add_product("Montelukast", "France", {4, 4, 2024}, 15, 15);      //10 Produkte einfugen
    repos.add_product("Robbitussin", "China", {1, 1, 2031}, 25, 44);
    repos.add_product("Dulcolax", "Spain", {4, 12, 2028}, 55, 35);
    repos.add_product("Aspenter", "India", {3, 3, 2033}, 22, 22);
    repos.add_product("Nurofen", "Serbia", {11, 11, 2026}, 88, 29);
    repos.add_product("Strepsils", "Sweden", {19, 3, 2029}, 69, 33);

    UI.menu();      //Programm (Interaktion mit dem Programm) startet nachdem alle Testfunktionen durchgefuhrt wurden und die 10 Produkte eingefugt wurden

    return 0;
}
