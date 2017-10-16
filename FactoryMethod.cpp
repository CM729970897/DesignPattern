/*
��������
*/
#include<iostream>
using namespace std;

// ��Ʒ����
class ProductBase{
public:
	virtual void operation() = 0;
};

// �����Ʒ��A
class ProductA : public ProductBase{
public:
	virtual void operation(){
		cout << "i am product A" << endl;
	}
};

// �����Ʒ��B
class ProductB : public ProductBase{
public:
	virtual void operation(){
		cout << "i am product B" << endl;
	}
};

// ��������
class FactoryBase{
public:
	virtual ProductBase * create() = 0;
};

// ���幤����A
class FactoryMethodA{
public:
	virtual ProductBase * create(){
		return new ProductA();
	}
};

// ���幤����B
class FactoryMethodB{
public:
	virtual ProductBase * create(){
		return new ProductB();
	}
};

// main 
int main(int argc, char *argv[]){
	FactoryMethodA * fma = new FactoryMethodA();
	FactoryMethodB * fmb = new FactoryMethodB();
	ProductBase * obja = fma->create();
	ProductBase * objb = fmb->create();
	obja->operation();
	objb->operation();
	return 0;
}