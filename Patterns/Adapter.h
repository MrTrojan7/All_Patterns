// ����� ����� ��������� � C++ ����, �������� ���, ��� ��������� ����������� ������ ����� ������
//��� ���������� ������ ������� � ������� ������������.
// �������� ���������� �������� : ������� �������� �������������� ������ � ������������ ��� 
//����� ��������� ����� �������.������ �������� ������ ���������� � ����������� ������ �������.
//��� ���������� ������ ���������� �������, ��������� ����� ���� ��������� ������ � ������, 
//�������������� ��������� ��������.

#include "Library.h"

class Target {
public:
    virtual ~Target() = default;

    virtual string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

 // ������������ ����� �������� ��������� �������� ���������, �� ��� ��������� ����������� � ������������ ����������
//  �����. ������������ ����� ��������� � ��������� ���������, ������ ��� ���������� ��� ������ ��� ������������.
 
class Adaptee 
{
public:
    string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// ������� ������ ��������� ������������� ������ ����������� � ������� �����������.
 
class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    string Request() const override
    {
        string to_reverse = this->adaptee_->SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

// ���������� ��� ������������ ��� ������, ������������ ������� ���������.
 
void ClientCode(const Target* target)
{
    cout << target->Request();
}
