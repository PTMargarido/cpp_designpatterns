#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Person
{
    Person (string name, int id) : name(name) , id(id) {}

    string name;
    int id;

    friend ostream &operator<<(ostream &os, const Person &person)
    {
        os << "person: " << person.name << " id: " << person.id;
        return os;
    }
};

class PersonFactory
{
    int personCounter{0};
    public:

        Person create_person(const string& name)
        {
            return Person{name, personCounter++};
        }
};

int main ()
{
    PersonFactory pf;

    auto p = pf.create_person("Pedro");
    cout << p << endl;
    return 0;
}
