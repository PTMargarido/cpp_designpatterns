#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class SingletonDatabase
{
    SingletonDatabase()
    {
       cout << "Initiliazing the database \n";
       ifstream ifs("cities.txt");
       string s, s2;

       while (getline(ifs,s))
       {
        getline(ifs,s2);
        int pop = stoi(s2);
        capitals[s] = pop;
       }
    }
    map <string, int> capitals;
    public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;
    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }
    int get_population(const string& name)
    {
        return capitals[name];
    }
};

struct SingletonRecorderFinder
{
    int total_population(vector<string> names)
    {
        int result{0};
        for (auto& name : names)
            result += SingletonDatabase::get().get_population(name);
        return result;
    }

};

int main()
{
    string city{"Tokyo"}; 
    auto pop = SingletonDatabase::get().get_population(city);
    cout << city << " has " << pop << endl; 
}
