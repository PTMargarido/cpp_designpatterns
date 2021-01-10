#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum class TextType
{
    html,
    markdown
};

struct TextStrategy
{
    virtual void start(ostringstream& os) {}
    virtual void end(ostringstream& os) {}
    virtual void content(ostringstream& os, const string& item) = 0;
};

struct MarkdownTextProcess : TextStrategy
{
    virtual void content(ostringstream& os, const string& item) override
    {
        os << "*" << item << "\n";
    }
};

struct HtmlTextProcess : TextStrategy
{
    virtual void start(ostringstream& os) override
    {
        os << "<ul>\n";
    }
    virtual void end(ostringstream& os) override
    {
        os << "</ul>\n";
    }
    virtual void content(ostringstream& os, const string& item) override
    {
        os << "   <il>" << item << "</il>\n";
    }
};

struct TextProcess
{
    void setStrategy(const TextType& type)
    {
        switch(type)
        {
            case TextType::html:
            {
                strat = make_unique<HtmlTextProcess>();
                break;
            }
            case TextType::markdown:
            {
                strat = make_unique<MarkdownTextProcess>();
                break;
            }
        }
    }

    void executeStrategy(const vector<string>&& items)
    {
        strat->start(os);
        for (const auto& item: items)
            strat->content(os, item);
        strat->end(os);
    }

    ostringstream os;
    unique_ptr<TextStrategy> strat;
};

int main()
{
    TextProcess textP;
    textP.setStrategy(TextType::html);
    textP.executeStrategy(vector<string>{"foo", "bar", "baz"});
    cout << textP.os.str() << endl;
}
