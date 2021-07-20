#pragma once
#include <ph_concepts/concepts.hpp>
//#include <math.h>


namespace ph::cryptography
{
    constexpr auto square_root (Number auto a) -> int;
    constexpr auto delar (int a, int b) -> bool;
    constexpr auto is_prime (auto n) -> bool;
    
    auto gcd (Number auto a, Number auto b)
    {
        assert(a != 0);
        assert(b != 0);
    }
    
    
    
    
    template <auto T>
    concept Prime = is_prime (T);
    template <typename T>
    concept Plaintext = String<T>;
    
    template <typename T>
    concept Ciphertext = String<T>;
    
    /**
     substitution - element i plaintext byts ut mot andra element
     transposition - element i plaintext flyttas om
     */
    
    /**algorithm for transforming plaintext to ciphertext*/
    template <typename T>
    concept Cipher = requires (T& t)
    {
        {t ("Ses kl 19?")} -> Ciphertext;
        true;
    };
    
    template <typename T>
    concept Key = requires ()
    {
        true;
    };
    
    
    
    auto encipher (Cipher auto&& algo, Key auto&& k, Plaintext auto&& src) -> Ciphertext auto;
    auto decipher (Cipher auto&& algo, Key auto&& key, Ciphertext auto&& src) -> Plaintext auto;
 
    auto rsa (Number auto p, Number auto q, String auto&& msg)
    requires (is_prime(p) and is_prime(q))
    {
        auto n = p * q;
        auto r = (p - 1) * (q - 1);
        auto e = 7;
        auto d = /**inverse(e)*/ e;
        
        
        
    }
    
    
    auto sign (String auto&& msg, auto&& private_key) -> String auto;
    auto encrypt (String auto&& msg, auto&& public_key) -> String auto;
    
    /**
     {[M]alice}alice = M
     
     [{M}alice]alice = M
     (message krypterat med alice publika nyckel message) krypterat med alice privata nyckel
     */
}
