#ifndef HOTEL_H
#define HOTEL_H

class hotel {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[11]; // Null byte for last character

public:
    void secure_login();
    void main_menu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void delete_rec(int);
};

#endif // HOTEL_H
