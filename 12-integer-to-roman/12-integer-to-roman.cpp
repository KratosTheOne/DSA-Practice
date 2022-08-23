//T.C & S.C -> O(charsInResultString) & O(1)
 
class Solution {
public:
    string intToRoman(int num) {
        
        int intCode[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        for(int i = 0; i < 13; i++)
        {
            while(num >= intCode[i])
            {
                result.append(code[i]);
                num -= intCode[i];
            }
        }
        
        return result;
    }
};