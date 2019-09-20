//
// Created by liuqian8 on 2019/8/20.
//

#include "SNTime.h"

SNTime::SNTime()
{

}

SNTime::~SNTime()
{

}

long long SNTime::getCurrentTime()
{
    gettimeofday(&tv,NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}