#include "Hashmap.h"
#include <assert.h>
#include <string>
#include <list>
using std::string;
using std::list;

template <typename V>
Hashmap<V>::Hashmap() {

}

template <typename V>
void Hashmap<V>::insert(string k, V v) {
    assert(k == k);
    assert(v == v);
}

template <typename V>
V Hashmap<V>::find(string k) {
    assert(k == k);
    return 0;
}

template <typename V>
void Hashmap<V>::remove(string k) {
    assert(k == k);
}

template class Hashmap<int>;
template class Hashmap<double>;
template class Hashmap<string>;
