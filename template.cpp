/*
	ģ�巽��ģʽ
	����һЩ�����ڹ���hook�Ŀպ������ȴ����������ھ���ʵ�֡�
*/
#include<iostream>
using namespace std;

class TestPaper{
public:
	void question(){
		cout << "���Ǹ߱Ȱ��ʣ�" << endl;
		cout << answer() << endl;
	}

	virtual char answer(){
		return '#';
	}
};

class TestPaperA : public TestPaper{
	virtual char answer(){
		return 'y';
	}
};

int main(int argc, char * argv[]){
	TestPaper * obj = new TestPaperA();
	obj->question();
	return 0;
}