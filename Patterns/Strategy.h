#include "Library.h"

// ����������, ������� ��������� ����������� ���������
__interface FlyBehavior
{
	void Fly();
};

__interface QuackBehavior
{
	void Quack();
};

///////////////////////////////////////////////////////////////////

// ������, ������� ��������� ���� �����
class FlyWithWings : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "����� ��������!\n";
	}
};

class Flightless : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "� �� ���� ������ :(\n";
	}
};

class JetPack : public FlyBehavior
{
public:
	void Fly()
	{
		cout << "���������� ���������� �����\n";
	}
};

///////////////////////////////////////////////////////////////////////

// ������, ������� ��������� ���� ��������
class UsualQuack : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "���-���!\n";
	}
};

class Squeak : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "����-����!\n";
	}
};

class SilentSqueak : public QuackBehavior
{
public:
	void Quack()
	{
		cout << "* ������ *\n";
		// ��� ������, ���� ������ ����� �������� ������
	}
};

////////////////////////////////////////////////////////////////

// ������� ����������� ����� ����
class Duck abstract
{
protected:
	FlyBehavior* fly_behavior = nullptr;
	QuackBehavior* quack_behavior = nullptr;

public:
	void virtual Swim() // ����� ���� ������������
	{
		cout << "��� ���� �������!\n";
	}

	void virtual Display() = 0; // ������ ���� ������������!

	//////////////////////////////////////////////////////////////////////

	void PerformFly()
	{
		fly_behavior->Fly(); // ������������� ���������
	}

	void PerformQuack()
	{
		quack_behavior->Quack();
	}

	//////////////////////////////////////////////////////////////////////

	void SetFlyBehavior(FlyBehavior* new_fly_behavior)
	{
		if (fly_behavior != nullptr) delete fly_behavior;
		fly_behavior = new_fly_behavior;
	}

	void SetQuackBehavior(QuackBehavior* new_quack_behavior)
	{
		if (quack_behavior != nullptr) delete quack_behavior;
		quack_behavior = new_quack_behavior;
	}
};

////////////////////////////////////////////////////////////////

// ���������� ����
class MallardDuck : public Duck
{
public:
	MallardDuck()
	{
		fly_behavior = new FlyWithWings;
		quack_behavior = new UsualQuack;
	}
	void Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/mallard.jpg");
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
	{
		fly_behavior = new Flightless;
		quack_behavior = new Squeak;
	}
	void virtual Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/rubber.jpg");
	}
};

class DecoyDuck : public Duck // ���������� ����-�����
{
public:
	DecoyDuck()
	{
		fly_behavior = new Flightless;
		quack_behavior = new SilentSqueak;
	}
	void virtual Display()
	{
		system("start https://trancemusic.000webhostapp.com/cpp/decoy.jpg");
	}
};
