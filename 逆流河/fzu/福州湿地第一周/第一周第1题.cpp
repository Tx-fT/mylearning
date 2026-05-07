//#include<iostream>
//using namespace std;
//int main(){
//	cout<<"请输入一个大于1且不为质数的正整数(可以化为两质数乘积):  "<<endl;
//	int a=0;
//	cin>>a;
//	while(1){
//		if(a%2==0){
//			cout<<"你输入的为偶数无法化为两质数成积，请重新输入"<<endl;
//			cin>>a;
//			continue;
//			}
//		else{
//			for(int i=3;i<a;i+=2){
//				if(a%i==0){    //a是否为质数
//					int b=i;
//					int c=a/b;
//					for(int u=3;u<a;u+=2){
//						if((b%u!=0||b/u==1)&&(c%u!=0||c/u==1)){
//							cout<<b<<endl;
//							system("pause");
//							return 0;
//						}	
//					}
//				cout<<"你输入的无法化为两质数成积，请重新输入"<<endl;
//				cin>>a;
//				break;	
//				}
//				cout<<"您输入的为质数,请重新输入"<<endl;//不能用else的原因：for循环会只看第一个值
//				cin>>a;	
//				break;
//		}
//			cout<<"不能输入1重新输入"<<endl;
//			cin>>a;		
//		}
//	}
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;

// 判断一个数是否为质数
bool isPrime(int n) {
    if (n <= 1) return false;  // 小于等于1的数不是质数
    if (n == 2) return true;   // 2是质数
    if (n % 2 == 0) return false; // 偶数不是质数
    for (int i = 3; i * i <= n; i += 2) { // 只检查奇数除数，效率更高
        if (n % i == 0) return false;
    }
    return true;//都不满足则ture
}

int main() {
    int a;
    while (true) {
        cout << "请输入一个大于1且不为质数的正整数(可以化为两质数乘积): " << endl;
        cin >> a;

        // 验证输入是否大于1
        if (a <= 1) {
            cout << "输入必须大于1，请重新输入！" << endl;
            continue;
        }

        // 验证输入是否为质数（质数不能分解为两个质数乘积，除非自身是质数且另一个是1，但1不是质数）
        if (isPrime(a)) {
            cout << "输入的是质数，无法分解为两个质数乘积，请重新输入！" << endl;
            continue;
        }

        // 尝试分解为两个质数的乘积
        bool found = false;
        // 从2开始检查可能的因数
        for (int i = 2; i * i <= a; ++i) {
            if (a % i == 0) { // i是a的因数
                int j = a / i; // 另一个因数
                if (isPrime(i) && isPrime(j)) { // 两个因数都是质数
                    cout << "分解结果：" << i << " × " << j << " = " << a << endl;
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            break; // 找到有效分解，退出循环  提前定义一个found可以继续退出大循环
        } else {
            cout << "该数无法分解为两个质数的乘积，请重新输入！" << endl;
        }
    }

    system("pause");
    return 0;
}
