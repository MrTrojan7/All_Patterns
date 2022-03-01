#include "Library.h"

// ������� �����
enum class Size { S = 80, M = 180, L = 280, XXL = 500 };

class Drink abstract // ������� ����������� �������
{
protected:
    Size size;
    double price;
    string description;

public:
    Size getSize() const
    {
        return size;
    }

    double getPrice() const
    {
        return price;
    }

    string getDescription() const
    {
        return description;
    }

    void print() const
    {
        cout << description << " = " << price << " UAH\n";
    }
};

// ������ ��� - ���������� ������� ������� ��� �������
class BlackTea : public Drink
{
public:
    BlackTea(Size size)
    {
        this->size = size;
        description = "black tea from teabag";

        if (size == Size::M) price = 27; // 180�
        else if (size == Size::L) price = 32; // 280�
        else throw "invalid cup size";
    }
};

// ������ ��� - ���������� ������� ������� ��� �������
class GreenTea : public Drink
{
public:
    GreenTea()
    {
        // size = ...
        description = "green leaf tea";
        price = 45;
    }
};

// �������� - ���������� ������� ������� ��� �������
class Espresso : public Drink
{
public:
    Espresso()
    {
        // size = ...
        description = "small portion of strong coffee";
        price = 29;
    }
};

////////////////////////////////////////////////////////////////

// ������� ����������� ������� (���� ���� ������� Additive?)
class Condiment abstract : public Drink // ������� �������� ��� ��������� ������� - ��� ����� ��� ���������� ��������!
{
protected:
    Drink* drink; // ��������� �� ������������ �������
};

// ������
class MilkCondiment : public Condiment
{
public:
    MilkCondiment(Drink* drink)
    {
        this->drink = drink; // ������� �������, � ������� ����� �������
        description = this->drink->getDescription() + " + Milk (3 UAH)";
        price = this->drink->getPrice() + 3;
    }

    MilkCondiment() // ������ ����� ���� ������� �������
    {
        this->drink = this; // ������� �������, � ������� ����� �������
        description = "glass of milk";
        price = 10;
    }
};

class ChocolateCondiment : public Condiment
{
public:
    ChocolateCondiment(Drink* drink)
    {
        this->drink = drink;
        description = this->drink->getDescription() + " + Chocolate (5 UAH)";
        price = this->drink->getPrice() + 5;
    }
};

class SugarCondiment : public Condiment
{
public:
    SugarCondiment(Drink* drink)
    {
        this->drink = drink;
        description = this->drink->getDescription() + " + Sugar (1 UAH)";
        price = this->drink->getPrice() + 1;
    }
};