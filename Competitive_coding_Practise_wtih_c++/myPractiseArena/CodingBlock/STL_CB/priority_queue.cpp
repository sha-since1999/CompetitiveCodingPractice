#include <bits/stdc++.h>

using namespace std;
class person
{
public:
    string name;
    int age;
    person(string name, int age) : name(name), age(age)
    {
    }
};

class personCompare
{
public:
    bool operator()(const person a, const person b)
    {
        return a.age > b.age;
    }
};

int main()
{

    person p1("A", 30), p2("B", 20), p3("c", 5), p4("D", 40);

    priority_queue<person, vector<person>, personCompare> pq;

    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    pq.push(p4);

    while (!pq.empty())
    {
        person pp = pq.top();
        pq.pop();
        cout << pp.name << " " << pp.age << endl;
    }
    return 0;
}