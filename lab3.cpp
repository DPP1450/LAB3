#include <bits/stdc++.h>
using namespace std;
class video
{
public:
    string name;
    int basePrice, latePrice, limit;
    float point;
    video(string name)
    {
        this->name = name;
    };
};

class newVideo : public video
{
public:
    newVideo(string name) : video(name)
    {
        basePrice = 3;
        latePrice = 2;
        limit = 1;
        point = 2;
    }
};

class oldVideo : public video
{
public:
    oldVideo(string name) : video(name)
    {
        basePrice = 2;
        latePrice = 1;
        limit = 3;
        point = 1;
    }
};
class childVideo : public video
{
public:
    childVideo(string name) : video(name)
    {
        basePrice = 2;
        latePrice = 1;
        limit = 5;
        point = 0.5;
    }
};

class customer
{
public:
    string name;
    int totalAmount;
    float point;
    customer(string name)
    {
        this->name = name;
        totalAmount = 0;
        point = 0;
    }
};

class rentRecord
{
public:
    customer *c;
    video *v;
    int day;
};

class manage
{
public:
    set<customer *> customers;                                 // 記錄所有的顧客
    set<video *> videos;                                       // 記錄所有的片
    set<rentRecord *> rentRecords;                             //記錄所有租借資料
    unordered_map<customer *, vector<rentRecord *>> recordMap; //用map可以快速查詢rentRecord

    void addRentRecord(customer *c, video *v, int totalDay)
    {
        rentRecord *r = new (rentRecord);
        r->v = v;
        r->c = c;
        r->day = totalDay;
        recordMap[c].push_back(r);
        rentRecords.insert(r);
        c->totalAmount += getPrice(totalDay, v);
        c->point += v->point;
    }

    void addCustomer(customer *newCustomer) // 新增顧客
    {
        customers.insert(newCustomer);
    }

    void addVideo(video *newVideo) // 新增影片
    {
        videos.insert(newVideo);
    }

    void getRecord(customer *c) // 印出特定顧客的租片紀錄
    {
        cout << "name :" << c->name << endl;
        for (auto r : recordMap[c])
            cout << r->v->name << " " << r->day << " days" << endl;
        cout << "totalAmount: " << c->totalAmount << "$" << endl;
        cout << "point: " << c->point << "pt" << endl
             << endl;
    }

    int getPrice(int totalDay, video *v)
    {
        return (totalDay <= v->limit) ? v->basePrice : v->basePrice + (totalDay - v->limit) * v->latePrice;
    }
};

int main()
{
    manage m;
    customer *april = new customer("april");
    customer *joe = new customer("joe");
    newVideo *superWoman = new newVideo("super woman");
    oldVideo *justiceLeague = new oldVideo("justice league");
    childVideo *thor3 = new childVideo("Thor3");
    m.addCustomer(april);
    m.addCustomer(joe);
    m.addVideo(superWoman);
    m.addVideo(justiceLeague);
    m.addVideo(thor3);
    m.addRentRecord(april, superWoman, 3);
    m.addRentRecord(joe, superWoman, 2);
    m.addRentRecord(april, justiceLeague, 5);
    m.addRentRecord(joe, thor3, 1);
    m.getRecord(april);
    m.getRecord(joe);
};