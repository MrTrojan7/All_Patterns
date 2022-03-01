#include "Library.h"

class SkiRent // ������ ����������
{
public:
    double rentBoots(int feetSize, int skierLevel) // �������
    {
        double price = 159.99;
        // if (feetSize < 40) price -= 20; // ������ ��� �����
        return price;
    }

    double rentHelmet(int feetSize, int skierLevel) // ����
    {
        return 120;
    }

    double rentSki(int weight, int skierLevel) // ����
    {
        return 180;
    }

    double rentSkiPoles(int height) // ������ �����
    {
        return 50;
    }
};

// https://bukovel24.com/ru/skipass
class SkiResortTicketSystem // ������� �������
{
public:
    double buyOneDayTicket()
    {
        return 1100;
    }

    double buyTwoDaysTicket()
    {
        return 2050;
    }

    double buyThreeDaysTicket()
    {
        return 2900;
    }

    double buyFourDaysTicket()
    {
        return 3800;
    }

    double buyFiveDaysTicket()
    {
        return 4600;
    }

    double buySixDaysTicket()
    {
        return 5150;
    }

    double buySevenDaysTicket()
    {
        return 5800;
    }
};

// https://bukovel24.com/uk/hotels
class HotelBookingSystem // ����� ���������
{
public:
    double bookRoom(int roomQuality) {
        switch (roomQuality) {
        case 3:
            return 5670 / 2;
        case 4:
            return 9240 / 2;
        case 5:
            return 41500 / 2;
        default:
            throw "roomQuality should be in range [3;5]";
        }
    }
};

class SkiResortFacade // ���������� �������� "�����"
{
    SkiRent sr;
    SkiResortTicketSystem ts;
    HotelBookingSystem hb;

public:
    double haveAVeryVeryNiceTime(int height, int weight, int feetSize, int skierLevel, int roomQuality)
    {
        double skiPrice = sr.rentSki(weight, skierLevel);
        double skiBootsPrice = sr.rentBoots(feetSize, skierLevel);
        double polesPrice = sr.rentSkiPoles(height);
        double skiPassPrice = ts.buySevenDaysTicket();
        double hotelPrice = hb.bookRoom(roomQuality);

        return skiPrice + skiBootsPrice + polesPrice + skiPassPrice + hotelPrice;
    }

    double haveALittleFunWithYourOwnEquipmentAndTent()
    {
        double skiPassPrice = ts.buyOneDayTicket();
        return 0 + 0 + 0 + skiPassPrice + 0;
    }
};
