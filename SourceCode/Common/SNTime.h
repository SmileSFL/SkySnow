//
// Created by liuqian8 on 2019/8/20.
//
#pragma once
using namespace std;
#include <sys/time.h>
class SNTime
{
public:
    SNTime();
    ~SNTime();

    long long getCurrentTime();

private:

    struct timeval tv;
};
