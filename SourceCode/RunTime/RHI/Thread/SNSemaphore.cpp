//
// Created by liuqian8 on 2019/8/19.
//
#include "SNSemaphore.h"

SNSemaphore::SNSemaphore()
{
    if (sem_init(&m_Semaphore, 0, 0) == -1) ;
}

SNSemaphore::~SNSemaphore()
{
    if(sem_destroy(&m_Semaphore) == -1);
}

void SNSemaphore::reset()
{
    if(sem_destroy(&m_Semaphore) == -1);
    if (sem_init(&m_Semaphore, 0, 0) == -1);
}

void SNSemaphore::waitForSignal()//拿球
{
    if (sem_wait(&m_Semaphore) == -1);
}

void SNSemaphore::signal()//放球
{
    if (sem_post(&m_Semaphore) == -1);
}

