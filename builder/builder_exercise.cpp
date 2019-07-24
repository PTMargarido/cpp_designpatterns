#include <string>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

struct ClassAttr
{
    string varType, varName;
    ClassAttr(const string& varType, const string& varName) : varType(varType), varName(varName) {};
};

struct ClassCreator
{
    string className;
    vector<ClassAttr> attr;

    ClassCreator() : className() {};
    ClassCreator(const string& className) : className(className) {};
};

class CodeBuilder
{
    ClassCreator c;

    ClassCreator GetClassCreater() const
    {
        return c;
    }

    public:

    CodeBuilder(const string& class_name)  
    {
        c.className = class_name;
    }
              
    CodeBuilder& add_field(const string& name, const string& type)
    {
        ClassAttr ca{type, name};
        c.attr.emplace_back(ca);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.GetClassCreater().className << endl;
        os << "{" << endl;
        for (const auto& attr : obj.GetClassCreater().attr)
            os << " " << attr.varType << " " << attr.varName << ";" << endl;
        os << "};" << endl;

        return os;
    }

//    operator ClassCreator() const
//    {
//        return move(c);
//    }
              
};


int main ()
{
    CodeBuilder cb = CodeBuilder{"Person"}.add_field("string", "name").add_field("int", "age");
    cout << cb << endl;
    return 0;
}
