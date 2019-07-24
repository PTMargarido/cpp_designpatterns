#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class HtmlBuilder;
class HtmlElement
{
    friend class HtmlBuilder;
    string name, text;
    vector<HtmlElement> elements;

    const size_t indent_size = 2;
    HtmlElement() {};

    HtmlElement(const string& name, const string& text) : name(name), text(text)  {};

    public:
    string str(int indent = 0) const 
    {
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << endl;
        if(text.size() > 0)
            oss << string(indent_size*(indent + 1), ' ') << text << endl;
    
        for (const auto& e : elements)
            oss << e.str(indent + 1);
    
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

    static HtmlBuilder create(string root_name);
};

class HtmlBuilder
{
    HtmlElement root;

    public:
    HtmlBuilder(string root_name);
   
    // Fluent Builder
    HtmlBuilder& add_child(string child_name, string child_text);

    string str() const 
    {
        return root.str();
    }

    HtmlElement build()
    { 
        return root; 
    };

   // operator HtmlElement () const
   // {
   //     return root;
   // }
};
