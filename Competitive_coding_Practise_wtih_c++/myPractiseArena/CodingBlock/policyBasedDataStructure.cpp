#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;
int main()
{

    PBDS st;
    st.insert(3);
    st.insert(32);
    st.insert(4);
    st.insert(23);
    for (int i = 0; i < st.size(); i++)
        cout << i << " " << *st.find_by_order(i) << endl; //actually this return value at index in set.
    cout << st.order_of_key(6) << endl;                   //understand this  like if this value is available in set then at what index it will be.
    cout << "<<<-------next Concept From here------->>>>" << endl;
    // you can insert a multiple value in set using a concept of index;
    typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDSP;
    PBDSP stp;
    stp.insert({1, 0});
    stp.insert({2, 1});
    stp.insert({32, 2});
    stp.insert({5, 3});
    stp.insert({56, 4});
    stp.insert({2, 5});
    stp.insert({56, 6});

    // for (auto p : stp)
    // {
    //     cout << p.first << endl;
    // }
    for (int i = 0; i < stp.size(); i++)
        cout << i << " " << stp.find_by_order(i)->first << endl;
    return 0;
}
// these two feature are not available in set that why we use this help to find this  in order of log(n)