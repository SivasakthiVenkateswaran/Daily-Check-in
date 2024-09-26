class Solution {
public:

    bool canTransform(string start, string end) {
        if (start.length() != end.length()) {
            return false;
        }
        
        string startChars, endChars;
        for (char c : start) {
            if (c != 'X') startChars += c;
        }
        for (char c : end) {
            if (c != 'X') endChars += c;
        }
        
        if (startChars != endChars) {
            return false;
        }
        
        int p1 = 0, p2 = 0;
        int n = start.size();
        
        while (p1 < n && p2 < n) {
            while (p1 < n && start[p1] == 'X') p1++;
            while (p2 < n && end[p2] == 'X') p2++;
            
            if (p1 == n && p2 == n) {
                return true;
            }
            
            if (p1 == n || p2 == n) {
                return false;
            }
            
            if (start[p1] != end[p2]) {
                return false;
            }
            
            if (start[p1] == 'L' && p1 < p2) {
                return false; 
            }
            if (start[p1] == 'R' && p1 > p2) {
                return false; 
            }
            
            p1++;
            p2++;
        }
        
        return true;
    }
};