#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person
{
    string street_address, post_code, city;

    string company_name, position;

    int annual_income{0};
    public: 
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
    friend ostream& operator<<(ostream& os, const Person &person)
    {
        os << person.street_address << " " << person.post_code << " " << person.city << " " <<
            person.company_name << " " << person.position << " " << person.annual_income << endl;
        return os;
    }

};

class PersonBuilderBase
{
    protected:
    Person& person;

    PersonBuilderBase(Person &person) : person(person) {};

    public:

    operator Person() const
    {
         return move(person);
    }

    PersonJobBuilder works() const;
    PersonAddressBuilder lives() const;
};

class PersonBuilder : public PersonBuilderBase
{
    private:
    Person p;

    public:
    PersonBuilder() : PersonBuilderBase(p)  {};

    Person build()
    {
        return p;
    }

    public:

};

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder Self;

    public:
        PersonAddressBuilder(Person &person) : PersonBuilderBase(person) {};

        Self& at(std::string street_address)
        {
            person.street_address = street_address;
            return *this;
        }

        Self& with_postcode(std::string post_code)
        {
            person.post_code = post_code;
            return *this;
        }

        Self& in(std::string city)
        {
            person.city = city;
            return *this;
        }
};


class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;

    public:
        PersonJobBuilder(Person &person) : PersonBuilderBase(person) {};

        Self& at(std::string company_name)
        {
            person.company_name = company_name;
            return *this;
        }

        Self& as_a(std::string position)
        {
            person.position = position;
            return *this;
        }

        Self& earning(int annual_income)
        {
            person.annual_income = annual_income;
            return *this;
        }
};

