class Solution {
public:
    vector<string> findItineraryNaive(vector<vector<string>>& tickets) {
        if(tickets.empty())
            return vector<string>();
        
        sort(tickets.begin(),tickets.end());
        
        map<string,vector<string>> itinerary;
        vector<string> result;
        
        for(const auto ticket : tickets) {
            itinerary[ticket[0]].push_back(ticket[1]);       
        }
        
        std::map<string,vector<string>>::iterator iter = itinerary.find("JFK");
        if(iter != itinerary.end()) {
          result.push_back(iter->first);
            while(result.size() < tickets.size() + 1 && iter != itinerary.end()) {
                result.push_back(iter->second.back());
                for(const auto str : result)
                    cout<< str << endl;
                auto temp = itinerary.find(iter->second.back());
                iter->second.pop_back();
                iter = temp;
            }
        }
        else
            return vector<string>();
        
        return result;
        
    }
    
    vector<string> findItinerary(vector<vector<string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket[0]].insert(ticket[1]);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
    }

    map<string, multiset<string>> targets;
    vector<string> route;

    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
    
    
    
};
