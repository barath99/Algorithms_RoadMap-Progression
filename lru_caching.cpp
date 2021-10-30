#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<list>
#include <unordered_map>
using namespace std;

class lru_cache {
    private:
    int capacity;
    int current_size;
    int page_faults;
    list<int> cache;
    unordered_map<int, list<int>::iterator> cache_map;
    
    public :
    lru_cache(int size) {
        this->capacity = size;
        this->current_size = 0;
        this->page_faults  = 0;
    }

    void add(int job);
    void display();
    bool isempty();
    int get_faults();
};

int lru_cache::get_faults() {
    return page_faults;
}

bool lru_cache::isempty() {
    return current_size != capacity;
}

void lru_cache::add(int job) {
    if(cache_map.find(job) == cache_map.end()) {
        
        page_faults++;

        if(cache.size() == capacity) {

            int last_job = cache.back();

            cache.pop_back();

            cache_map.erase(last_job);
        }
    }

    else 
        cache.erase(cache_map[job]);
        
        cache.push_front(job);
        cache_map[job] = cache.begin();
}

void lru_cache::display(){
    for(auto job = cache.begin(); job != cache.end(); job++)
    cout << *job << "\t";
}

int main() {
    vector<int> v = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    lru_cache lc(5);

    for(auto job : v)
    lc.add(job);

    lc.display();

    cout << "\n";

    cout << lc.get_faults();
    
    return 0;
}
