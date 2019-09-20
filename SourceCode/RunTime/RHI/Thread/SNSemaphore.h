//
// Created by liuqian8 on 2019/8/19.
//
#pragma once
#include <Semaphore.h>
class SNSemaphore
{
public:
    SNSemaphore();

    ~SNSemaphore();

    void reset();

    void waitForSignal();

    void signal();

private:
    sem_t m_Semaphore;
};
