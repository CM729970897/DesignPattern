/*
	װ����ģʽ
*/

#include<iostream>

// ������ࣨ����ʵ������
class Component{
public:
	virtual void operation() = 0;
};

// ConcreteComponent
class ConcreteComponent : public Component{
public:
	virtual void operation(){
		std::cout << "���Ǿ������" << std::endl;
	}
};

// ����װ����
class Decorator :public Component{
public:
	void set_component(Component * temp){
		this->component = temp;
	}

protected:
	Component * component = NULL;
};

// ����װ����A
class ConcreteDecoratorA :public Decorator{
public:
	void add_behavior_before_operation(){
		std::cout << "���Ǿ���װ����A��ConcreteDecoratorA��-->before" << std::endl;
	}

	void add_behavior_after_operation(){
		std::cout << "���Ǿ���װ����A��ConcreteDecoratorA��-->after" << std::endl;
	}

	virtual void operation(){
		this->add_behavior_before_operation();
		this->component->operation();
		this->add_behavior_after_operation();
	}
};

// ����װ����B
class ConcreteDecoratorB :public Decorator{
public:
	void add_behavior_before_operation(){
		std::cout << "���Ǿ���װ����B��ConcreteDecoratorA��-->before" << std::endl;
	}

	void add_behavior_after_operation(){
		std::cout << "���Ǿ���װ����B��ConcreteDecoratorA��-->after" << std::endl;
	}

	virtual void operation(){
		this->add_behavior_before_operation();
		this->component->operation();
		this->add_behavior_after_operation();
	}
};

// main
int main(int argc, char *argv[]){
	ConcreteComponent *pcc = new ConcreteComponent();
	ConcreteDecoratorA *pcda = new ConcreteDecoratorA();
	ConcreteDecoratorB *pcdb = new ConcreteDecoratorB();

	// װ��˳��
	pcda->set_component(pcc);
	pcdb->set_component(pcda);

	// do
	pcdb->operation();

	return 0;
}