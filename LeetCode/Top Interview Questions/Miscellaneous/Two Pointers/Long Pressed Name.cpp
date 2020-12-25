class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        //Corner Cases
        if((int)name.size() > typed.size() || (name == "" && typed != "")) return false;
        if(name == typed) return true;
        
        //General cases.
        int left1 = 0, right1 = 0;
        int left2 = 0, right2 = 0;
        while(right1 < (int)name.size()){
            while(right1 < (int)name.size() && name[left1] == name[right1]) right1++;
            while(right2 < (int)typed.size() && typed[left2] == typed[right2]) right2++;
            if(name[right1 - 1] != typed[right2 - 1]){
                return false;
            }
            int qtdl1 = right1 - left1;
            int qtdl2 = right2 - left2;
            if(qtdl2 < qtdl1){
                return false;
            }
            left1 = right1;
            left2 = right2;
        }
        if(right2 < (int)typed.size() && typed[right2] != name[(int)name.size() - 1]) return false;
        return true;
    }
};
