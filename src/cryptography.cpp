#include "cryptography.hpp"


namespace ph::cryptography {
    
    constexpr auto square_root (Number auto a) -> int
    {
        
        auto const fun = [] (auto&& f, Number auto const org, Number auto curr) constexpr -> int
        {
            if (curr * curr <= org)
            {
                return curr;
                
            } else if (curr > 1)
            {
                return f (std::forward <decltype (f)> (f), org, curr - 1);
            } else
            {
                return 0;
            }
        };
//        constexpr auto res = fun (fun, a, a);
//        return fun (fun);
        return fun (fun, a, a);
    }
    
    static_assert(square_root(100) == 10, "");
    static_assert(square_root(99) == 9, "");
    static_assert(square_root(81) == 9, "");
    static_assert(square_root(1) == 1, "");

    
    
    constexpr auto delar (int a, int b) -> bool
    {
        /**
         Låt a och b vara heltal. Vi säger att a delar b om det nns ett
         heltal k så att b = a · k och detta betecknas med a | b
         */
        return b % a == 0;
    }
    
    static_assert (delar (3, 6));
    static_assert (not delar (6, 3));
    
    
    constexpr auto is_prime (auto n) -> bool
    {
        /**
         A positive integer which is only divisible
         by 1 and itself is known as prime number.
         */
        if (n <= 1) {
            return false;
        } else {
            for (auto i = 2; i <= square_root (n); ++i) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
    static_assert(not is_prime(49), "");
    static_assert(not is_prime(25), "");
    static_assert(is_prime(5), "");
    static_assert(not is_prime(4), "");
    static_assert(is_prime(3), "");
    static_assert(not is_prime(1), "");
    static_assert(not is_prime(0), "");
    static_assert(not is_prime(-1), "");
    static_assert(not is_prime(-2), "");
}
