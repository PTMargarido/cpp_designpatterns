#include <memory>
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

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string& name, int suite)
    {
        static Contact p{"", new Address{"Rua Vasconcelos Pais", "Porto", 123}};
        return NewEmployee(name, suite, p);

    }
    private:
        static unique_ptr<Contact> NewEmployee(const string& name, int suite, const Contact &prototype)
        {
            auto result = make_unique<Contact>(prototype);
            result->name = name;
            result->address->suite = suite;
            return result;
        }
};

int main()
{
    auto person = EmployeeFactory::new_main_office_employee("Pedro", 134);
    cout << *person << endl; 
                    
    return 0;
}
