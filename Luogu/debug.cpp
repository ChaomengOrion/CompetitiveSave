#include <bits/stdc++.h>

struct node {
    int value;
};

struct CMP {
    bool operator()(const node& a, const node& b) const { return a.value < b.value; }
};

bool cmp1(const node& a, const node& b)
{
    return a.value < b.value;
}


int main()
{
    auto cmp2 = [](const node& a, const node& b) -> bool { 
        return a.value < b.value; 
    };

    std::set<node> set1;
    std::set<node, CMP> set2;
    std::set<node, decltype(cmp1)*> set3(cmp1);
    std::set<node, decltype(cmp2)> set4(cmp2);
    // set4.insert(node{0});


    struct myset {
        static bool cmp(const node& a, const node& b)
        {
            return a.value < b.value;
        }
        std::set<node, decltype(cmp)*> set;
        myset() { set = std::set<node, decltype(cmp)*>(cmp); }
    };
    std::map<int, myset> mymap2;
    mymap2.insert({115, myset()});
    mymap2[115].set.insert(node{1919});
    std::cout << mymap2.at(115).set.begin()->value << std::endl;
    std::cout << mymap2.begin()->second.set.begin()->value << std::endl;


    std::map<int, std::set<node, decltype(cmp2)>> mymap;
    mymap.insert({114, std::set<node, decltype(cmp2)>(cmp2)});
    mymap[114].insert(node{0});
    std::cout << mymap.at(114).begin()->value << std::endl;
    std::cout << mymap.begin()->second.begin()->value << std::endl;
}