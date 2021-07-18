#pragma once
#include <ph_concepts/concepts.hpp>

namespace ph::cryptography{
    
    
    template <typename T>
    concept Plaintext = String<T>;
    
    template <typename T>
    concept Ciphertext = String<T>;
    
    
    /**algorithm for transforming plaintext to ciphertext*/
    template <typename T>
    concept Cipher = requires (T& t)
    {
        {t ("Ses kl 19?")} -> Ciphertext;
        true;
    };
    
    auto encrypt (Plaintext auto&& src, auto key) -> Ciphertext auto&&;
    auto decrypt (Ciphertext auto&& src, auto key) -> Plaintext auto&&;
    
}
