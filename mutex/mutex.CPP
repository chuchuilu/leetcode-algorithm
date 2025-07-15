#include <mutex>

std::mutex mtx;

// 方法1：手动加锁/解锁（不推荐）
mtx.lock();
// 临界区代码
mtx.unlock();

// 方法2：使用 lock_guard（推荐）
{
    std::lock_guard<std::mutex> lock(mtx);
    // 临界区代码
    // 离开作用域自动解锁
}

// 方法3：使用 unique_lock（更灵活）
{
    std::unique_lock<std::mutex> lock(mtx);
    // 临界区代码
    // 可以手动 lock.unlock() 或自动解锁
}