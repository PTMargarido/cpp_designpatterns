#include <functional>
#include <string>
#include <map>
#include <iostream>
#include <memory>
using namespace std;

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare (int volume) = 0;
};


struct Tea : HotDrink
{
    void prepare (int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml \n";
    }
};

struct Coffee : HotDrink
{
    void prepare (int volume) override
    {
        cout << "Grind some beans, boil water, pour " << volume << "ml \n";
    }
};

struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Coffee>();
    }
};

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
    public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }
    
    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }

};

class DrinkWithVolumeFactory
{
    map<string, function<unique_ptr<HotDrink>()>> factories;
    public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = []
        {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        return factories[name]();
    }
};

unique_ptr<HotDrink> make_drink(string type)
{
    unique_ptr<HotDrink> drink;
    if (type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(100);
    }
    else
    {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

int main ()
{
    auto d = make_drink("tea");

    DrinkFactory df;

    auto c = df.make_drink("coffee");

    DrinkWithVolumeFactory dfv;
    auto t = df.make_drink("tea");
    return 0;
}
