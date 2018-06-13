#pragma once
#include <cassert>
#include <memory>
#include <stack>
#include <vector>

namespace sfe
{
    template<typename T, size_t FixedSize>
    class MemoryPool
    {
    public:
        MemoryPool()
        {
            for(size_t i = 0; i < FixedSize; ++i)
            {
                mFreeObjects.emplace(std::make_shared<T>());
            }
            mBusyObjects.reserve(FixedSize);
        }

        ~MemoryPool()
        {
            assert(mBusyObjects.empty() && "Not all objects were released");
        }

        MemoryPool(const MemoryPool&) = delete;
        MemoryPool& operator=(const MemoryPool&) = delete;

        std::shared_ptr<T> Get()
        {
            if (mFreeObjects.empty())
            {
                return std::shared_ptr<T>();
            }

            auto result = mFreeObjects.top();
            mFreeObjects.pop();
            mBusyObjects.push_back(result);
            return result;
        }

        void Put(std::shared_ptr<T> obj)
        {
            for(auto it = mBusyObjects.cbegin(); it != mBusyObjects.cend(); ++it)
            {
                if (*it == obj)
                {
                    mBusyObjects.erase(it);
                    return;
                }
            }

            assert(false && "Pointer provided is not from this pool");
        }

        const std::vector<std::shared_ptr<T>>& GetBusyObjects() const
        {
            return mBusyObjects;
        }

    private:
        std::stack<std::shared_ptr<T>> mFreeObjects;
        std::vector<std::shared_ptr<T>> mBusyObjects;
    };
}

