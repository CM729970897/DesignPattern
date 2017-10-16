/*
	�򵥹���
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

// �򵥹�����
class SimpleFactory{
public:
	static ProductBase * create(char type){
		switch (type)
		{
		case 'A':return new ProductA(); break;
		case 'B':return new ProductB(); break;
		default:
			return NULL;
			break;
		}
	}
};


// main 
int main(int argc, char *argv[]){
	ProductBase * obja = SimpleFactory::create('A');
	obja->operation();
	ProductBase * objb = SimpleFactory::create('B');
	objb->operation();

	return 0;
}