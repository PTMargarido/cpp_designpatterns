#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum class Importance
{
    primary,
    seconday,
    tertiary
};

template <typename T, typename Key = string>
class Multiton
{
    public:
        static shared_ptr<T> get(const Key& key)
        {
            auto it = instances.find(key);
            if(it != instances.end())
            {
                return it->second;
            }

            auto instance = make_shared<T>();
            instances[key] = instance;
            return instance;
        }
    private:
        static map<Key, shared_ptr<T>> instances;
    protected:
        Multiton() = default;
        virtual ~Multiton() = default;
        Multiton(Multiton const&) = delete;
        void operator=(Multiton const&) = delete;
};

template <typename T, typename Key>
map<Key, shared_ptr<T>> Multiton<T,Key>::instances;

class Printer
{
    public:
        Printer()
        {
            ++Printer::totalInstanceCount;
            cout << " Instance count: " << Printer::totalInstanceCount << endl;
        }
    private:
        static int totalInstanceCount;
};

int Printer::totalInstanceCount = 0;

int main()
{
    typedef Multiton<Printer, Importance> mt;
    auto main = mt::get(Importance::primary);
    auto aux =  mt::get(Importance::seconday);

    auto aux1 = mt::get(Importance::seconday);
    auto aux2 = mt::get(Importance::seconday);
    auto aux3 = mt::get(Importance::seconday);
}
