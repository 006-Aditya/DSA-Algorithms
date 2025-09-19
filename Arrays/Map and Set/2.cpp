// problem link --

// https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18

// Map and Set Use 

// code -- 


class TaskManager {
public:
    struct customHash{
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) const{
            if(get<0>(a)!=get<0>(b)){
                return get<0>(a) > get<0>(b);  
            }
            return get<1>(a) > get<1>(b);  
        }
    };
    set<tuple<int,int,int>, customHash>st;
    unordered_map<int,pair<int,int> >mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            st.insert({tasks[i][2],tasks[i][1],tasks[i][0]});
            mp[tasks[i][1]]={tasks[i][0],tasks[i][2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId,userId});
        mp[taskId]={userId,priority};
    }
    
    void edit(int taskId, int newPriority) {
        int userId=mp[taskId].first;
        int priority=mp[taskId].second;
        st.erase({priority,taskId,userId});
        st.insert({newPriority,taskId,userId});
        mp[taskId]={userId,newPriority};
    }
    
    void rmv(int taskId) {
        int userId=mp[taskId].first;
        int priority=mp[taskId].second;
        st.erase({priority,taskId,userId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        auto it=st.begin();
        int priority=get<0>(*it);
        int taskId=get<1>(*it);
        int userId=get<2>(*it);
        st.erase({priority,taskId,userId});
        return userId;

    }
};
