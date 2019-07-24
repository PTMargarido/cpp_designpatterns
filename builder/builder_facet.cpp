#include "builder_facet.h"

using namespace std;
PersonBuilder Person::create()
{
    return PersonBuilder{};
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{person};
}

int main ()
{
    Person p = Person::create().lives().at("Rua Vale Das Neves").with_postcode("9060-325").in("Funchal").works().at("HBM").as_a("Software Engineer").earning(6);

    cout << p << endl;
    return 0;
}
