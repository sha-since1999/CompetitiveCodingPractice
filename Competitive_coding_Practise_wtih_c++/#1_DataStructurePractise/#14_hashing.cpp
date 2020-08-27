#include <bits/stdc++.h>
using namespace std;
class Hash
{
    int index;
    int *H;

public:
    Hash(int size)
    {
        H = new int[size];
    }

    int HashKey(int);
    int lenearProb(int);
    void lenearInsert(int);
    void lenearSearch(int);

    int quadraticProb(int);
    void quadraticSearch(int);
    void quadraticInsert(int);

    void DHinsert(int);
    void DHsearch(int);
    int DHprob(int);
    int secHashKey(int);
    int DHhashKey(int, int);
};
void Hash::DHsearch(int key)
{
    int i = 0;
    while (H[DHhashKey(key, i)] != key && H[DHhashKey(key, i)])
        i++;
    if (H[DHhashKey(key, i)] == key)
        cout << "key found  :" << H[DHhashKey(key, i)] << endl;
    else
        cout << "key not found" << endl;
}
void Hash::DHinsert(int key)
{
    index = DHprob(key);
    if (!H[index])
        H[index] = key;
}
int Hash::secHashKey(int key)
{
    return (7 - (key % 7));
}
int Hash::DHhashKey(int key, int i)
{
    return HashKey(key) + i * secHashKey(key);
}
int Hash::DHprob(int key)
{
    int i = 0;
    while (H[DHhashKey(key, i)])
        i++;
    return DHhashKey(key, i);
}
int Hash::HashKey(int key)
{
    return key % 10;
}
int Hash::lenearProb(int key)
{
    int i = 0;
    index = HashKey(key);
    while (H[(index + i) % 10])
        i++;
    return (index + i) % 10;
}
void Hash::lenearInsert(int key)
{
    index = lenearProb(key);
    H[index] = key;
}
void Hash::lenearSearch(int key)
{
    index = HashKey(key);
    int i = 0;
    while (H[(index + i) % 10] != key && H[(index + i) % 10])
        i++;

    if (H[(index + i) % 10] == key)
        cout << "key found  :" << H[(index + i) % 10] << endl;
    else
        cout << "key not found" << endl;
}
int Hash::quadraticProb(int key)
{
    int i = 0;
    index = HashKey(key);
    while (H[(index + i * i) % 10])
        i++;
    return (index + i * i) % 10;
}
void Hash::quadraticInsert(int key)
{
    int i = 0;
    index = quadraticProb(key);
    H[index] = key;
}
void Hash::quadraticSearch(int key)
{
    index = HashKey(key);
    int i = 0;
    while (H[(index + i * i) % 10] != key && H[(index + i * i) % 10])
        i++;

    if (H[(index + i * i) % 10] == key)
        cout << "key found  :" << H[(index + i * i) % 10] << endl;
    else
        cout << "key not found" << endl;
}
int main()
{
    Hash hs(1000);
    // hs.lenearInsert(34);
    // hs.lenearInsert(2);
    // hs.lenearInsert(4);
    // hs.lenearInsert(12);
    // hs.lenearInsert(22);
    // hs.lenearInsert(42);
    // hs.lenearInsert(52);
    // hs.lenearInsert(31);
    // hs.lenearSearch(3);
    // hs.lenearSearch(52);

    // hs.quadraticInsert(2);
    // hs.quadraticInsert(12);
    // hs.quadraticInsert(22);
    // hs.quadraticInsert(42);
    // hs.quadraticInsert(32);
    // hs.quadraticInsert(43);
    // hs.quadraticSearch(3);
    // hs.quadraticSearch(42);
    // hs.quadraticSearch(22);
    // hs.quadraticSearch(62);

    // hs.DHinsert(22);
    // hs.DHinsert(32);
    // hs.DHinsert(32);
    // hs.DHinsert(32);
    // hs.DHinsert(12);
    // hs.DHinsert(24);
    // hs.DHinsert(12);
    // hs.DHsearch(32);
    // hs.DHsearch(22);
    // hs.DHsearch(12);
    // hs.DHsearch(13);

    return 0;
}
//every thing is okk in thisi program
// openHashing chaining method hashing is reamain to implement which is prety simple do this when you free okk sahu;