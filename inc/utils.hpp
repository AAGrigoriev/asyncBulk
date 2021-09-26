#pragma once

namespace async {
    
    template <typename S>
    struct enable_make : public S {
        template <typename... T>
        enable_make(T&&...t) : S(std::forward<T>(t)...) {}
    };

} // namespace async