class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxattack=0;
        int weak=0;
        for(auto &property:properties){
            maxattack=max(property[0],maxattack);
        }
        vector<int>maxdefense(maxattack+2,0);
        //storing the max defense for an attack value
        for(auto &property:properties){
            int attack=property[0];
            int defense=property[1];
            maxdefense[attack]=max(maxdefense[attack],defense);
        }
        
        //storing the max defense for attack greater than or equal to value
        for(int i=maxattack-1;i>=0;i--){
            maxdefense[i]=max(maxdefense[i],maxdefense[i+1]);
        }
        for(auto &property:properties){
            int attack=property[0];
            int defense=property[1];
            if(defense<maxdefense[attack+1])
                weak++;
        }
        return weak;
    }
};