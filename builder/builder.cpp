#include "builder.h"

HtmlBuilder HtmlElement::create(string root_name)
{
    return {root_name};
}

HtmlBuilder::HtmlBuilder(string root_name)
{
    root.name = root_name;
}

// Fluent Builder
HtmlBuilder& HtmlBuilder::add_child(string child_name, string child_text)
{
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
}

int main ()
{
    auto text = "hello";

    string output;

    output += "<p>";
    output += text;
    output += "</p>";
    cout << output << endl;

    string words[] = { "hello" , "world"};
    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
        oss << "   <li>" << w << "</li>";
    oss <<"</ul>";
    cout << oss.str() << endl;

    HtmlElement builder =  HtmlElement::create("").add_child("li","hello").add_child("li","world").build();
    cout << builder.str() << endl;
    
    return 0;
}
