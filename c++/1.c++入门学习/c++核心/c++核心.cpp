//c++核心编程

//内存的分区模型
//c++程序在执行时，将内存划分为4个区
//代码区：存放二进制代码  共享 只读
//全局区：存放全局变量（函数体外的） 静态变量（在普通变量前面＋static 例：static int a=1;） 常量（字符串常量（双引号引起来的），const修饰的变量（const修饰的全局变量（全局常量） const修饰的局部变量（不属于全局区与局部变量放在一起）（局部常量）））     
//栈区：编译器管理完成后释放内存（销毁掉了）， 函数的参数（形参），局部变量（函数体内的）（不要返回局部变量的地址 return &a）
//堆区：程序员分配释放，若程序员不释放，程序结束后由操作系统回收（用new在堆区开辟数据）
//灵活编程 
//局部开头（局部变量 局部常量）都不在全局区
//在程序运行之前分为全局区和代码区
//new  在函数内创造出一个不return的量
//#include<iostream>
//using namespace std;
//int *func(){//表示此函数为指针变量**
//	int *p=new int(10);//利用new关键字可以将数据开辟到a区  此时p得到堆区10的地址
//	return p;//指针本质也是局部变量，放在栈上，指针保存的数据是堆区
//}
//void test01(){
//	int *p1=func();//把地址传给新指针//func为全局变量可以保留到另外函数所以要return p地址给test01()
//		cout<<*p1<<endl;
//		cout<<*p1<<endl;//栈区的*p已无但*p1接任
//		cout<<*func()<<endl;
//}
//int main(){
//	func();
//	test01();
//	system("pause");
//	return 0;
//}
////在堆区开辟数组
//void test02(){
//	int *arr=new int[10];//()表示一个变量 []为数组
//	for(int i=0;i<10;i++){
//		arr[i]=i+1;
//		cout<<arr[i]<<endl;
//	}
//	delete[] arr;//释放堆区数组在前面＋[]
//}
//int main(){
//	test02();
////	int b=10;
////	int* a=&b;//说明new int(10)为地址 因为开辟内存实际上是开辟地址
////	*a=11;
////	cout<<b<<endl;
//	system("pause");
//	return 0;
//}
////new开辟delete释放
////语法：new 数据类型

//引用 给变量取别名
//语法：数据类型 &别名=原名 int &b=a;（让a和b都可以操控内存）
//引用的注意事项
//1.引用必须初始化（要不然野引用）
//2.引用一旦初始化后就不能更改（不能脚踏两条船）  指针const才不能改
//引用做函数参数
//值传递  地址传递  引用传递（形参修饰实参，简化指针）
//#include<iostream>
//using namespace std;
//void c(int &a,int &b){//用引用方式接收是价格另外的称呼
//	int temp=a;       //值传递形参是赋值操作
//	a=b;              //地址传递是用地址去附身
//	b=temp;
//	}
//int main(){
//	int a=10;
//	int b=20;
//	c(a,b);
//	cout<<a<<b<<endl;
//	system("pause");
//	return 0;
//}
//引用做函数的返回值
//1.不要返回局部变量的引用
//2.函数的调用可以作为左值  如果函数的返回值是引用，这个函数调用可以作为左值
//int &test01(){//因为在函数里的a没有存储功能用&加给函数（起到引用a的作用，又因为a的特殊性使test01就是a）但a最后return，test01成为野引用无意义 //本质就是将a地址存在全局变量里了
//	static int a=10;//使a成为全局常数不会被抹除
//	return a;//return才会传值  返回值数据类型
//}
//int main(){
//	int &ref=test01();
//	cout<<ref<<endl;
//	cout<<ref<<endl;
//    cout<<test01()<<endl;//但这只是函数调用了a而已如果test01没加&
//    cout<<test01()<<endl;//如果test01加了&那么test01可以作为变量使用与a共同管一块内存
//    cout<<test01()<<endl;
////a 和 test01都是全局变量都管一处地址
//    test01()=100;
//    cout<<ref<<endl;//&test01()成为全局变量所以可以赋值
//	system("pause");
//	return 0;
//}
//引用的本质  指针常量（谁在后面谁能改前面不能该   能改变值但不能改变引用对象）
//int &a=b;==int* const a=&b;(const直接修饰地址a)  自动帮你做成*ref（前提引用）
//常量的引用
//作用：修饰形参防止误操作
//原本不能直接引用常量因为不合法空间
//const int& a=1000;//加上const给予临时空间（毕竟本质为常量指针） 加上const后变成常量指针常量（只读状态）
//场景
//#include<iostream>
//using namespace std;
//void a(const int &b){//b成只读不能赋值
////    b=1000;
//	cout<<b<<endl;
//}
//int main(){
//	int c=10;
//	a(c);//若形参前不加const，根据指针变量c本身会改变要想使c不变形参前要加const
//	system("pause");
//	return 0;
//}

//函数的提高
//1.可以在函数（）内直接赋值（默认参数）//但是某个位置已经有了默认参数，从这个位置之后的形参必须要有默认参数，前面无所谓
//  在main函数中的实参能覆盖形参，重新赋值
//  声明和实现只能有一个有默认参数
//函数的占位参数
//返回值类型 函数名（数据类型）{}//占位参数也可以有默认参数int=10
//***函数重载技术
//作用：函数名可以相同，提高复用性
//函数重载满足条件：1.同一个作用域下 2.函数名称相同 3.函数类型不同或者个数不同顺序不同
//注意：函数的返回值不可以作为函数重载的条件
//#include<iostream>
//using namespace std;
//void a(int a){
//	cout<<"111"<<endl;//个数不同顺序不同
//}
//void a(double a,int b){
//	cout<<"222"<<endl;//都在全局作用域
//}
//返回值类型int void不可以作为函数重载的条件
//函数重载的注意事项
//void a(int &a)
//void a(const int &a)可传递常数
//函数重载与默认参数
//简单来说自己知不知道调用哪个函数

//*****类和对象*****
//C++面向对象的三大特性：封装，继承，多态
//C++认为万事万物皆为对象，对象上有其属性和行为
//具有相同性质的对象，我们可以抽象称为类
//封装
//意义：1.将属性和行为作为一个整体，表现生活中的事物    将属性和行为加以权限控制
//封装意义1
//在设计类时，属性和行为写在一起表示事物
//#include<iostream>//结构体与函数的结合
//#include<string>
//using namespace std;
//const double P1=3.14;
//class Circle{
//	//访问权限*
//	//公共权限
//public:
//	//属性*
//	//半径
//	int m_r;//m里的r
//	//行为*
//	//获得圆的周长
//	double calculate(){
//		return 2*P1*m_r;
//	}
//};
//int main(){
//	//实例化（通过一个类创建一个对象的过程）
//	Circle c1;//通过圆类，创建具体的圆（对象）
//	c1.m_r=10;
//	cout<<"圆的周长"<<c1.calculate()<<endl;
//	system("pause");
//	return 0;
//}
//class stu{
//public:
//	string name;//类中的属性和行为都叫成员
//	int stunum;//成员属性 成员变量
//	void show(){//成员函数 成员方法
//	cout<<name<<"  "<<stunum<<endl;
//	}	
//};第一种方式
//public:
//	string name;
//	int ID;
//public:
//	void setn(string n){
//		name=n;
//	}
//	void setID(int id){
//		ID=id;
//	}
//	void show(){
//		cout<<name<<ID<<endl;//因为都在class类里形参能直接使用
//	}
//};
//int main(){
//	stu a;
//    cout<<"name"<<endl;
//    string b;
//    cin>>b;
//    a.setn(b);
//    cout<<"num"<<endl;
//    int c;
//    cin>>c;
//    a.setID(c);
//    a.show();
//    system("pause");
//    return 0;
//    
//}//第二种方式//用class中行为函数去赋值  意义：
//封装意义2
//类在设计时，可以把属性和行为放在不同权限下，加以控制
//访问权限有三种：
//public公共权限 类内类外都可以访问
//protected保护权限 类内可以访问，类外不可以访问   儿子可以访问父亲中的保护内容
//private私有权限 类内可以访问，类外不可以访问   儿子不可以访问父亲的私有内容                                                   //继承有区别（有父子关系）
//public：
    //string name;可在class外访问到
//protected:
    //string car;不可在class外访问到
//private:
    //int passworf;不可在class外访问到
//public：
    //void a(){
//	string name;
//	string car;
//	int passworf;
//	}    虽然里面含有不可访问成员但总体a函数在class类内作为内鬼可以访问
//c++中stuct和class的区别
//都可以表示类
//唯一区别：默认访问权限不同struct public//class默认权限private  在c++中都支持设置权限
//成员属性设置为私有
//优点  1.可以自己控制读写权限2.对于写权限可以检测数据的有效性
//#include<iostream>
//#include<string>
//using namespace std;
//class stu{
//	string name;
//	int ID;
//public:
//	void setname(string n){
//		name=n;
//	}
//	string getname(){
//		return name;//不用加形参如果在同个局部变量**********
//	}
//	int getID(){
//		return ID;
//	}
//	void setID(int n){
//		if(n>10){
//			cout<<"输入有误"<<endl;
//			return;
//		}
//		ID=n;//用函数来调取权限//检查有效性
//	}
//};
//int main(){
//	stu s;
//	string a;
//	cin>>a;
//	s.setname(a);
//	cout<<s.getname()<<endl;
//	int b;
//	cin>>b;
//	s.setID(b);
//	cout<<s.getID()<<endl;
//	system("pause");
//	return 0;
//}
//练习案例一：设计立方体类
//#include<iostream>
//using namespace std;
//
//class cube{
//
//	int a;
//	int b;
//	int c;
//public:
//	void ga(int a1){
//		a=a1;
//	}
//	void gb(int b1){
//		b=b1;
//	}
//	void gc(int c1){
//		a=c1;
//	}
//	bool contrast(cube body2){
//		if(a==body2.a){
//			return true;
//		}
//		return false;
//	}
//		
//		
//};
//int main(){
//	cube body1;
//	body1.ga(1);
//	body1.gb(1);
//	body1.gc(1);
//	cube body2;
//	body2.ga(1);
//	body2.gb(1);
//	body2.gc(1);
//	if(body1.contrast(body2)==true){
//		cout<<"111"<<endl;
//		}
//	else{
//		cout<<"222"<<endl;
//		}
//	system("pause");
//	return 0;
//	
//}
//将函数变为int *或&a(){}的形式一般都是将函数里的栈区里的局部变量提到全局变量（以函数形式）
//#include<iostream>
//using namespace std;
//class POINT{
//	int x;
//	int y;
//public:
//	void setx(int x1){
//		x=x1;
//	}
//	int getx(){
//		return x;//形参啥也不是只是指代量，且在一个函数内都是同一个局部的变量可以直接用
//	}
//	int gety(){
//		return y;
//	}
//	void sety(int y1){
//		y=y1;
//	}
//};
//class Circle{
//	int m_r;
//	POINT m_center;//在一个类中可以让另一个类作为本类中的成员
//public://在全局域可互通
//	void setr(int r){
//		m_r=r;
//	}
//	int getr(){
//		return m_r;//因为m_r为私有需要public用int函数加return
//	}
//	void setcenter(POINT center){//POINT为全局可以直接用
//		m_center=center;//可以改变private  函数具有互动特性可接收外值  这就是封装
//	}
//	POINT getcenter(){
//		return m_center;//对成员的行为
//	}
//	void ifcenter(POINT &a,Circle &b){//取地址节省空间
//		int distance=
//		(b.m_center.getx()-a.getx())* (b.m_center.getx()-a.getx()) +//因为在类内可以用m_center在类外只能用getcenter
//		(b.m_center.gety()-a.gety())* (b.m_center.gety()-a.gety()) ;    //指针直接指代结构体才有P->
//		int r_distance=(b.getr())* (b.getr());
//		if(distance>r_distance){
//			cout<<"outcircle"<<endl;
//		}
//		else if(distance<r_distance){
//			cout<<"insidecircle"<<endl;
//		}
//		else{
//			cout<<"oncircle"<<endl;
//		}           
//	}
//};
//int main(){
//	Circle b;
//	POINT d;
//	d.setx(0);
//	d.sety(0);
//	b.setcenter(d);//直接用get那么在private里的成员属性根本没变
//	b.setr(10);
//    POINT a;
//    a.setx(6);
//    a.sety(8);
//    b.ifcenter(a,b);//引用  指针都能较小内存   但指针需要->引用不用只用.
//    system("pause");//set为设置，和判断get为获取值用其带入计算  用set和get其实就是为了储存在全局区的表现方式
//    return 0;
//    
//}
//其实指针1.节省内存2.交流函数使互通都可以访问一块内存

//对象的初始化和清理
//构造函数（初始化）和析构函数（清理）
//构造函数语法：
//类名（）{}
//1.构造函数，没有返回值也不用写void
//2.函数名称与类名相同
//3.构造函数可以有参数，因此可以发生函数重载
//4.程序程序在调用对象时候会自动调用构造，无需手动调用且只会调用一次
//析构函数语法：
//~类名（）{}
//1.没有返回值也不用写void
//2.函数名称与类名相同，在名称前加~
//3.析构函数不可以有参数因此不可以发生函数重载
//4.程序在对象销毁前会自动调用析构，无需手动调用，而且只会调用一次
//#include<iostream>
//using namespace std;
//class person{
//public:
//	person(){//即使不编编译器也会提供但是空实现隐形
//		cout<<"111"<<endl;
//	}
//	~person(){
//		cout<<"222"<<endl;
//	}
//};
//void test(){
//	person p;//栈区定义的类所以在main函数中调用test函数 p会调用和释放因此构造析构都会自动出来
//}
//int main(){
//	test();
//	person a;
//	system("pause");
//	return 0;//按任意键才释放main函数才有析构函数出现
//}
//
//#include<iostream>
//using namespace std;
//int main(){
//    char a[20];
//    scanf("%19s",a);
//    for(int i=0;i<20;i++){
//        if(a[i]>='A'&&a[i]<='Y'){
//            a[i]+=33;
//        }
//        else if(a[i]=='Z'){
//                a[i]='a';
//            }
//        else if(a[i]>='a'&&a[i]<='y'){
//            a[i]-=31; 
//        }
//        else if(a[i]=='z'){
//            a[i]='A';
//        }
//    }
//    printf("%s",a);
//    return 0;
//}
//构造函数的分类与调用
//两种分类方式
//按参数分类：有参构造和无参构造
//按类型分为：普通构造和拷贝构造
//三种调用方法：
//括号法 显示法 隐式转换法
//#include<iostream>
//using namespace std;
//class person{
//	int age;
//public:
//	person(){//无参构造函数（默认构造函数）
//		cout<<"0"<<endl;
//	}
//	person(int a){//有参构造函数
//		cout<<"1"<<endl;
//		age=a;
//	}
//    //拷贝构造函数
//    person(const person &p){//引用指针常量加const只读状态但可以给新变量赋值//现有拷贝构造函数才能完成拷贝操作但编译器也有默认的只不过仅仅复制没有其他操作
//    	//将传入的类身上的所有属性，拷贝到我身上
//		age=p.age;
//		cout<<"111"<<endl;
//		cout<<"age"<<age<<endl;
//	}
//	~person(){
//			cout<<"222"<<endl;
//	}
//};
////调用
//void test01(){
////括号法
////    person p1;//调用无参
////    person p2(10);//调用有参
////    person p3(p2);
//    //注意事项
//    //1.调用默认构造函数时候，不要加（）当作函数声明
//    
//    
////显示法
//    person p1;
//    person p2=person(10);//有参构造
//    person p3=person(p2);//拷贝构造
//    //person(10)匿名对象 特点：当前执行结束之后，系统会立即收掉匿名对象
//    //注意事项2
//    //不要利用拷贝构造函数，初始化一个匿名对象
//    //person(p3)==person p3;
//    
////隐式转换法
//    person p4=10;//==person p4=person(10);
//    person p5=p4;
//}
//int main(){
//	test01();
//	system("pause");
//	return 0;
//}
//***********

//拷贝构造函数调用时机
//C++中拷贝构造函数调用三种时机
//1.使用一个创建完毕的的对象来初始化一个新对象
//2.值传递的方式给函数参数传值
//3.以值方式返回局部对象
//#include<iostream>
//using namespace std;
//class person{
//public:
//	person(){
//		cout<<"0"<<endl;
//	}	
//	person(int age){
//		m_age=age;
//		cout<<"1"<<endl;
//	}
//	person(const person &p){
//		m_age=p.m_age;
//		cout<<"2"<<endl;
//	}
//	~person(){
//		cout<<"3"<<endl;
//	}
//	int m_age;
//	
//	
//};
////1
//void test(){
//		person p1(10);
//		person p2=p1;
//	}
////2
//void test01(person p){//值传递了实参传给形参 相当于隐式转换
//	
//}
//void test01(){//函数套函数//函数重载
//	person p;
//	test01(p);
//}
////3
//person test02(){
//	person p;
//	cout<<(int)&p<<endl;
//	return p;
//}
//void test021(){
//	person p1=test02();//又赋值了一个新的
//}
//int main(){
////    test();
////    test01();
//    test021();//相当于创建了一个新的
//	system("pause");
//	return 0;
//}//被c++编译器优化

//**********
//构造函数的调用规则
//前提：只要创建类，c++编译器会给每个类添加至少三个函数  默认构造（空实现） 析构函数（空实现） 拷贝构造（值拷贝）
//1.如果用户定义有参构造函数 c++不再提供默认无参构造 但是会提供默认拷贝构造
//2.如果用户定义拷贝构造函数 c++不会再提供其他构造函数
//#include<iostream>
//using namespace std;//写不同的构造函数 析构函数虽然都在一个类中但在以后创建中创建方式不同表现方式不同
//class person{
//public:
//	person(){
//		cout<<"moren"<<endl;
//	}	
//	~person(){
//		cout<<"xigou"<<endl;
//	}
////	person(const person &p){
////		cout<<"kaobei"<<endl;
////		m_age=p.m_age;
////	}
//	person(int age){
//		age=m_age;
//		cout<<"hancan"<<endl;
//	}
//private:
//	int m_age;
//};
//int main(){
//	person p(10);
//	person p1(p);//1.C++编译器有默认的拷贝构造函数只能值传递可以直接写person p1(p)
//	system("pause");
//	return 0;
//}
////默认构造函数<含参构造函数<拷贝构造函数

//深拷贝与浅拷贝！！！面试问题
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作
//使用场景：不想因a=b因b的改变导致a改变让a开辟到堆区
//#include<iostream>
//using namespace std;
//class person{
//public:
//	person(){
//		cout<<"111"<<endl;
//	}	
//	person(int age,int height){
//		cout<<"youcan"<<endl;
//		m_age=age;
//		m_height=new int(height);//地址=地址
//	}
//		//自己实现拷贝构造函数 解决浅拷贝带来的问题
//	person(const person &p){
//		cout<<"kaobei"<<endl;
//		m_age=p.m_age;
//		//m_height=p.m_height编译器默认拷贝函数是这行代码****
//		m_height=new int(*p.m_height);//重新赋个堆区新地址给拷贝函数变量
//	}
//	~person(){//析构代码，将堆区数据做释放操作
//		cout<<"xigou"<<endl;
//		if(m_height!=NULL){//*每个*构造函数只要被使用都会触发
//			delete m_height;//释放堆区空间
//			m_height=nullptr;//浅拷贝函数和被拷贝有参函数会两次释放堆区内存出错：浅拷贝拷贝了地址//要用深拷贝去解决   
//		}//野指针（Wild Pointer）是指指向无效内存区域的指针，它既不是空指针（nullptr 或 NULL），也不指向合法的内存空间
//	}
//    int m_age;
//    int* m_height;//指针用值需要解引用//用new用到堆区内存肯定要用*地址
//};	
//void test(){
//	person p1(18,175);
//	cout<<p1.m_age<<*p1.m_height<<endl;
//	person p2=p1;//用系统编译器默认拷贝函数，只是浅拷贝
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//总结：如果属性有在堆区开辟那么要用自己定义的深拷贝拷贝构造函数防止浅拷贝带来的问题

//初始化列表
//C++提供了初始化列表语法，用来初始化属性
//语法:构造函数（）：属性1（值1），属性2（值2）...{}
//class person{
//public:
//   	person(int a,int b,int c):m_a(a),m_b(b),m_c=(c){
	
//}
//int m_a;
//int m_b;
//int m_c;
//}
//类对象作为类成员
//#include<iostream>
//#include<string>
//using namespace std;
//class phone{
//public:
//	phone(string name){
//		m_pname=name;
//		cout<<"phone"<<endl;//先构造成员对象
//	}
//	~phone(){
//		cout<<"phone1"<<endl;
//	}
//    string m_pname;
//};
//class person{
//public:
//	person(string name,string pname):m_hname(name),m_pname(pname){//string为什么可以对应phone类因为phone类中定义过string这样构成了隐式转换法
//		cout<<"person"<<endl;
//	}
//	~person(){
//	    cout<<"person1"<<endl;	//先析构本类对象
//	}
//		string m_hname;
//		phone m_pname;	
//};
//void test(){
//	person p("zhuangsan","applepromax");
//	cout<<p.m_hname<<p.m_pname.m_pname<<endl;
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//静态成员
//定义：就是在成员变量和成员函数前加上关键字static，称为静态成员
//静态成员分为
//1.静态成员变量
//特点：
//所有对象共享同一份数据
//在编译阶段分配内存
//类内声明类外初始化
//#include<iostream>
//using namespace std;//****理解：无static创建类为复制的模板但互不干涉，有static修饰的成员连在同一变量（private等属性依旧可以定义，初始化在类外才能普照）
//class person{
//public:
//	static int m_a;//类内声明//static作用专属于类的全局变量，不管定义多少类都指向同一地址
//private:
//	//静态成员变量也是有访问权限的
////	static int m_b;//在private内声明
//};
//int person::m_a=100;//类外初始化//因为在类外初始化
//int person::m_b=10;
//void test(){
//	person p;
//	cout<<p.m_a<<endl;
//	person p1;
//	p1.m_a=200;
//	cout<<p.m_a<<endl;;
//}
//void test01(){
//	//访问方式：
//	//除了创建类多了一种直接用类名的访问方法
//	cout<<person::m_a<<endl;
//}
//int main(){
//	test();
//	test01();
//	system("pause");
//	return 0;
//}
//静态成员函数：
//1.所有对象共享同一个函数
//2.静态成员函数只能访问静态成员变量
//#include<iostream>
//using namespace std;
//class person{
//public:
//	static void func(){
//		m_a=100;//静态成员函数可以访问静态成员变量  普照方能对应普照
//		//m_b=200;//静态成员函数不能访问非静态成员变量，因为不同的类有不同的m_b无法区分
//		cout<<"静态成员函数的调用"<<endl;
//	}
//	static int m_a;	
//	int m_b=0;
////静态成员函数也有访问权限
//private:
//	static void func1(){
//		cout<<"static private"<<endl;//类外访问不到
//	}
//};
//int person::m_a=0;
//void test(){
//	//两种访问方式
//	person p;
//	p.func();
//	person::func();
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//c++对象模型和this指针
//成员变量和成员函数分开存储
//在c++，类内的成员变量和成员函数分开存储
//只有非静态成员成员变量才属于类的对象上（静态成员和非静态成员函数都不属于类的对象上）
//#include<iostream>
//using namespace std;
////成员变量和成员函数是分开存储的
//class person{
//	int m_a;//属于类的对象上
//	static int m_b;
//	void func(){
//		
//	}//不在类对象上但能区分不同person p1;person p2的类
//};
//int person::m_b;
//void test(){
//	person p;
//	cout<<sizeof(p)<<endl;//空对象占用内存空间为1//c++编译器会给每个空对象也非陪一个字节空间，是为了区分空对象占内存的位置
//	//确保每个空对象有一个独一无二的内存空间
//	//
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//this指针！
//背景：c++中非静态成员变量于与函数是分开存储的，成员变量会随不同类型对象诞生不同实例且存储在类中，而成员函数不在类中存储且每个非静态成员函数只会诞生一份函数实例，那么他是怎么区分哪个对象调用并对应
//this指针指向被调用的成员函数所属对象
//this指针是隐含每一个非静态成员函数内的指针    this指针可直接使用
//this指针的用途：
//1.当形参与成员变量同名时，可用this指针来区分
//2.在类的非静态成员函数中返回对象本身，可以用return *this
//#include<iostream>
//using namespace std;
//class person{
//public:
//	int age;
//	person(int age){
//		this->age=age;//this指针指向被调用的成员函数所属对象:指向被调用了有参构造函数所属的/*对象*/落脚在对象上的量//与形参冲突
//	}
//	person *addperson(person p){//person &addperson(person p){
//		age+=p.age;
//		return this;//有下文p的调用才有this this指向p但要写为&p//return *this;
//	}	
//};
//void test(){
//	person p=18;
//	cout<<p.age<<endl;
//	person p1=20;
//	p.addperson(p1)->addperson(p1);//p.addperson(p1).addperson(p1);
//	cout<<p.age<<endl;
//}
//
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//两种写法的领悟：
//this指向的是调用所在函数之上的一个类的地址（this指针）
//用this来return本身可以支持更简单的一串调用
//为甚形参重复时用this->因为正代表p.而this是p的指针形式
//调用person函数加return实际上是拷贝（把函数名看作p1）
//即person p1=p;(这是普通的值传递)而person &p1=p;才是地址传递（这里p用变量需要*this解引用）或person *p1=&p;(这时候this刚好就是地址)  
//空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针需要加以判断保证代码健壮性
//#include<iostream>
//using namespace std;
//class person{
//public:
//	void classname(){
//		cout<<1<<endl;//可以访问可调用
//	}
//	void personage(){
//		if(this==NULL){
//			return;//防止因this指针识别不到类的地址代码崩溃
//		}
//		cout<<m_a<<endl;//报错原因：传入的指针为空
//	}
//	int m_a;
//};
//void test(){
//	person *p=NULL;//无地址
//	p->classname();
//	p->personage();
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//const修饰成员函数
//常函数  成员函数后加const后称这个函数为常函数
//常函数不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改
//#include<iostream>
//using namespace std;
//class person{
//public:
//	void showperson() const//经实验const后打不出return* this的操作，这个操作相当于地址传递
//	{
//		m_b=100;
//		//m_a=100;==this->m_a=100;//this指针本质是指针常量指针（person *const this）的指向不可更改（所以不能this=NULL）
//    //要变为常量指针常量（也不可以修改值）
//	//在成员函数后加const，修饰的是this指针，让指针指向的值也不可以修改	
//	}
//	int m_a;
//	mutable int m_b;//特殊变量，即使在常函数中也可以修改这个值//加mutable	
//};
//int main(){
//	person p;
//	p.showperson();
//	cout<<p.m_b<<endl;
//	system("pause");
//	return 0;
//} 
//#include<iostream>
//using namespace std;
//class person{
//public:
//	person(){
//		cout<<"111"<<endl;
//	}
//	const person& showperson() const//经实验const后打不出return* this的操作，这个操作相当于地址传递
//	{
//		m_b=100;
//		return *this;//*****感悟：成员函数后加const直接修饰所在对象*this表示const person* const this返回不能只返回引用要加const在函数前成为p（只有开辟了新内存才算开辟新对象动用构造函数）
//		//m_a=100;==this->m_a=100;//this指针本质是指针常量指针（person *const this）的指向不可更改（所以不能this=NULL）
//    //要变为常量指针常量（也不可以修改值）
//	//在成员函数后加从上图，修饰的是this指针，让指针指向的值也不可以修改	
//	}
//	int m_a;
//	mutable int m_b;//特殊变量，即使在常函数中也可以修改这个值//加mutable	
//};
//int main(){
//	person p;
//	p.showperson();
//	cout<<p.m_b<<endl;
//	system("pause");
//	return 0;
//} 
//好的，这段代码你尝试在常函数中返回 *this，结果失败了，这个现象非常好，正好可以帮你更深入地理解 C++ 中 const 成员函数和 this 指针的关系。
//核心问题：const 成员函数的返回类型
//我们来分析一下为什么在 person& showperson() const 中不能 return *this。
//const 成员函数中的 this 指针：当你在成员函数后加上 const 关键字时，你就告诉编译器：这个函数不会修改对象的状态（除了 mutable 成员）。为了保证这一点，编译器会将隐含的 this 指针的类型从 person *const 变为 const person *const。
//person *const this：指针本身不能改，但指向的内容可以改。
//const person *const this：指针本身不能改，并且指向的内容也不能通过这个指针来改。
//return *this 的含义：*this 是对 this 指针的解引用，它代表了 this 指针所指向的对象本身。
//类型不匹配：
//你的函数返回类型是 person&，即一个非常量引用。
//然而，在 const 成员函数内部，*this 的类型是 const person（因为 this 是 const person *）。你不能将一个 const person 对象绑定到一个 person& 类型的引用上，这会破坏 const 的常量性承诺。
//简单来说：你不能从一个承诺不修改对象的函数里，返回一个可以用来修改对象的 “钥匙”（非常量引用）。
//如何正确地从 const 成员函数返回 *this
//如果你确实需要在 const 成员函数中返回对象本身，正确的做法是将返回类型声明为 const person&。
//修改后的代码如下：
//cpp
//运行
//#include<iostream>
//using namespace std;
//
//class person{
//public:
//    // 正确的做法：返回 const 引用
//    const person& showperson() const {
//        m_b = 100; // m_b 是 mutable 的，可以修改
//        return *this; // 现在 *this 的类型是 const person，与返回类型 const person& 匹配
//    }
//
//    int m_a;
//    mutable int m_b;
//};
//
//int main(){
//    person p;
//    p.m_a = 20;
//    
//    // 调用 const 成员函数，返回一个 const person&
//    const person& p2 = p.showperson();
//
//    cout << "p.m_b: " << p.m_b << endl;     // 输出 100
//    cout << "p2.m_b: " << p2.m_b << endl;   // 输出 100
//
//    // p2.m_a = 30; // 错误！p2 是 const 引用，不能修改其成员
//    // p2.m_b = 200; // 错误！即使 m_b 是 mutable，p2 的引用类型是 const person&，也不能通过 p2 修改
//
//    p.m_b = 200; // 正确，可以通过原始的非 const 对象 p 来修改
//    cout << "After p.m_b = 200, p2.m_b: " << p2.m_b << endl; // 输出 200，因为 p2 引用的是 p
//
//    system("pause");
//    return 0;
//}
//总结
//成员函数类型	this 指针类型	*this 类型	建议返回类型	目的
//普通成员函数
//person& showperson()	person *const	person	person&	返回对象本身，允许后续通过返回值修改对象。
//const 成员函数
//const person& showperson() const	const person *const	const person	const person&	返回对象本身的常量视图，保证后续不能通过返回值修改对象，符合 const 函数的语义。
//关键 takeaway：const 成员函数的返回类型如果是引用，也必须是 const 的引用，这样才能与 *this 的 const 类型相匹配，并维持函数的 const 承诺。
//#include<iostream>
//using namespace std;
//class person{
//public:
//	person(){
//		cout<<"111"<<endl;
//	}
//	person(const )
// 	person showperson()
//	{
//		m_b+=100;
//		return *this;
//	}
//	int m_a;
//	mutable int m_b;
//};
//int main(){
//	person p;
//	p.showperson().showperson();//调用默认拷贝构造函数
//	cout<<p.m_b<<endl;
//	system("pause");
//	return 0;
//} 
//#include<iostream>
//using namespace std;
//class person{
//public:
//	void showperson() const//经实验const后打不出return* this的操作，这个操作相当于地址传递
//	{
//		m_b=100;
//		//m_a=100;==this->m_a=100;//this指针本质是指针常量指针（person *const this）的指向不可更改（所以不能this=NULL）
//    //要变为常量指针常量（也不可以修改值）
//	//在成员函数后加从上图，修饰的是this指针，让指针指向的值也不可以修改	
//	}
////常对象
// 	
//	int m_a;
//	mutable int m_b;//特殊变量，即使在常函数中也可以修改这个值//加mutable	
//	
//};
//void test01(){
//	const person p;//在对象前加const变为常对象//常对象只能调用常函数
//	//常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
//	//p.func();
//	p.m_b=100;//可以修改
//	p.m_a=200;//没有mutable不可修改
//	}
//int main(){
////	person p;
////	p.showperson();
////	cout<<p.m_b<<endl;
//	system("pause");
//	return 0;
//} 

//友元
//在程序里，有些私有属性private也想让类外一些特殊的函数或者类进行访问，就需要用到友元技术
//友元的目的就是让一个函数或者类，访问另一个类中的私有成员
//友元关键字friend
//友元的实现;
//1全局函数做友元
//#include<iostream>
//#include<string>
//using namespace std;
//class building{
//	friend void bro(building *building);//在类内一开始声明:普通声明前加friend 说明此全局函数是可以尽情访问的
//public:
//	building(){
//		m_sittingroom="客厅";
//		m_bedroom="卧室";
//	}
//	string m_sittingroom;
//private:
//	string m_bedroom;
//};
//void bro(building *building){//可改值
//	cout<<"hibroopenthedoor"<<building->m_bedroom<<endl;
//
//}
//void test(){
//	building bud;
//	bro(&bud); 
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//2类做友元
//#include<iostream>
//#include<string>
//using namespace std;
//class Building;
//class guy{
//public:
//	void visit();//参观函数访问building属性
//	guy();
//	~guy();
////	Building building;//不能直接成员变量因为这样需要明确Building的定义而非声明
//    Building *building;	//为什么行：因为所有指针的大小都是固定的（在 32 位系统上通常是 4 字节，在 64 位系统上通常是 8 字节），无论它指向的对象是什么类型。
//};
//class Building{
//friend class guy;//依旧在private的类内声明
//public:
//	Building();//构造函数
//	~Building(){
//		cout<<22<<endl;//没输出new堆区没释放内存
//	}
//public:	
//	string sittingroom;
//private:
//	string bedroom;	
//};
//Building::Building(){//在最前加函数返回值类型
//	sittingroom="keting";
//	bedroom="woshi"	;
//	cout<<1<<endl;
//}
//guy::guy(){
//	building=new Building;//将building内存分配到堆区//只要创建对象就会有构造函数
//}
//void guy::visit(){
//	cout<<"zhengzaifangwen"<<building->sittingroom<<endl;
//	cout<<"zhengzaifangwen"<<building->bedroom<<endl;
//}
//void test(){
//	guy g;
//	g.visit();
//}
//guy::~guy(){
//	delete building;
//	building=nullptr;
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//3成员函数做友元
//#include<iostream>
//using namespace std;
//class building;
//class goodguy{
//public:
//	goodguy();
//	void visit();//让visit函数可以访问building中的私有成员
//	void visit1();//不可访问
//	building *building1;	
//};
//class building{
//	friend void goodguy::visit();//********
//public:
//	building();
//	string m_sittingroom;//客厅
//private:
//	string m_bedroom;	
//};
//building::building(){
//	m_sittingroom="keting";
//	m_bedroom="woshi";
//}
//goodguy::goodguy(){
//	building1=new building;
//}
//void goodguy::visit(){
//	cout<<building1->m_sittingroom<<endl;
//	cout<<building1->m_bedroom<<endl;
//}
//void goodguy::visit1(){
//	cout<<building1->m_sittingroom<<endl;
//}
//void test(){
//	goodguy g;
//	g.visit();
//	g.visit1();
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//运算符重载


//链表
//在指定位置上插入和删除
//#include<stdio.h>
//typedef struct node{
//	int value;
//	struct node*next;//指向而非创建
//};
//int main(){
//	node a;//节点
//	node b;
//	node *list=NULL;//空链表
//	list=&a;
//	a.next=&b;
//	b.next=NULL;
//	return 0;
//}
//链表的类型
//1.带头结点2.不带头结点
//不带头节点：每个节点都包含数据
//带头结点：头节点放任何数据（空链表） 每个数据节点都有一个前区（便利）
//方向
//1.单链表2.双向链表
//有无环
//链表 循环链表
//#include<stdio.h>
//#include<stdlib.h>
//struct node{
//	int value;
//	struct node*next;
//};
////创建头节点
////struct node* list_creat(){
////	struct node*list=(node *)malloc(sizeof(struct node));
////	if(list==NULL){
////		return NULL;
////	}
////	list->next=NULL;
////	
////	return list;
////}
////使用数组来创建一个
//struct node* list(int data[],int n){
//	struct node* list=(node*)malloc(sizeof(struct node));
//	list->value = -1;
//	if(list==NULL){
//		return NULL;
//	}
//	struct node* p=list;
//	for(int i=0;i<n;i++){
//		//创建
//		struct node*tmp=(node*)malloc(sizeof(struct node));
//		//设置数据
//		tmp->value=data[i];
//		p->next=tmp;
//		p=p->next;
//	}
//	p->next=NULL;
//	return list;
//}
//void visit_list(node *list){
//	for(struct node *p=list->next;p;p=p->next){
//		printf(" %d",p->value);
//	}
//	putchar('\n');
//}
////删除链表倒数节点
//bool list_del(struct node* list,int value){
//	if(list==NULL){
//		return false;
//	}
//	struct node*p;
//	for(p=list;p->next;p=p->next){
//		if(p->next->value==value){
//			break;
//		}
//	}
//	if(p->next==NULL){
//		return false;
//	}
//	//此时已经找到value
//	struct node* temp=p->next;//使用临时指针，指向代删节点
//	p->next=temp->next;
//	//内存释放
//	free(temp);//因为堆区只针对这一个地址
//	return true;
//}
//int main(){
//	int data[10]={1,2,3,4,5,6,7,8,9,10};
//	node *a=list(data,10);
//	visit_list(a);
//	list_del(a,5);
//	visit_list(a);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct node{
//    int index;
//    struct node *next;
//}node;
//
//node *list_creat(int a){
//    node* list=(node*)malloc(sizeof(node));
//    if(list==NULL){
//        exit(1);
//    }
//    list->index=a;
//    list->next=NULL;
//    return list;
//}
//
//node* addlist(int n){
//    node** temp = (node**)malloc((n+1) * sizeof(node*));
//    for(int i = 0; i <= n; i++){
//        temp[i] = list_creat(i);
//    }
//    int order;
//    for(int i=1;i<=n;i++){
//        scanf("%d",&order);
//        if(temp[order]->next==NULL){
//            temp[order]->next=temp[i];
//        }
//        else{
//            node* p=temp[order]->next;
//            temp[order]->next=temp[i];
//            temp[i]->next=p;
//        }
//    }
//    return temp[0];
//}
//void print(node* p){
//    node* tep=p->next;
//    while(tep!=NULL){
//        printf("%d",tep->index);
//        if(tep->next!=NULL){
//            putchar(' ');
//        }
//        tep=tep->next;
//    }
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    node *L=addlist(n);
//    print(L);
//    return 0;
//}
//#include<iostream>
//using namespace std; 
//int main(){
//	 int n;
//	 cin >> n;
//	 getchar();
//	 string s;
//	 while(n--){
//	 getline(cin,s);
//	 string result;
//	 if(s[0] >= 'a' && s[0] <= 'z'){
//	 s[0] -= 32;
//	 }
//	 result += s[0];
//	 for(int i = 1;i < s.size() - 1;i++){
//	 if(s[i] == ' ' && s[i + 1] != ' '){ // 对于本位是空格，下一位是字母的才处理，也就是只处理首字母，
//	//跳过连续空格
//	 if(s[i + 1] >= 'a' && s[i + 1] <= 'z'){
//	 s[i + 1] -= 32;
//	 }
//	 result += s[i + 1];
//	 }
//	 }
//	 cout << result << endl;
//	 }
//	 return 0;
//}
//运算重载符
//概念：对已有运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号运算符重载
//#include<iostream>
//using namespace std;
//class person{
//public:
//	int m_a;
//	int m_b;
//	//方法一：成员函数
//	person operator+(person &p){//自动使类靠左或右
//		person temp;
//		temp.m_a=this->m_a+p.m_a;
//		temp.m_b=this->m_b+p.m_b;
//		return temp;
//	}	//本质p1.m_a=p1.operator+(p2);
//};
//////全局函数重载
////	person operator+(person &p,person &p1){//表现形式p+p1//只针对这样的数据类型
////		person temp;
////		temp.m_a=p.m_a+p1.m_a;
////		temp.m_b=p.m_b+p.m_b;
////		return temp;
////	}
//void test(){
//	person p1;
//	p1.m_a=10;
//	p1.m_b=10;
//	person p2;
//	p2.m_a=10;
//	p2.m_b=10;
//	person p3;
//	p3=p1+p2;
//	cout<<p3.m_b;
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//左移运算符重载
//作用：可以输出自定义的数据类型
//#include<iostream>
//using namespace std;
//class person{
//	friend ostream &operator<<(ostream &out,person &p);//全局变量做友元
//public:
//	//1.利用成员函数重载左移运算符
//	//void operator<<()不用成员函数重载<<运算符，因为无法实现cout在左侧
//	int a;
//	int b;	
//private:
//	int c=1;
//	int d=2;
//};
////只能用全局运算符
//ostream &operator<<(ostream &out,person &p){//为什么&cout因为osteam类成员函数有且唯一有此输出功用（a,b）新定义符号放ab中间
//	//本质：operator<<(cout,p)==cout<<p;//只针对这一单一形参数据类型的组合
//	out<<p.a<<p.b<<p.c+p.d;
//	return out;
//}
//void test01(){
//	person p;
//	p.a=10;
//	p.b=10;
//	cout<<p<<" "<<"hello world";
//	cout<<p<<" 11";
//}
//int main(){
//	test01();
//	return 0;
//}
//递增运算符重载
//通过重载递增运算符，实现自己的整形数据
//#include<iostream>
//using namespace std;
////重载递增运算符
//
////自定义整形
//class myinteger{
//friend ostream& operator<<(ostream& cout,myinteger myint);
//public:
//	myinteger(){
//		m_num=0;
//	}
//	//重载前置++运算符
//	myinteger* operator++(){//构造函数会自动将类分配到符号后边，若有int去前面
//		//先进性++运算
//		m_num++;
//		//再将自身返回
//		return this;
//	}
//	//后置++
//	myinteger operator++(int){//返回值不可满足函数重载条件  int代表占位参数，可以区分前置和后置递增
//		//先记录
//		myinteger temp=*this;
//		//再递增
//		m_num++;
//		//后返回记录纸
//		return temp;//返回的是局部对象
//	}
//private:
//	int m_num;
//};
//////重载左移运算符
//ostream& operator<<(ostream& cout,myinteger myint){
//	cout<<myint.m_num;
//	return cout;
//}
//void test(){
//	myinteger myint;
//	cout<<*++(*++myint)<<"!";
//	cout<<myint;
////	cout<<myint++;//“++”当作构造函数
////	cout<<myint;
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//赋值运算符重载
//c++编译器至少给一个类添加4个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝构造函数，对属性进行值拷贝
//*4.赋值运算符operator=对属性进行值拷贝
//可以解决浅拷贝把地址拷贝一遍，删了两边问题
//#include<iostream>
//using namespace std;
//class person{
//	person& operator=(person &p){
//		if(m_a!=NULL){
//			delete m_a;
//			m_a=NULL;
//		}
//		m_a=new int(*p.m_a);
//	}
//	int *m_a;
//	return *this;
//};
//
//int main(){
//	
//}
//关系运算符重载
//#include<iostream>
//using namespace std;
//class person {
//public:
//	void operator()(int age) {
//		cout << age;
//	}
//	int operator()(int a, int b) {
//		return a + b;
//	}
//	bool operator==(person& p) {
//		if (this->age == p.age) {
//			return true;
//		}
//		return false;
//	}
//	int age;
//	person(int a) :age(a) {}
//	person() :age(0){}
//};
//int main() {
//	person p(18);
//	person p1 = 18;
//	p(18);
//	cout<<person()(100,100);//匿名对象调用函数内仿函数//前提要有默认构造函数，不要被含参和拷贝构造函数所覆盖
//	if (p1 == p) {
//		cout << "11";
//	}
//	return 0;
//}
//函数调用运算符重载
//由于重载后使用的方式非常像函数的调用，因此称仿函数
//仿函数无固定写法
//在一个类中重载的小括号
//继承
//下级别的成员除了拥有上亿的共性，还有特性
//#include<iostream>
//using namespace std;
//class a;
//class base{
//	friend a;
//public:
//	void print(){
//		cout<<"1"<<endl;
//	}
//private:
//	void print1(){
//		cout<<"2"<<endl;
//	}
//	int c;
//protected:
//	int a3;
//};
////语法class+子类：继承方式+父类；
////子类也称为派生类
////父类也称为基类
//class a:public base{
//public:	
//	int a1=0;
//	void solve(){
//		base temp;//应该有临时变量
//		temp.print1();//类内自动a.print1();
//		a1+=temp.c;
//		cout<<temp.a3;//protected只能继承
//	}
//};
//int main(){
//	a p;
//	base p1;
////	int c=p1.a3;//密封状态
////	p.print1();友元不能继承
////访问权限开放，但不能拥有
////继承时：public都可以拥有（都可访问） protected单传（儿子可拥有，有friend可以访问） private私有不可传（但可以访问如果friend）
////继承访问权限：虽然 a 是 base 的友元，但是 a 以 public 方式继承 base 时，基类的私有成员 print1() 在派生类 a 中仍然是不可访问的（即使 a 是 base 的友元）
//	p.solve();
//	p.print();
//	return 0;
//}
//继承方式
//一共有三种：
//公共继承
//public protect(仅限类内，和子类可访问) private（仅限类内）
//父类中私有权限访问不到，其他都可以以继承方式形式继承，但若父类protect，用public继承只能成protect
//容器：二元组
//std::pair<,> p;
//p.first/p.second;
//std::set
//插入的只保留一个（类似桶）//不支持随机访问
//自动排序
//std::map
//std::map<,> m;
//映射first->second
//可以开大值
//语法糖：利好编程的新特性
//1.auto 编译自动推导数据类型
//基于范围的for循环
//2for(datatype i:a){},适用容器
//结构化绑定
//3可以更方便提取子数据
//pair<int,int> u;
//auto[x,y]=u;
//cout<<x<<y;可以直接用xy；
//4lambda表达式
//把函数定义在函数里面，不会污染函数库
//函数std:reverse 功能：用来反转一个容器
// 类内声明

//模板函数，类外定义结构
//template <typename T>
//class Square {
//private:
//    T width;
//public:
//    Square(T w);           // 构造函数
//    T getArea() const;     // 成员函数
//    void setWidth(T w);    // 成员函数
//};
//
//// 类外定义：需要加上 template 声明和类名<T>::
//template <typename T>
//Square<T>::Square(T w) : width(w) {}
//
//template <typename T>
//T Square<T>::getArea() const {
//    return width * width;
//}
//
//template <typename T>
//void Square<T>::setWidth(T w) {
//    width = w;
//}



























