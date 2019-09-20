//
// Created by liuqian8 on 2019/8/19.
//
#pragma once

class Mutex
{
public:
    Mutex();

    ~Mutex();

    void acquire();

    bool tryAcquire();

    void release();

private:
    void* handle_;
};

class MutexLock
{
public:
    ///构造并获取互斥锁
    MutexLock(Mutex& mutex);
    /// 析构并释放互斥锁
    ~MutexLock();

private:
    /// 防止复制构造,重载这些操作符是防止非法的进行构造一个互斥量造成不可预料的结果
    MutexLock(const MutexLock& rhs);
    /// 防止重载运算符=复制构造
    MutexLock& operator =(const MutexLock& rhs);

    ///互斥锁指针
    Mutex& mutex_;
};
