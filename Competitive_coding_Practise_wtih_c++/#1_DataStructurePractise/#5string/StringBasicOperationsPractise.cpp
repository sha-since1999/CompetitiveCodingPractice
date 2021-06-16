#include <bits/stdc++.h>
using namespace std;

int main()
{
    string Str1("sahu this is me");
    string Str2 = "rohit mera naam";
    Str1.replace(5, 4, "rohit"); //index form and lenth of word to be replaced and string which want to place
    Str1.insert(11, "sahu");
    Str1.insert(15, " ");
    // Str1.insert(Str1.begin(), "sa");
    // Str1.inserter(Str1.begin(),"good");
    Str1.append(Str2);
    Str1.erase(2, 8);
    // cout << Str1.empty();
    //    const char *str = str1.c_str();

    // for (auto it = Str1.cbegin(); it <= Str1.cend(); it++)
    //     cout << *it << "  ";
    // for (auto &&i : Str1)
    //     cout << i << " ";

    Str2 = Str1.substr(4, 9);
    cout << Str2 << endl;

    // cout << Str1.compare(Str2) << endl;
    // string digit;
    // cin >> digit;
    // for (auto &i : digit)
    // {
    //     if (i < 48 || i > 57)
    //         cout << "no containg charcter tooo" << endl;
    //     break;
    // }

    //     string sahu = "123312";
    //     string rohit = "1343";
    //     int data = 1232;
    //     int ram = 344;
    //     sahu = to_string(data)+to_string(ram);
    //     data = stoi(to_string(data) + to_string(ram));
    //     // intl data = stoi(sahu + rohit);
    //     cout << stoi(sahu)+1 << endl;
    //     cout << data << endl;
    //     // stringstream(sahu) >> data; ///to convert string to integer
    //     // cout << data << endl;

    return 0;
}
