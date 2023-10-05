#ifndef __FRAMWORK_CORE_HPP__
#define __FRAMWORK_CORE_HPP__

#include "core_helper.hpp"
#include <vector>
#include <cstdint>
FRAMEWORK_NAMESPACE
{
    //--------- define vector ----------//
    template <typename Ty>
    using vector = std::vector<Ty>;

    //--------- define bese type ----------//
    using int8_t = std::int8_t;
    using int16_t = std::int16_t;
    using int32_t = std::int32_t;
    using int64_t = std::int64_t;
    using uint8_t = std::uint8_t;
    using uint16_t = std::uint16_t;
    using uint32_t = std::uint32_t;
    using uint64_t = std::uint64_t;
    using float32_t = float;
    using float64_t = double;
    using size_t = std::size_t;
} // namespace framework
#endif // __FRAMWORK_CORE_HPP__
