#include <iostream>
#include <string>
using namespace std;
struct Address
{
    string street, city;
    int suite;

    Address(const string& street, const string& city, int suite) : street(street) , city(city) , suite(suite) {}

    Address(const Address& other) : street{other.street} ,
        city{other.city}, suite{other.suite} {}

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact
{
    string name;
    Address* address;
    
    Contact(const string& name, Address* address) : name(name) , address(address) {}
    Contact(const Contact& other) : name{other.name} , address { new Address {*other.address}} {}
    ~Contact() { delete address; }

    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "name: " << contact.name << " Address: " << *contact.address;
        return os;
    }
};

int main()
{
    Contact pedro{"Pedro" , new Address{"Rua Vale das Neves n53", "Funchal", 9060}};
    Contact ines{pedro};

    ines.name = "Ines";
    ines.address->suite = 123;

    cout << pedro << endl;
    cout << ines << endl;
    return 0;
}
