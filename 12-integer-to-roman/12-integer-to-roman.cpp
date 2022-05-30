class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        
        while(num)
        {
            if(num>=1 and num<5)
            {
                int data=num/1;
                if(data==4) ans+="IV";
                else while(data--) ans+='I';
                
                num=0;
            }
            
            else if(num>=5 and num<10)
            {
                if(num==9) 
                {
                    ans+="IX";
                    num=0;
                }
                
                else
                {
                    ans+='V';
                    num-=5;
                }
            }
            
            else if(num>=10 and num<50)
            {
                if(num>=40)
                {
                    ans+="XL";
                    num-=40;
                }
                
                else
                {
                    while(num>=10)
                    {
                        ans+='X';
                        num-=10;
                    }
                }
            }
            
            else if(num>=50 and num<100)
            {
                if(num>=90)
                {
                    ans+="XC";
                    num-=90;
                }
                
                else
                {
                    ans+='L';
                    num-=50;
                }
            }
            
            else if(num>=100 and num<500)
            {
                if(num>=400)
                {
                    ans+="CD";
                    num-=400;
                }
                
                else
                {
                    while(num>=100)
                    {
                        ans+='C';
                        num-=100;
                    }
                }
            }
            
            else if(num>=500 and num<1000)
            {
                if(num>=900)
                {
                    ans+="CM";
                    num-=900;
                }
                
                else
                {
                    ans+='D';
                    num-=500;
                }
            }
            
            else
            {
                while(num>=1000)
                {
                    ans+='M';
                    num-=1000;
                }
            }
        }
        
        return ans;
    }
};