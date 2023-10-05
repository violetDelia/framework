#ifndef __FRAMWORK_TENSOR_HPP__
#define __FRAMWORK_TENSOR_HPP__
#include "../core.hpp"

FRAMEWORK_NAMESPACE
{
    template <typename Base>
    class Tensor
    {
    public:
    protected:
    private:
        using data_type = Base;
    public:
    protected:
    private:
        data_type data_;
    };
} // namespace framwork

#endif // __FRAMWORK_TENSOR_HPP__
