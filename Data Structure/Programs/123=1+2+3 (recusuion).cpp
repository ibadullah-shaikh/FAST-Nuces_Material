#include <iostream>
    using namespace std;

    class Sum
    {
    public:
        Sum() {}
        int calculate_Sum(int m)
        {
            if (m%10 == 0 || m%10 == 1)
            {
                return m;
            }
            else{
                return m%10+calculate_Sum( m/10 );
            }
            return 0;
        }
    };

    int main()
    {
        
        system("cls");
        Sum S;
        int sum=S.calculate_Sum(1234); 
        cout << sum;        // 1234 => 1+2+3+4=10
    }
