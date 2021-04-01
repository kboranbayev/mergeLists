#include<iostream>
#include<list>
#include<cstring>
#include<set>

using namespace std;

struct Comparator {
    bool operator() (string s1, string s2)
    {
        if (s1 == s2) return false;             // No duplicates
        
        if (s1.length() != s2.length()) {       // Sort by length
            if (s1.length() < s2.length()) return false;
        } else
            for (int i = 0; i < s1.length(); i++) { // Sort by reverse alphabetical
                if (s1[i] == s2[i]) continue;
                if (s1[i] < s2[i]) return false;
                if (s1[i] > s2[i]) return true;
            }

        return true;
    }
};


list<string> mergeLists(const list<string> l1, const list<string> l2) {
    list<string> result;
    set<string, Comparator> st;

    for (auto & s : l2)
        st.insert(s);

    for (auto & s : l1)
        st.insert(s);

    for (auto & s : st)
        result.push_back(s);

    return result;
}


list<string> deleteItems(const list<string> l1, const list<string> l2) {
    list<string> result;
    set<string, Comparator> st;

    // converting list to set
    for (auto & s : l1)
        st.insert(s);

    // removing items
    for (auto & s : l2)
        st.erase(s);

    for (auto & s : st)
        result.push_back(s);

    return result;
}



int main() {

    const list<string> original = {"one", "two", "three"};

    const list<string> addList = {"one", "two", "five", "six"};

    const list<string> deleteList = {"two", "five"};

    const list<string> resultList = {"three", "six", "one"};

    list<string> res = mergeLists(original, addList);
    list<string> res2 = deleteItems(res, deleteList);

    cout << "After Merging: ";
    for (auto & s : res)
        cout << s << " ";
    cout << endl;


    cout << "After Deletion: ";
    for (auto & s : res2)
        cout << s << " ";
    cout << endl;
    
    return 0;
}
