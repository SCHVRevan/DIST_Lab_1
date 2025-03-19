#include <iostream>
using namespace std;

class Product {
    int price;
    public:
        Product(int p) {
            price = p;
        }
        void set_price(int p) {
            price = p;
        }
        int get_price() {
            return price;
        }
};

class IValid {
    virtual bool IsValid(int) = 0;
};

class otherValidator: IValid {
    public:
        bool IsValid(int pr) {
            return pr > 0;
        }
};

class customerValidator: IValid {
    public:
        bool IsValid(int pr) {
            return pr > 100000;
        }
};

int main() {
    int pr[4] = {-40, 0, 1300, 1000000000};
    otherValidator val1;
    customerValidator val2;
    for (int i = 0; i < 4; i++) {
        Product smth(pr[i]);
        cout << "For other: " << val1.IsValid(smth.get_price());
        cout << "   For customer: " << val2.IsValid(smth.get_price());
        cout << "   Price: " << smth.get_price() << "\n";
    }

    return 0;
}