#include <list>
#include <memory>
#include <mutex>

class ThreadStrategy {
   public:
    virtual ~ThreadStrategy() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class SingleThreadStrategy final : public ThreadStrategy {
   public:
    void lock() override {};
    void unlock() override {};
};

class MyltiThreadStrategy final : public ThreadStrategy {
   public:
    void lock() override { m_mutex.lock(); };
    void unlock() override { m_mutex.unlock(); };

   private:
    std::mutex m_mutex{};
};

static_assert(sizeof(std::list) == 40);
static_assert(sizeof(std::unique_ptr<ThreadStrategy>) == 8);

template <typename T>
class Stack {
   public:
    explicit Stack(std::unique_ptr<ThreadStrategy>&& strategy) : m_strategy{std::move(strategy)} {};

    void push(T data) {
        m_strategy->lock();
        m_data.push(data);
        m_strategy->unlock();
    }

    T pop() {
        m_strategy->lock();
        auto data = m_data.back;
        m_strategy->unlock();
        return data;
    }

   private:
    std::list<T> m_data;                                  // 40
    std::unique_ptr<ThreadStrategy> m_strategy = nullptr; // 8
};

int main() {
    Stack<int> stack(std::make_unique<SingleThreadStrategy>());
    return 0;
}