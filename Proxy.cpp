/*
	����ģʽ
*/
#include<iostream>
using namespace std;

// ����ʵ����
class Subject{
public:
	virtual void operation() = 0;			// ���屩¶�Ľӿ�
};

// ��ʵʵ����
class RealSubject : public Subject{
public:
	virtual void operation(){
		cout << "��ʵ�Ĳ��������" << endl;
	}
};

RealSubject global_realsubject;		// ȫ����ʵʵ�����

// proxy ������
class Proxy : public Subject{
public:
	Proxy(){
		this->temp = &global_realsubject;
	}
	virtual void operation(){
		// handle something before do real operation
		// ......
		this->temp->operation();
	}

protected:
	RealSubject * temp;				// ����ʵʵ���һ������
};

int main(int argc, char * argv[]){
	Proxy * obj = new Proxy();
	obj->operation();

	delete obj;
	return 0;
}
