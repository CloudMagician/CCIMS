#ifndef CCMIS_H
#define CCMIS_H

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <time.h>

using namespace std;
#include "information.h"
#include "shop.h"
#include "user.h"
#include "jsonxx.h"



class CCMIS
{
private:
    Information*    mInfo;//信息表头结点
    Shop*   mShop;        //商店表头结点
    User*   mUser;        //用户表头结点
    int mUserNumber;

public:

    static const string USER_FILE_NAME;
    static const string SHOP_FILE_NAME;
    static const string INFO_FILE_NAME;

    static const string JSON_KEY_NUMBER;
    static const string JSON_KEY_NAME;
    static const string JSON_KEY_PASSWORD;
    static const string JSON_KEY_BALANCE;
    static const string JSON_KEY_COUPON;

    static const string JSON_KEY_TAG;
    static const string JSON_KEY_YEAR;
    static const string JSON_KEY_MONTH;
    static const string JSON_KEY_DAY;
    static const string JSON_KEY_HOUR;
    static const string JSON_KEY_MINUTE;
    static const string JSON_KEY_SECOND;
    static const string JSON_KEY_ONUMBER;
    static const string JSON_KEY_INUMBER;
    static const string JSON_KEY_MONEY;

    static const int GROUP_SUPERUSER;
    static const int GROUP_CANTEEN;
    static const int GROUP_MARKET;
    static const int GROUP_BATH;

    CCMIS();
    ~CCMIS() {}

    bool ReadInf(string filename);          //读入整个信息表文件
    bool WriteInf(string filename);         //写出整个信息表文件
    void ClearInf();                        //清空整个信息表
    void InsertInf(Information* tempinf);      //添加单个信息表
    void DeleteInf(Information* tempinf);   //删除单个信息表
    void ChangeInf(Information* beforeinf, Information* afterinf);//改变单个信息表

    bool WriteUser(string filename);

    bool ReadShop(string filename);     //读入整个商户表文件
    bool ReadUser(string filename);     //读入整个用户表文件

    void SearchNumber(int id);      //根据卡号输出信息
    void SearchSubsidy(int id);     //根据补贴输出信息
    void SearchTime(int startdate, int startime,
                    int finishdate, int finishtime);  //根据时间输出信息

    string GenerateTag(int onum, int inum, int mon);    //根据当前时间生成流水号
    string GenerateTag(int year, int month, int day, int hour, int min, int sec, int onum, int inum, int mon);    //手动生成流水号

    Information* BuildInfo(int onum, int inum, int mon);
    Information* BuildInfo(int year, int month, int day, int hour, int min, int sec, int onum, int inum, int mon);

    bool CheckPassword(string password);

    void SetUserNumber(int n);
};

#endif // CCMIS_H