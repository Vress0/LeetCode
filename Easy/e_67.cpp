#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        // the last one of the string
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0; // 進位數
        string ans="";
        // sum%2可決定這一位，sum/2可決定carry
       
        while(i>=0 || j>=0 || carry>0){
            int sum = carry;
            //當a的第i位是1時，sum+1
            //當b的第j位是1時，sum+1
            // '1' 字元 char
            // "1" 字串 string
            //a[i] 是 char
            if (i >= 0 && a[i] == '1'){    //&&->and 、 ||->or
                sum++;
            }
            if (j >= 0 && b[j] == '1'){
                sum++;
            }

            //sum % 2 → 決定這一位寫 0 還是 1
            if (sum%2==0){
                ans += '0';
            }
            else{
                ans += '1';
            }

            //sum / 2 → 決定下一輪 carry
            carry = sum / 2;

            i--;
            j--;
        }


        reverse(ans.begin(), ans.end());
        return ans;
    }
};

 /*
        可以用for，但是會條件會很長
        for (int i = a.length() - 1, j = b.length() - 1, carry = 0;
            i >= 0 || j >= 0 || carry > 0;
            i--, j--) {

        }
        */