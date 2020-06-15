class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> s;
    vector<unsigned> auxVec;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val))
            return false;
        s.insert(val);
        auxVec.push_back((*s.find(val)));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(s.count(val)) {
            auto ptr = (*s.find(val));
            for(int i = 0; i < auxVec.size();i++) {
                if(auxVec[i] == ptr) {
                    auxVec.erase(auxVec.begin() + i);
                    break;
                }
            }
            s.erase(val);
            return true;
        }

        return false;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return *select_randomly(auxVec.begin(), auxVec.end());
        
    }
    
    template<typename Iter, typename RandomGenerator>
    Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(g));
        return start;
    }
    
    template<typename Iter>
    Iter select_randomly(Iter start, Iter end) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
